// Kevin Bui
// lab3.cpp
// 10/13/21

// Purpose: this program takes two integers from the user and determines
// if the first integer is a multiple of the second integer.

// Input: two integers, and a y/n for replayability.

// Procssing: the program will divide the first integer by the
// second to find the other factor, as well as use the modulo operator to
// determine if the first integer is a multiple or not.

// Output: The program will tell the user whether the first integer
// selected is a multiple, and if it is it will also state the other
// factor.

// Example: inputs: 20 and 4 ; output: 20 is a multiple of 4
// and the other factor is 5.

#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

int main()
{
  // Variables
  int num1 = 0, num2 = 0, factor = 0, remainder = 0;
  char choice = 'y';

  // Welcome message
  cout << "\n\nHello! This is a program to determine whether the first number you input is a multiple of the second number!\n\n\n" ;

  // Loop for infinite tries
  while(choice == 'y'){

    // input
    cout << "\n\nPlease input your first integer: " ;
    cin >> num1;
    while(num1 == 0){ // covers the zero case
      cout << "\n\nDividing zero by anything will equal 0. Please input another number: ";
      cin >> num1;
    }
    cout << "\n\nPlease input your second integer: " ;
    cin >> num2;
    while(num2 == 0){ // covers the other zero case
      cout << "\n\nYou can't divide by zero! Please input another number: ";
      cin >> num2;
    }

    // Calculation
    factor = num1 / num2;
    remainder = num1 % num2;

    // determines whether the integers are multiples
    if(remainder == 0 && num2 * factor == num1){
      cout << "\n\nYes, " << num1 << " is a multiple of " << num2 << ", and the other factor is " << factor;
    }else{
      cout << "\n\nNo, " << num1 << " is not a multiple of " << num2;
    }

    // prompt for replay
    cout << ".\n\n\nWould you like to try again?(y/n): ";
    cin >> choice;
  }

  // Goodbye message
  cout << "\n\n\nGoodbye!\n\n\n";
  
  return 0;
}
    
