#include "Card.h"
#include "CheckerUtils.h"
#include "HandRank.h"
#include "PokerHandChecker.h"

#include <algorithm>
#include <functional>
#include <iostream>
#include <map>
#include <memory>
#include <string>
#include <vector>

std::map<int, int> rankCounts(const Hand& hand) {
    std::map<int, int> counts;
    for (const Card& card : hand) {
        ++counts[card.rank];
    }
    return counts;
}

std::vector<int> countPattern(const Hand& hand) {
    std::vector<int> pattern;
    for (const auto& entry : rankCounts(hand)) {
        pattern.push_back(entry.second);
    }

    std::sort(pattern.begin(), pattern.end(), std::greater<int>());
    return pattern;
}

bool hasPattern(const Hand& hand, const std::vector<int>& expected) {
    return countPattern(hand) == expected;
}

bool isFlush(const Hand& hand) {
    const Suit firstSuit = hand[0].suit;
    for (const Card& card : hand) {
        if (card.suit != firstSuit) {
            return false;
        }
    }
    return true;
}

bool isStraight(const Hand& hand) {
    std::vector<int> ranks;
    ranks.reserve(hand.size());

    for (const Card& card : hand) {
        ranks.push_back(card.rank);
    }

    std::sort(ranks.begin(), ranks.end());

    auto uniqueEnd = std::unique(ranks.begin(), ranks.end());
    if (uniqueEnd != ranks.end()) {
        return false;
    }

    bool consecutive = true;
    for (std::size_t i = 1; i < ranks.size(); ++i) {
        if (ranks[i] != ranks[i - 1] + 1) {
            consecutive = false;
            break;
        }
    }
    if (consecutive) {
        return true;
    }

    const std::vector<int> wheel = {2, 3, 4, 5, 14};
    return ranks == wheel;
}

bool isRoyal(const Hand& hand) {
    std::vector<int> ranks;
    ranks.reserve(hand.size());

    for (const Card& card : hand) {
        ranks.push_back(card.rank);
    }

    std::sort(ranks.begin(), ranks.end());
    const std::vector<int> royal = {10, 11, 12, 13, 14};
    return ranks == royal;
}

namespace {

void runSession() {
    const std::shared_ptr<IPokerHandChecker> checkerChain = buildDefaultCheckerChain();
    std::cout << "=== Testing ===\n";
    std::cout << "Generating hand...\n";

    const Hand hand = generateRandomHand();

    std::cout << "Playing hand...\n";
    std::cout << "Scoring...\n";
    std::cout << "Checking Hand...\n";

    const HandRank detected = checkerChain->evaluate(hand);

    std::cout << "Detected (" << handRankToString(detected) << ")...\n";
    std::cout << "Selesai\n";
    std::cout << "=== End ===\n";
}

}  // namespace

int main() {
    runSession();
    return 0;
}
