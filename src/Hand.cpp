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
HandAction chooseHand(Hand& deck) {
    printf("\n--- Choose Hand ---\n");
    sortHandByRank(deck);
    displayDeck(deck);
    
    printf("Enter card indices separated by space, then 'p' to Play or 'd' to Discard\n");
    printf("(e.g., '1 2 3 p' or '0 4 d'): ");
    
    std::string input;
    std::getline(std::cin, input);
    
    // Clean up input to handle trailing space or mixed input
    std::istringstream iss(input);
    std::vector<std::string> tokens;
    std::string token;
    while (iss >> token) {
        tokens.push_back(token);
    }
    
    if (tokens.empty()) {
        printf("Empty input! Please try again.\n");
        return chooseHand(deck);
    }
    
    HandAction action;
    bool commandFound = false;
    std::string lastToken = tokens.back();
    
    if (lastToken == "p" || lastToken == "P") {
        action.type = HandActionType::Play;
        tokens.pop_back();
        commandFound = true;
    } else if (lastToken == "d" || lastToken == "D") {
        action.type = HandActionType::Discard;
        tokens.pop_back();
        commandFound = true;
    } else {
        // Default to Play if no command, but better to be explicit
        printf("No command found (p/d). Defaulting to Play.\n");
        action.type = HandActionType::Play;
    }
    
    for (const auto& t : tokens) {
        try {
            int idx = std::stoi(t);
            // Validate index range
            if (idx < 0 || idx >= 8) {
                printf("Invalid index %d! Please enter 0-7\n", idx);
                return chooseHand(deck);  // Retry
            }
            
            // Check if already selected
            bool alreadySelected = false;
            for (int sel : action.indices) {
                if (sel == idx) {
                    alreadySelected = true;
                    break;
                }
            }
            
            if (alreadySelected) {
                printf("Duplicate index %d! Please select different cards.\n", idx);
                return chooseHand(deck);  // Retry
            }
            
            action.indices.push_back(idx);
        } catch (...) {
            printf("Invalid token '%s'! Please use numbers for indices.\n", t.c_str());
            return chooseHand(deck);
        }
    }
    
    // Validate selection count
    if (action.indices.empty()) {
        printf("Please select at least 1 card!\n");
        return chooseHand(deck);  // Retry
    }
    
    if (action.indices.size() > 5) {
        printf("Maximum 5 cards! You selected %zu\n", action.indices.size());
        return chooseHand(deck);  // Retry
    }
    
    displaySelectedCards(deck, action.indices);
    printf("Action: %s\n", (action.type == HandActionType::Play ? "PLAY" : "DISCARD"));
    
    return action;
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
