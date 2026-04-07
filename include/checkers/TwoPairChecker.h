#pragma once

#include "../IPokerHandChecker.h"

class TwoPairChecker final : public IPokerHandChecker {
protected:
    HandRank check(const Hand& hand) const override;
};
