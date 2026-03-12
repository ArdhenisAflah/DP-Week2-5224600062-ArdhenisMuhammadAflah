#include "OptimalHandChooser.h"
#include "PokerLogic.h"

std::vector<Card> OptimalHandChooser::Choose(const std::vector<Card> &dealtCards)
{
    std::vector<Card> bestHand;
    int maxScore = -1;

    // Cari kombinasi 5 kartu terbaik
    for (int i = 0; i < 6; i++)
    {
        for (int j = i + 1; j < 7; j++)
        {
            std::vector<Card> combo;
            for (int k = 0; k < 7; k++)
                if (k != i && k != j)
                    combo.push_back(dealtCards[k]);

            int score = PokerLogic::SimulateScore(combo);
            if (score > maxScore)
            {
                maxScore = score;
                bestHand = combo;
            }
        }
    }
    return bestHand;
}