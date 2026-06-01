#include "../../include/scoring/ScoringRule.h"

ScoringRule::ScoringRule() 
    : chipIncreasePerLevel(0.1), multIncreasePerLevel(0.1) {
}

int ScoringRule::calculateScore(int chips, int mult) const {
    return chips * mult;
}

int ScoringRule::calculateAdjustedChips(int baseChips, int level) const {
    // Formula: adjustedChips = baseChips + (baseChips * (level - 1) * chipIncreasePerLevel)
    // Atau bisa juga: adjustedChips = baseChips * (1 + (level - 1) * chipIncreasePerLevel)
    if (level <= 1) {
        return baseChips;
    }
    
    int increase = static_cast<int>(baseChips * (level - 1) * chipIncreasePerLevel);
    return baseChips + increase;
}

int ScoringRule::calculateAdjustedMult(int baseMult, int level) const {
    // Formula: adjustedMult = baseMult + (baseMult * (level - 1) * multIncreasePerLevel)
    if (level <= 1) {
        return baseMult;
    }
    
    int increase = static_cast<int>(baseMult * (level - 1) * multIncreasePerLevel);
    return baseMult + increase;
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
