#include "checkers/OnePairChecker.h"

#include <vector>

#include "CheckerUtils.h"

bool OnePairChecker::matches(const Hand& hand) const {
    return hasPattern(hand, {2, 1, 1, 1});
}

HandRank OnePairChecker::currentRank() const {
    return HandRank::Pair;
}


