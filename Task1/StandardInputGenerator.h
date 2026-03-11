#pragma once
#include "IInputGenerator.h"

class StandardInputGenerator : public IInputGenerator
{
public:
    TurnInput GenerateInput(int round) override;
};