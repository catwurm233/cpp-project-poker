#ifndef cardhpp
#define cardhpp
#include <iostream>

class Card {
    private: 
        int rank;
        int suit;

    public:
        Card();
        Card(int newRank, int newSuit);
        
        int getrank() const;
        int getsuit() const;
        bool operator==(const Card& other) const;
        friend std::ostream& operator<<(std::ostream& os, const Card& other);
        bool operator<(const Card& other) const;
};

    std::ostream& operator<<(std::ostream& os, const Card& other);

#endif // cardhpp