/*
Name: Dylan Zuber
Assignment: PA 5
Course/Semester: CS343/Fall2020
Lab Section: N/A
Sources Consulted: (Source #1) https://stackoverflow.com/questions/18362896/printing-the-vector-in-a-map, (Source #2) https://stackoverflow.com/questions/313970/how-to-convert-stdstring-to-lower-case

Description: program takes in a string for a file containing a set of grammar rules. With that set of grammar rules, the program
will be able to develop randomly generated sentences.

*/

#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Grammar.h"
#ifndef _RandomSentenceGenerator_H
#define _RandomSentenceGenerator_H

class RandomSentenceGenerator {


private:
  Grammar grammar; //contains all of the grammar rules

public:

/*
Given a file name, this will create a RandomSentenceGenerator object that contains a grammar object within it that allows a user to randomly generate sentences.
@param filename string containing name of file with grammar rules
*/
RandomSentenceGenerator( const std::string & filename );

/*
When called, returns a string that represents a randomly generated sentence based on the given grammar object.
*/
std::string randomSentence();

// Prints the rules of the grammar contained within the grammar object
void printGrammar();

};



#endif