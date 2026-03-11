#pragma once
class IRewardRule
{
public:
    virtual int ComputeReward(int finalScore, int targetScore) = 0;
    virtual ~IRewardRule() = default;
};