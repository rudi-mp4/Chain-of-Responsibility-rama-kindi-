#pragma once

#include "../IPokerHandChecker.h"

class FullHouseChecker final : public IPokerHandChecker {
protected:
    HandRank check(const chosenHand& hand) const override;
};
