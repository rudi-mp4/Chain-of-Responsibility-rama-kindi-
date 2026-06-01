#ifndef SHOPINVENTORY_H
#define SHOPINVENTORY_H

#include "ShopItem.h"
#include <vector>

/**
 * @class ShopInventory
 * @brief Inventory pemain - menyimpan item yang sudah dibeli dari shop.
 * 
 * Responsible for:
 * - Menyimpan item yang dimiliki pemain
 * - Track chip/money yang dimiliki pemain
 * - Buy item dari shop
 * - Remove item dari inventory
 * - Display inventory
 */
class ShopInventory {
public:
    // Constructor
    ShopInventory(int initialChips = 0);
    
    /**
     * Tambah chips ke inventory.
     * @param amount - Jumlah chips yang ditambahkan
     */
    void addChips(int amount);
    
    /**
     * Kurangi chips dari inventory.
     * @param amount - Jumlah chips yang dikurangi
     * @return true jika berhasil, false jika chips tidak cukup
     */
    bool spendChips(int amount);
    
    /**
     * Get jumlah chips saat ini.
     * @return Jumlah chips
     */
    int getChips() const;
    
    /**
     * Tambah item ke inventory.
     * @param item - ShopItem yang ditambahkan
     */
    void addItem(const ShopItem& item);
    
    /**
     * Hapus item dari inventory berdasarkan ID.
     * @param itemId - ID item
     * @return true jika berhasil, false jika tidak ditemukan
     */
    bool removeItemById(int itemId);
    
    /**
     * Get item dari inventory berdasarkan ID.
     * @param itemId - ID item
     * @return ShopItem jika ditemukan, nullptr otherwise
     */
    ShopItem* getItemById(int itemId);
    
    /**
     * Get daftar semua item yang dimiliki.
     * @return Vector of ShopItems
     */
    const std::vector<ShopItem>& getAllItems() const;
    
    /**
     * Get jumlah item yang dimiliki.
     * @return Jumlah item
     */
    size_t getItemCount() const;
    
    /**
     * Get jumlah joker yang dimiliki.
     * @return Jumlah jokers
     */
    size_t getJokerCount() const;
    
    /**
     * Check apakah sudah memiliki item tertentu.
     * @param itemId - ID item
     * @return true jika ada, false otherwise
     */
    bool hasItem(int itemId) const;
    
    /**
     * Attempt buy item - kurangi chips dan tambah item.
     * @param item - ShopItem yang akan dibeli
     * @return true jika berhasil, false jika chips tidak cukup
     */
    bool buyItem(const ShopItem& item);
    
    /**
     * Display inventory.
     */
    void displayInventory() const;
    
    /**
     * Clear semua item dari inventory.
     */
    void clearItems();
    
    /**
     * Reset inventory (chips dan items).
     * @param initialChips - Chips awal
     */
    void reset(int initialChips = 0);

private:
    int chips_;
    std::vector<ShopItem> items_;
};

#endif // SHOPINVENTORY_H
