#ifndef GAME_MANAGER_H
#define GAME_MANAGER_H

#include "jokers/JokerManager.h"

// GameManager adalah utility class untuk mengelola setup dan konfigurasi game
// Menggunakan static methods sebagai Facade untuk inisialisasi game components
class GameManager {
public:
    // Deleted constructor untuk mencegah instantiation
    GameManager() = delete;

    // Setup jokers default untuk game session
    // Menambahkan semua joker yang tersedia ke dalam JokerManager
    static void setupJokers(JokerManager& jokerManager);
};

#endif // GAME_MANAGER_H
