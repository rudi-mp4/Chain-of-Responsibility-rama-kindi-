#include "../../include/checkers/OnePairChecker.h"

HandRank OnePairChecker::check(const Hand& hand) const {
    // cek apakah ada pasangan
    for(int i = 0; i < 4; i++) {
        if(hand[i].rank == hand[i+1].rank) {
            return HandRank::Pair;
        }
    }

    return nextChecker 
            ? nextChecker->check(hand) 
            : HandRank::Unknown;
}

