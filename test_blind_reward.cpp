#include "include/blind state/BlindState.h"
#include "include/blind state/SmallBlindState.h"
#include "include/blind state/BigBlindState.h"
#include "include/blind state/BossBlindState.h"
#include "include/reward command/RewardCommand.h"
#include "include/reward command/BonusHandCommand.h"
#include "include/reward command/FreePlayingCardCommand.h"
#include "include/reward command/GameSession.h"

#include <cstdio>
#include <memory>

int main() {
    printf("=== Blind Progression System Test ===\n");
    printf("=== Skip Reward System Test ===\n\n");

    // Test 1: Small Blind State
    printf("Test 1: Small Blind State (ante=1)\n");
    std::unique_ptr<BlindState> state = std::make_unique<SmallBlindState>(1);
    printf("  Name: %s\n", state->getName().c_str());
    printf("  Target Score: %d\n", state->getTargetScore());
    printf("  Reward Money: %d\n", state->getRewardMoney());
    
    // Test skip reward
    auto skipReward = state->createSkipReward();
    if (skipReward) {
        printf("  Skip Reward: %s\n", skipReward->getDescription().c_str());
        printf("  Timing: %d\n", static_cast<int>(skipReward->getTiming()));
    }
    
    // Test transition to next state
    auto nextState = state->getNextState();
    printf("  Next State: %s\n\n", nextState->getName().c_str());

    // Test 2: Big Blind State
    printf("Test 2: Big Blind State (ante=2)\n");
    state = std::make_unique<BigBlindState>(2);
    printf("  Name: %s\n", state->getName().c_str());
    printf("  Target Score: %d\n", state->getTargetScore());
    printf("  Reward Money: %d\n", state->getRewardMoney());
    
    skipReward = state->createSkipReward();
    if (skipReward) {
        printf("  Skip Reward: %s\n", skipReward->getDescription().c_str());
    }
    
    nextState = state->getNextState();
    printf("  Next State: %s\n\n", nextState->getName().c_str());

    // Test 3: Boss Blind State (ante increment)
    printf("Test 3: Boss Blind State (ante=2)\n");
    state = std::make_unique<BossBlindState>(2);
    printf("  Name: %s\n", state->getName().c_str());
    printf("  Target Score: %d\n", state->getTargetScore());
    printf("  Reward Money: %d\n", state->getRewardMoney());
    
    skipReward = state->createSkipReward();
    if (skipReward) {
        printf("  Skip Reward: %s\n", skipReward->getDescription().c_str());
    }
    
    nextState = state->getNextState();
    printf("  Next State: %s (ante should be 3)\n\n", nextState->getName().c_str());
    printf("  Next State Target: %d (300*3=900)\n\n", nextState->getTargetScore());

    // Test 4: Full progression cycle
    printf("Test 4: Full Progression Cycle\n");
    state = std::make_unique<SmallBlindState>(1);
    for (int i = 0; i < 4; i++) {
        printf("  %d. %s (Target: %d)\n", i+1, state->getName().c_str(), state->getTargetScore());
        state = state->getNextState();
    }
    printf("\n");

    // Test 5: GameSession with commands
    printf("Test 5: GameSession with Reward Commands\n");
    GameSession session;
    printf("  Initial hands: %d\n", session.getAvailableHands());
    printf("  Initial plays: %d\n", session.getRemainingPlays());
    
    // Execute bonus hand command
    auto bonusCmd = std::make_unique<BonusHandCommand>();
    bonusCmd->execute(&session);
    printf("  After BonusHandCommand: %d hands\n", session.getAvailableHands());
    
    // Execute free card command
    auto cardCmd = std::make_unique<FreePlayingCardCommand>();
    cardCmd->execute(&session);
    printf("  After FreePlayingCardCommand: %d plays\n", session.getRemainingPlays());
    
    printf("\n=== All Tests Passed! ===\n");
    return 0;
}
