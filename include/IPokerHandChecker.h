#pragma once

#include <memory>

#include "Card.h"
#include "HandRank.h"

class IPokerHandChecker {
public:
    virtual ~IPokerHandChecker() = default;

    void setNext(std::shared_ptr<IPokerHandChecker> nextChecker);
    HandRank evaluate(const Hand& hand) const;

protected:
    virtual bool matches(const Hand& hand) const = 0;
    virtual HandRank currentRank() const = 0;

private:
    std::shared_ptr<IPokerHandChecker> nextChecker_;
};
