#pragma once
#include "Board.h"
#include "Player.h"

class Game {
    public:
        Game();
        void run();

    private:
        Board board;
        Player player1;
        Player player2;

        void switchPlayer();
        bool isRuning;
};
