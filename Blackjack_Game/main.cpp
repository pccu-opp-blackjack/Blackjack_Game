#include "Game.h"
#include <iostream>

int main() {
    // 確保終端機能正確顯示中文 (Windows 系統適用)
    system("chcp 65001 > nul");

    std::cout << "歡迎來到 C++ 物件導向 21 點遊戲！\n";
    Game game;
    char playAgain = 'y';

    while (playAgain == 'y' || playAgain == 'Y') {
        game.play();
        std::cout << "\n要再玩一局嗎？(y/n): ";
        std::cin >> playAgain;
    }

    std::cout << "遊戲結束，感謝遊玩！\n";
    return 0;
}