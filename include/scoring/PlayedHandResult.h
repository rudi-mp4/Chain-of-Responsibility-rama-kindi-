#pragma once

#include <vector>
#include "../Card.h"
#include "../HandRank.h"

/**
 * PlayedHandResult
 * Menyimpan hasil akhir dari hand yang dimainkan.
 */
struct PlayedHandResult {
    // Kartu-kartu yang dipilih
    std::vector<Card> cards;
    
    // Jenis poker hand akhir
    HandRank handType;
    
    // Level dari hand tersebut
    int level;
    
    // Nilai base chip
    int chips;
    
    // Nilai base multiplier
    int mult;
    
    // Skor akhir yang dihitung
    int finalScore;
    
    // Constructor
    PlayedHandResult() 
        : handType(HandRank::Unknown), level(1), chips(0), mult(0), finalScore(0) {}
    
    PlayedHandResult(const std::vector<Card>& c, HandRank h, int lvl, 
                     int ch, int m, int score)
        : cards(c), handType(h), level(lvl), chips(ch), mult(m), finalScore(score) {}
};
