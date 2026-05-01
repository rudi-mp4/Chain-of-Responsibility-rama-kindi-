#pragma once

#include <memory>

#include "Card.h"
#include "Hand.h"
#include "HandRank.h"

class IPokerHandChecker {
public:
    virtual ~IPokerHandChecker() = default;
    void setNext(IPokerHandChecker* nextChecker);
    virtual HandRank check(const Hand& hand) const = 0;

protected:
    IPokerHandChecker* nextChecker = nullptr;
};
