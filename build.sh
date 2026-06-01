#!/bin/bash
# Build script for Chain-of-Responsibility Poker Game

cd "$(dirname "$0")"

# Compile semua .cpp files
g++ -I include -std=c++17 -o game \
  src/main.cpp \
  src/Card.cpp \
  src/Hand.cpp \
  src/HandGenerator.cpp \
  src/HandRank.cpp \
  src/IPokerHandChecker.cpp \
  src/PokerHandChecker.cpp \
  src/blinds/BlindState.cpp \
  src/blinds/SmallBlindState.cpp \
  src/blinds/BigBlindState.cpp \
  src/blinds/BossBlindState.cpp \
  src/commands/RewardCommand.cpp \
  src/reward\ command/BonusHandCommand.cpp \
  src/reward\ command/FreePlayingCardCommand.cpp \
  src/reward\ command/GameSession.cpp \
  src/checkers/HighCardChecker.cpp \
  src/checkers/OnePairChecker.cpp \
  src/checkers/TwoPairChecker.cpp \
  src/checkers/ThreeOfAKindChecker.cpp \
  src/checkers/StraightChecker.cpp \
  src/checkers/FlushChecker.cpp \
  src/checkers/FullHouseChecker.cpp \
  src/checkers/FourOfAKindChecker.cpp \
  src/checkers/StraightFlushChecker.cpp \
  src/checkers/RoyalFlushChecker.cpp \
  src/checkers/FiveOfAKindChecker.cpp \
  src/checkers/FlushFiveChecker.cpp \
  src/checkers/FlushHouseChecker.cpp \
  2>&1

echo "Build complete. Executable: game"
