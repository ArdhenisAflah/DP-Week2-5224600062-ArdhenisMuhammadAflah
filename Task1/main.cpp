#include "RunSession.h"
#include "RandomInputGenerator.h" // Pakai generator random modification
#include "StandardScoringRule.h"
#include "ModifiedRewardRule.h" // Pakai reward rule modification
#include "StandardShopSystem.h"
#include <ctime>
#include <cstdlib>

int main()
{
    std::srand(std::time(0));

    // Injeksi object baru ke RunSession
    RunSession session(
        std::make_unique<RandomInputGenerator>(),
        std::make_unique<StandardScoringRule>(),
        std::make_unique<ModifiedRewardRule>(),
        std::make_unique<StandardShopSystem>());

    session.Start(3);
    return 0;
}