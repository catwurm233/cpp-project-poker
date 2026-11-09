#ifndef deckhpp
#define deckhpp
#include "card.hpp"
#include <iostream>

struct Node {
    Card card;
    Node* next;
};

class Deck {
    private:
        Node* head;
        int count;
    public:
        Deck();
        ~Deck();
        Deck(const Deck&) = delete;
        Deck& operator=(const Deck&) = delete;
        
        void addCard(const Card& c);
        Card drawTopCard();
        bool isEmpty() const;
        void shuffle();
        void reset();
        int size() const; 
};

#endif // deckhpp