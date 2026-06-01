#include "../include/PokerHandChecker.h"
#include "../include/Card.h"
#include "../include/Hand.h"
#include "../include/HandGenerator.h"
#include "../include/scoring/HandResolver.h"
#include "../include/scoring/HandScoreTable.h"

// Joker System includes
#include "../include/jokers/ScoreContext.h"
#include "../include/jokers/JokerManager.h"
#include "../include/jokers/PairJoker.h"
#include "../include/jokers/FlatChipJoker.h"

#include "../include/GameManager.h"

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

// Include scoring implementations
#include "scoring/HandScoreTable.cpp"
#include "scoring/ScoringRule.cpp"
#include "scoring/HandResolver.cpp"

// Include Joker implementations
#include "jokers/JokerManager.cpp"
#include "jokers/PairJoker.cpp"
#include "jokers/FlatChipJoker.cpp"

// Include GameManager
#include "GameManager.cpp"
// Hand hand;
// ====== BATAS VARIABEL GLOBAL =====

void runSession(){
    printf("=== Run Started ===\n");
    
    // Setup Joker Manager dan Jokers
    JokerManager jokerManager;
    GameManager::setupJokers(jokerManager);
    
    // Generate random hand
    Hand deck = generateRandomHand();
    // Player chooses cards
    SelectedIndices selected = chooseHand(deck);
    // Convert to chosenHand format
    chosenHand hand = convertToHand(deck, selected);
    // Play the hand
    playHand(hand, selected.size());
    // Resolve scoring dengan HandResolver
    IPokerHandChecker* checkerChain = buildDefaultCheckerChain();
    HandResolver resolver(checkerChain);
    PlayedHandResult result = resolver.resolveHand(hand, 1);
    
    printf("\n[Hand played!]\n");
}

int main() {
    runSession();
    return 0;
}
