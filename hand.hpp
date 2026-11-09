#ifndef handhpp
#define handhpp
#include "card.hpp"
#include "handvalue.hpp"
#include <iostream>
#include <vector>

class Hand {
    private:
        std::vector<Card> cards;
    public:
        
        void addCard(const Card& c);
        void printHand() const;
        bool isEmpty() const;

        bool operator<(const Hand& other) const;
        bool operator>(const Hand& other) const;
        bool operator==(const Hand& other) const;

        HandValue evaluate() const; // evaluate the hand of 7 cards and return the best hand value
        const std::vector<Card>& getCards() const;
};
#endif //handhpp