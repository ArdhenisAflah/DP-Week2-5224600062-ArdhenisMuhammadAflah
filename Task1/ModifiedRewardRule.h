#pragma once
#include "IRewardRule.h"

class ModifiedRewardRule : public IRewardRule {
public:
    int ComputeReward(int finalScore, int targetScore) override;
};