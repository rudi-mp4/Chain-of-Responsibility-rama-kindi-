#include "../include/PokerHandChecker.h"
#include "../include/Card.h"
#include "../include/Hand.h"
#include "../include/HandGenerator.h"
#include "../include/scoring/HandResolver.h"
#include "../include/scoring/HandScoreTable.h"
#include "../include/jokers/JokerManager.h"
#include "../include/GameManager.h"
#include "../include/shop/Shop.h"
#include "../include/shop/ShopInventory.h"
#include "../include/blind state/BlindState.h"
#include "../include/blind state/SmallBlindState.h"
#include "../include/reward command/GameSession.h"
#include "../include/HandRank.h"
#include "../include/jokers/PairJoker.h"
#include "../include/jokers/FlatChipJoker.h"

#include <iostream>
#include <string>
#include <memory>
#include <vector>

/**
 * createJokerFromMetadata
 * Helper untuk membuat instance Joker berdasarkan metadata dari ShopItem.
 */
std::unique_ptr<Joker> createJokerFromMetadata(const std::string& metadata) {
    if (metadata == "PairJoker") {
        return std::make_unique<PairJoker>();
    } else if (metadata == "FlatChipJoker") {
        return std::make_unique<FlatChipJoker>();
    }
    return nullptr;
}

/**
 * handleShop
 * Mengelola fase toko di mana pemain bisa membeli item (Joker, dll).
 */
void handleShop(Shop& shop, ShopInventory& inventory, JokerManager& jokerManager) {
    bool inShop = true;
    while (inShop) {
        std::cout << "\n========================================" << std::endl;
        std::cout << "               SHOP PHASE               " << std::endl;
        std::cout << "========================================" << std::endl;
        std::cout << "Your Chips: " << inventory.getChips() << std::endl;
        shop.displayCatalog();
        
        std::cout << "\nEnter Item ID to buy, '0' to exit shop, or 'R' to restock (5 chips): ";
        std::string input;
        std::cin >> input;
        
        if (input == "0") {
            inShop = false;
        } else if (input == "R" || input == "r") {
            if (inventory.spendChips(5)) {
                shop.resetShop();
                std::cout << ">> Shop restocked!" << std::endl;
            } else {
                std::cout << ">> Not enough chips to restock!" << std::endl;
            }
        } else {
            try {
                int choice = std::stoi(input);
                ShopItem* item = shop.getItemById(choice);
                if (item) {
                    if (inventory.buyItem(*item)) {
                        std::cout << ">> Successfully bought " << item->getName() << "!" << std::endl;
                        
                        // Jika item adalah Joker, tambahkan ke JokerManager
                        if (item->getType() == ItemType::JOKER) {
                            auto joker = createJokerFromMetadata(item->getMetadata());
                            if (joker) {
                                jokerManager.addJoker(std::move(joker));
                                std::cout << ">> Joker activated!" << std::endl;
                            }
                        }
                        
                        shop.removeItemById(choice);
                    } else {
                        std::cout << ">> Not enough chips!" << std::endl;
                    }
                } else {
                    std::cout << ">> Invalid Item ID!" << std::endl;
                }
            } catch (...) {
                std::cout << ">> Invalid input!" << std::endl;
            }
        }
    }
}

