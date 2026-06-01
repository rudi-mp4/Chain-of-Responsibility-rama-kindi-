#include "../include/GameManager.h"
#include "../include/jokers/PairJoker.h"
#include "../include/jokers/FlatChipJoker.h"

void GameManager::setupJokers(JokerManager& jokerManager) {
    // Tambahkan default jokers yang tersedia untuk game
    jokerManager.addJoker(std::make_unique<PairJoker>());
    jokerManager.addJoker(std::make_unique<FlatChipJoker>());
}
