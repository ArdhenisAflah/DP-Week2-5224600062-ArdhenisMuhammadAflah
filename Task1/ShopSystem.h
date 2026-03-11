#pragma once

class ShopSystem
{
public:
    virtual void ProcessShop(int &playerMoney, int &extraChips, int &extraMult) = 0;
    virtual ~ShopSystem() = default;
};