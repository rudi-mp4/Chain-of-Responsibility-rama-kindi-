#include "../../include/scoring/HandResolver.h"

HandResolver::HandResolver(IPokerHandChecker* checker)
    : pokerHandChecker(checker),
      scoreTable(std::make_unique<HandScoreTable>()),
      scoringRule(std::make_unique<ScoringRule>()) {}

HandResolver::HandResolver(IPokerHandChecker* checker,
                           std::unique_ptr<HandScoreTable> table,
                           std::unique_ptr<ScoringRule> rule)
    : pokerHandChecker(checker),
      scoreTable(std::move(table)),
      scoringRule(std::move(rule)) {}

PlayedHandResult HandResolver::resolveHand(const chosenHand& hand, int level, JokerManager* jokerManager) {
    // Step 1: Evaluasi hand menggunakan checker
    HandRank handType = pokerHandChecker->check(hand);
    
    // Step 2: Ambil base chips dan mult dari score table
    int baseChips = scoreTable->getBaseChips(handType);
    int baseMult = scoreTable->getBaseMult(handType);
    
    // Step 3: Sesuaikan nilai berdasarkan level
    int adjustedChips = scoringRule->calculateAdjustedChips(baseChips, level);
    int adjustedMult = scoringRule->calculateAdjustedMult(baseMult, level);
    
    // --- BARU: Integrasi Joker ---
    // Step 4: Buat ScoreContext dan jalankan Joker Pipeline
    std::vector<Card> cards;
    for (const auto& card : hand) {
        if (card.rank != 0) cards.push_back(card);
    }
    
    ScoreContext context(cards, handType, level, adjustedChips, adjustedMult);
    
    if (jokerManager) {
        jokerManager->executeJokerPipeline(context);
    }
    
    // Step 5: Hitung final score dari context yang mungkin sudah dimodifikasi Joker
    int finalScore = context.getFinalScore();
    
    // Step 6: Buat dan kembalikan hasil
    return PlayedHandResult(cards, handType, level, context.chips, context.multiplier, finalScore);
}

void HandResolver::setChecker(IPokerHandChecker* checker) {
    pokerHandChecker = checker;
}

const HandScoreTable* HandResolver::getScoreTable() const {
    return scoreTable.get();
}

const ScoringRule* HandResolver::getScoringRule() const {
    return scoringRule.get();
}
