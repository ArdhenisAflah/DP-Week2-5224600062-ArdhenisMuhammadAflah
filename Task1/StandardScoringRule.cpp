#include "StandardScoringRule.h"
#include "PokerLogic.h"
#include <iostream>

int StandardScoringRule::ComputeBaseScore(const TurnInput &input)
{
    std::string name;
    int bChips, bMult;
    std::vector<Card> scoring = PokerLogic::GetScoringCards(input.bestHand, name, bChips, bMult);

    int sum = 0;
    for (auto &c : scoring)
        sum += PokerLogic::CalculateCardValue(c);

    // Kalkulasi Base + Buff
    int totalChips = bChips + sum + input.extraChips;
    int totalMult = bMult + input.extraMult;
    int finalScore = totalChips * totalMult;

    // UI UPDATE: Tampilan lebih bersih dan sejajar
    std::cout << "   [EVAL] Hand Played : " << name << "\n";
    std::cout << "          --------------------------------\n";

    std::cout << "          Chips       : " << bChips << " (Base) + " << sum << " (Cards)";
    if (input.extraChips > 0)
        std::cout << " + " << input.extraChips << " (Buff)";
    std::cout << " = " << totalChips << "\n";

    std::cout << "          Multiplier  : " << bMult << " (Base)";
    if (input.extraMult > 0)
        std::cout << " + " << input.extraMult << " (Buff)";
    std::cout << " = " << totalMult << "\n";

    std::cout << "          --------------------------------\n";
    std::cout << "          FINAL SCORE : " << totalChips << " x " << totalMult << " = " << finalScore << "\n";

    return finalScore;
}