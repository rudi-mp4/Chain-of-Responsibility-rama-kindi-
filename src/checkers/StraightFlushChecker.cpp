#include "../../include/checkers/StraightFlushChecker.h"

HandRank StraightFlushChecker::check(const chosenHand& hand) const {
    if(hand[4].rank != 0){
        // cek straight dulu
        if(hand[0].rank == hand[1].rank - 1 &&
           hand[1].rank == hand[2].rank - 1 &&
           hand[2].rank == hand[3].rank - 1 &&
           hand[3].rank == hand[4].rank - 1) {
            // cek flush
            if(hand[0].suit == hand[1].suit &&
               hand[1].suit == hand[2].suit &&
               hand[2].suit == hand[3].suit &&
               hand[3].suit == hand[4].suit) {
                return HandRank::StraightFlush;
            }
        }
    }

    return nextChecker 
            ? nextChecker->check(hand) 
            : HandRank::Unknown;
}

