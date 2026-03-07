#pragma once

#include <iostream>

class IScoringRule
{
    public:
        //take input playing card nanti, abis itu di passing ke Irewardrule sebagai base score.
        virtual int ComputeBaseScore(int input) = 0;
        virtual ~IScoringRule() = default;
};