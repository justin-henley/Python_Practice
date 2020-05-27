#include <iostream>
#include "ConwayLife.h"

using namespace std;
using namespace justin_a_henley;

void analyzeLife(long numGames, int width, int height, long maxTurns, int liveRate);

int main() {
    // Seed the random number generator once
    srand(time(NULL));

    cout << "Hello, World!" << endl;
    GameOfLife newGame;
    int t1 = newGame.visibleLife();
    cout << "\n\nTurns = " << t1 << endl;

    GameOfLife visibleGame(10, 10, 500, 37, '@', '-');
    int t2 = visibleGame.visibleLife();
    cout << "\n\nTurns = " << t2 << endl;

    // TODO loop the analysis request for repeated use
    // TODO Clean up interface

    // Variables for storing request
    int width, height, liveRate;
    long maxTurns, numGames;
    cout << "Enter values separated by spaces:" << endl << "Width, height, maximum turns, live rate, number of games" << endl;
    cin >> width >> height >> maxTurns >> liveRate >> numGames;
    analyzeLife(numGames, width, height, maxTurns, liveRate);
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