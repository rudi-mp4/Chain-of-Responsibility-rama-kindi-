#pragma once

#include "../IPokerHandChecker.h"

class OnePairChecker final : public IPokerHandChecker {
protected:
    HandRank check(const Hand& hand) const override;
};
