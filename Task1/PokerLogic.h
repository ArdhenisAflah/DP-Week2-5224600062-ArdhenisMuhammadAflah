#pragma once
#include "Card.h"
#include <vector>
#include <string>

enum HandType
{
    HIGH_CARD,
    PAIR,
    TWO_PAIR,
    THREE_OF_A_KIND,
    STRAIGHT,
    FLUSH,
    FULL_HOUSE,
    FOUR_OF_A_KIND,
    STRAIGHT_FLUSH
};

struct HandInfo
{
    HandType type;
    int chips;
    int mult;
    std::string name;
};

class PokerLogic
{
public:
    static HandInfo Evaluate5Cards(std::vector<Card> cards);
    static int CalculateCardValue(const Card &c);
    static std::vector<Card> GetScoringCards(std::vector<Card> combo, std::string &outName, int &outChips, int &outMult);
    static int SimulateScore(std::vector<Card> combo);
};