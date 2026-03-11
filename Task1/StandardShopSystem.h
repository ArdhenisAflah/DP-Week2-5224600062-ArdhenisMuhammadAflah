#pragma once
#include "ShopSystem.h"

class StandardShopSystem : public ShopSystem
{
public:
    void ProcessShop(int &playerMoney, int &extraChips, int &extraMult) override;
};