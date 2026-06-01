#ifndef BONUS_HAND_COMMAND_H
#define BONUS_HAND_COMMAND_H

#include "RewardCommand.h"

// BonusHandCommand memberikan +1 hand pada blind berikutnya.
class BonusHandCommand final : public RewardCommand {
public:
    BonusHandCommand();

    std::string getDescription() const override;
    RewardTiming getTiming() const override;
    void execute(GameSession* session) override;

private:
    static constexpr int kHandBonus = 1;
};

#endif // BONUS_HAND_COMMAND_H
