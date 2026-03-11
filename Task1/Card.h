#ifndef CARD_H
#define CARD_H

#include <string>

// Kode Warna ANSI
#define RESET "\033[0m"
#define RED "\033[31m"     // Hearts
#define GREEN "\033[32m"   // Clubs
#define YELLOW "\033[33m"  // Mining / Gold
#define BLUE "\033[34m"    // Spades
#define MAGENTA "\033[35m" // Diamonds
#define CYAN "\033[36m"    // Corrupted / Glass
#define GRAY "\033[90m"    // Firewall / Stone

enum Suit
{
    HEARTS,
    DIAMONDS,
    CLUBS,
    SPADES
};

//  Enum Rank biar tidak bingung angka 11, 12, 13, 14
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
    int rank; // Tetap simpan int untuk kompatibilitas sorting, tapi isinya dari Enum Rank

    std::string ToString() const
    {
        std::string suitColor = RESET;

        // 1. Tentukan Warna SUIT
        switch (suit)
        {
        case HEARTS:
            suitColor = RED;
            break;
        case DIAMONDS:
            suitColor = MAGENTA;
            break;
        case CLUBS:
            suitColor = GREEN;
            break;
        case SPADES:
            suitColor = BLUE;
            break;
        }

        // 3. Konversi Rank & Suit String
        std::string rStr;
        if (rank <= 10)
            rStr = std::to_string(rank);
        else if (rank == JACK)
            rStr = "J";
        else if (rank == QUEEN)
            rStr = "Q";
        else if (rank == KING)
            rStr = "K";
        else if (rank == ACE)
            rStr = "A";

        std::string sStr;
        switch (suit)
        {
        case HEARTS:
            sStr = "H";
            break;
        case DIAMONDS:
            sStr = "D";
            break;
        case CLUBS:
            sStr = "C";
            break;
        case SPADES:
            sStr = "S";
            break;
        }

        // Kartu biasa
        return suitColor + rStr + "-" + sStr + RESET;
    }
};

#endif