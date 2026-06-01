#pragma once

#include "HandScoreTable.h"
#include "PlayedHandResult.h"

/**
 * ScoringRule
 * Fungsi dan parameter untuk menghitung skor akhir berdasarkan rumus:
 * Final Score = chips * mult
 * 
 * Nilai chips dan mult akan bertambah berdasarkan level dari masing-masing hand.
 */
class ScoringRule {
public:
    ScoringRule();
    
    /**
     * Menghitung skor akhir
     * Formula: finalScore = chips * mult
     */
    int calculateScore(int chips, int mult) const;
    
    /**
     * Menghitung chips yang sudah disesuaikan dengan level
     * Formula: adjustedChips = baseChips + (baseChips * (level - 1) * chipIncreasePerLevel)
     */
    int calculateAdjustedChips(int baseChips, int level) const;
    
    /**
     * Menghitung mult yang sudah disesuaikan dengan level
     * Formula: adjustedMult = baseMult + (baseMult * (level - 1) * multIncreasePerLevel)
     */
    int calculateAdjustedMult(int baseMult, int level) const;
    
    /**
     * Setter untuk parameter peningkatan per level (dalam bentuk desimal)
     * Contoh: 0.1 berarti 10% per level
     */
    void setChipIncreasePerLevel(double increase);
    void setMultIncreasePerLevel(double increase);
    
    /**
     * Getter untuk parameter peningkatan per level
     */
    double getChipIncreasePerLevel() const;
    double getMultIncreasePerLevel() const;

private:
    // Persentase peningkatan chips per level (default: 0.1 = 10%)
    double chipIncreasePerLevel = 0.1;
    
    // Persentase peningkatan mult per level (default: 0.1 = 10%)
    double multIncreasePerLevel = 0.1;
};
