#include "checkers/FullHouseChecker.h"

#include <vector>

#include "CheckerUtils.h"

bool FullHouseChecker::matches(const Hand& hand) const {
    return hasPattern(hand, {3, 2}) && !isFlush(hand);
}

HandRank FullHouseChecker::currentRank() const {
    return HandRank::FullHouse;
}


