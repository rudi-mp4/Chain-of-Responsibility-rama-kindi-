#include "../../include/scoring/ScoringRule.h"

ScoringRule::ScoringRule()
    : chipIncreasePerLevel(0.1), multIncreasePerLevel(0.1) {}

int ScoringRule::calculateScore(int chips, int mult) const {
    return chips * mult;
}

int ScoringRule::calculateAdjustedChips(int baseChips, int level) const {
    // Formula: adjustedChips = baseChips + (baseChips * (level - 1) * chipIncreasePerLevel)
    if (level <= 1) return baseChips;
    double increase = baseChips * (level - 1) * chipIncreasePerLevel;
    return baseChips + static_cast<int>(increase);
}

int ScoringRule::calculateAdjustedMult(int baseMult, int level) const {
    // Formula: adjustedMult = baseMult + (baseMult * (level - 1) * multIncreasePerLevel)
    if (level <= 1) return baseMult;
    double increase = baseMult * (level - 1) * multIncreasePerLevel;
    return baseMult + static_cast<int>(increase);
}

void ScoringRule::setChipIncreasePerLevel(double increase) {
    chipIncreasePerLevel = increase;
}

void ScoringRule::setMultIncreasePerLevel(double increase) {
    multIncreasePerLevel = increase;
}

double ScoringRule::getChipIncreasePerLevel() const {
    return chipIncreasePerLevel;
}

double ScoringRule::getMultIncreasePerLevel() const {
    return multIncreasePerLevel;
}
