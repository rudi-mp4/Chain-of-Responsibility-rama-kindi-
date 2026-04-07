#include "../../include/checkers/HighCardChecker.h"

HandRank HighCardChecker::check(const Hand& hand) const {
    printf("Ini tangan High Card");
    return HandRank::HighCard;
}

