#include <cstdlib>
#include <ctime>
#include <iostream>
#include "Grammar.h"

Grammar::Grammar() {}


void Grammar::addProduction( const std::string & nonTerm, const std::string & rhs) {
  std::vector<std::string> list;
  if(map.count(nonTerm) == 1) {
    list = map[nonTerm];
  }
  list.push_back(rhs);
  map[nonTerm] = list;
}


std::string Grammar::getRandomRHS( const std::string & nonTerm ){
  std::string result;
  std::vector<std::string> vec = map[nonTerm];
  int num = std::rand() % vec.size();
  result = vec.at(num);
  return result;
}


bool Grammar::containsNonTerminal( const std::string & nonTerm) {
  if(map.find(nonTerm) == map.end()) {
    std::cout << "no nonterminal: " << nonTerm << "\n";
    return false;
  } 
  return true;
}

std::map<std::string, std::vector<std::string>> Grammar::getMap() {
  return map;
}

Grammar::~Grammar() {}