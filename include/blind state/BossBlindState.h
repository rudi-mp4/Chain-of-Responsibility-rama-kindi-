#ifndef BOSS_BLIND_STATE_H
#define BOSS_BLIND_STATE_H

#include "BlindState.h"

// BossBlindState adalah state puncak sebelum ante naik.
class BossBlindState final : public BlindState {
public:
    explicit BossBlindState(int ante = 1);

    std::string getName() const override;
    int getTargetScore() const override;
    int getRewardMoney() const override;

    std::unique_ptr<BlindState> getNextState() override;
    std::unique_ptr<RewardCommand> createSkipReward() override;

private:
    int ante_;
};

#endif
