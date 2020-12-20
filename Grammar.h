/*
Name: Dylan Zuber
Assignment: PA 5
Course/Semester: CS343/Fall2020
Lab Section: N/A
Sources consulted: N/A 

Description: holds the grammar rules of a given grammar. 

*/

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <map>
#include <vector>

#ifndef _GRAMMAR_H
#define _GRAMMAR_H

class Grammar {

public:
  // contains non-terminals as keys and their corressponding RHS as values
  std::map<std::string, std::vector<std::string>> map;

public:
  //constructor to create a grammar object 
  Grammar();

  /*
  Adds a production rule. Given a non terminal and right hand side a, this function will add the rhs to the existing rules for the non terminal or create a new non terminal with this RHS as its only rule
  @param nonTerm string containing the non-terminal
  @param rhs right hand side of corresponding non terminal 
  */
  void addProduction( const std::string & nonTerm, const std::string & rhs );


  /*
  Given a non terminal, returns a string that is a right hand side rule to the given non terminal
  @param nonTerm string representing a non terminal 
  @return string containing value 
  */
  std::string getRandomRHS( const std::string & nonTerm );


  /*
  Returns true if the given non terminal exists, false if not 
  @param nonTerm string containing possible non terminal
  */
  bool containsNonTerminal( const std::string & nonTerm );

  /*
  Returns map representation of grammar with non terminals as keys and rules
  as values 
  @return map representing grammar 
  */
  std::map<std::string, std::vector<std::string>> getMap();

  // destructor 
  ~Grammar();

};

#endif