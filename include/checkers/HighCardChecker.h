#pragma once

#include "../IPokerHandChecker.h"

class HighCardChecker final : public IPokerHandChecker {
protected:
    HandRank check(const chosenHand& hand) const override;
};
