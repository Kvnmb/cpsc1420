// Kevin Bui
// lab4.cpp
// 10/20/21

// Purpose: This program demonstrates the use of loops to create a multiplication table
// as well as an outline of a half-diamond.

// Input: the user inputs a number for how far the multiplication table spans and another
// number for the width of the half-diamond.

// Process: Loops and variables are used to create patterns

// Output: The program outputs a multiplication table and a half-diamond with user-inputted
// width

#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

int main()
{

  int diamondNum = 0, multiplyNum = 0, width = 0, counter = 0;

  // Welcome message and user input
  cout << "\n\n\nHello! I can create a multiplication table for you as well as a half-diamond!\n\n\n"
       << "Give me a number for the multiplication table: ";
  cin >> multiplyNum;
  cout << "\n\nGive me a number for the half-diamond's width: ";
  cin >> diamondNum;
  cout << endl << endl;

  // Multiplication table
  // sets the number of rows
  for(int x = 0; x <= multiplyNum; x++){
    // sets the number of columns
    for(int y = 0; y <= multiplyNum; y++){
      cout << setw(5) << y * counter;
    }
    // sets the multiplier of y
    counter++;
    cout << endl;
  }
  cout << endl << endl;

  // Loop for top half of half-diamond
  for(int top = 1; top <= diamondNum; top++){
    width++;
    cout << setw(width) << top << "\n";
  }

  // Loop for bottom half of half-diamond
  for(int bottom = diamondNum - 1; bottom >= 1; bottom--){
    width--;
    cout << setw(width) << bottom << "\n";
  }
  cout << endl << endl << endl;
  return 0;
}
