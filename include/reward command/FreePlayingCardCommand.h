#ifndef FREE_PLAYING_CARD_COMMAND_H
#define FREE_PLAYING_CARD_COMMAND_H

#include "RewardCommand.h"

// FreePlayingCardCommand memberikan 1 kartu gratis pada hand berikutnya.
class FreePlayingCardCommand final : public RewardCommand {
public:
    FreePlayingCardCommand();

    std::string getDescription() const override;
    RewardTiming getTiming() const override;
    void execute(GameSession* session) override;

private:
    static constexpr int kCardBonus = 1;
};

#endif // FREE_PLAYING_CARD_COMMAND_H
