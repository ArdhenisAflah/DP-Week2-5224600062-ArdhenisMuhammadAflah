#pragma once
#include "IChooseHand.h"

class RandomHandChooser : public IChooseHand
{
public:
    std::vector<Card> Choose(const std::vector<Card> &dealtCards) override;
};