//
// Created by justin on 2020-05-26.
//

#include "ConwayLife.h"


const double PAUSE_TIME = 0.1;  // Pause time between printing frames
typedef char* charPtr;

namespace justin_a_henley {
    class GameOfLife {
    public:
        // Constructors
        GameOfLife();  // Uses default game size
        GameOfLife(int width, int height, int maxTurns, int liveRate, char liveChar, char deadChar);  // Allows custom specs

        // Destructor TODO

        // Member functions
        int visibleLife();
        int invisibleLife();

    private:
        // Game specs, overridden by non-default constructor
        int _width = 20;
        int _height = 20;
        int _maxTurns = 1000;  // Maximum number of turns before a game ends
        int _liveRate = 50;  // Out of 100, percent of cells alive
        char _liveChar = '#';
        char _deadChar = ' ';
        // Empty game board list pointer
        char* prevBoard = nullptr;
        char* gameBoard = nullptr;
        // private member functions
        void generateBoard();
        void printBoard();
        void checkBoard();
        char checkCell(int yPos, int xPos);
        bool boardAlive();
    };
}

namespace justin_a_henley {
    GameOfLife::GameOfLife() {
        //todo
    }

    GameOfLife::GameOfLife(int width, int height, int maxTurns, int liveRate, char liveChar, char deadChar) {
        _width = width;
        _height = height;
        _maxTurns = maxTurns;
        _liveRate = liveRate;
        _liveChar = liveChar;
        _deadChar = deadChar;
        //todo
    }

    // Destructor todo

    void GameOfLife::generateBoard() {
        return;
    }

    void GameOfLife::printBoard() {
        return;
    }

    void GameOfLife::checkBoard() {
        return;
    }

    char GameOfLife::checkCell(int yPos, int xPos) {
        return '?';
    }

    bool GameOfLife::boardAlive() {
        return false;
    }

    int GameOfLife::visibleLife() {
        return 0;
    }

    int GameOfLife::invisibleLife() {
        return 0;
    }
}