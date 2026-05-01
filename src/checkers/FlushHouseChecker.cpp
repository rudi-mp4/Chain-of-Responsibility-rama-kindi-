#include "../../include/checkers/FlushHouseChecker.h"

HandRank FlushHouseChecker::check(const Hand& hand) const {
    // cek dulu semua suitnya sama
    if(hand[0].suit == hand[1].suit &&
       hand[1].suit == hand[2].suit &&
       hand[2].suit == hand[3].suit &&
       hand[3].suit == hand[4].suit) {
        // cek angkanya full house
        if((hand[0].rank == hand[1].rank && hand[1].rank == hand[2].rank && hand[3].rank == hand[4].rank) ||
           (hand[0].rank == hand[1].rank && hand[2].rank == hand[3].rank && hand[3].rank == hand[4].rank)) {
            return HandRank::FlushHouse;
        }
    }
    return nextChecker 
            ? nextChecker->check(hand) 
            : HandRank::Unknown;
}


