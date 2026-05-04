#include "../../include/checkers/FlushChecker.h"

HandRank FlushChecker::check(const chosenHand& hand) const {
    if(hand[4].rank != 0){
        if(hand[0].suit == hand[1].suit &&
           hand[1].suit == hand[2].suit &&
           hand[2].suit == hand[3].suit &&
           hand[3].suit == hand[4].suit) {
            return HandRank::Flush;
        }
    }
    
    return nextChecker 
            ? nextChecker->check(hand) 
            : HandRank::Unknown;
}


