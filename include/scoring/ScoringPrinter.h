#pragma once

#include "PlayedHandResult.h"

/**
 * ScoringPrinter
 * Fungsi-fungsi untuk menampilkan hasil scoring
 */

/**
 * Menampilkan evaluasi hand dalam format yang rapi
 * @param result Hasil scoring dari HandResolver
 */
void printHandEvaluation(const PlayedHandResult& result);

/**
 * Menampilkan detail scoring lengkap dengan breakdown chips dan mult
 * @param result Hasil scoring dari HandResolver
 */
void printDetailedScore(const PlayedHandResult& result);
