#ifndef GAME_H
#define GAME_H
#include "Deck.h"
#include "Player.h"
#include <iostream>

class Game {
private:
    Deck deck;
    Player player;
    Dealer dealer;

public:
    Game() : player("玩家") {}

    void play() {
        deck = Deck(); // 重置牌堆
        deck.shuffle();
        player.clearHand();
        dealer.clearHand();

        // 初始發牌 (各兩張)
        player.addCard(deck.dealCard());
        dealer.addCard(deck.dealCard());
        player.addCard(deck.dealCard());
        dealer.addCard(deck.dealCard());

        std::cout << "\n====================\n";
        dealer.showPartialHand();
        player.showHand();
        std::cout << "====================\n";

        if (player.getScore() == 21) {
            std::cout << "玩家直接獲得 21 點！\n";
        } else {
            // 玩家回合
            char choice;
            while (!player.isBusted()) {
                std::cout << "要加牌嗎？(y/n): ";
                std::cin >> choice;
                if (choice == 'y' || choice == 'Y') {
                    player.addCard(deck.dealCard());
                    player.showHand();
                } else {
                    break;
                }
            }
        }

        if (player.isBusted()) {
            std::cout << "玩家爆牌！莊家獲勝。\n";
            return;
        }

        // 莊家回合 (規則：未滿 17 點必須加牌)
        std::cout << "\n--- 莊家回合開始 ---\n";
        dealer.showHand();
        while (dealer.getScore() < 17) {
            std::cout << "莊家加牌...\n";
            dealer.addCard(deck.dealCard());
            dealer.showHand();
        }

        // 結算
        std::cout << "\n【最終結算】\n";
        if (dealer.isBusted()) {
            std::cout << "莊家爆牌！玩家獲勝。\n";
        } else {
            int pScore = player.getScore();
            int dScore = dealer.getScore();
            if (pScore > dScore) std::cout << "玩家獲勝！\n";
            else if (pScore < dScore) std::cout << "莊家獲勝！\n";
            else std::cout << "雙方平手！\n";
        }
    }
};
#endif