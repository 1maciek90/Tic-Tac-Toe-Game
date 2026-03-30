#include "Game.h"
#include <iostream>


Game::Game() : board(nullptr), player1('X'), player2('O') {
    Game::isComputerPlaying = false;
    Game::difficulty = EASY;
}

void Game::choseDifficulty() {
    int chose_player = 0;
    while (chose_player != 1 && chose_player != 2) {
        std::cout << "1. Play against player 2" << std::endl;
        std::cout << "2. Play adainst computer" << std::endl;
        std::cout << "Chose player: ";
        
        std::cin >> chose_player;

        if (chose_player == 1) {
            Game::isComputerPlaying = false;
        } else if (chose_player == 2) {
            Game::isComputerPlaying = true;
        } else {
            std::cout << "Incorect number" << std::endl;
        }
    }
}


void Game::choseOpponent() {
    int chose_difficulty = 0;
    while (chose_difficulty != 1 && chose_difficulty != 2 && chose_difficulty != 3) {
        std::cout << "1. Easy" << std::endl;
        std::cout << "2. Medium" << std::endl;
        std::cout << "3. Hard" << std::endl;
        std::cout << "Chose difficulty: ";
        std::cin >> chose_difficulty;

        if (chose_difficulty == 1) {
            Game::difficulty = EASY;
        } else if (chose_difficulty == 2) {
            Game::difficulty = MEDIUM;
        } else if (chose_difficulty == 3) {
            Game::difficulty = HARD;
        } else {
            std::cout << "Incorect number" << std::endl;
        }
    }
}


void Game::run() {
    Player* current = &player1;

    choseOpponent();
    choseDifficulty();

    Game::board = nullptr;
    int size = 3;
    if (Game::difficulty == MEDIUM) {
        size = 5;
    } else if (Game::difficulty == HARD) {
        size = 7;
    }

    Game::board = new Board(size);

    Game::board->drawBoard();


    
    
}

