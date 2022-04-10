// Kevin Bui
// lab1.cpp
// 9/30/21
// Purpose: This program takes information about the user such as name, favorite color, and email address, and displays it on the screen.
// Input: name, favorite color, email address
// Process: saving user input to variables
// Output: displays user inputs neatly
// Example: name: John Doe, favorite color: blue, email address: Jdoe@seattleu.edu
//  result: Hi! My name is John Doe. My favorite color is blue. You can contact me at Jdoe@seattleu.edu. Nice to meet you!

#include <iostream>
using namespace std;

int main()
{
  string name, favColor, emailAddress;

  // explanation
  cout << endl << endl << endl;
  cout << " Please introduce yourself! ";
  cout << endl << endl;

  //input
  cout << "What is your name? ";
  getline(cin, name);
  cout << "What is your favorite color? ";
  getline(cin, favColor);
  cout << "What is your email address? ";
  getline(cin, emailAddress);

  //output
  cout << endl <<endl;
  cout << "Hi! My name is " << name << ". " << endl;
  cout << "My favorite color is " << favColor << ". " << endl;
  cout << "You can contact me at " << emailAddress << ". " << endl;
  cout << "Nice to meet you! "<< endl;
  cout << endl << endl<< endl;

  return 0;
}
