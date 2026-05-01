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
// ====== BATAS VARIABEL GLOBAL =====

// ====== FUNGSI DI BAWAH SINI =====
void printHandRank(HandRank rank) {
    switch (rank) {
        case HandRank::HighCard: printf("High Card\n"); break;
        case HandRank::Pair: printf("One Pair\n"); break;
        case HandRank::TwoPair: printf("Two Pair\n"); break;
        case HandRank::ThreeOfAKind: printf("Three of a Kind\n"); break;
        case HandRank::Straight: printf("Straight\n"); break;
        case HandRank::Flush: printf("Flush\n"); break;
        case HandRank::FullHouse: printf("Full House\n"); break;
        case HandRank::FourOfAKind: printf("Four of a Kind\n"); break;
        case HandRank::StraightFlush: printf("Straight Flush\n"); break;
        case HandRank::RoyalFlush: printf("Royal Flush\n"); break;
        case HandRank::FiveOfAKind: printf("Five of a Kind\n"); break;
        case HandRank::FlushHouse: printf("Flush House\n"); break;
        case HandRank::FlushFive: printf("Flush Five\n"); break;
        default: printf("Unknown hand rank\n");
    }
}

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

    // ngecheck kartunya
    IPokerHandChecker* checkerChain = buildDefaultCheckerChain();
    HandRank rank = checkerChain->check(hand);
    printHandRank(rank);
    
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
