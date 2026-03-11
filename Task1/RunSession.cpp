#include "RunSession.h"
#include <iostream>

RunSession::RunSession(std::unique_ptr<IInputGenerator> ig, std::unique_ptr<IScoringRule> sr,
                       std::unique_ptr<IRewardRule> rr, std::unique_ptr<ShopSystem> ss)
    : inputGen(std::move(ig)), scoringRule(std::move(sr)),
      rewardRule(std::move(rr)), shopSystem(std::move(ss)),
      currentMoney(12), bonusChips(0), bonusMult(0) {}

void RunSession::Start(int totalRounds)
{
    std::cout << "\n==========================================\n";
    std::cout << "           BALATRO CORE SYSTEM            \n";
    std::cout << "==========================================\n";

    for (int round = 1; round <= totalRounds; ++round)
    {
        std::cout << "\n==========================================\n";
        std::cout << "                 ROUND " << round << "                  \n";
        std::cout << "==========================================\n";

        TurnInput input = inputGen->GenerateInput(round);

        // 1. Suntikkan stat buff ke input sebelum dikalkulasi
        input.extraChips = bonusChips;
        input.extraMult = bonusMult;

        std::cout << "[!] TARGET SCORE : " << input.targetScore << "\n";
        std::cout << "------------------------------------------\n";

        std::cout << "[>] Dealt 7 Cards: ";
        for (auto &c : input.dealtCards)
            std::cout << c.ToString() << " ";
        std::cout << "\n[>] Best 5 Played: ";
        for (auto &c : input.bestHand)
            std::cout << c.ToString() << " ";
        std::cout << "\n\n";

        // 2. Eksekusi Scoring
        int finalScore = scoringRule->ComputeBaseScore(input);

        // 3. Evaluasi
        std::string resultStr = (finalScore >= input.targetScore) ? "SUCCESS" : "FAILED";
        std::string opStr = (finalScore >= input.targetScore) ? " >= " : " < ";

        std::cout << "\n------------------------------------------\n";
        std::cout << "[RESULT] " << finalScore << opStr << input.targetScore << " (Target) -> " << resultStr << "!\n";

        int reward = rewardRule->ComputeReward(finalScore, input.targetScore);
        currentMoney += reward;
        std::cout << "[REWARD] +$" << reward << " | Wallet: $" << currentMoney << "\n";
        std::cout << "==========================================\n";

        // 4. Toko akan tertutup jika ini adalah ronde terakhir
        if (round < totalRounds)
        {
            shopSystem->ProcessShop(currentMoney, bonusChips, bonusMult);
        }
    }
    std::cout << "\n============= SYSTEM OFFLINE =============\n";
    std::cout << "   FINAL WALLET BALANCE: $" << currentMoney << "\n";
    std::cout << "==========================================\n\n";
}