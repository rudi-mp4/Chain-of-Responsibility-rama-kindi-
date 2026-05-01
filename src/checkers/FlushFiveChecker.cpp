#include "../../include/checkers/FlushFiveChecker.h"

HandRank FlushFiveChecker::check(const Hand& hand) const {
    // cek suitnya dulu
    if(hand[0].suit == hand[1].suit &&
       hand[1].suit == hand[2].suit &&
       hand[2].suit == hand[3].suit &&
       hand[3].suit == hand[4].suit) {
        // cek ranknya
        if(hand[0].rank == hand[1].rank &&
           hand[1].rank == hand[2].rank &&
           hand[2].rank == hand[3].rank &&
           hand[3].rank == hand[4].rank) {
            return HandRank::FlushFive;
        }
    }
    
    return nextChecker 
            ? nextChecker->check(hand) 
            : HandRank::Unknown;
}



