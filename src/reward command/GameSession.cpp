#include "../../include/reward command/GameSession.h"

GameSession::GameSession()
    : currentAnte_(1),
      totalScore_(0),
      remainingPlays_(5),
      remainingDiscards_(1),
      availableHands_(0) {}

int GameSession::getCurrentAnte() const {
    return currentAnte_;
}

void GameSession::setCurrentAnte(int ante) {
    currentAnte_ = (ante >= 1) ? ante : 1;
}

int GameSession::getTotalScore() const {
    return totalScore_;
}

void GameSession::addScore(int amount) {
    totalScore_ += amount;
}

void GameSession::resetScore() {
    totalScore_ = 0;
}

int GameSession::getRemainingPlays() const {
    return remainingPlays_;
}

void GameSession::addPlay() {
    remainingPlays_++;
}

void GameSession::spendPlay() {
    if (remainingPlays_ > 0) {
        remainingPlays_--;
    }
}

void GameSession::resetPlays() {
    remainingPlays_ = 5;
}

int GameSession::getRemainingDiscards() const {
    return remainingDiscards_;
}

void GameSession::addDiscard() {
    remainingDiscards_++;
}

void GameSession::spendDiscard() {
    if (remainingDiscards_ > 0) {
        remainingDiscards_--;
    }
}

void GameSession::resetDiscards() {
    remainingDiscards_ = 1;
}

int GameSession::getAvailableHands() const {
    return availableHands_;
}

void GameSession::addAvailableHand() {
    availableHands_++;
}

void GameSession::spendAvailableHand() {
    if (availableHands_ > 0) {
        availableHands_--;
    }
}

void GameSession::resetAvailableHands() {
    availableHands_ = 0;
}

void GameSession::addCardToDeck(const Card& card) {
    deck_.push_back(card);
}

const std::vector<Card>& GameSession::getDeck() const {
    return deck_;
}

void GameSession::clearDeck() {
    deck_.clear();
}

void GameSession::enqueuePendingCommand(std::unique_ptr<RewardCommand> command) {
    if (command) {
        pendingCommands_.push_back(std::move(command));
    }
}

size_t GameSession::getPendingCommandCount() const {
    return pendingCommands_.size();
}

RewardCommand* GameSession::getPendingCommandAt(size_t index) const {
    if (index < pendingCommands_.size()) {
        return pendingCommands_[index].get();
    }
    return nullptr;
}

void GameSession::clearPendingCommands() {
    pendingCommands_.clear();
}

void GameSession::executePendingCommandsWithTiming(RewardTiming timing) {
    for (auto& cmd : pendingCommands_) {
        if (cmd && cmd->getTiming() == timing) {
            cmd->execute(this);
        }
    }
}
