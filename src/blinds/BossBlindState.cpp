#include "../include/blind state/BossBlindState.h"
#include "../include/blind state/SmallBlindState.h"
#include "../include/reward command/BonusHandCommand.h"

#include <memory>

namespace {
constexpr int kMinAnte = 1;
constexpr int kBossBlindBaseTarget = 180;
constexpr int kBossBlindBaseReward = 200;
}

BossBlindState::BossBlindState(int ante)
    : ante_(ante < kMinAnte ? kMinAnte : ante) {}

std::string BossBlindState::getName() const {
    return "Boss Blind";
}

int BossBlindState::getTargetScore() const {
    return kBossBlindBaseTarget * ante_;
}

int BossBlindState::getRewardMoney() const {
    return kBossBlindBaseReward * ante_;
}

std::unique_ptr<BlindState> BossBlindState::getNextState() {
    // Boss Blind menaikkan ante lalu mengulang ke Small Blind.
    const int nextAnte = ante_ + 1;
    return std::make_unique<SmallBlindState>(nextAnte);
}

std::unique_ptr<RewardCommand> BossBlindState::createSkipReward() {
    // Boss Blind memberikan bonus hand (reward paling valuable).
    return std::make_unique<BonusHandCommand>();
}
