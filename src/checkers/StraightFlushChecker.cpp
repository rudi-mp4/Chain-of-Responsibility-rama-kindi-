#include "../../include/checkers/StraightFlushChecker.h"

HandRank StraightFlushChecker::check(const Hand& hand) const {
    printf("Ini tangan Straight Flush");
    return HandRank::StraightFlush;
}

