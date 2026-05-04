#include "../../include/checkers/ThreeOfAKindChecker.h"

HandRank ThreeOfAKindChecker::check(const chosenHand& hand) const {
    if(hand[2].rank != 0){
        // cek apakah ada tiga kartu dengan rank yang sama
        for(int i = 0; i < 3; i++) {
            if(hand[i].rank == hand[i+1].rank && hand[i+1].rank == hand[i+2].rank) {
                return HandRank::ThreeOfAKind;
            }
        }
    }

    return nextChecker 
            ? nextChecker->check(hand) 
            : HandRank::Unknown;
}


