#pragma once

#include "Joker.h"

/**
 * PairJoker
 * Joker yang hanya aktif jika handType adalah Pair.
 * Efeknya: memberikan +4 multiplier ke ScoreContext.
 */
class PairJoker : public Joker {
public:
    PairJoker() = default;
    virtual ~PairJoker() = default;
    
    std::string getName() const override;
    std::string getDescription(const ScoreContext& context) const override;
    void onScoreCalculated(ScoreContext& context) override;
};