int main() {
    std::cout << "========================================" << std::endl;
    std::cout << "       BALATRO POKER CLONE (CLI)       " << std::endl;
    std::cout << "========================================" << std::endl;
    
    // Inisialisasi Sistem
    GameSession session;
    ShopInventory inventory(10); // Mulai dengan 10 chips
    Shop shop;
    shop.initializeDefaultItems();
    
    JokerManager jokerManager;
    // GameManager::setupJokers(jokerManager); // Opsional: Berikan joker awal
    
    // Inisialisasi Resolver
    IPokerHandChecker* checkerChain = buildDefaultCheckerChain();
    HandResolver resolver(checkerChain);
    
    // Mulai dari Small Blind Ante 1
    std::unique_ptr<BlindState> currentBlind = std::make_unique<SmallBlindState>(1);
    
    bool gameOver = false;
    
    while (!gameOver) {
        std::cout << "\n----------------------------------------" << std::endl;
        std::cout << "Current Blind: " << currentBlind->getName() << std::endl;
        std::cout << "Target Score:  " << currentBlind->getTargetScore() << std::endl;
        std::cout << "Reward Money:  " << currentBlind->getRewardMoney() << " chips" << std::endl;
        std::cout << "Your Chips:    " << inventory.getChips() << std::endl;
        std::cout << "Active Jokers: " << jokerManager.getJokerCount() << std::endl;
        std::cout << "----------------------------------------" << std::endl;
        
        std::cout << "\n1. Play Blind" << std::endl;
        std::cout << "2. Skip Blind (Get Tag/Reward)" << std::endl;
        std::cout << "3. View Inventory" << std::endl;
        std::cout << "4. Exit Game" << std::endl;
        std::cout << "Choose action: ";
        
        int action;
        if (!(std::cin >> action)) {
            std::cin.clear();
            std::cin.ignore(1000, '\n');
            continue;
        }
        
        if (action == 4) {
            std::cout << "Thanks for playing!" << std::endl;
            break;
        }
        
        if (action == 2) {
            std::cout << "\nSkipping blind..." << std::endl;
            auto reward = currentBlind->createSkipReward();
            if (reward) {
                std::cout << ">> Executing skip reward..." << std::endl;
                reward->execute(&session);
            }
            std::cout << ">> Moving to next blind." << std::endl;
            currentBlind = currentBlind->getNextState();
            continue;
        } else if (action == 3) {
            inventory.displayInventory();
            std::cout << "\nPress Enter to continue...";
            std::cin.ignore(1000, '\n');
            std::cin.get();
            continue;
        } else if (action != 1) {
            std::cout << ">> Invalid action!" << std::endl;
            continue;
        }
        
        // --- Fase Play Blind ---
        session.resetScore();
        session.resetPlays();
        session.resetDiscards();
        
        bool blindCleared = false;
        while (session.getRemainingPlays() > 0 && !blindCleared) {
            std::cout << "\n--- Round Status ---" << std::endl;
            std::cout << "Target: " << currentBlind->getTargetScore() << " | Current: " << session.getTotalScore() << std::endl;
            std::cout << "Remaining Plays: " << session.getRemainingPlays() << " | Discards: " << session.getRemainingDiscards() << std::endl;
            
            // Generate kartu tangan (8 kartu)
            Hand deck = generateRandomHand();
            
            // Player memilih kartu dan aksi (Play/Discard)
            HandAction action = chooseHand(deck);
            
            if (action.type == HandActionType::Play) {
                chosenHand hand = convertToHand(deck, action.indices);
                
                // Resolusi skor dengan menyertakan JokerManager
                PlayedHandResult result = resolver.resolveHand(hand, 1, &jokerManager);
                
                std::cout << "\n========================================" << std::endl;
                std::cout << "Played: " << handRankToString(result.handType) << std::endl;
                std::cout << "Base: (" << result.chips << " x " << result.mult << ")" << std::endl;
                std::cout << "Earned: " << result.finalScore << " chips" << std::endl;
                std::cout << "========================================" << std::endl;
                
                session.addScore(result.finalScore);
                session.spendPlay();
                
                if (session.getTotalScore() >= currentBlind->getTargetScore()) {
                    blindCleared = true;
                }
            } else {
                // Discard logic
                if (session.getRemainingDiscards() > 0) {
                    session.spendDiscard();
                    std::cout << ">> Discarded " << action.indices.size() << " cards." << std::endl;
                } else {
                    std::cout << ">> No discards remaining! Hand must be played." << std::endl;
                }
            }
        }
        
        if (blindCleared) {
            std::cout << "\n****************************************" << std::endl;
            std::cout << "         *** BLIND CLEARED! ***         " << std::endl;
            std::cout << "****************************************" << std::endl;
            int rewardMoney = currentBlind->getRewardMoney();
            std::cout << "Cash out: " << rewardMoney << " chips" << std::endl;
            inventory.addChips(rewardMoney);
            
            // Fase Toko
            handleShop(shop, inventory, jokerManager);
            
            // Pindah ke blind berikutnya
            currentBlind = currentBlind->getNextState();
        } else {
            std::cout << "\n****************************************" << std::endl;
            std::cout << "         *** GAME OVER! ***             " << std::endl;
            std::cout << "****************************************" << std::endl;
            std::cout << "Final Score: " << session.getTotalScore() << " / " << currentBlind->getTargetScore() << std::endl;
            gameOver = true;
        }
    }
    
    return 0;
}
