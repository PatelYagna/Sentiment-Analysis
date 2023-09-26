#include "functions.h"
#include <iostream>

using namespace std;

int main() {
  vector<sentimentFile> positive, negative, sentiment;
  vector<string> wordVector;
  string input, text, orignal;
  char choice, loop = 'Y';
  sentVal("sentiment.txt", positive, negative, sentiment);

  while (toupper(loop) == 'Y') {
    cout << endl << endl << "Enter the name of the input file to use: ";
    cin >> input;
    text = importtext(input);
    orignal = original(input);
    cout << endl << "The original text is: " << endl;
    cout << orignal;
    cout << endl;
    wordVector = textWordVec(orignal);
    cout << "The orignal sentimental value of" << input
         << " is: " << sentCalc(wordVector, sentiment) << "." << endl;
    cout << endl
         << "------------------------------------------------------------------"
            "----------------------------------------"
         << endl
         << endl;
    cout << "What would you like to do? " << endl << endl;
    cout << "P - Change from Negative to Positive" << endl;
    cout << "N - Change from Positive to Negative" << endl;
    cout << "Q - to Quit" << endl << endl;
    cout << "Your choice: ";
    cin >> choice;
  }
}
