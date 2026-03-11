// --- StandardInputGenerator.cpp ---
#include "StandardInputGenerator.h"
#include "PokerLogic.h"
#include <algorithm>
#include <iostream>

TurnInput StandardInputGenerator::GenerateInput(int round)
{
    TurnInput ti;
    ti.targetScore = (round == 1) ? 60 : (round == 2) ? 150
                                                      : 300;

    std::vector<Card> deck;
    for (int s = 0; s < 4; s++)
        for (int r = 2; r <= 14; r++)
            deck.push_back({(Suit)s, r});
    std::random_shuffle(deck.begin(), deck.end());

    for (int i = 0; i < 7; i++)
        ti.dealtCards.push_back(deck[i]);

    int maxScore = -1;
    for (int i = 0; i < 6; i++)
    {
        for (int j = i + 1; j < 7; j++)
        {
            std::vector<Card> combo;
            for (int k = 0; k < 7; k++)
                if (k != i && k != j)
                    combo.push_back(ti.dealtCards[k]);

            int score = PokerLogic::SimulateScore(combo);
            if (score > maxScore)
            {
                maxScore = score;
                ti.bestHand = combo;
            }
        }
    }
    return ti;
}