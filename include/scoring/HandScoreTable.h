#pragma once

#include <unordered_map>
#include "../HandRank.h"

// Hash function specialization untuk HandRank enum
namespace std {
    template<>
    struct hash<HandRank> {
        std::size_t operator()(const HandRank& rank) const {
            return static_cast<std::size_t>(rank);
        }
    };
}

/**
 * HandScoreTable
 * Menyimpan nilai dasar (Chips dan Mult) untuk setiap jenis poker hand pada Level 1.
 */
class HandScoreTable {
public:
    struct ScoreEntry {
        int chips;
        int mult;
    };
    
    HandScoreTable();
    
    /**
     * Mendapatkan nilai base chips untuk hand type tertentu pada level 1
     */
    int getBaseChips(HandRank rank) const;
    
    /**
     * Mendapatkan nilai base multiplier untuk hand type tertentu pada level 1
     */
    int getBaseMult(HandRank rank) const;
    
    /**
     * Mendapatkan entry lengkap (chips dan mult)
     */
    ScoreEntry getEntry(HandRank rank) const;
    
private:
    std::unordered_map<HandRank, ScoreEntry> scoreTable;
};
