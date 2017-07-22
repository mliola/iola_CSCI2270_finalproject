# iola_CSCI2270_finalproject

Phase 1: Description
Create a logic circuit program using graphs. It will get built from a parsed .txt file in and generate a graph of all of the logical nodes as well as the initial
conditions as described by the .txt. The program will contain 2 main funtions: simulate, which is given parameters a and b as either true or false and runs through
the logic circuit, either successfully (returning true) or not (returning false), and satisfy, which asks the user to provide the desired outcome of the circuit and
checks for solutions. Satisfy can often fail to find a solution for certain circuits and returns false. Satisfy's implementation involves both a stack and a queue
to solve, as they serve as user created memory banks when the logical guesses the program makes to solve fail and it has to regress. When is has a regression error
on level 0 of the stack it returns false as it has failed to find a solution past the lowest level of gates in the circuit. This overall program will also contain
many auxiliary functions used by the main two.
