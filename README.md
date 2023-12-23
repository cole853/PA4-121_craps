# PA4-121_craps

A game of craps for CPTS 121 programming assignment 4. Completed on 10/11/2020.

This game of craps is for a single player. The rules are displayed at the beginning of the game. A starting amount is put in by the player along with a bet amount on each roll. If the bet is more than the bank balance the player will need to put in an acceptable bet amount.
Dice are rolled and summed in order to determine whether the roll won, lost, or neither.

# Three files are required:

craps.h: contains declarations for functions defined in craps.c

craps.c: contains definitions for functions declared in craps.h

main.c: contains the main function where outputs are printed in the terminal and user input is taken from the terminal.

# Possible improvements

Currently this game will only continue until there is a win or loss. This could be modified to continue until the player quits or their bank balance goes to 0.

bank balance could also be shown after every roll.
