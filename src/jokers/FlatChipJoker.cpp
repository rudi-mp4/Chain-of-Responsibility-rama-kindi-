#include "../../include/jokers/FlatChipJoker.h"

std::string FlatChipJoker::getName() const {
    return "Flat Chip Joker";
}

std::string FlatChipJoker::getDescription(const ScoreContext& context) const {
    return "Flat Chip Joker: +20 Chips (always active)";
}

void FlatChipJoker::onScoreCalculated(ScoreContext& context) {
    // Selalu aktif: berikan +20 chips
    context.chips += 20;
}
