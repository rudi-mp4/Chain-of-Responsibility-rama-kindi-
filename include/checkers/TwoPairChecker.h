#pragma once

#include "../IPokerHandChecker.h"

class TwoPairChecker final : public IPokerHandChecker {
protected:
    bool matches(const Hand& hand) const override;
    HandRank currentRank() const override;
};
