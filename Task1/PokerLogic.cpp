#include "PokerLogic.h"
#include <algorithm>
#include <map>

HandInfo PokerLogic::Evaluate5Cards(std::vector<Card> cards)
{
    std::sort(cards.begin(), cards.end(), [](const Card &a, const Card &b)
              { return a.rank < b.rank; });

    bool flush = true, straight = true;
    for (int i = 1; i < 5; i++)
        if (cards[i].suit != cards[0].suit)
            flush = false;
    for (int i = 0; i < 4; i++)
        if (cards[i].rank + 1 != cards[i + 1].rank)
            straight = false;

    std::map<int, int> counts;
    for (auto &c : cards)
        counts[c.rank]++;

    bool four = false, three = false;
    int pairs = 0;
    for (auto &kv : counts)
    {
        if (kv.second == 4)
            four = true;
        if (kv.second == 3)
            three = true;
        if (kv.second == 2)
            pairs++;
    }

    if (flush && straight)
        return {STRAIGHT_FLUSH, 100, 8, "Straight Flush"};
    if (four)
        return {FOUR_OF_A_KIND, 60, 7, "Four of a Kind"};
    if (three && pairs == 1)
        return {FULL_HOUSE, 40, 4, "Full House"};
    if (flush)
        return {FLUSH, 35, 4, "Flush"};
    if (straight)
        return {STRAIGHT, 30, 4, "Straight"};
    if (three)
        return {THREE_OF_A_KIND, 30, 3, "Three of a Kind"};
    if (pairs >= 2)
        return {TWO_PAIR, 20, 2, "Two Pair"};
    if (pairs == 1)
        return {PAIR, 10, 2, "One Pair"};
    return {HIGH_CARD, 5, 1, "High Card"};
}

int PokerLogic::CalculateCardValue(const Card &c)
{
    if (c.rank <= 10)
        return c.rank;
    if (c.rank <= 13)
        return 10;
    return 11; // ACE
}

std::vector<Card> PokerLogic::GetScoringCards(std::vector<Card> combo, std::string &outName, int &outChips, int &outMult)
{
    HandInfo info = Evaluate5Cards(combo);
    outName = info.name;
    outChips = info.chips;
    outMult = info.mult;

    if (info.type == STRAIGHT_FLUSH || info.type == FLUSH || info.type == STRAIGHT)
        return combo;

    std::map<int, std::vector<Card>> groups;
    for (auto &c : combo)
        groups[c.rank].push_back(c);

    std::vector<Card> quads, trips, pairs;
    for (auto &kv : groups)
    {
        if (kv.second.size() == 4)
            quads = kv.second;
        else if (kv.second.size() == 3)
            trips = kv.second;
        else if (kv.second.size() == 2)
            pairs.insert(pairs.end(), kv.second.begin(), kv.second.end());
    }

    if (info.type == FOUR_OF_A_KIND)
        return quads;
    if (info.type == FULL_HOUSE)
    {
        trips.insert(trips.end(), pairs.begin(), pairs.end());
        return trips;
    }
    if (info.type == THREE_OF_A_KIND)
        return trips;
    if (info.type == TWO_PAIR || info.type == PAIR)
        return pairs;

    std::sort(combo.begin(), combo.end(), [](const Card &a, const Card &b)
              { return a.rank < b.rank; });
    return {combo.back()};
}

int PokerLogic::SimulateScore(std::vector<Card> combo)
{
    std::string name;
    int bChips, bMult;
    std::vector<Card> scoring = GetScoringCards(combo, name, bChips, bMult);
    int sum = 0;
    for (auto &c : scoring)
        sum += CalculateCardValue(c);
    return (bChips + sum) * bMult;
}