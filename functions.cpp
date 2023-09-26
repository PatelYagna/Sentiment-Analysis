#include "functions.h"
#include <cstring>
#include <fstream>
#include <iostream>
#include <random>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

/*void printVector(vector<sentimentFile> const &v1) {
  for (int i = 0; i < v1.size(); i++)
    cout << v1[i].word << " " << v1[i].value << endl;
}*/

string original(string input) {
  ifstream inFS;
  string inStr, output = "";
  int newlinePos;

  inFS.open(input);
  if (inFS.is_open()) {
    while (inFS.good() && inFS.eof() == false) {
      getline(inFS, inStr);
      if (inStr.length() == 1) {
        continue;
      }
      output += inStr + "\n";
    }
    inFS.close();
  } else {
    throw runtime_error("Error: Unable to open file.");
  }
  return output;
}

float sentCalc(vector<string> wordVector,
               vector<sentimentFile> sentimentVector) {
  float output = 0.0f;
  int size = wordVector.size();
  for (int i = 0; i < size; i++) {
    output += theCalc(sentimentVector, 0, sentimentVector.size() - 1,
                      lower(wordVector[i]))
                  .value;
  }
  return output;
}

vector<string> textWordVec(string text) {
  vector<string> wordVector;
  int wordLength;
  string word;

  stringstream SS(text);
  while (SS >> word) {
    wordLength = word.length();
    for (int i = 0; i < wordLength; i++) {
      if (ispunct(word[i]) && word[i] != '\'') {
        word.erase(i, 1);
        wordLength--;
        i--;
      }
    }
    wordVector.push_back(word);
  }
  return wordVector;
}

string importtext(string input) {
  ifstream inFS;
  string inStr, output = "";

  try {
    inFS.open(input);
    if (inFS.is_open()) {
      while (inFS.good() && inFS.eof() == false) {
        inFS >> inStr;
        output += inStr + " ";
      }
      inFS.close();
    } else {
      throw runtime_error("Error: Unable to open file.");
    }
    return output;
  } catch (runtime_error e) {
    cout << e.what() << endl;
  }
}


void sentVal(string input, vector<sentimentFile> &posVector,
             vector<sentimentFile> &negVector,
             vector<sentimentFile> &sentimentVector) {
  ifstream inFS;
  string inStr, sentimentStr;
  float sentimentFloat;
  int commaIndex;
  sentimentFile SentimentValue;

  inFS.open(input);
  if (inFS.is_open()) {
    while (inFS.good() && inFS.eof() == false) {
      getline(inFS, inStr);
      commaIndex = inStr.find(',');
      sentimentStr = inStr.substr(0, commaIndex);
      sentimentFloat = stof(inStr.substr(commaIndex + 1, inStr.length()));

      SentimentValue.word = sentimentStr;
      SentimentValue.value = sentimentFloat;

      if (SentimentValue.value < -1.5f)
        negVector.push_back(SentimentValue);
      if (SentimentValue.value > 1.5f)
        posVector.push_back(SentimentValue);
      sentimentVector.push_back(SentimentValue);
    }
    inFS.close();
  }
}
