#include "checkers/StraightChecker.h"

#include "CheckerUtils.h"

bool StraightChecker::matches(const Hand& hand) const {
    return isStraight(hand) && !isFlush(hand);
}

HandRank StraightChecker::currentRank() const {
    return HandRank::Straight;
}


