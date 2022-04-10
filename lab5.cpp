// Kevin Bui
// lab5.cpp
// 10/28/21

// Purpose: the purpose of this program is to demonstrate the use of functions
// to clarify code and shorten it. Functions are more convenient for
// reusability of repeated code.

// Input: the user inputs a number from 5 to 25 and the program outputs the sum
// of the numbers from 1 to the user-inputted number. It will also take a char
// input to determine replaying the program.

// Processing: the char will cycle through the program if the user inputs 'y',
// or will end the program with 'n'. After the user inputs a number between
// 5 and 25, the summation function will use a for-loop to add consecutive
// numbers from 1 to the user input and store this number in a variable.

// Output: the program will tell the user the sum of the numbers from 1 to
// their input.

// Example: input: 5; output: 15

#include <iostream>

using namespace std;

// the welcome message function
void welcomeFunc()
{
  cout << "\n\nWelcome! This program demonstrates the use of functions!\n\n" ;
}

// the goodbye message function
void byeFunc()
{
  cout << "\n\nThank you for using the program! Goodbye!\n\n" ;
}

// function taking user input
int inputFunc()
{
  int input = 0;
  cout << "\n\nPlease choose a number between 5 and 25: " ;

  // loop until answer within boundaries is chosen
  while(input <= 5 || input >= 25){
    cin >> input;
    if(input >= 5 && input <= 25){
      break; // breaks loop because the while loop has "or" operator
    }else{
      cout << "\n\nThat is not between 5 and 25! Try again: " ;
    }
  }
  return input;
}

// summation function 
void sumFunc()
{
  int result = 0;
  // instead of using global variables, use input function
  // in this function
  int input = inputFunc();
  for(int x = 1; x <= input; x++){
    result += x;
  }
  cout << "\n\nThe sum of numbers from 1 to "
       << input << " is " << result << ".\n\n" ;
}

// main function holding all other functions
void mainFunc()
{
  welcomeFunc();

  char choice = 'y';

  // replay loop
  while(choice == 'y'){

    // inputFunc is inside sumFunc
    sumFunc();

    cout << "\n\nWould you like to input another number?(y/n): " ;
    cin >> choice;
  }

  byeFunc();
}

int main()
{      

  mainFunc();
  
  return 0;
}
