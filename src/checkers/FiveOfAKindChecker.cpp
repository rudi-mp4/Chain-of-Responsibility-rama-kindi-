#include "../../include/checkers/FiveOfAKindChecker.h"

HandRank FiveOfAKindChecker::check(const Hand& hand) const {
    if(hand[0].rank == hand[1].rank &&
       hand[1].rank == hand[2].rank &&
       hand[2].rank == hand[3].rank &&
       hand[3].rank == hand[4].rank) {
        return HandRank::FiveOfAKind;
    }
    
    return nextChecker 
            ? nextChecker->check(hand) 
            : HandRank::Unknown;
}


