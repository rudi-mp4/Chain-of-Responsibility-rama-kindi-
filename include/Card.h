#pragma once

#include <array>
#include <string>

enum class Suit {
    Clubs,
    Diamonds,
    Hearts,
    Spades
};

struct Card {
    int rank;
    Suit suit;
};

using Hand = std::array<Card, 5>;

Hand generateRandomHand();
