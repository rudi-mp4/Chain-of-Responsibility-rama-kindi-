#include "../include/blind state/SmallBlindState.h"
#include "../include/blind state/BigBlindState.h"
#include "../include/reward command/BonusHandCommand.h"

#include <memory>

namespace {
constexpr int kMinAnte = 1;
constexpr int kSmallBlindBaseTarget = 60;
constexpr int kSmallBlindBaseReward = 50;
}

SmallBlindState::SmallBlindState(int ante)
    : ante_(ante < kMinAnte ? kMinAnte : ante) {}

std::string SmallBlindState::getName() const {
    return "Small Blind";
}

int SmallBlindState::getTargetScore() const {
    // Target meningkat seiring ante.
    return kSmallBlindBaseTarget * ante_;
}

int SmallBlindState::getRewardMoney() const {
    // Reward meningkat seiring ante.
    return kSmallBlindBaseReward * ante_;
}

std::unique_ptr<BlindState> SmallBlindState::getNextState() {
    // Progress ke Big Blind dengan ante yang sama.
    return std::make_unique<BigBlindState>(ante_);
}

std::unique_ptr<RewardCommand> SmallBlindState::createSkipReward() {
    // Small Blind memberikan bonus hand.
    return std::make_unique<BonusHandCommand>();
}
