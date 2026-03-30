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
        void makeMove(char symbol);
        bool checkWin();
        bool isFull();
        
};
