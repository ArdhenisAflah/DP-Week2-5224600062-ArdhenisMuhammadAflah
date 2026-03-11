#include "StandardRewardRule.h"
int StandardRewardRule::ComputeReward(int finalScore, int targetScore)
{
    return (finalScore >= targetScore) ? 3 : 1;
}