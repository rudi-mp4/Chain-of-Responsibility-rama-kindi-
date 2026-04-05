#include "checkers/TwoPairChecker.h"

#include <vector>

#include "CheckerUtils.h"

bool TwoPairChecker::matches(const Hand& hand) const {
    return hasPattern(hand, {2, 2, 1});
}

HandRank TwoPairChecker::currentRank() const {
    return HandRank::TwoPair;
}


