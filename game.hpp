#ifndef gamehpp
#define gamehpp

#include "deck.hpp"
#include "hand.hpp"
#include "player.hpp"
#include <vector>
#include <string>

class Game {
public:
    enum class Round { PreFlop, Flop, Turn, River, Showdown, Done };

private:
    Deck                 deck;
    Hand                 board;         // community cards
    std::vector<Player>  players;
    int                  pot;
    int                  dealerIndex;
    int                  currentPlayerIndex;
    int                  currentBet;    // highest bet THIS round
    int                  smallBlindAmount;
    int                  bigBlindAmount;
    Round                currentRound;

    void advanceDealer();
    void postBlinds();
    void dealHoleCards();
    void dealFlop();                    // burns one card, deals 3
    void dealTurn();                    // burns one card, deals 1
    void dealRiver();                   // burns one card, deals 1
    void burnCard();                    // discard top card (no state change visible)

    void bettingRound();                // loops until every active player has acted & matched
    void collectBets();                 // move currentBet chips into pot; reset player bets
    void showdown();                    // evaluate all non-folded, find winner(s)
    void awardPot();                    // split pot among winners
    void endHand();

    int  countActivePlayers() const;    // !folded
    int  nextActivePlayer(int from) const;
    bool handOver() const;              // ≤1 non-folded player, or everyone all-in

    HandValue bestHandFor(const Player& p) const;   // combines p's hole cards + board

public:
    Game(const std::vector<std::string>& names,
         int startingChips,
         int smallBlind,
         int bigBlind);

    void playHand();

    const Hand&                getBoard()   const;
    const std::vector<Player>& getPlayers() const;
    int                        getPot()     const;
    Round                      getRound()   const;
};

#endif // GAME_HPP