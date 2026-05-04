#include "../../include/checkers/HighCardChecker.h"

HandRank HighCardChecker::check(const chosenHand& hand) const {
    return HandRank::HighCard;
}

