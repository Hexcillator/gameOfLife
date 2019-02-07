# gameOfLife

Game of Life 

The game of life is a zero player game created by the British mathematician John Horton Conway in 1970.
It consists in an infinite two-dimensional grid populated by cells that evolve according to certain rules.
Each cell has 8 neighbours horizontally, vertically, or diagonally adjacent, and their life on the next iteration depend on the following rules:
•	No interactions: When there are no live cells then in the next iteration there are still not live cells
•	Underpopulation: When a live cell has fewer than 2 live neighbours then it dies
•	Overcrowding: When a live cell has more than 3 neighbours it also dies
•	Survival: When a live cell has 2 or 3 neighbours the cell stays alive
•	Creation of Life: When a dead cell has exactly 3 lice cell neighbours a new live cell is created in its position

Instructions for my version of the game

Once running the app there is a welcome screen giving the option to start the game by pressing 1 in the keyboard.
Once starting the game we can see the cells interacting with each other.
Each cell is 10px in size but they can be either zoomed in or out by using the slider in the top left of the screen.
To restart the game press the “R” key.
To clear the grid press “C” key
To quit to the welcome screen press “Q” key
Have fun!
 

Assumptions about the problem and possible issues


•	It is a game I had seen before but had not tried developing it 
•	The game is meant to be an infinite two dimensional grid but I will use a limited number of element in a 2-dimensional array.
•	If it is a game it is probably expected to have a title screen where we can somehow activate the game.
•	There is no specification about the size of the grid or its cells so in this case the grid goes as big as 1024,768px
•	As being a zero player game its initial state should have a random seeded grid
•	The stroke of the squares (if we want to see the grid) can be a problem if trying to have a 1px cell
•	To make it an infinite grid we might need to wrap the beginning of the grid to the end in both the y and x axis
•	The game can have some additional functionality such as clear grid, repopulate and quit
More details in code comments

Patricio Ordonez P.

