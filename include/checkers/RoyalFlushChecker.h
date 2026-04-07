#pragma once

#include "../IPokerHandChecker.h"

class RoyalFlushChecker final : public IPokerHandChecker {
protected:
    HandRank check(const Hand& hand) const override;
};
