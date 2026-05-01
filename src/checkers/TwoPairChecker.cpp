#include "../../include/checkers/TwoPairChecker.h"

HandRank TwoPairChecker::check(const Hand& hand) const {
    // cek apakah ada dua pasang
    if((hand[0].rank == hand[1].rank && hand[2].rank == hand[3].rank) ||
       (hand[0].rank == hand[1].rank && hand[3].rank == hand[4].rank) ||
       (hand[1].rank == hand[2].rank && hand[3].rank == hand[4].rank)) {
        return HandRank::TwoPair;
    }

    return nextChecker 
            ? nextChecker->check(hand) 
            : HandRank::Unknown;
}


