#include "../../include/jokers/PairJoker.h"

std::string PairJoker::getName() const {
    return "Pair Joker";
}

std::string PairJoker::getDescription(const ScoreContext& context) const {
    // Hanya aktif jika hand type adalah Pair
    if (context.handType == HandRank::Pair) {
        return "Pair Joker: +4 Multiplier";
    }
    return "Pair Joker: Inactive (not a pair)";
}

void PairJoker::onScoreCalculated(ScoreContext& context) {
    // Berikan +4 multiplier jika hand adalah Pair
    if (context.handType == HandRank::Pair) {
        context.multiplier += 4;
    }
}
