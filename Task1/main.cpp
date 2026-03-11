#include "RunSession.h"
#include "StandardInputGenerator.h"
#include "StandardScoringRule.h"
#include "StandardRewardRule.h"
#include "StandardShopSystem.h"
#include <ctime>
#include <cstdlib>

int main()
{
    std::srand(std::time(0)); // Initialize seed for randomized deck

    RunSession session(
        std::make_unique<StandardInputGenerator>(),
        std::make_unique<StandardScoringRule>(),
        std::make_unique<StandardRewardRule>(),
        std::make_unique<StandardShopSystem>());

    session.Start(3);
    return 0;
}