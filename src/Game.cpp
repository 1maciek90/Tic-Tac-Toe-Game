#include "Game.h"
#include <iostream>


Game::Game() : board(nullptr), player1('X'), player2('O') {
    isComputerPlaying = false;
    difficulty = EASY;
}

Game::~Game() {
    delete board;
}

void Game::choseOpponent() {
    int chose_player = 0;
    while (chose_player != 1 && chose_player != 2) {
        std::cout << "1. Play against player 2" << std::endl;
        std::cout << "2. Play adainst computer" << std::endl;
        std::cout << "Chose player: ";
        
        std::cin >> chose_player;

        if (chose_player == 1) {
            isComputerPlaying = false;
        } else if (chose_player == 2) {
            isComputerPlaying = true;
        } else {
            std::cout << "Incorect number" << std::endl;
        }
    }
}


void Game::choseDifficulty() {
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


Player* Game::switchPlayer(Player* current) {
    return (current == &player1) ? &player2 : &player1; 
}


void Game::run() {
    Player* current = &player1;

    choseOpponent();
    choseDifficulty();

    Game::board = nullptr;
    int size = 3;
    if (difficulty == MEDIUM) {
        size = 5;
    } else if (difficulty == HARD) {
        size = 7;
    }


    if (board != nullptr) delete board;
    board = new Board(size);


    while (true) {
        board->drawBoard();
        board->makeMove(current->getSymbol());
        if (board->checkWin()) {
            std::cout << "Player " << current->getSymbol() << " wins!" << std::endl;
            break;
        } else if (board->isFull()) {
            std::cout << "It's a draw!" << std::endl;
            break;
        }

        current = switchPlayer(current);
    }
    
}

