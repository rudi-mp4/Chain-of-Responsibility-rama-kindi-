#include "checkers/StraightFlushChecker.h"

#include "CheckerUtils.h"

bool StraightFlushChecker::matches(const Hand& hand) const {
    return isStraight(hand) && isFlush(hand) && !isRoyal(hand);
}

HandRank StraightFlushChecker::currentRank() const {
    return HandRank::StraightFlush;
}


