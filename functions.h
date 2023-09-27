#include <iostream>
#include <vector>
using namespace std;

struct sentimentFile {
  string word = "";
  float value = 0.0f;
};

// Pre: v1 is a vector of sentimentFile structs that contains words and their
// corresponding sentiment values. Post: Prints the words and sentiment values
// in v1 to the console.
//void printVector(vector<sentimentFile> const &v1);


// Pre: input is a string that contains text to be analyzed, posVector is a
// vector of sentimentFile structs that contains positive words and their
// corresponding sentiment values, negVector is a vector of sentimentFile
// structs that contains negative words and their corresponding sentiment
// values, sentimentVector is an empty vector of sentimentFile structs. Post:
// Calculates the sentiment value for each word in the input text and stores the
// word and its corresponding sentiment value in sentimentVector.
void sentVal(string input, vector<sentimentFile> &posVector,
             vector<sentimentFile> &negVector,
             vector<sentimentFile> &sentimentVector);

// Pre: input is a string that contains a file path to a text file.
// Post: Returns the contents of the text file as a string.
string importtext(string input);

// Pre: input is a string that contains text to be analyzed.
// Post: Returns the original input text.
string original(string input);

// Pre: text is a string that contains the text to be analyzed.
// Post: Returns a vector of words extracted from the input text.
vector<string> textWordVec(string text);

// Pre: wordVector is a vector of strings that contains words to be analyzed,
// sentimentVector is a vector of sentimentFile structs that contains words and
// their corresponding sentiment values. Post: Calculates the sentiment value
// for each word in wordVector using the sentiment values of words in
// sentimentVector and returns the overall sentiment value.
float sentCalc(vector<string> wordVector,
               vector<sentimentFile> sentimentVector);

// Pre: sentimentVector is a vector of sentimentFile structs that contains words
// and their corresponding sentiment values, startIndex is an integer that
// represents the starting index in the sentimentVector to search for the
// searchWord, endIndex is an integer that represents the ending index in the
// sentimentVector to search for the searchWord, searchWord is a string
// representing the word to search for in the sentimentVector. Post: Calculates
// the sentiment value for searchWord using the sentiment values of words in
// sentimentVector between startIndex and endIndex and returns a sentimentFile
// struct containing searchWord and its calculated sentiment value.
sentimentFile theCalc(vector<sentimentFile> sentimentVector, int startIndex,
                      int endIndex, string searchWord);

// Pre: sentimentVector is a vector of sentimentFile structs that contains words
// and their corresponding sentiment values. Post: Prints the words and
// sentiment values in sentimentVector to the console.
void printSentimentVector(vector<sentimentFile> sentimentVector);

// Pre: sentimentVector is a vector of sentimentFile structs that contains words
// and their corresponding sentiment values, negVec is a vector of sentimentFile
// structs that contains negative words and their corresponding sentiment
// values, wordVector is a vector of strings that contains words to be analyzed,
// text is a string that contains the text to be analyzed. Post: Replaces
// negative words in wordVector with their positive counterparts using negVec
// and updates the text with the replaced words.
void negativeConversion(vector<sentimentFile> sentimentVector,
                        vector<sentimentFile> negVec,
                        vector<string> &wordVector, string &text);

// Pre: sentimentVector is a vector of sentimentFile structs that contains words
// and their corresponding sentiment values, posVec is a vector of sentimentFile
// structs that contains positive words and their corresponding sentiment
// values, wordVector is a vector of strings that contains words to be analyzed,
// text is a string that contains the text to be analyzed. Post: Replaces
// positive words in wordVector
void positiveConversion(vector<sentimentFile> sentimentVector,
                        vector<sentimentFile> posVec,
                        vector<string> &wordVector, string &text);

// PRE: Takes in a reference to a string 'input' and a string 'text'
// POST: Outputs the contents of the string 'text' to a file with the name
// specified in 'input'
void outputFile(string &input, string text);

// PRE: Takes in a reference to a string 'text'
// POST: Prints the contents of the string 'text' to the console
void printText(string &text);

// PRE: Takes in a string 'word'
// POST: Returns a lowercase version of the input string 'word'
string lower(string word);
