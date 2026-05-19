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
        void makeComputerMove(char symbol, char opponentSymbol, int difficulty);
        bool checkWin();
        bool isFull();
        
};
