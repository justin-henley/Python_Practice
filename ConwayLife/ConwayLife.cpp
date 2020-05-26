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

        // Duplicate _gameBoard to _prevBoard to set the size correctly
        _prevBoard = _gameBoard;
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

    // Generates the next frame of the gameboard
    // Precondition: _prevBoard and _gameBoard have both been generated
    // Postcondition: _prevBoard holds the last frame, and _gameBoard holds the new frame
    void GameOfLife::checkBoard() {
        // Switch _gameBoard to _oldBoard, _gameBoard will overwrite the new frame
        _gameBoard.swap(_prevBoard);

        // Iterate over each row (height)
        for (int y = 0; y < _height; y++){
            // Iterate over each cell in the row
            for (int x = 0; x < _width; x++){
                _gameBoard[y][x] = checkCell(y, x);
            }
        }
    }

    // Decides if a cell is alive or dead in the next frame
    // Precondition: yPos and xPos are valid locations within _prevBoard and _gameBoard
    // Postcondition: returns the state of the cell in the next frame
    char GameOfLife::checkCell(int yPos, int xPos) {
        // Track the total number of neighbors
        int totalNeighbors = 0;

        // Coordinates for the neighbors
        // Modulo deals with edges, and wraps to the other edge
        int rightPos = (xPos + 1) % _width;
        int leftPos = (xPos - 1) % _width;
        int upPos = (yPos - 1) % _width; // Y-axis goes down to due printing
        int downPos = (yPos + 1) % _width;

        // Vector of positions allows for looped checks of each neighbor
        // NOTE also checks the current cell, must be accounted for when deciding status
        vector<int> xAxis = {leftPos, xPos, rightPos};
        vector<int> yAxis = {upPos, yPos, downPos};

        // Iterate over yAxis and xAxis and tally neighbors
        for (int y : yAxis){
            for (int x : xAxis){
                if(_prevBoard[y][x] == _liveChar)
                    totalNeighbors++;
            }
        }

        // Decide next state of current cell based on rules and current cell state
        // Applies if current cell is alive
        if(_prevBoard[yPos][xPos] == _liveChar){
            // Middle cell is counted in neighbor tally, and must be removed
            totalNeighbors--;

            // Decide if live or dead next
            if ((totalNeighbors == 2) || (totalNeighbors == 3))
                return _liveChar;
            else
                return _deadChar;
        }
        // Applies if current cell is dead
        else{
            if(totalNeighbors == 3)
                return _liveChar;
            else
                return _deadChar;
        }
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