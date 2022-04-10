// Kevin Bui
// lab6.cpp
// 11/4/21

// Purpose: the purpose of this program is to demonstrate the use of
// input files and placing the values read into arrays to store the data.

// Input: the input file "lab6input.dat" will be read by the program.

// Processing: as the program reads the values in the input file, a
// while loop will organize the value into three different arrays
// based on whether the value is odd, even, or negative.

// Output: the program will display the arrays with the numbers correctly organized.


#include <iostream>
#include <fstream>

using namespace std;

int main()
{
  ifstream numFile; // input file
  
  // variables to save values from file and store data into arrays, counters for space used
  int number = 0, neg = 0, even = 0, odd = 0;

  // Arrays
  int negNum[30], evenNum[30], oddNum[30]; // assuming file has no more than 30 integers

  // Welcome message
  cout << "\n\nHello! This program reads a file with numbers and organizes the numbers into"
       << "\narrays based on whether they are even, odd, or negative.\n\n" ;

  // Opens data file
  numFile.open("lab6input.dat");
  
  if(numFile){ // Checks for file open errors
    cout << "\n\nThe file is open! Processing...\n\n" ;
    
    while(numFile >> number){ // While loop to read all numbers in file
      if(number == 0){
        continue; // Skips iteration of loop to ignore zero

      }else if(number < 0){ // Stores negative numbers into array
        negNum[neg] = number;
        neg++; 
        
      }else if(number > 0 && (number % 2 == 0)){// Stores even numbers into array
        evenNum[even] = number;
        even++;
        
      }else{ // Rest are odd numbers to be stored in third array
        oddNum[odd] = number;
        odd++;
      }
    }
  }else{
    cout << "\n\nThe file failed to open.\n\n" ;
  }

  // For loops only display array index up to the last used slot in array
  cout << "\n\nThe numbers in the negative array are:\n" ;
  for(int x = 0; x < neg; x++){
    cout << "Index[" << x << "]: " << negNum[x] << endl;
  }

  cout << "\n\nThe numbers in the even array are:\n" ;
  for(int x = 0; x < even; x++){
    cout << "Index[" << x <<"]: " << evenNum[x] << endl;
  }


  cout << "\n\nThe numbers in the odd array are:\n" ;
  for(int x = 0; x < odd; x++){
    cout << "Index[" << x << "]: " << oddNum[x] << endl;
  }
  
  numFile.close(); // closes file
  cout << "\n\nThe file is closed. Goodbye!\n\n" ;
  
  return 0;
}
