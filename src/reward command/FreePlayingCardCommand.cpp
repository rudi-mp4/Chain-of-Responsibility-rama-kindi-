#include "../../include/reward command/FreePlayingCardCommand.h"
#include "../../include/reward command/GameSession.h"

FreePlayingCardCommand::FreePlayingCardCommand() {}

std::string FreePlayingCardCommand::getDescription() const {
    return "Dapatkan 1 kartu gratis pada hand berikutnya";
}

RewardTiming FreePlayingCardCommand::getTiming() const {
    return RewardTiming::NEXT_BLIND;
}

void FreePlayingCardCommand::execute(GameSession* session) {
    if (session) {
        session->addPlay();
    }
}
