#include <iostream>
#include "ConwayLife.h"

using namespace std;
using namespace justin_a_henley;

void analyzeLife(long numGames, int width, int height, long maxTurns, int liveRate);

int menu();

GameOfLife customInput();

void analysisInput();

int main() {
    // Seed the random number generator once
    srand(time(NULL));

    // Menu
    int choice = 1;

    // Would be better done with regex for user input
    while ((choice < 4) && (choice > 0)){
        choice = menu();

        switch (choice) {
            case 1:  // Default visible game
            {
                GameOfLife defaultGame;
                int dTurns = defaultGame.visibleLife();
                cout << "\n\nTurns = " << dTurns << endl;
                break;
            }
            case 2:  // Custom visible game
            {
                GameOfLife customGame = customInput();
                int cTurns = customGame.visibleLife();
                cout << "\n\nTurns = " << cTurns << endl;
                break;
            }

            case 3: // Runs a custom analysis of multiple games
            {
                analysisInput();
                break;
            }

            default:
                break;
        }
    }



}

// Runs an analysis of lifespans over repeated random games
// todo should be a class inheriting?
void analyzeLife(long numGames, int width, int height, long maxTurns, int liveRate){
    // Variables for tracking
    long sumTurns = 0;
    long maxLifespan = 0;
    long minLifespan = maxTurns;

    // Runs numGames number of games and records turns survived
    for (int round = 0; round < numGames; round++){
        // Run a new game
        GameOfLife life(width, height, maxTurns, liveRate);
        int lifespan = life.invisibleLife();

        //track new game
        sumTurns += lifespan;
        // Check if new max or min lifespan
        if (lifespan > maxLifespan){
            maxLifespan = lifespan;
        }
        if (lifespan < minLifespan){
            minLifespan = lifespan;
        }
        // Display the lifespan of each round
        cout << "Round " << round << ": " << lifespan << " turns" << endl;
    }

    // Prints analysis after all games have finished
    double averageTurns = static_cast<double>(sumTurns) / static_cast<double>(numGames);
    cout << "\n\n\nMax lifespan: " << maxLifespan << endl;
    cout << "Min lifespan: " << minLifespan << endl;
    cout << "Avg lifespan: " << averageTurns << endl;
}

int menu(){
    cout << "\n Conway's Game of Life:";
    cout << "\n1. Run a default game";
    cout << "\n2. Run a custom game";
    cout << "\n3. Run an analysis over repeated games";
    cout << "\n4. Exit\n\n";
    cout << "Choice: ";

    int choice;
    cin >> choice;
    return choice;

}

GameOfLife customInput(){
    // variables for creating new GameOfLife object
    // Would be safer with regex and prompting for single variables, but fast this way for practice
    int height, width, maxTurns, liveRate;
    char liveChar, deadChar;

    // Prompt for input
    cout << "\n\nPlease enter integer values separated by spaces\n";
    cout << "Height width maxTurns liveRate\n";
    cin >> height >> width >> maxTurns >> liveRate;
    cout << "\nPlease enter the live and dead characters separated by a single space:";
    cin >> liveChar >> deadChar;

    // Create the new object
    GameOfLife customLife(width, height, maxTurns, liveRate, liveChar, deadChar);
    return customLife;
}

void analysisInput(){
    // variables for creating new GameOfLife object
    // Would be safer with regex and prompting for single variables, but fast this way for practice
    int height, width, maxTurns, liveRate, numGames;

    // Prompt for input
    cout << "\n\nPlease enter integer values separated by spaces\n";
    cout << "Height width maxTurns liveRate\n";
    cin >> height >> width >> maxTurns >> liveRate;
    cout << "\nPlease enter the maximum number of games as an integer";
    cin >> numGames;

    // Call the analysis
    analyzeLife(numGames, width, height, maxTurns, liveRate);
}