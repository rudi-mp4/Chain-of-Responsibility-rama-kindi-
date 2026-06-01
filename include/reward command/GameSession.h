#ifndef GAME_SESSION_H
#define GAME_SESSION_H

#include <vector>
#include <memory>
#include "../Card.h"
#include "RewardCommand.h"

// GameSession adalah runtime state yang menampung current blind state, 
// score, hands, dan pending reward commands.
class GameSession {
public:
    GameSession();
    virtual ~GameSession() = default;

    // Blind & Ante management
    int getCurrentAnte() const;
    void setCurrentAnte(int ante);

    // Score management
    int getTotalScore() const;
    void addScore(int amount);
    void resetScore();

    // Plays management
    int getRemainingPlays() const;
    void addPlay();
    void spendPlay();
    void resetPlays();

    // Discards management
    int getRemainingDiscards() const;
    void addDiscard();
    void spendDiscard();
    void resetDiscards();

    // Hand management
    int getAvailableHands() const;
    void addAvailableHand();
    void spendAvailableHand();
    void resetAvailableHands();

    // Card management (deck)
    void addCardToDeck(const Card& card);
    const std::vector<Card>& getDeck() const;
    void clearDeck();

    // Reward command management
    void enqueuePendingCommand(std::unique_ptr<RewardCommand> command);
    size_t getPendingCommandCount() const;
    RewardCommand* getPendingCommandAt(size_t index) const;
    void clearPendingCommands();
    void executePendingCommandsWithTiming(RewardTiming timing);

private:
    int currentAnte_;
    int totalScore_;
    int remainingPlays_;
    int remainingDiscards_;
    int availableHands_;
    std::vector<Card> deck_;
    std::vector<std::unique_ptr<RewardCommand>> pendingCommands_;
};

#endif // GAME_SESSION_H
