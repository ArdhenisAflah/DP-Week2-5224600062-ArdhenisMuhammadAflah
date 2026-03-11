#include "RandomInputGenerator.h"
#include <algorithm>
#include <cstdlib>

TurnInput RandomInputGenerator::GenerateInput(int round)
{
    TurnInput ti;
    ti.targetScore = (round == 1) ? 60 : (round == 2) ? 150
                                                      : 300;

    std::vector<Card> deck;
    for (int s = 0; s < 4; s++)
        for (int r = 2; r <= 14; r++)
            deck.push_back({(Suit)s, r});

    // Acak deck utama
    std::random_shuffle(deck.begin(), deck.end());

    // Generate 7 Kartu Randoms
    for (int i = 0; i < 7; i++)
        ti.dealtCards.push_back(deck[i]);

    //  copy 7 kartu tersebut, kita acak lagi urutannya,
    // lalu kita ambil 5 kartu pertama saja secara "buta" (Blind Pick).
    // Dont care is it itu kombinasi High Card atau Flush

    std::vector<Card> shuffledHand = ti.dealtCards;
    std::random_shuffle(shuffledHand.begin(), shuffledHand.end());

    for (int i = 0; i < 5; i++)
    {
        ti.bestHand.push_back(shuffledHand[i]);
    }

    return ti;
}