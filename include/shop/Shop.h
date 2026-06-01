#ifndef SHOP_H
#define SHOP_H

#include "ShopItem.h"
#include <vector>
#include <memory>

/**
 * @class Shop
 * @brief Manager untuk inventory shop yang tersedia untuk dijual.
 * 
 * Responsible for:
 * - Menyimpan semua item yang tersedia di shop
 * - Menampilkan katalog
 * - Menjual item (remove dari inventory)
 * - Reset shop (restock items)
 */
class Shop {
public:
    // Constructor
    Shop();
    
    /**
     * Tambah item ke shop.
     * @param item - ShopItem yang akan ditambahkan
     */
    void addItem(const ShopItem& item);
    
    /**
     * Get item dari shop berdasarkan ID.
     * @param itemId - ID item yang dicari
     * @return ShopItem jika ditemukan, nullptr otherwise
     */
    ShopItem* getItemById(int itemId);
    
    /**
     * Get item berdasarkan nama.
     * @param itemName - Nama item
     * @return ShopItem jika ditemukan, nullptr otherwise
     */
    ShopItem* getItemByName(const std::string& itemName);
    
    /**
     * Hapus item dari shop (sell transaction).
     * @param itemId - ID item yang akan dijual
     * @return true jika berhasil, false jika tidak ditemukan
     */
    bool removeItemById(int itemId);
    
    /**
     * Get daftar semua item yang sedang tersedia.
     * @return Vector of ShopItems
     */
    const std::vector<ShopItem>& getAllItems() const;
    
    /**
     * Get jumlah item yang tersedia di shop.
     * @return Jumlah item
     */
    size_t getItemCount() const;
    
    /**
     * Check apakah shop memiliki item tertentu.
     * @param itemId - ID item
     * @return true jika ada, false otherwise
     */
    bool hasItem(int itemId) const;
    
    /**
     * Display semua item di shop dengan format catalog.
     */
    void displayCatalog() const;
    
    /**
     * Reset shop ke kondisi awal (restock).
     */
    void resetShop();
    
    /**
     * Initialize shop dengan default items (Pair Joker dan Flat Chip Joker).
     */
    void initializeDefaultItems();

private:
    std::vector<ShopItem> items_;
    int nextItemId_;  // Untuk auto-generate ID
};

#endif // SHOP_H
