#include "Card.h"

#include <algorithm>
#include <random>
#include <sstream>
#include <vector>

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

std::string handToString(const Hand& hand) {
    std::ostringstream stream;
    for (std::size_t i = 0; i < hand.size(); ++i) {
        if (i > 0) {
            stream << " ";
        }
        stream << cardToString(hand[i]);
    }
    return stream.str();
}

Hand generateRandomHand() {
    std::vector<Card> deck;
    deck.reserve(52);

    for (int suit = 0; suit < 4; ++suit) {
        for (int rank = 2; rank <= 14; ++rank) {
            deck.push_back(Card{rank, static_cast<Suit>(suit)});
        }
    }

    static thread_local std::mt19937 rng(std::random_device{}());
    std::shuffle(deck.begin(), deck.end(), rng);

    Hand hand{};
    for (std::size_t i = 0; i < hand.size(); ++i) {
        hand[i] = deck[i];
    }

    return hand;
}
