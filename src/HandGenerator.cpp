#include "../include/HandGenerator.h"

#include <algorithm>
#include <random>
#include <vector>

Deck generateRandomDeck() {
    std::vector<Card> fullDeck;
    fullDeck.reserve(52);

    // Buat full deck (52 kartu)
    for (int suit = 0; suit < 4; ++suit) {
        for (int rank = 2; rank <= 14; ++rank) {
            fullDeck.push_back(Card{rank, static_cast<Suit>(suit)});
        }
    }

    // Shuffle
    static thread_local std::mt19937 rng(std::random_device{}());
    std::shuffle(fullDeck.begin(), fullDeck.end(), rng);

    // Ambil 8 kartu pertama
    Deck deck{};
    for (std::size_t i = 0; i < deck.size(); ++i) {
        deck[i] = fullDeck[i];
    }

    return deck;
}
