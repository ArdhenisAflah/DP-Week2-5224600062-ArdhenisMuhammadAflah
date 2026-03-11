#pragma once
#include <memory>
#include "IInputGenerator.h"
#include "IScoringRule.h"
#include "IRewardRule.h"
#include "ShopSystem.h"

class RunSession
{
private:
    std::unique_ptr<IInputGenerator> inputGen;
    std::unique_ptr<IScoringRule> scoringRule;
    std::unique_ptr<IRewardRule> rewardRule;
    std::unique_ptr<ShopSystem> shopSystem;

    int currentMoney;
    int bonusChips;
    int bonusMult;

public:
    RunSession(std::unique_ptr<IInputGenerator> ig, std::unique_ptr<IScoringRule> sr,
               std::unique_ptr<IRewardRule> rr, std::unique_ptr<ShopSystem> ss);
    void Start(int totalRounds);
};