#pragma once

#include <string>
#include "ScoreContext.h"

/**
 * Joker
 * Base Abstract Class untuk semua Joker.
 * Setiap Joker baru wajib mewarisi kelas ini.
 */
class Joker {
public:
    virtual ~Joker() = default;
    
    /**
     * Mendapatkan nama Joker
     */
    virtual std::string getName() const = 0;
    
    /**
     * Mendapatkan deskripsi Joker dengan konteks saat ini
     */
    virtual std::string getDescription(const ScoreContext& context) const = 0;
    
    /**
     * Callback yang dipanggil saat scoring dihitung.
     * Joker dapat memodifikasi context.chips dan context.multiplier di sini.
     */
    virtual void onScoreCalculated(ScoreContext& context) = 0;
};
