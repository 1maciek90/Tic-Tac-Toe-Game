#include "Board.h"
#include <iostream>
#include <cstdlib>
#include <ctime>



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
        if (i == (this->size - 1)) continue;
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


void Board::makeMove(char symbol) {
    int row, col;

    std::cout << "Enter row and column: ";
    std::cin >> row >> col;
    while (row < 0 || row >= this->size || col < 0 || col >= this->size || board[row][col] != ' ') {
         std::cout << "Invalid move. Try again." << std::endl;
         std::cout << "Enter row and column: ";
         std::cin >> row >> col;
    }

    board[row][col] = symbol;
}


void Board::makeComputerMove(char symbol, char opponentSymbol, int difficulty) {
    static bool isRandomSeeded = false;
    if (!isRandomSeeded) {
        std::srand(static_cast<unsigned int>(std::time(nullptr)));
        isRandomSeeded = true;
    }

    if (difficulty != 0) {
        for (int i = 0; i < this->size; i++) {
            for (int j = 0; j < this->size; j++) {
                if (board[i][j] != ' ') continue;

                board[i][j] = symbol;
                if (checkWin()) {
                    std::cout << "Computer move: " << i << " " << j << std::endl;
                    return;
                }
                board[i][j] = ' ';
            }
        }
    }

    if (difficulty == 2) {
        for (int i = 0; i < this->size; i++) {
            for (int j = 0; j < this->size; j++) {
                if (board[i][j] != ' ') continue;

                board[i][j] = opponentSymbol;
                if (checkWin()) {
                    board[i][j] = symbol;
                    std::cout << "Computer move: " << i << " " << j << std::endl;
                    return;
                }
                board[i][j] = ' ';
            }
        }

        int center = this->size / 2;
        if (board[center][center] == ' ') {
            board[center][center] = symbol;
            std::cout << "Computer move: " << center << " " << center << std::endl;
            return;
        }
    }

    int row;
    int col;
    do {
        row = std::rand() % this->size;
        col = std::rand() % this->size;
    } while (board[row][col] != ' ');

    board[row][col] = symbol;
    std::cout << "Computer move: " << row << " " << col << std::endl;
}


bool Board::isFull() {
    for (int i = 0; i < this->size; i++) {
        for (int j = 0; j< this->size; j++) {
            if (board[i][j] == ' ') {
                return false;
            }
        }
    }

    return true;
}


bool Board::checkWin() {
    int winLength = 3;

    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {

            char start = board[i][j];
            if (start == ' ') continue;

            // poziomo
            if (j + winLength <= size) {
                bool win = true;
                for (int k = 1; k < winLength; k++) {
                    if (board[i][j + k] != start) {
                        win = false;
                        break;
                    }
                }
                if (win) return true;
            }

            // pionowo
            if (i + winLength <= size) {
                bool win = true;
                for (int k = 1; k < winLength; k++) {
                    if (board[i + k][j] != start) {
                        win = false;
                        break;
                    }
                }
                if (win) return true;
            }

            // przekątna
            if (i + winLength <= size && j + winLength <= size) {
                bool win = true;
                for (int k = 1; k < winLength; k++) {
                    if (board[i + k][j + k] != start) {
                        win = false;
                        break;
                    }
                }
                if (win) return true;
            }

            // przekątna
            if (i + winLength <= size && j - winLength + 1 >= 0) {
                bool win = true;
                for (int k = 1; k < winLength; k++) {
                    if (board[i + k][j - k] != start) {
                        win = false;
                        break;
                    }
                }
                if (win) return true;
            }
        }
    }

    return false;
}
