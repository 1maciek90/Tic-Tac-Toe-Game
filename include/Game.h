#pragma once
#include "Board.h"
#include "Player.h"

enum Difficulty {
    EASY,
    MEDIUM,
    HARD
};

class Game {
    public:
        Game();
        void run();

    private:
        Board* board;
        Player player1;
        Player player2;
        
        bool isComputerPlaying;
        Difficulty difficulty;

        void choseDifficulty();
        void choseOpponent();
        void switchPlayer();
};
