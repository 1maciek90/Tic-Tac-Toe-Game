#pragma once

class Board {
    private:
        int size;
        char** board;


    public:
        Board(int size);
        ~Board();
        void drawBoard();
        void createBoard();
        void makeMove();
        bool checkWin();
        bool isFull();
        
};
