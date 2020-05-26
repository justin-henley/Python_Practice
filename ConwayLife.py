import time, random, copy

# NOTE FOR UNDERSTANDING
# For the gameboards, represented as 2D lists
## The first index is the height, the y position
## The second index is the width, the x position

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
    #Iterate over each row(first index is the height)
    for y in range(HEIGHT):
        # Concatenate all values in the row into a string for easy printing
        rowString = ''
        #Iterate over each cell in the row (the width)
        for x in range(WIDTH):
            rowString += board[y][x]
        #Print the full row
        print(rowString)

# Checks the board and generates the next turn's board
# In: current game board
# Out: returns the next frame of the game
def checkBoard(gameBoard):
    # Copies the current board, easy than generating a new frame
    nextBoard = copy.deepcopy(gameBoard)

    # Iterate over each row (the height)
    for y in range(HEIGHT):
        # Iterate over each cell in the row (the width)
        for x in range(WIDTH):
            # Find the new value for this cell, and
            # assign it to the same position in the next board
            nextBoard[y][x] = checkCell(gameBoard, x, y)

    # return the new board, must be assigned
    return nextBoard

# Decides whether a cell will be live or dead in the next frame
# In: the current board, and the coordinates of the cell in wuestion
# Out: Returns LIVE_CHAR or DEAD_CHAR
def checkCell(board, xPos, yPos):
    # Track the total number of neighbors
    totalNeighbors = 0

    # Coordinates for the nieghbors
    # Modulo deals with edges, and wraps to the other edge
    rightPos = (xPos + 1) % WIDTH
    leftPos = (xPos - 1) % WIDTH
    upPos = (yPos - 1) % WIDTH  # Y-axis goes down due to printing
    downPos = (yPos + 1) % WIDTH

    # Lists to allow for looped checks of each neighbors
    # NOTE also checks the current cell, must be accounted for when deciding next state
    xAxis = [leftPos, xPos, rightPos]
    yAxis = [upPos, yPos, downPos]

    # Iterate over xAxis and yAxis and tally neighbors
    for i in range(len(yAxis)):
        for j in range(len(xAxis)):
            if board[yAxis[i]][xAxis[j]] == LIVE_CHAR:
                totalNeighbors += 1

    # Decide next state of the current cell based on rules and current cell status
    if board[yPos][xPos] == LIVE_CHAR:
        # Applies if current cell is alive
        # Middle cell is counted in neighbor tally, and must be removed
        totalNeighbors -= 1
        # Decide live or dead
        if totalNeighbors == 2 or totalNeighbors == 3:
            return LIVE_CHAR
        else:
            return DEAD_CHAR
    else:
        # Applies if current cell is dead
        if totalNeighbors == 3:
            return LIVE_CHAR
        else:
            return DEAD_CHAR

# Main program
def main():
    #stub
    print('Hello, world!')

# Begins the program
main()