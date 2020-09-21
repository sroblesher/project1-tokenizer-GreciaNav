Project 1: Tokenizer
====================
# Overview:

This project consists of building a tokenizer that maintains a history. This
was done by implementing various classes, such as a tokenizer and history
class. The tokenizer class has all functions needed to
tokenize user input, and the history class has methods to keep track of the
input history.

The program has a simple UI which shows possible options the user can choose
from, these include:
 - Quitting the program.
 - Inputting a sentence.
 - Recalling a certain history.
 - Printing all histories.

# How to Compile and Run:

  1. Inside the src, type 'make'. An executable named "tokenizer" will be
  generated.
  2. Type './tokenizer' to run the program.

# Input Commands:

In this program, the user is given 4 actions which they can choose to perform,
below are these actions:

 - **'q'** Quit: The user should input **'q'** to quit, this will cause history
  memory to be freed, print a goodbye message, and terminate the program.

 - **'i'** Input a sentence to be added to the history: The user should input **'i'** to
  input a sentence, they will then be asked to input the sentence and it will
  be printed back to them.Input will then be added to the history.

 - **'!'** Recalling a certain history: The user should input **'!'** followed by a
   sequence id number to recall a certain history. The program will then
   print the history with matching id. History ids start from 1.

 - **'h'** Printing all histories: The user should input **'h'** to view all histories. The program will then print all histories up to that point.
