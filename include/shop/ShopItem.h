#ifndef SHOPITEM_H
#define SHOPITEM_H

#include <string>
#include <memory>

/**
 * @enum ItemType
 * @brief Tipe item yang bisa dijual di shop.
 */
enum class ItemType {
    JOKER,        // Joker item
    CARD,         // Card item
    UPGRADE,      // Upgrade/boost
    CONSUMABLE    // One-time use item
};

/**
 * @class ShopItem
 * @brief Representasi item yang dijual di shop.
 * 
 * Setiap item memiliki:
 * - Unique ID
 * - Tipe (JOKER, CARD, etc)
 * - Nama
 * - Harga (dalam chips)
 * - Deskripsi
 * - Metadata (joker name, card rank, etc)
 */
class ShopItem {
public:
    // Constructor
    ShopItem(
        int id,
        ItemType type,
        const std::string& name,
        int price,
        const std::string& description,
        const std::string& metadata = ""
    );
    
    // Getters
    int getId() const;
    ItemType getType() const;
    std::string getTypeName() const;
    const std::string& getName() const;
    int getPrice() const;
    const std::string& getDescription() const;
    const std::string& getMetadata() const;
    
    // Display
    std::string toString() const;
    
    // Static helper untuk convert ItemType ke string
    static std::string itemTypeToString(ItemType type);

private:
    int id_;
    ItemType type_;
    std::string name_;
    int price_;
    std::string description_;
    std::string metadata_;  // Bisa berisi joker name, card info, etc
};

#endif // SHOPITEM_H
