#include "../../include/checkers/FourOfAKindChecker.h"

HandRank FourOfAKindChecker::check(const chosenHand& hand) const {
    if(hand[3].rank != 0){
        if((hand[0].rank == hand[1].rank && hand[1].rank == hand[2].rank && hand[2].rank == hand[3].rank) ||
           (hand[1].rank == hand[2].rank && hand[2].rank == hand[3].rank && hand[3].rank == hand[4].rank)) {
            return HandRank::FourOfAKind;
        }
    }

    return nextChecker 
            ? nextChecker->check(hand) 
            : HandRank::Unknown;
}

