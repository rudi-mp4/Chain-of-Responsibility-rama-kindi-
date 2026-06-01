#include "../include/blind state/BigBlindState.h"
#include "../include/blind state/BossBlindState.h"
#include "../include/reward command/FreePlayingCardCommand.h"

#include <memory>

namespace {
constexpr int kMinAnte = 1;
constexpr int kBigBlindBaseTarget = 100;
constexpr int kBigBlindBaseReward = 100;
}

BigBlindState::BigBlindState(int ante)
    : ante_(ante < kMinAnte ? kMinAnte : ante) {}

std::string BigBlindState::getName() const {
    return "Big Blind";
}

int BigBlindState::getTargetScore() const {
    return kBigBlindBaseTarget * ante_;
}

int BigBlindState::getRewardMoney() const {
    return kBigBlindBaseReward * ante_;
}

std::unique_ptr<BlindState> BigBlindState::getNextState() {
    // Progress ke Boss Blind dengan ante yang sama.
    return std::make_unique<BossBlindState>(ante_);
}

std::unique_ptr<RewardCommand> BigBlindState::createSkipReward() {
    // Big Blind memberikan kartu gratis.
    return std::make_unique<FreePlayingCardCommand>();
}
