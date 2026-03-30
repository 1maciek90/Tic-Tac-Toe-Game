#pragma once

class Board {
    private:
        char board[3][3];


    public:
        Board();
        void drawBoard();
        void makeMove();
        bool checkWin();
        bool isFull();
        
};
