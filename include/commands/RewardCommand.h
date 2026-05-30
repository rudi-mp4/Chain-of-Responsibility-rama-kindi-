#ifndef REWARD_COMMAND_H
#define REWARD_COMMAND_H

#include <string>
#include <memory>

class GameSession; // Forward declaration

enum class RewardTiming {
    START,
    NEXT_BLIND,
    NEXT_ANTE
};

class RewardCommand {
public:
    virtual ~RewardCommand() = default;

    // Get command description
    virtual std::string getDescription() const = 0;

    // Get timing for when reward should execute
    virtual RewardTiming getTiming() const = 0;

    // Execute the reward command on game session
    virtual void execute(GameSession* session) = 0;
};

#endif // REWARD_COMMAND_H
