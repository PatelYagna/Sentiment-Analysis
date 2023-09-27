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

void negativeConversion(vector<sentimentFile> sentimentVector,
                        vector<sentimentFile> negVec,
                        vector<string> &wordVector, string &text) {
  sentimentFile sentiment, negSentiment;
  int wordVectorSize = wordVector.size();
  int negVectorSize = negVec.size();
  int randIndex, wordIndex;
  srand(time(0));

  for (int i = 0; i < wordVectorSize; i++) {
    sentiment = theCalc(sentimentVector, 0, sentimentVector.size() - 1,
                        lower(wordVector[i]));
    if (sentiment.value > 1.0f) {
      randIndex = rand() % negVectorSize;
      negSentiment = negVec[randIndex];

      cout.width(20);
      cout << right << sentiment.word;
      cout << "\t";
      cout.width(4);
      cout << left << sentiment.value;
      cout.width(20);
      cout << right << negSentiment.word;
      cout << "\t";
      cout.width(4);
      cout << left << negSentiment.value;
      cout << endl;

      wordIndex = text.find(wordVector[i]);
      text.erase(wordIndex, wordVector[i].length());
      text.insert(wordIndex, negSentiment.word);
      wordVector[i] = negSentiment.word;
    }
  }
}

string lower(string word) {
  int length = word.length();
  for (int i = 0; i < length; i++) {
    word[i] = tolower(word[i]);
  }
  return word;
}

void outputFile(string &input, string text) {
  int periodIndex = input.find('.');
  input = input.substr(0, periodIndex) + "Output" +
          input.substr(periodIndex, input.length());
  ofstream outFS;
  outFS.open(input);
  if (outFS.is_open()) {
    outFS << text;
    outFS.close();
  }
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

void positiveConversion(vector<sentimentFile> sentimentVector,
                        vector<sentimentFile> posVec,
                        vector<string> &wordVector, string &text) {
  sentimentFile sentiment, posSentiment;
  int wordVectorSize = wordVector.size();
  int posVectorSize = posVec.size();
  int randIndex, wordIndex;
  srand(time(0));

  for (int i = 0; i < wordVectorSize; i++) {
    sentiment = theCalc(sentimentVector, 0, sentimentVector.size() - 1,
                        lower(wordVector[i]));
    if (sentiment.value < -1.0f) {
      randIndex = rand() % posVectorSize;
      posSentiment = posVec[randIndex];

      cout.width(20);
      cout << right << sentiment.word;
      cout << "\t";
      cout.width(4);
      cout << left << sentiment.value;
      cout.width(20);
      cout << right << posSentiment.word;
      cout << "\t";
      cout.width(4);
      cout << left << posSentiment.value;
      cout << endl;

      wordIndex = text.find(wordVector[i]);
      text.erase(wordIndex, wordVector[i].length());
      text.insert(wordIndex, posSentiment.word);
      wordVector[i] = posSentiment.word;
    }
  }
}

void printText(string &text) {
  int length = text.length();
  int newLineIndex = 0;
  for (int i = 80; i < length; i += 80) {
    while (text[i] != ' ') {
      i--;
    }
    text.erase(i, 1);
    text.insert(i, "\n");
  }
  cout << text;
}

sentimentFile theCalc(vector<sentimentFile> sentimentVector, int startIndex,
                      int endIndex, string searchWord) {
  int midPoint = (startIndex + endIndex) / 2;
  sentimentFile output;
  if (searchWord == sentimentVector[midPoint].word) {
    return sentimentVector[midPoint];
  } else if (startIndex == endIndex) {
    return output;
  } else if (searchWord < sentimentVector[midPoint].word) {
    return theCalc(sentimentVector, startIndex, midPoint, searchWord);
  } else if (searchWord > sentimentVector[midPoint].word) {
    return theCalc(sentimentVector, midPoint + 1, endIndex, searchWord);
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

void printSentimentVector(vector<sentimentFile> sentimentVector) {
  int size = sentimentVector.size();
  for (int i = 0; i < size; i++) {
    cout << sentimentVector[i].word << ", " << sentimentVector[i].value << endl;
  }
}

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
