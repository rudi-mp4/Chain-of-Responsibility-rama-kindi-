#pragma once

#include <memory>

#include "checkers/FiveOfAKindChecker.h"
#include "checkers/FlushChecker.h"
#include "checkers/FlushFiveChecker.h"
#include "checkers/FlushHouseChecker.h"
#include "checkers/FourOfAKindChecker.h"
#include "checkers/FullHouseChecker.h"
#include "checkers/HighCardChecker.h"
#include "IPokerHandChecker.h"
#include "checkers/OnePairChecker.h"
#include "checkers/RoyalFlushChecker.h"
#include "checkers/StraightChecker.h"
#include "checkers/StraightFlushChecker.h"
#include "checkers/ThreeOfAKindChecker.h"
#include "checkers/TwoPairChecker.h"

std::shared_ptr<IPokerHandChecker> buildDefaultCheckerChain();
