#include "deck.hpp"
#include <iostream>
using namespace std;

Deck::Deck() {
    head = nullptr;
}

Deck::~Deck() {
    while (head != nullptr) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
}

Card Deck::drawTopCard() {
    if (head == nullptr) {
        cout << "Deck is empty" << endl;
        return Card();
    }
 
    Node* temp = head;
    Card topCard = head->card;
    head = head->next;
    delete temp;
    return topCard;
}

bool Deck::isEmpty() const {
    if (head == nullptr) {
        cout << "Deck is empty" << endl;
        return true;
    } else {
        cout << "Deck is not empty" << endl;
        return false;
    }
}
