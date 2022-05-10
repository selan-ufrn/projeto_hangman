# Contents

- [Introduction](#introduction)
- [Gameplay](#gameplay)
- [Running](#running)
# Introduction

This programming project implements a simple text-based version of the game Keno.
Keno is a popular gambling game with similarities to a lottery or bingo.
Players place a bet and pick a set of numbers between 1 and 80, inclusive.
The number of numbers chosen can be anywhere from one to twenty, with each having
a different payoff scale.
Once the players have chosen their numbers, twenty random numbers between 1 and 80
are chosen, and players receive a payoff based on how many numbers they picked that
matched the chosen numbers.

For example, if a player picked five numbers and all five were chosen, she might
win around $1,000 for a one- or two-dollar bet.
The actual payoffs are based on the probabilities of hitting k numbers out of n
chosen, but this is irrelevant for our discussion.


# Gameplay

The game should read the player's bet from a ascii file.
The bet file should contain 3 valid lines, in this order:

- **IC**: the total amount of money the player wishes to bet;
- **NR**: the number of rounds the player wants to run, and;
- **SP**: the chosen numbers, or *spots*.

The input file may have blank lines in any order and leading spaces
in any line.

After reading, and validating a bet file, the game displays on the
screen the total amount, the number of rounds, and the *payout table*.
The payout table takes is defined considering the number of *spots* the player has chosen.

Next, the game runs for **NR** rounds, waging in each round $(**IC**/**NR**) dollars.
For each round the game randomly picks 20 winning numbers or *hits* and display them on the screen.
The player's bet numbers are compared to the *hits* to dermine how many of them match.
The corresponding payout factor is multiplied by the round's wage to determine wheter
the player wins or loses money.

Finally, the game displays on the screen a summary of the game, showing the total
amount of money the player won/lost after all rounds are completed.

# Runnig

To run the game use the following sintax:

    $ ./keno bet_file.dat

Where `bet_file.dat` is a valid ascii file with 3 valid lines, as described [here](#Gameplay).
