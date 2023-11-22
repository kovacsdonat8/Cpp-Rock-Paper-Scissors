# Cpp-Rock-Paper-Scissors

## An extended rock-paper-scissors game
Designed object model for modeling the rock-paper-scissors game! Our goal is to determine the best strategy, if any, by drawing lots of players playing with different strategies.

## Game rules
Rock-paper-scissors is played by two players. Players choose one shape at a time (rock, paper or scissors). The object of the game is to choose a shape that knocks out the one chosen by the other player. The rock wears out the scissors, the scissors cuts the paper, the paper wraps the stone. If both chose the same, the result of the round is a tie.

The extended version of the game is rock-paper-scissors-lizard-Spock, with possible winning outcomes as follows:
![kép](https://github.com/kovacsdonat8/Cpp-Rock-Paper-Scissors/assets/114249590/8ff1089d-99f2-4653-81fe-c143982ed3c8)
The game ends when someone reaches the predetermined amount of wins.

## Players
The game can be played by two players, either human or computer. In the case of the computer, several strategies can be selected (e.g.: random, using the opponent's previous moves, etc.). By default, humans play against the machine's random strategy.

## Menu
The program works in English and in character mode.
### 1. Play
### 2. Options
  1. Game Type – rock-paper-scissors or rock-paper-scissors-lizard-Spock (default: rock-paper-scissors)
  2. Game Mode – Step by step, Simulation or Tournament (default: Step by step)
  3. Game length - how long should a game last (default: up to 20 wins)
  4. Player 1 Name: Player 1 – setting the name of the first player, not displayed in tournament mode (default: Player 1)
  5. Player 1 Type: Human – first player type setting, not displayed in tournament mode
  6. Player 2 Name: Player 2 – setting the name of the second player, not displayed in tournament mode (default: Player 2)
  7. Player 2 Type: Computer Strategy 1 – second player type setting, not displayed in tournament mode
  0. Main Menu – return to the main menu
### 3. Rules - displaying game rules
### 0. Exit - exit from the game

## Gameplay
### Step by step
In this game mode, a game can be played one step at a time. This is the only mode where you can play against the computer. The program asks the player for the shape number at each step. And if you are playing on a computer, the step is done by pressing Enter.
### Simulation
In this game mode, you can automatically run through an entire game without stepping. In the simulation, only computer can play against computer.
### Tournament
In this game mode, you can simulate an entire tournament of different computer strategies without stepping and display a statistic about it.
If the game session reaches the 100th game due to many draws, it will end there and the player with the most wins until then wins the session. If they have the same number of wins, the result will be a draw.
The program can be expanded later with new algorithms as desired.

## Plan
The task presents the object-oriented design of a program in a UML diagram.
The program contains the following classes, their relationships and attributes:
![kép](https://github.com/kovacsdonat8/Cpp-Rock-Paper-Scissors/assets/114249590/b38723c5-e532-4d73-b043-64917026bfab)

## Algorithms
Description of the algorithms of the three strategies in the task:
### Random Strategy:
A random number is generated from 0 to 2 or from 0 to 4 (depending on the game type) and the algorithm returns the number that represents the number of a shape.
### Copy Strategy:
In the first step, it randomly generates a number from 0 to 2 or 0 to 4 (depending on the game type) and returns that number, then the algorithm stores the number of the opponent's shape at each step and returns it in the next step.
### Clever Strategy:
At the first step, it randomly generates a number from 0 to 2 or from 0 to 4 (depending on the game type) and returns that number, then from the second step, by calculating the frequency of the last move combination, it returns the shape that is the opponent's biggest defeats your likely move.

Description of the algorithm that scores the performance of the players in the tournament:
After a simulated game, the algorithm gives the winner 2 points and the loser 0 points. In case of a draw, both players get 1 point each. Thus, at the end of the championship, we get statistics about the winning probability of the given strategies through the points.

## Implementation
Solving the task required the preparation of 14 classes and a test program. The final interface of the classes differs slightly from the way defined in the design step. It differs from the design part in that it was mainly set and get, but I also created more new functions, which were only needed as I developed the program. The testing process remained the same as the test program created in Skeleton. Furthermore, my assignment does not contain tools from the STL library.
When adding a new player or rule, it must be created as a new derived class from the base class, and then override the corresponding virtual functions. Furthermore, the new player or rule must be added to the App class as a function of CreateGame (AddPlayer / AddRule) and from then on it will be displayed and used automatically.
