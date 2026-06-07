#ifndef DECK_H
#define DECK_H
#include "Card.h"
#include <vector>
#include <algorithm>
#include <random>
#include <chrono>
using namespace std;

class Deck {
private:
    vector<Card> cards;

public:
    Deck() {
        string suits[] = {"黑桃", "紅心", "方塊", "梅花"};
        string ranks[] = {"A", "2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K"};
        int values[] = {11, 2, 3, 4, 5, 6, 7, 8, 9, 10, 10, 10, 10};

        for (const auto& suit : suits) {
            for (int i = 0; i < 13; ++i) {
                cards.push_back(Card(suit, ranks[i], values[i]));
            }
        }
    }

    void shuffle() {
        unsigned seed = chrono::system_clock::now().time_since_epoch().count();
        std::shuffle(cards.begin(), cards.end(), default_random_engine(seed));
    }

    Card dealCard() {
        Card c = cards.back();
        cards.pop_back();
        return c;
    }
};
#endif
