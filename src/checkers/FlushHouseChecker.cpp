#include "checkers/FlushHouseChecker.h"

#include <vector>

#include "CheckerUtils.h"

bool FlushHouseChecker::matches(const Hand& hand) const {
    return hasPattern(hand, {3, 2}) && isFlush(hand);
}

HandRank FlushHouseChecker::currentRank() const {
    return HandRank::FlushHouse;
}


