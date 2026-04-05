#include "checkers/FlushFiveChecker.h"

#include <vector>

#include "CheckerUtils.h"

bool FlushFiveChecker::matches(const Hand& hand) const {
    return hasPattern(hand, {5}) && isFlush(hand);
}

HandRank FlushFiveChecker::currentRank() const {
    return HandRank::FlushFive;
}


