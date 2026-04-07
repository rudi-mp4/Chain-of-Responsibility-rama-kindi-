#include "../../include/checkers/RoyalFlushChecker.h"

HandRank RoyalFlushChecker::check(const Hand& hand) const {
    printf("Ini tangan Royal Flush");
    return HandRank::RoyalFlush;
}


