#pragma once
#include "IScoringRule.h"

class StandardScoringRule : public IScoringRule
{
public:
    int ComputeBaseScore(const TurnInput &input) override;
};