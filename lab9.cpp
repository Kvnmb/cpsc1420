// Kevin Bui
// lab9.cpp
// 12/2/21

// Purpose: the purpose of this program is to use struct arrays and selection sorting
// to organize student files.

// Input: a file containing student records out of order is read into a struct array.

// Processing: for-loops read through the array to check for students with the highest GPA,
// and a selectionsort function is used to organize the records alphabetically.

// Output: the program outputs the student records with the highest GPAs, prints the entire record
// without sorting, then alphabetizes and prints the record once more.


#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

struct Students // struct for student records
{
  string name;
  string studentNum; 
  int credits;
  double gpa;
};

const int ARRAY_SIZE = 150; // assume no more than 150 students

// Function Prototypes

void printFile(Students[], int);
// prints the contents of an array element, parameters are the struct array and the number of elements used

void selectionSort(Students[], int);
// organizes array contents alphabetically, parameters are the struct array and the number of elements used

void swap(Students[], Students[]);
// swaps values in one element with another, parameters are the struct array and the indexes

int main()
{
  Students list[ARRAY_SIZE]; // struct holding 150 files
  ifstream studentRecords;
  int count = 0; // to count how many files are actually used
  double highest = 0; // holds highest GPA score
  
  studentRecords.open("lab9input.dat");

  // While loop to input files and check for end of file
  while(count < ARRAY_SIZE && studentRecords >> list[count].name
        >> list[count].studentNum >> list[count].credits >> list[count].gpa){
    count++; // count will later keep track of how manny indexes the array goes to in order to avoid printing null
  }

  studentRecords.close();

  cout << endl << endl << "Students who have the highest GPA are: \n" ;

  // set highest to first GPA value for loop to process
  highest = list[0].gpa;

  // loop checks through the array to determine highest GPA
  for(int index = 1; index < count; index++){
    if(list[index].gpa > highest)
      highest = list[index].gpa;
  }

  // loop checks through array for students with highest GPA in case of multiple students and prints their file
  for(int index = 0; index < count; index++){
    if(list[index].gpa == highest)
      printFile(list, index);
  }

  cout << "\n\nRecords before sorting:\n" ;
  
  // prints the unsorted array contents
  for(int index = 0; index < count; index++){
    printFile(list, index);
  }

  cout << "\n\nRecords after sorting:\n" ;
  selectionSort(list, count); // organizes array based on name

  // prints the newly organized file
  for(int index = 0; index < count; index++){
    printFile(list, index);
  }

  cout << endl << endl;
  
  return 0;
}

// prints the student's record, parameters are the index and the array name
void printFile(Students list[], int index)
{
  cout << fixed << showpoint << setprecision(2); // sets decimal to two places
  cout << endl << setw(15) << list[index].name; // prints name, no more than 15 letters
  cout << " " << setw(10) << list[index].studentNum; // prints student ID, is no more than 10 characters
  cout << " " << setw(3) << list[index].credits;// prints number of credits, no more than 3 digits
  cout << " " << list[index].gpa; // prints gpa to 2 decimal places
}

// function to swap the values of array elements, parameters are the array and the two indexes being swapped
void swap(Students &a, Students &b)
{
  Students temp; // temporary value to hold one index

  temp.name = a.name;
  temp.studentNum = a.studentNum;
  temp.credits = a.credits;
  temp.gpa = a.gpa;

  a.name = b.name;
  a.studentNum = b.studentNum;
  a.credits = b.credits;
  a.gpa = b.gpa;

  b.name = temp.name;
  b.studentNum = temp.studentNum;
  b.credits = temp.credits;
  b.gpa = temp.gpa;
}

// selectionsort function, parameters are the array and the number of indexes used
void selectionSort(Students list[], int size)
{
  int startScan, minIndex;
  string minValue;

  // loop to compare array elements
  for(startScan = 0; startScan < (size - 1); startScan++){
    minIndex = startScan;
    minValue = list[startScan].name; // sets minValue to first element

    // compares minValue with the next element value
    for(int index = startScan + 1; index < size; index++){
      if(list[index].name < minValue){
        minValue = list[index].name;
        minIndex = index;
      }
    }

    // swaps the student records
    swap(list[minIndex], list[startScan]);
  }
}
