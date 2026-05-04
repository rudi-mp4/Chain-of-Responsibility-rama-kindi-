#pragma once

#include "../IPokerHandChecker.h"

class FlushHouseChecker final : public IPokerHandChecker {
protected:
    HandRank check(const chosenHand& hand) const override;
};
