#include <iostream>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <utility>
#include <sstream>
#include <string>
#include <algorithm>
#include <regex>
#include <iterator>
#include <cctype>
#include "RandomSentenceGenerator.h"
#include "Grammar.h"


Grammar grammar;

RandomSentenceGenerator::RandomSentenceGenerator( const std::string & filename ){
  std::ifstream inStream(filename, std::ios::in);
  if( !inStream.is_open() ) {
    std::cout << "Failed to open: " << filename << "\n";
  } else {
    while(inStream.good()) {
      std::string begin;
      std::getline(inStream, begin);
      if(begin.length() == 0 || begin.at(0) != '{') continue;
      break;
    }
    std::string line;
    std::string nonTerminal;
    bool startNonTerminal = true;
    bool sameLine = false;
    while( inStream.good() ) {
      std::getline(inStream, line);
      std::istringstream iss(line);
      std::string word;
      std::string result = "";
      while(iss >> word) {
        if(word == "{" || word == "}") {
          startNonTerminal = true;
          break;
        }
        if(word.at(0) == '<' && word.at(word.at(word.length() - 1) == '>') && startNonTerminal) {
          nonTerminal = word;
          std::transform(nonTerminal.begin(), nonTerminal.end(), nonTerminal.begin(), [](unsigned char c){ return std::tolower(c); });
          startNonTerminal = false;
          continue;
        }
        if(word == ";"){
          sameLine = false;
          continue;
        }
        if(word.at(word.length() - 1) == ';') {
          word = word.substr(0, word.length() - 1);
        }
        if(sameLine) {
          result = result + " " + word;
        } else {
          result = word;
        }
        sameLine = true;
      }
      if(result == " " || result == "") continue;
      grammar.addProduction(nonTerminal, result);
    }
  }
}


std::string RandomSentenceGenerator::randomSentence(){

  std::vector<std::string> start = grammar.map["<start>"];

  std::string begin = start.at(0);
  for(int i = 1; i < start.size(); i++) {
    begin = begin + " " + start.at(i);
  }

  int i = 0, j = 1;
  while(i < begin.length()) {
    if(begin.at(i) == '<') {
      j = i;
      while(begin.at(j) != '>') {
        j++;
        if(begin.at(j) == '>') {

          std::string replace = begin.substr(i, j - i + 1);

          std::transform(replace.begin(), replace.end(), replace.begin(), [](unsigned char c){ return std::tolower(c); });

          begin.replace(i, replace.length(), grammar.getRandomRHS(replace));

          i--;
          break;
        }
      }
    }
    i++;
  }
  return begin;
}


void RandomSentenceGenerator::printGrammar() {
  std::map<std::string, std::vector<std::string>> map = grammar.getMap();
  for(std::map<std::string, std::vector<std::string>>::iterator ii=map.begin(); ii != map.end(); ii++){
    std::cout << (*ii).first << ": ";
    std::vector<std::string> vect = (*ii).second;
    for(unsigned j=0; j<vect.size(); j++) {
      if(j == vect.size() - 1){
        std::cout << vect[j];   
      } else {
        std::cout << vect[j] << ", ";
      }
      
    } 
    std::cout << std::endl;
  }
}




