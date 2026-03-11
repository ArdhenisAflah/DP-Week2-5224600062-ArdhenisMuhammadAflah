#pragma once
#include <vector>
#include "Card.h"

struct TurnInput
{
    int targetScore;
    std::vector<Card> dealtCards; // 7 kartu
    std::vector<Card> bestHand;   // 5 kartu terbaik

    // Variabel penampung buff dari ShopSystem
    int extraChips = 0;
    int extraMult = 0;
};