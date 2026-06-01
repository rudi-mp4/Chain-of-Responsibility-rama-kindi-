#ifndef BIG_BLIND_STATE_H
#define BIG_BLIND_STATE_H

#include "BlindState.h"

// BigBlindState adalah state kedua setelah Small Blind.
class BigBlindState final : public BlindState {
public:
    explicit BigBlindState(int ante = 1);

    std::string getName() const override;
    int getTargetScore() const override;
    int getRewardMoney() const override;

    std::unique_ptr<BlindState> getNextState() override;
    std::unique_ptr<RewardCommand> createSkipReward() override;

private:
    int ante_;
};

#endif
