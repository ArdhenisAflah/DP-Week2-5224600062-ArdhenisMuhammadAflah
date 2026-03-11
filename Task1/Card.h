#pragma once
#include <string>

enum Suit
{
    HEARTS,
    DIAMONDS,
    CLUBS,
    SPADES
};
enum Rank
{
    TWO = 2,
    THREE,
    FOUR,
    FIVE,
    SIX,
    SEVEN,
    EIGHT,
    NINE,
    TEN,
    JACK = 11,
    QUEEN = 12,
    KING = 13,
    ACE = 14
};

struct Card
{
    Suit suit;
    int rank;

    std::string ToString() const
    {
        std::string rStr = (rank <= 10) ? std::to_string(rank) : (rank == JACK) ? "J"
                                                             : (rank == QUEEN)  ? "Q"
                                                             : (rank == KING)   ? "K"
                                                                                : "A";
        std::string sStr = (suit == HEARTS) ? "H" : (suit == DIAMONDS) ? "D"
                                                : (suit == CLUBS)      ? "C"
                                                                       : "S";
        return rStr + sStr;
    }
};