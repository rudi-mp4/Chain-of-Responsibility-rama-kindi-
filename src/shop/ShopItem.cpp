#include "../../include/shop/ShopItem.h"
#include <sstream>

ShopItem::ShopItem(
    int id,
    ItemType type,
    const std::string& name,
    int price,
    const std::string& description,
    const std::string& metadata
) : id_(id), type_(type), name_(name), price_(price), description_(description), metadata_(metadata) {}

int ShopItem::getId() const {
    return id_;
}

ItemType ShopItem::getType() const {
    return type_;
}

std::string ShopItem::getTypeName() const {
    return itemTypeToString(type_);
}

const std::string& ShopItem::getName() const {
    return name_;
}

int ShopItem::getPrice() const {
    return price_;
}

const std::string& ShopItem::getDescription() const {
    return description_;
}

const std::string& ShopItem::getMetadata() const {
    return metadata_;
}

std::string ShopItem::toString() const {
    std::stringstream ss;
    ss << "[" << getTypeName() << "] " << name_ << " (" << price_ << " chips) - " << description_;
    return ss.str();
}

std::string ShopItem::itemTypeToString(ItemType type) {
    switch (type) {
        case ItemType::JOKER:      return "JOKER";
        case ItemType::CARD:       return "CARD";
        case ItemType::UPGRADE:    return "UPGRADE";
        case ItemType::CONSUMABLE: return "CONSUMABLE";
        default:                   return "UNKNOWN";
    }
}
