#include "Game.h"
#include <iostream>
using namespace std;

int main() {
    cout << "歡迎來到 C++ 物件導向 21 點遊戲！\n";
    Game game;
    char playAgain = 'y';

    while (playAgain == 'y' || playAgain == 'Y') {
        game.play();
        cout << "\n要再玩一局嗎？(y/n): ";
        cin >> playAgain;
    }

    cout << "遊戲結束，感謝遊玩！\n";
    return 0;
}
