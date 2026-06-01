#include "../../include/shop/Shop.h"
#include <iostream>
#include <algorithm>

Shop::Shop() : nextItemId_(1) {}

void Shop::addItem(const ShopItem& item) {
    // We might want to ensure the item has the correct next ID if we're managing it here,
    // but the ShopItem constructor already takes an ID. 
    // For simplicity, we'll just add it as is.
    items_.push_back(item);
    if (item.getId() >= nextItemId_) {
        nextItemId_ = item.getId() + 1;
    }
}

ShopItem* Shop::getItemById(int itemId) {
    for (auto& item : items_) {
        if (item.getId() == itemId) {
            return &item;
        }
    }
    return nullptr;
}

ShopItem* Shop::getItemByName(const std::string& itemName) {
    for (auto& item : items_) {
        if (item.getName() == itemName) {
            return &item;
        }
    }
    return nullptr;
}

bool Shop::removeItemById(int itemId) {
    auto it = std::find_if(items_.begin(), items_.end(), [itemId](const ShopItem& item) {
        return item.getId() == itemId;
    });
    
    if (it != items_.end()) {
        items_.erase(it);
        return true;
    }
    return false;
}

const std::vector<ShopItem>& Shop::getAllItems() const {
    return items_;
}

size_t Shop::getItemCount() const {
    return items_.size();
}

bool Shop::hasItem(int itemId) const {
    for (const auto& item : items_) {
        if (item.getId() == itemId) {
            return true;
        }
    }
    return false;
}

void Shop::displayCatalog() const {
    std::cout << "======= SHOP CATALOG =======" << std::endl;
    if (items_.empty()) {
        std::cout << "The shop is currently empty." << std::endl;
    } else {
        for (const auto& item : items_) {
            std::cout << "ID: " << item.getId() << " " << item.toString() << std::endl;
        }
    }
    std::cout << "============================" << std::endl;
}

void Shop::resetShop() {
    items_.clear();
    nextItemId_ = 1;
    initializeDefaultItems();
}

void Shop::initializeDefaultItems() {
    addItem(ShopItem(
        nextItemId_++,
        ItemType::JOKER,
        "Pair Joker",
        4,
        "+4 Mult if played hand contains a Pair",
        "PairJoker"
    ));
    
    addItem(ShopItem(
        nextItemId_++,
        ItemType::JOKER,
        "Flat Chip Joker",
        2,
        "+50 Chips",
        "FlatChipJoker"
    ));
}
