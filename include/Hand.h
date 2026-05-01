#pragma once

#include <array>
#include <cstddef>
#include <vector>
#include "Card.h"

// 8 kartu yang di-generate random
using Hand = std::array<Card, 8>;

// 5 kartu yang dipilih player
using chosenHand = std::array<Card, 5>;

// Helper untuk track pilihan kartu (index dari deck)
using SelectedIndices = std::vector<int>;

void displayDeck(const Hand& deck);
void displaySelectedCards(const Hand& deck, const SelectedIndices& selected);
SelectedIndices chooseHand(const Hand& deck);
chosenHand convertToHand(const Hand& deck, const SelectedIndices& selected);
void playHand(const chosenHand& hand, std::size_t numCards);
