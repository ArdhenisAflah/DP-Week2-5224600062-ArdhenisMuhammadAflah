#include "RandomHandChooser.h"
#include <algorithm>

std::vector<Card> RandomHandChooser::Choose(const std::vector<Card> &dealtCards)
{
    std::vector<Card> shuffledHand = dealtCards;
    std::random_shuffle(shuffledHand.begin(), shuffledHand.end());

    std::vector<Card> hand;
    for (int i = 0; i < 5; i++)
    {
        hand.push_back(shuffledHand[i]);
    }
    return hand;
}