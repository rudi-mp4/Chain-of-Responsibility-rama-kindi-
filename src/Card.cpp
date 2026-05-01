#include "../include/Card.h"

#include <string>

std::string suitToString(Suit suit) {
    switch (suit) {
        case Suit::Clubs:
            return "C";
        case Suit::Diamonds:
            return "D";
        case Suit::Hearts:
            return "H";
        case Suit::Spades:
            return "S";
    }
    return "?";
}

std::string rankToString(int rank) {
    switch (rank) {
        case 14:
            return "A";
        case 13:
            return "K";
        case 12:
            return "Q";
        case 11:
            return "J";
        default:
            return std::to_string(rank);
    }
}

std::string cardToString(const Card& card) {
    return rankToString(card.rank) + suitToString(card.suit);
}
