#include "checkers/FlushChecker.h"

#include <vector>

#include "CheckerUtils.h"

bool FlushChecker::matches(const Hand& hand) const {
    return isFlush(hand) && !isStraight(hand) && !hasPattern(hand, {3, 2}) && !hasPattern(hand, {5});
}

HandRank FlushChecker::currentRank() const {
    return HandRank::Flush;
}


