#include "../../include/scoring/HandResolver.h"
#include <stdexcept>

HandResolver::HandResolver(IPokerHandChecker* checker)
    : pokerHandChecker(checker),
      scoreTable(std::make_unique<HandScoreTable>()),
      scoringRule(std::make_unique<ScoringRule>()) {
    if (!checker) {
        throw std::invalid_argument("PokerHandChecker tidak boleh null");
    }
}

HandResolver::HandResolver(IPokerHandChecker* checker,
                           std::unique_ptr<HandScoreTable> scoreTable,
                           std::unique_ptr<ScoringRule> scoringRule)
    : pokerHandChecker(checker),
      scoreTable(std::move(scoreTable)),
      scoringRule(std::move(scoringRule)) {
    if (!checker) {
        throw std::invalid_argument("PokerHandChecker tidak boleh null");
    }
    if (!this->scoreTable) {
        this->scoreTable = std::make_unique<HandScoreTable>();
    }
    if (!this->scoringRule) {
        this->scoringRule = std::make_unique<ScoringRule>();
    }
}

PlayedHandResult HandResolver::resolveHand(const chosenHand& hand, int level) {
    // Step 1: Evaluasi hand type menggunakan PokerHandChecker
    HandRank handType = pokerHandChecker->check(hand);
    
    // Step 2: Ambil nilai base dari HandScoreTable
    int baseChips = scoreTable->getBaseChips(handType);
    int baseMult = scoreTable->getBaseMult(handType);
    
    // Step 3: Hitung chips dan mult yang sudah disesuaikan dengan level
    int adjustedChips = scoringRule->calculateAdjustedChips(baseChips, level);
    int adjustedMult = scoringRule->calculateAdjustedMult(baseMult, level);
    
    // Step 4: Hitung final score
    int finalScore = scoringRule->calculateScore(adjustedChips, adjustedMult);
    
    // Step 5: Buat dan kembalikan PlayedHandResult
    std::vector<Card> cards(hand.begin(), hand.end());
    
    return PlayedHandResult(cards, handType, level, adjustedChips, adjustedMult, finalScore);
}

void HandResolver::setChecker(IPokerHandChecker* checker) {
    if (!checker) {
        throw std::invalid_argument("PokerHandChecker tidak boleh null");
    }
    pokerHandChecker = checker;
}

const HandScoreTable* HandResolver::getScoreTable() const {
    return scoreTable.get();
}

const ScoringRule* HandResolver::getScoringRule() const {
    return scoringRule.get();
}
