#pragma once
#include "IInputGenerator.h"

class RandomInputGenerator : public IInputGenerator
{
public:
    TurnInput GenerateInput(int round) override;
};