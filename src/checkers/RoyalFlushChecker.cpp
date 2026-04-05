#include "checkers/RoyalFlushChecker.h"

#include "CheckerUtils.h"

bool RoyalFlushChecker::matches(const Hand& hand) const {
    return isStraight(hand) && isFlush(hand) && isRoyal(hand);
}

HandRank RoyalFlushChecker::currentRank() const {
    return HandRank::RoyalFlush;
}


