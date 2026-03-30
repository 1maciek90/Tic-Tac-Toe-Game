#include "Board.h"
#include <iostream>



Board::Board(int size) {
    this->size = size;

    board = new char*[size];
    for (int i = 0; i < size; i++){
        board[i] = new char[size];
    }

    createBoard();
}

Board::~Board() {
    for (int i = 0; i < this->size; i++) {
        delete[] board[i];
    }
    delete[] board;
}


void Board::createBoard() {
    for (int i = 0; i < this->size; i++) {
        for (int j = 0; j < this->size; j++) {
            board[i][j] = ' ';
        }
    }
}


void Board::drawBoard() {
    for (int i = 0; i < this->size; i++) {
        for (int j = 0; j < this->size; j++) {
            if (j == 0) {
                std::cout << this->board[i][j];
            } else {
                std::cout << " | " <<  this->board[i][j];
            }
        }
        std::cout << std::endl;
        for (int j = 0; j < this->size; j++) {
            if (j == 0) {
                std::cout << "--+";
            } else if (j == (this->size - 1)) {
                std::cout << "--";
            } else {
                std::cout << "---+";
            }
        }
        std::cout << std::endl;
    }
}
 