// #include "../include/PokerHandChecker.h"
// #include "../include/Card.h"
#include "../include/PokerHandChecker.h"
#include "../include/Card.h"
#include "../include/Hand.h"
#include "../include/HandGenerator.h"

#include <cstdio>
#include "Card.cpp"
#include "HandGenerator.cpp"
#include "IPokerHandChecker.cpp"
#include "HandRank.cpp"
#include "PokerHandChecker.cpp"
#include "hand.cpp"

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
// Hand hand;
// ====== BATAS VARIABEL GLOBAL =====

void runSession(){
    printf("=== Run Started ===\n");
    // Generate random hand
    Hand deck = generateRandomHand();
    // Player chooses cards
    SelectedIndices selected = chooseHand(deck);
    // Convert to chosenHand format
    chosenHand hand = convertToHand(deck, selected);
    // Play the hand (evaluate rank)
    playHand(hand, selected.size());

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
