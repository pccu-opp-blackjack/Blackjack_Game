#ifndef GAME_H
#define GAME_H
#include "Deck.h"
#include "Player.h"
#include <iostream>
using namespace std;

class Game {
private:
    Deck deck;
    Player player;
    Dealer dealer;

public:
    Game() : player("玩家") {}

    void play() {
        deck = Deck();
        deck.shuffle();
        player.clearHand();
        dealer.clearHand();

        player.addCard(deck.dealCard());
        dealer.addCard(deck.dealCard());
        player.addCard(deck.dealCard());
        dealer.addCard(deck.dealCard());

        std::cout << "\n====================\n";
        dealer.showPartialHand();
        player.showHand();
        cout << "====================\n";

        if (player.getScore() == 21) {
            cout << "玩家直接獲得 21 點！\n";
        } else {
            char choice;
            while (!player.isBusted()) {
                cout << "要加牌嗎？(y/n): ";
                cin >> choice;
                if (choice == 'y' || choice == 'Y') {
                    player.addCard(deck.dealCard());
                    player.showHand();
                } else {
                    break;
                }
            }
        }

        if (player.isBusted()) {
            cout << "玩家爆牌！莊家獲勝。\n";
            return;
        }

        cout << "\n--- 莊家回合開始 ---\n";
        dealer.showHand();
        while (dealer.getScore() < 17) {
            cout << "莊家加牌...\n";
            dealer.addCard(deck.dealCard());
            dealer.showHand();
        }

        cout << "\n【最終結算】\n";
        if (dealer.isBusted()) {
            cout << "莊家爆牌！玩家獲勝。\n";
        } else {
            int pScore = player.getScore();
            int dScore = dealer.getScore();
            if (pScore > dScore) std::cout << "玩家獲勝！\n";
            else if (pScore < dScore) cout << "莊家獲勝！\n";
            else cout << "雙方平手！\n";
        }
    }
};
#endif
