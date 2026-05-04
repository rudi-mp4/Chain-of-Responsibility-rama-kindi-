#include "../../include/checkers/FiveOfAKindChecker.h"

HandRank FiveOfAKindChecker::check(const chosenHand& hand) const {
    // Cek apakah kartu ke-5 adalah joker (rank 0)
    // jika rank 0 maka skip pengecekan handRank
    if(hand[4].rank != 0){
        if(hand[0].rank == hand[1].rank &&
           hand[1].rank == hand[2].rank &&
           hand[2].rank == hand[3].rank &&
           hand[3].rank == hand[4].rank) {
            return HandRank::FiveOfAKind;
        }
    }

    
    return nextChecker 
            ? nextChecker->check(hand) 
            : HandRank::Unknown;
}


