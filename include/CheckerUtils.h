#pragma once

#include <map>
#include <vector>

#include "Card.h"

std::map<int, int> rankCounts(const Hand& hand);
std::vector<int> countPattern(const Hand& hand);
bool hasPattern(const Hand& hand, const std::vector<int>& expected);
bool isFlush(const Hand& hand);
bool isStraight(const Hand& hand);
bool isRoyal(const Hand& hand);
