#include "IPokerHandChecker.h"

#include <utility>

void IPokerHandChecker::setNext(std::shared_ptr<IPokerHandChecker> nextChecker) {
    nextChecker_ = std::move(nextChecker);
}

HandRank IPokerHandChecker::evaluate(const Hand& hand) const {
    if (matches(hand)) {
        return currentRank();
    }

    if (nextChecker_) {
        return nextChecker_->evaluate(hand);
    }

    return HandRank::Unknown;
}
