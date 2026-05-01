#include "../include/PokerHandChecker.h"
#include "../include/Card.h"
#include "../include/Hand.h"
#include "../include/HandGenerator.h"
#include "Card.cpp"
#include "HandGenerator.cpp"
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

#include <iostream>
#include <sstream>
#include <vector>
#include <cctype>

void displayDeck(const Hand& deck) {
    printf("\n=== Available Cards ===\n");
    for (std::size_t i = 0; i < deck.size(); ++i) {
        printf("[%zu] %s\n", i, cardToString(deck[i]).c_str());
    }
    printf("\n");
}

void displaySelectedCards(const Hand& deck, const SelectedIndices& selected) {
    if (selected.empty()) {
        printf("(No cards selected yet)\n");
        return;
    }
    printf("Selected: ");
    for (std::size_t i = 0; i < selected.size(); ++i) {
        if (i > 0) printf(", ");
        printf("%s", cardToString(deck[selected[i]]).c_str());
    }
    printf("\n");
}

SelectedIndices chooseHand(const Hand& deck) {
    printf("\n--- Choose Hand ---\n");
    displayDeck(deck);
    
    printf("Enter card indices separated by space (e.g., 3 1 2 5 4): ");
    std::string input;
    std::getline(std::cin, input);
    
    SelectedIndices selected;
    std::istringstream iss(input);
    int idx;
    
    while (iss >> idx) {
        // Validate index range
        if (idx < 0 || idx >= 8) {
            printf("Invalid index %d! Please enter 0-7\n", idx);
            return chooseHand(deck);  // Retry
        }
        
        // Check if already selected
        bool alreadySelected = false;
        for (int sel : selected) {
            if (sel == idx) {
                alreadySelected = true;
                break;
            }
        }
        
        if (alreadySelected) {
            printf("Duplicate index %d! Please select different cards.\n", idx);
            return chooseHand(deck);  // Retry
        }
        
        selected.push_back(idx);
    }
    
    // Validate selection count
    if (selected.empty()) {
        printf("Please select at least 1 card!\n");
        return chooseHand(deck);  // Retry
    }
    
    if (selected.size() > 5) {
        printf("Maximum 5 cards! You selected %zu\n", selected.size());
        return chooseHand(deck);  // Retry
    }
    
    displaySelectedCards(deck, selected);
    return selected;
}

chosenHand convertToHand(const Hand& deck, const SelectedIndices& selected) {
    chosenHand hand{};
    for (std::size_t i = 0; i < selected.size(); ++i) {
        hand[i] = deck[selected[i]];
    }
    return hand;
}

void playHand(const chosenHand& hand, std::size_t numCards) {
    printf("\n=== Playing Hand ===\n");
    printf("Your selected hand:\n");
    for (std::size_t i = 0; i < numCards; ++i) {
        printf("%s\n", cardToString(hand[i]).c_str());
    }
    
    // TODO: Integrate dengan checker chain
    auto checkerChain = buildDefaultCheckerChain();
    // HandRank rank = checkerChain->check(hand);
    // printf("Hand Rank: %s\n", handRankToString(rank).c_str());
    
    printf("\n[Hand played!]\n");
}

void runGameSession() {
    printf("---Card Game---\n");
   
    // Generate 8 random cards
    Hand deck = generateRandomDeck();
    printf("\nRound started! 8 cards generated.\n");
    
    // Player pilih kartu
    SelectedIndices selected = chooseHand(deck);
    
    // Play hand langsung
    chosenHand hand = convertToHand(deck, selected);
    playHand(hand, selected.size());
}

int main() {
    runGameSession();
    return 0;
}
