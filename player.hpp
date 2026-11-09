#ifndef playerhpp
#define playerhpp

#include "hand.hpp"
#include <string>
#include <ostream>

class Player {
private:
    std::string name;
    Hand holeCards;         // the 2 private cards
    int chips;              // chips remaining
    int currentBet;         // chips committed THIS betting round
    int totalInPot;         // chips committed THIS hand 
    bool folded;
    bool allIn;

public:
    Player();
    Player(const std::string& name, int startingChips);

    const std::string& getName()       const;
    const Hand&        getHoleCards()  const;
    int                getChips()      const;
    int                getCurrentBet() const;
    int                getTotalInPot() const;
    bool               hasFolded()     const;
    bool               isAllIn()       const;
    bool               isActive()      const;   // !folded  (may still be all-in)

    void dealHoleCard(const Card& c);           // add one hole card
    void clearHoleCards();                      // reset between hands

    int  commit(int amount);

    void fold();

    void resetForNewRound();

    friend std::ostream& operator<<(std::ostream& os, const Player& p);
};

std::ostream& operator<<(std::ostream& os, const Player& p);

#endif // playerhpp