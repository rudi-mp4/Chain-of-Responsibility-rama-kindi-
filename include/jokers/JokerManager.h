#pragma once

#include <vector>
#include <memory>
#include "Joker.h"
#include "ScoreContext.h"

/**
 * JokerManager
 * Bertanggung jawab untuk mengelola siklus hidup dan eksekusi Joker.
 */
class JokerManager {
private:
    // Daftar Joker yang aktif
    std::vector<std::unique_ptr<Joker>> jokers;
    
public:
    JokerManager() = default;
    virtual ~JokerManager() = default;
    
    /**
     * Menambahkan Joker baru ke dalam manager.
     */
    void addJoker(std::unique_ptr<Joker> joker);
    
    /**
     * Menjalankan Joker Flow Pipeline.
     * Menerima ScoreContext, melakukan loop untuk menotifikasi setiap Joker,
     * dan membiarkan Joker memodifikasi chips/multiplier dalam context.
     */
    void executeJokerPipeline(ScoreContext& context);
    
    /**
     * Mendapatkan jumlah Joker yang terdaftar
     */
    size_t getJokerCount() const;
    
    /**
     * Mendapatkan Joker pada index tertentu
     */
    Joker* getJokerAt(size_t index) const;
    
    /**
     * Menghapus semua Joker
     */
    void clearJokers();
};
