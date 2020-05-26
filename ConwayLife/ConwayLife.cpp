//
// Created by justin on 2020-05-26.
//
#include "ConwayLife.h"

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

    // Generates the gameboard with the appropriate size and characters
    // Precondition: _gameBoard has not been given any values
    // Postcondition:  _gameBoard has been filled
    void GameOfLife::generateBoard() {
        // todo figure out pointer type



        // Seed the random number generator for the gameBoard
        srand(time(NULL));

        // Generates random values for each cell
        // Iterate over each row
        for(int y = 0; y < _height; y++) {
            vector<char> row;
            // Iterate over each cell in the row
            for(int x = 0; x < _width; x++) {
                // A random score between 1 and 100
                int lifeScore = rand() % 100 + 1;
                // Decide if score meets life requirements
                if (lifeScore <= _liveRate)
                    row.push_back(_liveChar);
                else
                    //_gameBoard[y][x] = _deadChar;
                    row.push_back(_deadChar);
            }
            //Add the new row to the vector
            _gameBoard.push_back(row);
        }
    }

    // Prints the current gameBoard
    // Precondition:  The board has been generated
    // Postcondition:  The board is printed to std::cout
    void GameOfLife::printBoard() {
        // Iterate over each row in the vector
        for (int y = 0; y < _height; y++){
            // Create a string to print out the row
            string row = "";
            // Iterate over each cell in the row
            for (int x = 0; x < _width; x++){
                row.push_back(_gameBoard[y][x]);
            }
            // Print the row
            cout << row << endl;
        }
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
        printBoard();
        return 0;
        // todo this is a stub
    }

    int GameOfLife::invisibleLife() {
        return 0;
    }
}