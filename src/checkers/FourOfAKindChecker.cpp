#include "checkers/FourOfAKindChecker.h"

#include <vector>

#include "CheckerUtils.h"

bool FourOfAKindChecker::matches(const Hand& hand) const {
    return hasPattern(hand, {4, 1});
}

HandRank FourOfAKindChecker::currentRank() const {
    return HandRank::FourOfAKind;
}


