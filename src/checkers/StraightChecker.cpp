#include "../../include/checkers/StraightChecker.h"

HandRank StraightChecker::check(const Hand& hand) const {
    if(hand[0].rank == hand[1].rank - 1 &&
       hand[1].rank == hand[2].rank - 1 &&
       hand[2].rank == hand[3].rank - 1 &&
       hand[3].rank == hand[4].rank - 1) {
        return HandRank::Straight;
    }

    return nextChecker 
            ? nextChecker->check(hand) 
            : HandRank::Unknown;
}



