#include "../include/PokerHandChecker.h"

#include <memory>

IPokerHandChecker* buildDefaultCheckerChain() {
    static auto flushFive = std::make_shared<FlushFiveChecker>();
    static auto fiveOfAKind = std::make_shared<FiveOfAKindChecker>();
    static auto royalFlush = std::make_shared<RoyalFlushChecker>();
    static auto straightFlush = std::make_shared<StraightFlushChecker>();
    static auto fourOfAKind = std::make_shared<FourOfAKindChecker>();
    static auto flushHouse = std::make_shared<FlushHouseChecker>();
    static auto fullHouse = std::make_shared<FullHouseChecker>();
    static auto flush = std::make_shared<FlushChecker>();
    static auto straight = std::make_shared<StraightChecker>();
    static auto threeOfAKind = std::make_shared<ThreeOfAKindChecker>();
    static auto twoPair = std::make_shared<TwoPairChecker>();
    static auto onePair = std::make_shared<OnePairChecker>();
    static auto highCard = std::make_shared<HighCardChecker>();

    flushFive->setNext(fiveOfAKind.get());
    fiveOfAKind->setNext(royalFlush.get());
    royalFlush->setNext(straightFlush.get());
    straightFlush->setNext(fourOfAKind.get());
    fourOfAKind->setNext(flushHouse.get());
    flushHouse->setNext(fullHouse.get());
    fullHouse->setNext(flush.get());
    flush->setNext(straight.get());
    straight->setNext(threeOfAKind.get());
    threeOfAKind->setNext(twoPair.get());
    twoPair->setNext(onePair.get());
    onePair->setNext(highCard.get());

    return flushFive.get();
}
