//
// Created by justin on 2020-05-26.
//

#ifndef CONWAYLIFE_CONWAYLIFE_H
#define CONWAYLIFE_CONWAYLIFE_H



#include <memory>
#include <vector>
#include <iostream>
#include <cstdlib>
#include <time.h>
#include <string>

using namespace std;

const double PAUSE_TIME = 0.1;  // Pause time between printing frames

namespace justin_a_henley {
    class GameOfLife {
    public:
        // Constructors
        GameOfLife();  // Uses default game size
        GameOfLife(int width, int height, int maxTurns, int liveRate, char liveChar, char deadChar);  // Allows custom specs
        GameOfLife(int width, int height, int maxTurns, int liveRate);

        // Member functions
        int visibleLife();
        int invisibleLife();

    private:
        // Game specs, overridden by non-default constructor
        int _width = 20; // Default board width
        int _height = 20; // Default board height
        int _maxTurns = 1000;  // Maximum number of turns before a game ends
        int _liveRate = 50;  // Out of 100, percent of cells alive
        char _liveChar = '#';
        char _deadChar = ' ';

        // Empty game board list pointer
        vector<vector<char>> _prevBoard;
        vector<vector<char>> _gameBoard;

        // private member functions
        void generateBoard();
        // Generates the gameboard with the appropriate size and characters
        // Precondition: _gameBoard has not been given any values
        // Postcondition:  _gameBoard has been filled

        void printBoard();
        // Prints the current gameBoard
        // Precondition:  The board has been generated
        // Postcondition:  The board is printed to std::cout

        void checkBoard();
        char checkCell(int yPos, int xPos);
        bool boardAlive();
    };
}


#endif //CONWAYLIFE_CONWAYLIFE_H
