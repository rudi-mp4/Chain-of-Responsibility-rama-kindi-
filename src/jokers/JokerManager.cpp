#include "../../include/jokers/JokerManager.h"

void JokerManager::addJoker(std::unique_ptr<Joker> joker) {
    if (joker) {
        jokers.push_back(std::move(joker));
    }
}

void JokerManager::executeJokerPipeline(ScoreContext& context) {
    // Jalankan callback onScoreCalculated untuk setiap joker
    for (auto& joker : jokers) {
        if (joker) {
            joker->onScoreCalculated(context);
        }
    }
}

size_t JokerManager::getJokerCount() const {
    return jokers.size();
}

Joker* JokerManager::getJokerAt(size_t index) const {
    if (index < jokers.size()) {
        return jokers[index].get();
    }
    return nullptr;
}

void JokerManager::clearJokers() {
    jokers.clear();
}
