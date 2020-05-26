//
// Created by justin on 2020-05-26.
//

#include "ConwayLife.h"
#include <memory>
#include <vector>
#include <iostream>
#include <cstdlib>
#include <time.h>

using namespace std;

const int HEIGHT = 20;
const int WIDTH = 20;
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
        int _width = WIDTH;
        int _height = HEIGHT;
        int _maxTurns = 1000;  // Maximum number of turns before a game ends
        int _liveRate = 50;  // Out of 100, percent of cells alive
        char _liveChar = '#';
        char _deadChar = ' ';

        // Empty game board list pointer
        // todo vector<vector<char>> prevBoard;
        // todo shared_ptr<>> gameBoard;
        vector<vector<char>> _prevBoard;
        vector<vector<char>> _gameBoard;

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
        // Generate the new game board
        generateBoard();
    }

    GameOfLife::GameOfLife(int width, int height, int maxTurns, int liveRate, char liveChar, char deadChar) {
        // Initialize private member variables with arguments
        _width = width;
        _height = height;
        _maxTurns = maxTurns;
        _liveRate = liveRate;
        _liveChar = liveChar;
        _deadChar = deadChar;

        // Generate the new game board
        generateBoard();
    }

    // Destructor todo

    void GameOfLife::generateBoard() {
        // todo figure out pointer type

        // Resizes the gameboard to spec if not default
        if ((_height != HEIGHT) || (_width != WIDTH)){
            _gameBoard.resize(_height);
            for(int y = 0; y < _height; y++ ){
                (_gameBoard.at(y)).resize(_width);
            }
        }

        // Seed the random number generator for the gameBoard
        srand(time(NULL));

        // Generates random values for each cell
        // Iterate over each row
        for(int y = 0; y < _height; y++) {
            // Iterate over each cell in the row
            for(int x = 0; x < _width; x++) {
                // A random score between 1 and 100
                int lifeScore = rand() % 100 + 1;
                // Decide if score meets life requirements
                if (lifeScore <= _liveRate)
                    _gameBoard[y][x] = _liveChar;
                else
                    //_gameBoard[y][x] = _deadChar; todo should be at or []?
                    (_gameBoard.at(y)).at(x) = _deadChar;
            }
        }
    }

    // Prints the current gameBoard
    // Precondition:  The board has been generated
    // Postcondition:  The board is printed to std::cout
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