#include "../include/PokerHandChecker.h"
#include "../include/Hand.h"
#include "../include/HandRank.h"
#include <cstdio>
#include <iostream>
#include <sstream>
#include <algorithm>

// Implementasi fungsi terkait hand (display, input, dll)
void displayDeck(const Hand& deck) {
    printf("\n=== Available Cards ===\n");
    for (std::size_t i = 0; i < deck.size(); ++i) {
        printf("[%zu] %s\n", i, cardToString(deck[i]).c_str());
    }
    printf("\n");
}

// Tampilkan kartu yang sudah dipilih
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

// urutkan kartu hand berdasarkan rank, dari tertinggi ke terkecil
void sortHandByRank(Hand& hand) {
    std::sort(hand.begin(), hand.end(), [](const Card& a, const Card& b) {
        return a.rank > b.rank; // urutkan dari tertinggi ke terkecil
    });
}

// Fungsi untuk memilih kartu dari deck
SelectedIndices chooseHand(Hand& deck) {
    printf("\n--- Choose Hand ---\n");
    sortHandByRank(deck);
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

// Convert selected indices to actual chosen hand
chosenHand convertToHand(const Hand& deck, const SelectedIndices& selected) {
    chosenHand hand{};
    for (std::size_t i = 0; i < selected.size(); ++i) {
        hand[i] = deck[selected[i]];
    }
    return hand;
}

// Placeholder untuk main game logic (evaluasi hand, dll)
void playHand(const chosenHand& hand, std::size_t numCards) {
    printf("\n=== Playing Hand ===\n");
    printf("Your selected hand:\n");
    for (std::size_t i = 0; i < numCards; ++i) {
        printf("%s\n", cardToString(hand[i]).c_str());
    }
    
    // Get the checker chain and evaluate the hand
    IPokerHandChecker* checkerChain = buildDefaultCheckerChain();
    HandRank rank = checkerChain->check(hand);
    // Display the result
    printf("\n*** Hand Rank: %s ***\n", handRankToString(rank).c_str());
    
    printf("\n[Hand played!]\n");
}
