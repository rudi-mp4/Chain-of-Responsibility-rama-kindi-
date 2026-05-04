#pragma once

#include "../IPokerHandChecker.h"

class FourOfAKindChecker final : public IPokerHandChecker {
protected:
    HandRank check(const chosenHand& hand) const override;
};
