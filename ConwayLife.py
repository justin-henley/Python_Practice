import time, random, copy

# Global constants for character representation and board size
LIVE_CHAR = '#'
DEAD_CHAR = ' '
WIDTH = 20
HEIGHT = 20

# Generates a new board of size WIDTH*HEIGHT
# In: Height and Width
# Out: Returns a 2D list representing a game board
def generateBoard():
    # Create empty list for the board
    newBoard = []
    # Create HEIGHT number of rows
    for y in range(HEIGHT):
        row = []
        # Generates WIDTH cells in each row
        for x in range(WIDTH):
            # Frequency of live cells at start is decided here
            # One site claims 37.5% live is optimal, test this yourself
            if random.randint(0,100) <= 37:
                row.append(LIVE_CHAR)
            else:
                row.append(DEAD_CHAR)

    #returns the filled board, which must be assigned
    return newBoard

# Prints the board
# In: a filled game board
def printBoard(gameBoard):
    # stub
    print('printBoard incomplete')

# Checks the board and generates the next turn's board
# In: current game board
# Out: returns the next frame of the game
def checkBoard(gameBoard):
    # stub
    return empty

# Decides whether a cell will be live or dead in the next frame
# In: the current board, and the coordinates of the cell in wuestion
# Out: Returns LIVE_CHAR or DEAD_CHAR
def checkCell(board, xpos, ypos):
    # stub
    return DEAD_CHAR

# Main program
def main():
    #stub
    print('Hello, world!')

# Begins the program
main()