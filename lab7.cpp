// Kevin Bui
// lab7.cpp
// 11/11/21

// Purpose: the purpose of this program is to demonstrate the use of two-dimensional
// arrays to store information. This program stores user-inputted integers in
// the location of their choosing and once all entries are filled, outputs
// the total of the values in the array along with printing the array as a table.

// Input: the user inputs two numbers from 1-3 to decide the row and column, then
// inputs their desired value.

// Processing: The program stores the value into each element in the array and
// after all elements are filled, computes the total of the values in the array.

// Output: The program prints a table of the array values and the total of the values.

#include <iostream>
#include <iomanip>

using namespace std;

const int SIZE = 3; // to set up a 3x3 array
const int ELEMENTS = 9; // rows x columns = number of elements in array

int rowFunc(); // function for rows, returns a number between 1-3
int columnFunc(); // function for columns, returns a number between 1-3
int valueFunc(); // function asks user for a value, returns user input
void arrayFunc(int [][SIZE], int, int, int); // function to store values in array,
// parameters are the array, the row #, the column #, and the value

int main()
{
  int table[SIZE][SIZE]; // two-dimensional array
  int totalVal = 0, row = 0, column = 0, value = 0, counter = 0; // variables for array

  // initializes all entries to 0
  for(int x = 0; x < SIZE; x++){
    for(int y = 0; y < SIZE; y++){
      table[x][y] = 0;
    }
  }

  // welcome message
  cout << "\n\nHello! This program takes integers and stores it in a 3-by-3 array, "
       << "\nand once the array is filled the total of the values will be computed.\n\n" ;

  // loop iterates for every element in the array
  while(counter != ELEMENTS){
    row = rowFunc();
    column = columnFunc(); // asks for rows and columns
    
    while(table[row][column] != 0){ // checks for whether the array has a value inputted yet
      cout << "\nThis element has already been filled! Please choose another location.\n" ;
      row = rowFunc();
      column = columnFunc();
    }
    
    value = valueFunc(); // asks for value
    arrayFunc(table, row, column, value); // stores value in array element
    counter++;
  }

  cout << "\n\nArray Table\n-----------\n" ;

  for(int x = 0; x < SIZE; x++){
    for(int y = 0; y < SIZE; y++){ // displays array content in table
      cout << setw(3) << table[x][y];
    }
    cout << endl;
  }

  for(int x = 0; x < SIZE; x++){
    for(int y = 0; y < SIZE; y++){ // adds all values from table
      totalVal += table[x][y];
    }
  }
  cout << "\n\nThe total value of the array is " << totalVal << ". Goodbye!\n\n\n" ;
  return 0;
  
}

int rowFunc() // gets row # from user
{
  int row = 0;
  cout << "\nPlease enter a row #: " ;
  cin >> row;
  if(row < 1 || row > 3){ // boolean to ensure value is between 1 and 3
    while(row < 1 || row > 3){
      cout << "\nPlease input a row value between 1 and 3: " ;
      cin >> row;
    }
  }
  return row - 1; // array row starts at 0
}

int columnFunc() // gets column # from user
{
  int column = 0;
  cout << "\nPlease enter a column #: " ;
  cin >> column;
  if(column < 1 || column > 3){ // boolean to ensure value is between 1 and 3
    while(column < 1 || column > 3){
      cout << "\nPlease input a column value between 1 and 3: " ;
      cin >> column;
    }
  }
  return column - 1; // column row starts at 0
}

int valueFunc() // gets value from user
{
  int value = 0;
  cout << "\nPlease enter a value: " ;
  cin >> value;
  return value; // returns user input
}

// function to store values in array, parameters are the array, the row #, the column #, and the value
void arrayFunc(int arr[][SIZE], int row, int column, int value)
{
  arr[row][column] = value;
}
  
