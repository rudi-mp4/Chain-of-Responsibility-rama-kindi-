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

std::string suitToString(Suit suit);
std::string rankToString(int rank);
std::string cardToString(const Card& card);
std::string handToString(const Hand& hand);
Hand generateRandomHand();
