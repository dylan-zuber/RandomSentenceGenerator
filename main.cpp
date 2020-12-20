/*
Name: Dylan Zuber
Assignment: PA 5
Course/Semester: CS343/Fall2020
Lab Section: N/A
Sources consulted: N/A 

Description: Main class driving the program. Creates RandomSentenceGenerator object with from file passed in from command line arguments and calls functions to give correct output (prints grammar and prints 3 randomly generated sentences).

Also, I believe the medieval.g file is in the incorrect format. Each variable ends with a semicolon which is how I differentiated between a variable and a rule.

*/

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <stdlib.h>
#include <thread>
#include <chrono>
#include <ctime>
#include "RandomSentenceGenerator.h"
#include "Grammar.h"


int main(int argc, char* argv[]) {
  std::string line = argv[1];
  std::srand(std::time(nullptr)); // creates random seed
  // Creates RandomSentenceGenerator with file specified in command line argument
  RandomSentenceGenerator rsg{ line };
  
  //Prints grammar
  rsg.printGrammar();

  // Prints 3 randomly generated sentences
  std::cout << rsg.randomSentence() << std::endl;
  std::cout << rsg.randomSentence() << std::endl;
  std::cout << rsg.randomSentence() << std::endl;
  
}
