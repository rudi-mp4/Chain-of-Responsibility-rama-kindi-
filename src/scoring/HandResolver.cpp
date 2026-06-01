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

PlayedHandResult HandResolver::resolveHand(const chosenHand& hand, int level) {
    // Step 1: Evaluasi hand menggunakan checker
    HandRank handType = pokerHandChecker->check(hand);
    
    // Step 2: Ambil base chips dan mult dari score table
    int baseChips = scoreTable->getBaseChips(handType);
    int baseMult = scoreTable->getBaseMult(handType);
    
    // Step 3: Sesuaikan nilai berdasarkan level
    int adjustedChips = scoringRule->calculateAdjustedChips(baseChips, level);
    int adjustedMult = scoringRule->calculateAdjustedMult(baseMult, level);
    
    // Step 4: Hitung final score
    int finalScore = scoringRule->calculateScore(adjustedChips, adjustedMult);
    
    // Step 5: Buat dan kembalikan hasil
    std::vector<Card> cards(hand.begin(), hand.end());
    return PlayedHandResult(cards, handType, level, adjustedChips, adjustedMult, finalScore);
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
