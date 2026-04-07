#pragma once

#include "../IPokerHandChecker.h"

class FlushFiveChecker final : public IPokerHandChecker {
protected:
    HandRank check(const Hand& hand) const override;
};
