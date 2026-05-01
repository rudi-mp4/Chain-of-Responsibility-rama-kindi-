#pragma once

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

std::string suitToString(Suit suit);
std::string rankToString(int rank);
std::string cardToString(const Card& card);
