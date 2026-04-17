#ifndef PLAYER_H
#define PLAYER_H
#include "Card.h"
#include <vector>
#include <iostream>

class Player {
protected:
    std::vector<Card> hand;
    std::string name;

public:
    Player(std::string n) : name(n) {}
    virtual ~Player() {}

    void addCard(Card c) { hand.push_back(c); }
    void clearHand() { hand.clear(); }

    int getScore() const {
        int score = 0;
        int aces = 0;
        for (const auto& card : hand) {
            score += card.getValue();
            if (card.getRank() == "A") aces++;
        }
        // 如果分數超過 21 且有 A，就把 A 當作 1 (減去 10)
        while (score > 21 && aces > 0) {
            score -= 10;
            aces--;
        }
        return score;
    }

    bool isBusted() const { return getScore() > 21; }

    virtual void showHand() const {
        std::cout << name << " 的牌: ";
        for (const auto& card : hand) {
            card.display();
        }
        std::cout << " (總分: " << getScore() << ")\n";
    }
};

class Dealer : public Player {
public:
    Dealer() : Player("莊家") {}
    
    void showPartialHand() const {
        std::cout << name << " 的牌: ";
        hand[0].display();
        std::cout << "[暗牌]\n";
    }
};
#endif