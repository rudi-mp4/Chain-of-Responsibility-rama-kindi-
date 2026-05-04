#pragma once

#include "../IPokerHandChecker.h"

class FiveOfAKindChecker final : public IPokerHandChecker {
protected:
    HandRank check(const chosenHand& hand) const override;
};
