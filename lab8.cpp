// Kevin Bui
// lab8.cpp
// 11/17/21

// Purpose: the purpose of this program is to test the efficiency of linear searches for arrays.
// The program searches through an array to find a string that is inputted by the user.

// Input: the user can input a string file to process, and then input words to see whether
// those words are in the file.

// Processing: the file's values will be transferred to the array, and a linear search
// will run to find strings inputted by the user.

// Output: The program will either tell the user the index of the first instance of the
// word or will say the string was not found.

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

// function that takes a string array, size of array, and a string to search array for the string. Returns index or -1
int linearSearch(const string[], int, string);

int main()
{
  const int SIZE = 75; // size of array
  string words[SIZE]; // array
  string fileName, word; // fileName allows for user to input a file, word holds their input for the search
  fstream file; 
  bool open = false;
  int count = 0, result = 0;
  char choice = 'y'; // repeat loop

  // welcome message
  cout << "\n\nHello! this program will allow you to search for words in a word file. "
       << "\nPlease input a word file: " ;

  // searches for a text file
  while(open == false){
    cin >> fileName;
    file.open(fileName);
    if(file){
      cout << "\n\nThe file has been opened!\n\n" ;
      open = true;
    }else{
      cout << "\n\nError opening the file. Please input another file: " ;
    }
  }
  // loop to read file contents to array
  while(count < SIZE && file >> words[count])
    count++;

  file.close();

  // repeat loop
  while(choice == 'y'){
    cout << "\n\nPlease input a word that you want to find in the file: " ;
    cin >> word;
    result = linearSearch(words, SIZE, word); // searches for word in the array and result is assigned the index number
    if(result == -1){ // if the word is not found
      cout << "\n\nThis word is not in the file." ;
    }else{
      cout << "\n\nThis word has been found at index " << result << endl;
    }

    cout << "\n\nWould you like to find another word? (y/n): " ;
    cin >> choice;
  }
  cout << "\n\nGoodbye!\n\n" ;
  
  return 0;
}

// function to search array
int linearSearch(const string arr[], int size, string value)
// parameters are the array, the size of the array, and the word inputted by user

{
  int index = 0, position = -1;
  bool found = false;

  // loop to search whole array
  while(index < size && !found){
    if(arr[index] == value){
      found = true;
      position = index;
    }
    index++;
  }
  return position; // returns either the index or -1 for not found
}
     
