#pragma once

#include "../IPokerHandChecker.h"

class StraightFlushChecker final : public IPokerHandChecker {
protected:
    HandRank check(const chosenHand& hand) const override;
};
