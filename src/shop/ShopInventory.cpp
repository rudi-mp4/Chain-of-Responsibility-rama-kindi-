#include "../../include/shop/ShopInventory.h"
#include <iostream>
#include <algorithm>

ShopInventory::ShopInventory(int initialChips) : chips_(initialChips) {}

void ShopInventory::addChips(int amount) {
    if (amount > 0) {
        chips_ += amount;
    }
}

bool ShopInventory::spendChips(int amount) {
    if (amount > 0 && chips_ >= amount) {
        chips_ -= amount;
        return true;
    }
    return false;
}

int ShopInventory::getChips() const {
    return chips_;
}

void ShopInventory::addItem(const ShopItem& item) {
    items_.push_back(item);
}

bool ShopInventory::removeItemById(int itemId) {
    auto it = std::find_if(items_.begin(), items_.end(), [itemId](const ShopItem& item) {
        return item.getId() == itemId;
    });
    
    if (it != items_.end()) {
        items_.erase(it);
        return true;
    }
    return false;
}

ShopItem* ShopInventory::getItemById(int itemId) {
    for (auto& item : items_) {
        if (item.getId() == itemId) {
            return &item;
        }
    }
    return nullptr;
}

const std::vector<ShopItem>& ShopInventory::getAllItems() const {
    return items_;
}

size_t ShopInventory::getItemCount() const {
    return items_.size();
}

size_t ShopInventory::getJokerCount() const {
    size_t count = 0;
    for (const auto& item : items_) {
        if (item.getType() == ItemType::JOKER) {
            count++;
        }
    }
    return count;
}

bool ShopInventory::hasItem(int itemId) const {
    for (const auto& item : items_) {
        if (item.getId() == itemId) {
            return true;
        }
    }
    return false;
}

bool ShopInventory::buyItem(const ShopItem& item) {
    if (spendChips(item.getPrice())) {
        addItem(item);
        return true;
    }
    return false;
}

void ShopInventory::displayInventory() const {
    std::cout << "--- Player Inventory ---" << std::endl;
    std::cout << "Chips: " << chips_ << std::endl;
    std::cout << "Items (" << items_.size() << "):" << std::endl;
    if (items_.empty()) {
        std::cout << "  (Empty)" << std::endl;
    } else {
        for (const auto& item : items_) {
            std::cout << "  " << item.toString() << std::endl;
        }
    }
    std::cout << "------------------------" << std::endl;
}

void ShopInventory::clearItems() {
    items_.clear();
}

void ShopInventory::reset(int initialChips) {
    chips_ = initialChips;
    items_.clear();
}
