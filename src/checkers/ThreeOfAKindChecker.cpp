#include "checkers/ThreeOfAKindChecker.h"

#include <vector>

#include "CheckerUtils.h"

bool ThreeOfAKindChecker::matches(const Hand& hand) const {
    return hasPattern(hand, {3, 1, 1});
}

HandRank ThreeOfAKindChecker::currentRank() const {
    return HandRank::ThreeOfAKind;
}


