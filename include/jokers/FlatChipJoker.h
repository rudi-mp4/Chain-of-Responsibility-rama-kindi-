#pragma once

#include "Joker.h"

/**
 * FlatChipJoker
 * Joker yang selalu aktif.
 * Efeknya: memberikan +20 chips ke ScoreContext.
 */
class FlatChipJoker : public Joker {
public:
    FlatChipJoker() = default;
    virtual ~FlatChipJoker() = default;
    
    std::string getName() const override;
    std::string getDescription(const ScoreContext& context) const override;
    void onScoreCalculated(ScoreContext& context) override;
};
