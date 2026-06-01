#ifndef BLIND_STATE_H
#define BLIND_STATE_H

#include "../reward command/RewardCommand.h"
#include <memory>
#include <string>

class RewardCommand;

class BlindState {
public:
    virtual ~BlindState() = default;

    // Blind information
    virtual std::string getName() const = 0;
    virtual int getTargetScore() const = 0;
    virtual int getRewardMoney() const = 0;

    // Blind progression behavior
    virtual std::unique_ptr<BlindState> getNextState() = 0;

    // Skip reward generation behavior
    virtual std::unique_ptr<RewardCommand> createSkipReward() = 0;
};

#endif
