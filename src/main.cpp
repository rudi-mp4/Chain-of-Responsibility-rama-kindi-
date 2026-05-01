// #include "../include/PokerHandChecker.h"
// #include "../include/Card.h"
#include "../include/PokerHandChecker.h"
#include "../include/Card.h"
#include "Card.cpp"
#include "IPokerHandChecker.cpp"
#include "HandRank.cpp"
#include "PokerHandChecker.cpp"

// Include all checker implementations
#include "checkers/HighCardChecker.cpp"
#include "checkers/OnePairChecker.cpp"
#include "checkers/TwoPairChecker.cpp"
#include "checkers/ThreeOfAKindChecker.cpp"
#include "checkers/StraightChecker.cpp"
#include "checkers/FlushChecker.cpp"
#include "checkers/FullHouseChecker.cpp"
#include "checkers/FourOfAKindChecker.cpp"
#include "checkers/StraightFlushChecker.cpp"
#include "checkers/RoyalFlushChecker.cpp"
#include "checkers/FiveOfAKindChecker.cpp"
#include "checkers/FlushFiveChecker.cpp"
#include "checkers/FlushHouseChecker.cpp"

// variabel global
Hand hand;

void runSession(){
    printf("=== Run Started ===\n");
    // generate kartu random
    hand = generateRandomHand();

    // ngeprint kartunya
    printf("Your hand:\n");
    for (const auto& card : hand) {
        printf("%d of %s\n", card.rank, card.suit == Suit::Clubs ? "Clubs" :
                             card.suit == Suit::Diamonds ? "Diamonds" :
                             card.suit == Suit::Hearts ? "Hearts" : "Spades");
    }

    // hand.playHand(hand);
    // int score = scoringRule.scoreHand(hand);
    // bool win = blindRule.checkBlind(score);
    // int reward = rewardRule.earnMoney(win, score);
    // std::cout << "Money gained: " << reward << "\n";
    printf("=== Run Ended ===\n");
}

int main() {
    runSession();
    return 0;
}
