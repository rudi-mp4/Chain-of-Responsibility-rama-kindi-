#pragma once

#include <vector>
#include "../Card.h"
#include "../HandRank.h"

/**
 * ScoreContext
 * Menyimpan runtime score data yang bersifat mutable.
 * Akan dimodifikasi langsung oleh Joker selama pipeline scoring.
 */
struct ScoreContext {
    // Kartu yang dimainkan
    std::vector<Card> cards;
    
    // Jenis poker hand
    HandRank handType;
    
    // Level dari hand
    int level;
    
    // Nilai chip saat ini (mutable, dapat dimodifikasi oleh Joker)
    int chips;
    
    // Nilai multiplier saat ini (mutable, dapat dimodifikasi oleh Joker)
    int multiplier;
    
    // Constructor
    ScoreContext()
        : handType(HandRank::Unknown), level(1), chips(0), multiplier(1) {}
    
    ScoreContext(const std::vector<Card>& c, HandRank h, int lvl, int ch, int mult)
        : cards(c), handType(h), level(lvl), chips(ch), multiplier(mult) {}
    
    // Helper untuk menghitung final score
    int getFinalScore() const {
        return chips * multiplier;
    }
};
