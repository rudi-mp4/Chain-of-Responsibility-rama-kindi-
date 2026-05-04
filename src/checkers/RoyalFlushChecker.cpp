#include "../../include/checkers/RoyalFlushChecker.h"

HandRank RoyalFlushChecker::check(const chosenHand& hand) const {
    if(hand[4].rank != 0){
        // cek apakah suitnya sama
        if(hand[0].suit == hand[1].suit &&
           hand[1].suit == hand[2].suit &&
           hand[2].suit == hand[3].suit &&
           hand[3].suit == hand[4].suit) {
            
            // cek apakah ranknya 10, J, Q, K, A
            // bikin array untuk nyimpan rank tiap kartu
            std::array<int, 5> ranks;
            for(int i = 0; i < 5; i++) {
                ranks[i] = hand[i].rank; // masukin rank kartu ke array
            }
    
            std::sort(ranks.begin(), ranks.end()); // sort array rank supaya urut
            if(ranks[0] == 10 && ranks[1] == 11 && ranks[2] == 12 && ranks[3] == 13 && ranks[4] == 14) {
                return HandRank::RoyalFlush;
            }
        }
    }

    return nextChecker 
            ? nextChecker->check(hand) 
            : HandRank::Unknown;
}


