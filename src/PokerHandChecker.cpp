#include "PokerHandChecker.h"

#include <memory>

std::shared_ptr<IPokerHandChecker> buildDefaultCheckerChain() {
    auto flushFive = std::make_shared<FlushFiveChecker>();
    auto fiveOfAKind = std::make_shared<FiveOfAKindChecker>();
    auto royalFlush = std::make_shared<RoyalFlushChecker>();
    auto straightFlush = std::make_shared<StraightFlushChecker>();
    auto fourOfAKind = std::make_shared<FourOfAKindChecker>();
    auto flushHouse = std::make_shared<FlushHouseChecker>();
    auto fullHouse = std::make_shared<FullHouseChecker>();
    auto flush = std::make_shared<FlushChecker>();
    auto straight = std::make_shared<StraightChecker>();
    auto threeOfAKind = std::make_shared<ThreeOfAKindChecker>();
    auto twoPair = std::make_shared<TwoPairChecker>();
    auto onePair = std::make_shared<OnePairChecker>();
    auto highCard = std::make_shared<HighCardChecker>();

    flushFive->setNext(fiveOfAKind);
    fiveOfAKind->setNext(royalFlush);
    royalFlush->setNext(straightFlush);
    straightFlush->setNext(fourOfAKind);
    fourOfAKind->setNext(flushHouse);
    flushHouse->setNext(fullHouse);
    fullHouse->setNext(flush);
    flush->setNext(straight);
    straight->setNext(threeOfAKind);
    threeOfAKind->setNext(twoPair);
    twoPair->setNext(onePair);
    onePair->setNext(highCard);

    return flushFive;
}
