#pragma once

#include "../IPokerHandChecker.h"

class FlushChecker final : public IPokerHandChecker {
protected:
    HandRank check(const Hand& hand) const override;
};
