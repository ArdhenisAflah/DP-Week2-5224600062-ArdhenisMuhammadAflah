#pragma once

#include <iostream>

class ShopSystem
{
public:
    virtual ~ShopSystem() = default;
    virtual void processShop() = 0;
};