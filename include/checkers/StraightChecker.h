#pragma once

#include "../IPokerHandChecker.h"

class StraightChecker final : public IPokerHandChecker {
protected:
    HandRank check(const Hand& hand) const override;
};
