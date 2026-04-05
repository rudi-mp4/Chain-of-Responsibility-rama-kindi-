#include "checkers/FiveOfAKindChecker.h"

#include <vector>

#include "CheckerUtils.h"

bool FiveOfAKindChecker::matches(const Hand& hand) const {
    return hasPattern(hand, {5}) && !isFlush(hand);
}

HandRank FiveOfAKindChecker::currentRank() const {
    return HandRank::FiveOfAKind;
}


