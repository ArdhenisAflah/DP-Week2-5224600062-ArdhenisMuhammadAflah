#pragma once
#include <vector>
#include "Card.h"

class IChooseHand
{
public:
    virtual std::vector<Card> Choose(const std::vector<Card> &dealtCards) = 0;
    virtual ~IChooseHand() = default;
};