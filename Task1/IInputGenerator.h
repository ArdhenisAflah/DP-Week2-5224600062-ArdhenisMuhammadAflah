#pragma once
#include "TurnInput.h"
class IInputGenerator
{
public:
    virtual TurnInput GenerateInput(int round) = 0;
    virtual ~IInputGenerator() = default;
};