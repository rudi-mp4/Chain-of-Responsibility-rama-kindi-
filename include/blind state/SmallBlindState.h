#ifndef SMALL_BLIND_STATE_H
#define SMALL_BLIND_STATE_H

#include "BlindState.h"

// SmallBlindState adalah state awal dalam siklus blind.
class SmallBlindState final : public BlindState {
public:
    explicit SmallBlindState(int ante = 1);

    std::string getName() const override;
    int getTargetScore() const override;
    int getRewardMoney() const override;

    std::unique_ptr<BlindState> getNextState() override;
    std::unique_ptr<RewardCommand> createSkipReward() override;

private:
    int ante_;
};

#endif
