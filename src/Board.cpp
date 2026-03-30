#include <Board.h>



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
        for (int j = 0; j< this->size; i++) {
            board[i][j] = ' ';
        }
    }
}
 