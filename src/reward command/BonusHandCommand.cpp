#include "../../include/reward command/BonusHandCommand.h"
#include "../../include/reward command/GameSession.h"

BonusHandCommand::BonusHandCommand() {}

std::string BonusHandCommand::getDescription() const {
    return "Dapatkan +1 hand pada blind berikutnya";
}

RewardTiming BonusHandCommand::getTiming() const {
    return RewardTiming::NEXT_BLIND;
}

void BonusHandCommand::execute(GameSession* session) {
    if (session) {
        session->addAvailableHand();
    }
}
