#include <iostream>
#include "ConwayLife.h"

using namespace std;
using namespace justin_a_henley;

void analyzeLife(int numGames, int width, int height, int maxTurns, int liveRate);

int main() {
    cout << "Hello, World!" << endl;
    GameOfLife newGame;
    int t1 = newGame.visibleLife();
    cout << "\n\nTurns = " << t1;

    GameOfLife visibleGame(10, 10, 500, 37, '@', '-');
    int t2 = visibleGame.visibleLife();
    cout << "\n\nTurns = " << t2;

    analyzeLife(100, 20, 20, 10000, 80);
}

// Runs an analysis of lifespans over repeated random games
// todo should be a class inheriting?
void analyzeLife(int numGames, int width, int height, int maxTurns, int liveRate){
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