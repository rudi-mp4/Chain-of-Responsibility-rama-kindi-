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

void runSession() {
    printf("Welcome to the Poker Hand Checker!\n");
    
    // eeee generetae kartu random
    Hand hand = generateRandomHand();

    // ngeprint kartunya
    printf("Your hand:\n");
    for (const auto& card : hand) {
        printf("%d of %s\n", card.rank, card.suit == Suit::Clubs ? "Clubs" :
                             card.suit == Suit::Diamonds ? "Diamonds" :
                             card.suit == Suit::Hearts ? "Hearts" : "Spades");
    }

    // ngecek kartunya
    auto checkerChain = buildDefaultCheckerChain();
    // HandRank rank = checkerChain->check(hand);
    // printf("\nYour hand rank: %s\n", handRankToString(rank).c_str());

}

int main() {
    runSession();
    return 0;
}
