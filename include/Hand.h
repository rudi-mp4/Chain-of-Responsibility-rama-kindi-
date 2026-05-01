#pragma once

#include <array>
#include <vector>
#include "Card.h"

// 8 kartu yang di-generate random
using Hand = std::array<Card, 8>;

// 5 kartu yang dipilih player
using chosenHand = std::array<Card, 5>;

// Helper untuk track pilihan kartu (index dari deck)
using SelectedIndices = std::vector<int>;
