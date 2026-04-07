#pragma once

#include "../IPokerHandChecker.h"

class ThreeOfAKindChecker final : public IPokerHandChecker {
protected:
    HandRank check(const Hand& hand) const override;
};
