Tower of Hanoi Game
This is a simple console-based Tower of Hanoi game implemented in C++ using stacks and linked lists. The game allows the player to move disks between three towers while following the rules of the Tower of Hanoi puzzle. The goal is to move all disks from the first tower to the third tower in the fewest moves possible.

Features:
Interactive gameplay where the player can move disks between towers.
Validation to prevent placing larger disks on top of smaller disks.
Displays the current state of the towers after every move.
Includes a winning condition that congratulates the player after solving the puzzle.
Option to exit the game mid-way if the player decides not to continue.
How to Play:
The game starts with three disks ('A', 'B', 'C') on Tower 1.
The player can choose from the following moves:
Move the top disk from Tower 1 to Tower 2 or 3.
Move the top disk from Tower 2 to Tower 1 or 3.
Move the top disk from Tower 3 to Tower 1 or 2.
The objective is to move all disks to Tower 3 while following the rules:
Only one disk can be moved at a time.
A larger disk cannot be placed on top of a smaller disk.
The game ends when all disks are successfully moved to Tower 3 or when the player exits the game.
Usage:
Clone the repository to your local machine.
Compile the C++ code using a C++ compiler (e.g., g++ tower_of_hanoi.cpp -o tower_of_hanoi).
Run the compiled program (./tower_of_hanoi) to start the game.
