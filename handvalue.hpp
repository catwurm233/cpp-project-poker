#ifndef handvaluehpp
#define handvaluehpp
#include <algorithm>
#include <ostream>
#include <vector>

enum class HandRank : int {
    HighCard = 0,
    Pair,
    TwoPair,
    ThreeOfAKind,
    Straight,
    Flush,
    FullHouse,
    FourOfAKind,
    StraightFlush
};

inline const char* toString(HandRank r) {
    switch (r) {
        case HandRank::HighCard:      return "High Card";
        case HandRank::Pair:       return "Pair";
        case HandRank::TwoPair:       return "Two Pair";
        case HandRank::ThreeOfAKind:  return "Three of a Kind";
        case HandRank::Straight:      return "Straight";
        case HandRank::Flush:         return "Flush";
        case HandRank::FullHouse:     return "Full House";
        case HandRank::FourOfAKind:   return "Four of a Kind";
        case HandRank::StraightFlush: return "Straight Flush";
    }
    return "Unknown";
}

struct HandValue {
    HandRank rank = HandRank::HighCard;
    std::vector<int> tiebreakers;
};


inline bool operator==(const HandValue& a, const HandValue& b) {
    return a.rank == b.rank && a.tiebreakers == b.tiebreakers;
}

inline bool operator<(const HandValue& a, const HandValue& b) {
    if (a.rank != b.rank)
        return static_cast<int>(a.rank) < static_cast<int>(b.rank);
    return std::lexicographical_compare(
        a.tiebreakers.begin(), a.tiebreakers.end(),
        b.tiebreakers.begin(), b.tiebreakers.end());
}

inline bool operator!=(const HandValue& a, const HandValue& b) { return !(a == b); }
inline bool operator>(const HandValue& a, const HandValue& b)  { return b < a; }
inline bool operator<=(const HandValue& a, const HandValue& b) { return !(b < a); }
inline bool operator>=(const HandValue& a, const HandValue& b) { return !(a < b); }

#endif // handvaluehpp