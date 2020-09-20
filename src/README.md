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

# User Commands:

In this program, the user is given 4 actions which they can choose to perform,
below are these actions:

 - Quit: The user should input 'q' to quit, this will cause history
  memory to be freed, print a goodbye message, and terminate the program.

 - Input a sentence to be added to the history: The user should input 'i' to
  input a sentence, the
  sentence will be printed back to the user, and added to the history.

 - Recalling a certain history: The user should input '!' followed by a
   sequence id number to recall a certain history. The program will then
   print the history with matching id. History ids start from 1.

 - Printing all histories: The user should input 'h' to view all histories. The program will then print all histories up to that point.
