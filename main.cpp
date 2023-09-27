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

    switch (toupper(choice)) {
    case 'P':
      cout << endl
           << "----------------------------------------------------------------"
              "------------------------------------------"
           << endl
           << endl;
      cout << endl
           << "Okay! I will edit file: " << input << " to be more positive!"
           << endl
           << endl;
      positiveConversion(sentiment, positive, wordVector, text);
      cout << "After this chage, the new file is: " << endl;
      printText(text);
      cout << endl << endl;
      cout << "New Sentiment Value = " << sentCalc(wordVector, sentiment)
           << endl
           << endl;
      outputFile(input, text);
      cout << "The new output file will be stored in: " << input << endl
           << endl;
      cout << "Would you like to go again? ([Y]es or [N]o) ";
      cin >> loop;
      break;

    case 'N':
      cout << endl
           << "----------------------------------------------------------------"
              "------------------------------------------"
           << endl
           << endl;
      cout << endl
           << "Okay! I will edit file: " << input << " to be more negative!"
           << endl
           << endl;
      negativeConversion(sentiment, negative, wordVector, text);
      cout << endl << "After this chage, the new file is: " << endl;
      printText(text);
      cout << endl << endl;
      cout << "New Sentiment Value = " << sentCalc(wordVector, sentiment)
           << endl
           << endl;
      outputFile(input, text);
      cout << "The new output file will be stored in: " << input << endl
           << endl;
      cout << "Would you like to go again? (Y/N) ";
      cin >> loop;
      break;

    case 'Q':
      loop = 'N';
      break;
    }
  }
}
