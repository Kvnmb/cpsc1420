// Kevin Bui
// lab2.cpp
// 10/6/21

// Purpose: This program stores a word inputted by the user and displays the word
// on the screen. It also stores two integers provided by the user, and
// divides these integers to display an answer and the remainder.
// Furthermore, it stores two floating-point numbers from the user and divides
// them to demonstrate the program's computational abilities.

// Input: a word, two integers, two floating-point numbers

// Processing: simple and complex division, storing values into variables

// Output: User-prompted word and quotients (with remainders for integer quotients)

// Example: word: candy; integers: 8 and 3; floating point-numbers: 2.05 and
// 4.36; displays "candy", "8 divided by 3 is 2 with a remainder of 2", and
// "0.470183"

#include <iostream>
#include <string>

using namespace std;

int main()
{
  // variables
  string word;
  int integerOne = 0, integerTwo = 0, quotientInteger = 0, remainder = 0; 
  float decimalOne = 0, decimalTwo = 0, quotientFloat = 0;

  // Prompts for inputs
  cout << "\n\nHello! Please enter any word you'd like!\n\n ";
  getline(cin, word);
  cout << "\n\nPlease enter the first integer:\n\n ";
  cin >> integerOne;
  cout << "\n\nPlease enter the second integer:\n\n ";
  cin >> integerTwo;
  cout << "\n\nPlease enter the first floating-point number:\n\n ";
  cin >> decimalOne;
  cout << "\n\nFinally, please enter the second floating-point number:\n\n ";
  cin >> decimalTwo;

  // Calculations
  quotientInteger = integerOne / integerTwo;
  remainder = integerOne % integerTwo;
  quotientFloat = decimalOne / decimalTwo;

  // Output
  cout << "\n\nThe word you chose was " << word << ". " << endl << endl;
  cout << integerOne << " divided by " << integerTwo << " equals " << quotientInteger;
  cout << ", with a remainder of " << remainder << ". " << endl << endl;
  cout << decimalOne << " divided by " << decimalTwo << " equals " << quotientFloat;
  cout << "\n\nGoodbye!\n\n\n\n ";

  return 0;
}
