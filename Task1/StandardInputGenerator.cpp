#include "StandardInputGenerator.h"
#include <algorithm>

StandardInputGenerator::StandardInputGenerator(std::unique_ptr<IChooseHand> chooser)
    : handChooser(std::move(chooser)) {}

TurnInput StandardInputGenerator::GenerateInput(int round)
{
    TurnInput ti;
    ti.targetScore = (round == 1) ? 60 : (round == 2) ? 150 : 300;

    // TANGGUNG JAWAB 1: Generate Hand (7 Kartu)
    std::vector<Card> deck;
    for (int s = 0; s < 4; s++)
        for (int r = 2; r <= 14; r++)
            deck.push_back({(Suit)s, r});
    std::random_shuffle(deck.begin(), deck.end());

    for (int i = 0; i < 7; i++)
        ti.dealtCards.push_back(deck[i]);

    // TANGGUNG JAWAB 2: Choose Best 5 Cards (Didelegasikan!)
    ti.bestHand = handChooser->Choose(ti.dealtCards);

    return ti;
}