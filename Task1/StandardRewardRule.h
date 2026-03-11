#pragma once
#include "IRewardRule.h"

class StandardRewardRule : public IRewardRule
{
public:
    int ComputeReward(int finalScore, int targetScore) override;
};