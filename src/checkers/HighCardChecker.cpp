#include "../../include/checkers/HighCardChecker.h"

HandRank HighCardChecker::check(const Hand& hand) const {
    return HandRank::HighCard;
}

