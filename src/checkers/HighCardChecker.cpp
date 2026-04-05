#include "checkers/HighCardChecker.h"

bool HighCardChecker::matches(const Hand& hand) const {
    (void)hand;
    return true;
}

HandRank HighCardChecker::currentRank() const {
    return HandRank::HighCard;
}


