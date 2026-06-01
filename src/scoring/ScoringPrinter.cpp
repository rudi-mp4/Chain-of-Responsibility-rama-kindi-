#include "../../include/scoring/ScoringPrinter.h"
#include <cstdio>

void printHandEvaluation(const PlayedHandResult& result) {
    printf("\n=== Hand Evaluation ===\n");
    printf("Hand Type: %s\n", handRankToString(result.handType).c_str());
    printf("Base Score: %d x %d = %d\n", result.chips, result.mult, result.finalScore);
}

void printDetailedScore(const PlayedHandResult& result) {
    printf("\n=== Hand Evaluation ===\n");
    printf("Hand Type: %s\n", handRankToString(result.handType).c_str());
    printf("Level: %d\n", result.level);
    printf("Chips: %d\n", result.chips);
    printf("Multiplier: %d\n", result.mult);
    printf("Final Score: %d\n", result.finalScore);
}
