#include "RunSession.h"
#include "StandardInputGenerator.h"
#include "RandomHandChooser.h"
#include "StandardScoringRule.h"
#include "ModifiedRewardRule.h"
#include "StandardShopSystem.h"
#include <ctime>
#include <cstdlib>

int main()
{
    std::srand(std::time(0));

    // 1. Siapkan "otak" pemilih kartu (bisa RandomHandChooser atau OptimalHandChooser)
    auto chooser = std::make_unique<RandomHandChooser>();

    // 2. Gabungkan (Compose) "otak" pemilih tersebut ke dalam Input Generator
    auto inputGen = std::make_unique<StandardInputGenerator>(std::move(chooser));

    // 3. Masukkan Generator ke dalam Session
    RunSession session(
        std::move(inputGen),
        std::make_unique<StandardScoringRule>(),
        std::make_unique<ModifiedRewardRule>(),
        std::make_unique<StandardShopSystem>());

    session.Start(3);
    return 0;
}