#include "../../include/checkers/FullHouseChecker.h"

HandRank FullHouseChecker::check(const chosenHand& hand) const {
    if(hand[4].rank != 0){
        if((hand[0].rank == hand[1].rank && hand[1].rank == hand[2].rank && hand[3].rank == hand[4].rank) ||
           (hand[0].rank == hand[1].rank && hand[2].rank == hand[3].rank && hand[3].rank == hand[4].rank)) {
            return HandRank::FullHouse;
        }
    }

    return nextChecker 
            ? nextChecker->check(hand) 
            : HandRank::Unknown;
}


