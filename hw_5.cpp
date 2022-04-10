// Kevin Bui
// hw_5.cpp
// 12/2/21

// Purpose: The purpose of this program is to sort the inventory of an electronics company
// and display the inventory or a report of what needs to be reordered.

// Input: The user inputs a data file, and can select to check the inventory or see if anything needs to be reordered.

// Processing: the file writes data into a struct, then a sorting function alphabetizes the inventory and the screen
// displays either the inventory report or the reorder report based on user input.

// Output: The program outputs a menu displaying a report of the inventory.

#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

struct Part  // struct for items
{
  string name;
  string manufacturer; 
  int quantity, min;
  double cost;
  double totalValue; // holds total value of the part
};

const int ARRAY_SIZE = 150; // assume no more than 150 students

// Function Prototypes

void printInv(Part[], int);
// prints the contents of an array element, parameters are the struct array and the number of elements used

void printReorder(Part[], int);

void selectionSort(Part[], int);
// organizes array contents alphabetically, parameters are the struct array and the number of elements used

void swap(Part[], Part[]);
// swaps values in one element with another, parameters are the struct array and the indexes

int main()
{
  Part list[ARRAY_SIZE]; // struct holding 150 files
  ifstream file;
  int count = 0; // to count how many elements are actually used
  string fileName;
  bool open;
  int option, quantityTotal; // option holds menu choice, quantityTotal holds number of items in inventory
  double costTotal; // holds value of current inventory
  
  // welcome message
  cout << "\n\nHello! this program will allow you to track the inventory of Everything Electronic!" ;


  // searches for a text file

  cout << "\n\nPlease input the inventory file: " ;
  
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

  count = 0;
    
  // While loop to input files and check for end of file

  while(count < ARRAY_SIZE && file >> list[count].name >> list[count].manufacturer
        >> list[count].quantity >> list[count].min >> list[count].cost){
    count++; // count will later keep track of how many indexes the array goes to in order to avoid printing null
  }
  

  file.close();

  selectionSort(list, count); // organizes array based on name

  // menu
  while(option != 3){
    option = 0;
    cout << "\n\n\n\n\t\tInventory Menu\n\n"
         << "1. Inventory Report\n"
         << "2. Reorder Report\n"
         << "3. Quit Program"
         << "\n\nPlease input your choice: ";
    while(option < 1 || option > 3){
      cin >> option;
      if(option < 1 || option > 3){
        cout << "\n\nPlease input a valid option: " ;
      }
    }

    // inventory report
    if(option == 1){
      quantityTotal = 0;
      costTotal = 0;

      cout << "\n\n\n\t\t\t\t\t\tInventory Report\n\n"
           << setw(20) << right << "Item" << setw(20) << right << "Manufacturer"
           << setw(20) << right << "Quantity" << setw(20) << right << "Cost each($)"
           << setw(20) << right << "Total Value($)\n";
      
      for(int index = 0; index < count; index++){
        printInv(list, index);
      }
      
      cout << "\n\nNumber of different items: " << count;

      for(int index = 0; index < count; index++){
        quantityTotal += list[index].quantity; // adds up the quantities
      }
      cout << "\nTotal quantity: " << quantityTotal;

      for(int index = 0; index < count; index++){
        costTotal += (list[index].quantity * list[index].cost); // adds up the costs
      }

      cout << "\nTotal value of all items: $" << costTotal;

      // reorder report
    }else if(option == 2){

      cout << "\n\n\n\t\t\t\t\t\t\t\tReorder Report\n\n"
           << setw(20) << right << "Item" << setw(20) << right << "Manufacturer"
           << setw(20) << right << "Quantity" << setw(20) << right << "Minimum"
           << setw(20) << right << "Order" << setw(20) << right << "Cost($)" << endl;

      int diffItems = 0; // counter for how many different items need reordering
      int orderTotal = 0; // counts how many items need to be ordered in total
      double reorderCosts = 0; // adds up cost of total items needing reordering
      for(int index = 0; index < count; index++){
        if(list[index].quantity < list[index].min){ // prints item if quantity is below the minimum
          printReorder(list, index);
          diffItems++;
          orderTotal += (list[index].min - list[index].quantity);
          reorderCosts += (list[index].min - list[index].quantity) * list[index].cost;
        }
      }
      cout << "\n\nNumber of different items to order: " << diffItems;
      cout << "\nTotal number to order: " << orderTotal;
      cout << "\nTotal cost: $" << reorderCosts;

      // quits program
    }else if(option == 3){
      break;
    }
  }
  cout << "\n\nGoodbye!" << endl << endl;

  return 0;
}

// prints the inventory report, parameters are the index and the array name
void printInv(Part list[], int index)
{
  // prints struct element values
  cout << fixed << showpoint << setprecision(2);
  cout << endl << setw(20) << right << list[index].name; 
  cout << setw(20) << right << list[index].manufacturer; 
  cout << setw(20) << right << list[index].quantity; 
  cout << setw(20) << right << list[index].cost;
  list[index].totalValue = (list[index].quantity * list[index].cost);
  cout << setw(20) << right << list[index].totalValue;
}

// prints the reorder report, parameters are the index and array name
void printReorder(Part list[], int index)
{
  cout << fixed << showpoint << setprecision(2); 
  cout << endl << setw(20) << right << list[index].name; 
  cout << setw(20) << right << list[index].manufacturer;
  cout << setw(20) << right << list[index].quantity;
  cout << setw(20) << right << list[index].min;
  cout << setw(20) << right << (list[index].min - list[index].quantity); // prints the amount needing to be ordered
  cout << setw(20) << right << (list[index].min - list[index].quantity) * list[index].cost; // prints the cost of the missing amount
}

// function to swap the values of array elements, parameters are the array and the two indexes being swapped
void swap(Part &a, Part &b)
{
  Part temp; // temporary value to hold one index

  temp.name = a.name;
  temp.manufacturer = a.manufacturer;
  temp.quantity = a.quantity;
  temp.min = a.min;
  temp.cost = a.cost;
  
  a.name = b.name;
  a.manufacturer = b.manufacturer;
  a.quantity = b.quantity;
  a.min = b.min;
  a.cost = b.cost;
  
  b.name = temp.name;
  b.manufacturer = temp.manufacturer;
  b.quantity = temp.quantity;
  b.min = temp.min;
  b.cost = temp.cost;
}

// selectionsort function, parameters are the array and the number of indexes used
void selectionSort(Part list[], int size)
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
