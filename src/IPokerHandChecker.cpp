#include "../include/IPokerHandChecker.h"

#include <utility>

void IPokerHandChecker::setNext(IPokerHandChecker* nextChecker) {
    this->nextChecker = nextChecker;
}