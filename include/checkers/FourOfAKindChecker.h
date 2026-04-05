#pragma once

#include "../IPokerHandChecker.h"

class FourOfAKindChecker final : public IPokerHandChecker {
protected:
    bool matches(const Hand& hand) const override;
    HandRank currentRank() const override;
};
