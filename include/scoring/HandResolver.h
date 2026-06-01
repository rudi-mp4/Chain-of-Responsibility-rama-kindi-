#pragma once

#include <memory>
#include "PlayedHandResult.h"
#include "HandScoreTable.h"
#include "ScoringRule.h"
#include "../Hand.h"
#include "../IPokerHandChecker.h"
#include "../jokers/JokerManager.h"

/**
 * HandResolver
 * Kelas utama sistem penilaian yang menggabungkan PokerHandEvaluator dan ScoringRule.
 * 
 * Workflow:
 * 1. Menerima ChosenHand dan level saat ini
 * 2. Memanggil PokerHandChecker untuk mendapatkan handType
 * 3. Mengambil nilai base chips dan mult dari HandScoreTable
 * 4. Menghitung finalScore menggunakan ScoringRule
 * 5. Mengembalikan PlayedHandResult
 */
class HandResolver {
public:
    /**
     * Constructor
     * @param checker Pointer ke IPokerHandChecker untuk evaluasi hand
     */
    explicit HandResolver(IPokerHandChecker* checker);
    
    /**
     * Constructor dengan dependency injection untuk semua komponen
     */
    HandResolver(IPokerHandChecker* checker, 
                 std::unique_ptr<HandScoreTable> scoreTable,
                 std::unique_ptr<ScoringRule> scoringRule);
    
    /**
     * Menyelesaikan hand dan mengembalikan hasil scoring
     * @param hand Hand yang dipilih oleh pemain (5 kartu)
     * @param level Level dari hand ini
     * @return PlayedHandResult yang berisi hasil akhir scoring
     */
    PlayedHandResult resolveHand(const chosenHand& hand, int level = 1, JokerManager* jokerManager = nullptr);
    
    /**
     * Setter untuk PokerHandChecker (dalam hal perlu diganti)
     */
    void setChecker(IPokerHandChecker* checker);
    
    /**
     * Getter untuk HandScoreTable
     */
    const HandScoreTable* getScoreTable() const;
    
    /**
     * Getter untuk ScoringRule
     */
    const ScoringRule* getScoringRule() const;

private:
    // Pointer ke evaluator hand
    IPokerHandChecker* pokerHandChecker;
    
    // Tabel scoring
    std::unique_ptr<HandScoreTable> scoreTable;
    
    // Rule scoring
    std::unique_ptr<ScoringRule> scoringRule;
};
