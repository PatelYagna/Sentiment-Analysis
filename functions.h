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
