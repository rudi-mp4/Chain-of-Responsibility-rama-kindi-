#include "../../include/scoring/HandScoreTable.h"

HandScoreTable::HandScoreTable() {
    // Inisialisasi tabel scoring dengan data default sesuai spesifikasi
    scoreTable[HandRank::FlushFive]      = {160, 16};
    scoreTable[HandRank::FlushHouse]     = {140, 14};
    scoreTable[HandRank::FiveOfAKind]    = {120, 12};
    scoreTable[HandRank::RoyalFlush]     = {100,  8};
    scoreTable[HandRank::StraightFlush]  = {100,  8};
    scoreTable[HandRank::FourOfAKind]    = { 60,  7};
    scoreTable[HandRank::FullHouse]      = { 40,  4};
    scoreTable[HandRank::Flush]          = { 35,  4};
    scoreTable[HandRank::Straight]       = { 30,  4};
    scoreTable[HandRank::ThreeOfAKind]   = { 30,  3};
    scoreTable[HandRank::TwoPair]        = { 20,  2};
    scoreTable[HandRank::Pair]           = { 10,  2};
    scoreTable[HandRank::HighCard]       = {  5,  1};
    scoreTable[HandRank::Unknown]        = {  0,  0};
}

int HandScoreTable::getBaseChips(HandRank rank) const {
    auto it = scoreTable.find(rank);
    if (it != scoreTable.end()) {
        return it->second.chips;
    }
    return 0;  // Default jika tidak ditemukan
}

int HandScoreTable::getBaseMult(HandRank rank) const {
    auto it = scoreTable.find(rank);
    if (it != scoreTable.end()) {
        return it->second.mult;
    }
    return 0;  // Default jika tidak ditemukan
}

HandScoreTable::ScoreEntry HandScoreTable::getEntry(HandRank rank) const {
    auto it = scoreTable.find(rank);
    if (it != scoreTable.end()) {
        return it->second;
    }
    return {0, 0};  // Default entry jika tidak ditemukan
}
