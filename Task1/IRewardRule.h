#pragma once

#include <iostream>

class IRewardRule
{
public:
    virtual int ComputeReward(int baseScore) = 0;
    virtual ~IRewardRule() = default;
};