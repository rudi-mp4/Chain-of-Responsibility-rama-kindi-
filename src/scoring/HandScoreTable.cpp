#include "../../include/scoring/HandScoreTable.h"

HandScoreTable::HandScoreTable() {
    // Inisialisasi tabel scoring berdasarkan modul praktikum
    // Format: HandRank -> {chips, mult}
    
    scoreTable[HandRank::HighCard] = {5, 1};
    scoreTable[HandRank::Pair] = {10, 1};
    scoreTable[HandRank::TwoPair] = {20, 1};
    scoreTable[HandRank::ThreeOfAKind] = {30, 2};
    scoreTable[HandRank::Straight] = {30, 2};
    scoreTable[HandRank::Flush] = {35, 2};
    scoreTable[HandRank::FullHouse] = {40, 2};
    scoreTable[HandRank::FourOfAKind] = {60, 3};
    scoreTable[HandRank::StraightFlush] = {100, 4};
    scoreTable[HandRank::RoyalFlush] = {150, 5};
    scoreTable[HandRank::FiveOfAKind] = {100, 4};
    scoreTable[HandRank::FlushFive] = {120, 4};
    scoreTable[HandRank::FlushHouse] = {90, 3};
    scoreTable[HandRank::Unknown] = {0, 1};
}

int HandScoreTable::getBaseChips(HandRank rank) const {
    auto it = scoreTable.find(rank);
    if (it != scoreTable.end()) {
        return it->second.chips;
    }
    return 0;
}

int HandScoreTable::getBaseMult(HandRank rank) const {
    auto it = scoreTable.find(rank);
    if (it != scoreTable.end()) {
        return it->second.mult;
    }
    return 1;
}

HandScoreTable::ScoreEntry HandScoreTable::getEntry(HandRank rank) const {
    auto it = scoreTable.find(rank);
    if (it != scoreTable.end()) {
        return it->second;
    }
    return {0, 1};
}
