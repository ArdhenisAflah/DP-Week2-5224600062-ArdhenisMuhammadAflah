#include "StandardShopSystem.h"
#include <iostream>
#include <limits>

void StandardShopSystem::ProcessShop(int &playerMoney, int &extraChips, int &extraMult)
{
    bool shopping = true;
    while (shopping)
    {
        std::cout << "\n[SHOP] ================================\n";
        std::cout << "[SHOP] Money: $" << playerMoney << " | Active Buffs - Chips: +" << extraChips << ", Mult: +" << extraMult << "\n";
        std::cout << "[SHOP] Available items:\n";
        std::cout << "[SHOP]   1. Boost       (+20 Chips)          | Cost: $2\n";
        std::cout << "[SHOP]   2. Super       (+2 Mult)            | Cost: $3\n";
        std::cout << "[SHOP]   3. BoosterPlus (+20 Chips, +2 Mult) | Cost: $5\n";
        std::cout << "[SHOP] Enter item number to buy (0 to leave): ";

        int choice;
        // Proteksi jika input bukan angka
        if (!(std::cin >> choice))
        {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "[SHOP] Invalid input. Must be a number.\n";
            continue;
        }

        if (choice == 0)
        {
            shopping = false;
            std::cout << "[SHOP] Disconnected from shop.\n";
        }
        else if (choice == 1)
        {
            if (playerMoney >= 2)
            {
                playerMoney -= 2;
                extraChips += 20;
                std::cout << "[SHOP] System Upgraded: Boost!\n";
            }
            else
                std::cout << "[SHOP] Integrity (Money) insufficient!\n";
        }
        else if (choice == 2)
        {
            if (playerMoney >= 3)
            {
                playerMoney -= 3;
                extraMult += 2;
                std::cout << "[SHOP] System Upgraded: Super!\n";
            }
            else
                std::cout << "[SHOP] Integrity (Money) insufficient!\n";
        }
        else if (choice == 3)
        {
            if (playerMoney >= 5)
            {
                playerMoney -= 5;
                extraChips += 20;
                extraMult += 2;
                std::cout << "[SHOP] System Upgraded: BoosterPlus!\n";
            }
            else
                std::cout << "[SHOP] Integrity (Money) insufficient!\n";
        }
        else
        {
            std::cout << "[SHOP] Invalid item index.\n";
        }
    }
    std::cout << "[SHOP] ================================\n\n";
}