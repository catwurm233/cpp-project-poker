#include "card.hpp"
#include <iostream>
#include <string>
using namespace std;

Card::Card() {
    rank = 1;
    suit = 3;
}
Card::Card(int newRank, int newSuit) {
    rank = newRank;
    suit = newSuit; 
}

const string suitName[]  = {"Clubs", "Diamonds", "Hearts", "Spades"};
const string rankName[]  = {"", "Ace", "2", "3", "4", "5", "6", "7", "8", "9", "10", "Jack", "Queen", "King"};

ostream& operator<<(ostream& os, const Card& card) {
    os << rankName[card.rank] << " of " << suitName[card.suit];
    return os;
}
