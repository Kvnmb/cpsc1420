// Christian Buenafe
// p5.cpp
// Purpose:
//
//

#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

const int MAX = 150;
const char REPEAT = 'y';
const int SCREEN_HEIGHT = 12;
const int INVENTORY = 1;
const int REORDER = 2;
const int QUIT = 3;

struct Data
{
  string name;
  string manufacturer;
  int quantity;
  int min;
  double cost;
  double totalValue;
};

void welcome();

void goodbye();

int menu();

void printList(Data arr[], int num);

void inventoryReport(Data arr[], int num);

void reorderReport(Data arr[], int num);

void printOrder(Data arr[], int num);

void selSort(Data arr[], int num);

void swapVal(Data& val1, Data& val2);

void clrScreen(); 

int readFile(Data arr[]);

int main()
{

  int menuSelection = 0;
  Data arr[MAX];
  int num = 0;
  string input;
  string file;
  
  clrScreen();
  
  cout << endl << endl;

  welcome();

  num = readFile(arr);
  
  selSort(arr, num);

  menuSelection = menu();

  while(menuSelection != QUIT){
    switch(menuSelection){
    case INVENTORY:
      inventoryReport(arr, num);
      break;
    case REORDER:
      reorderReport(arr, num);
      break;
    }
    menuSelection = menu();
  }
  
    
  cout << endl << endl;

  selSort(arr, num);
  
  goodbye();
  
  return 0;
}

void welcome()
{
  cout << "Hello! This program will create an electron inventory!"
       << endl << endl;
}

void goodbye()
{
  cout << "Thank you for using this program!" << endl;
}

void clrScreen()
{
  for (int i = 0; i < SCREEN_HEIGHT; i++){
    cout << endl;
  }
}

void inventoryReport(Data arr[], int num)
{
  const int WIDTH = 80;
  const int COL_BIG = 20;
  const int COL_SMALL = 8;
  const string DS = "$";
  const string TITLE = "Inventory Report";  
  const string HEADINGS_ONE = "Item          Manufacturer         ";
  const string HEADINGS_TWO = "Quantity  Cost each   Total Value";
  const string QUANTITY = "Total Quantity: ";
  const string VALUE = "Total Value: ";

  for(unsigned i = 0; i < (WIDTH - TITLE.length())/2; i++){
    cout << ' ';
  }
  cout << TITLE << endl;
  cout << HEADINGS_ONE << HEADINGS_TWO << endl;

  for (int i = 0; i < num; i++){
    cout << left << setw(COL_BIG) << arr[i].name << setw(COL_BIG)
         << arr[i].manufacturer;
    cout << right << setw(COL_SMALL) << arr[i].quantity;
  }
}

void reorderReport(Data arr[], int num)
{

}

int menu()
{
  const string SPACE = " ";
  int selection = 0;
  
  clrScreen();
  
  while (selection < INVENTORY || selection > QUIT){
    cout << SPACE << INVENTORY << ". Inventory" << endl << endl;
    cout << SPACE << REORDER << ". Reordered" << endl << endl;
    cout << SPACE << QUIT << ". Quit" << endl << endl;
    cout << SPACE << "Rerun Program? ";
    cin >> selection;
    cin.ignore();
  }
  return selection;
}

int readFile(Data arr[])
{
  ifstream file;
  int count = 0;
  string filename;

  cout << "Please provide a filename: ";
  cin >> filename;
  cin.ignore();
  file.open(filename);
  if (file){
    while(count < MAX && file >> arr[count].name
          >> arr[count].manufacturer >> arr[count].quantity
          >> arr[count].min >> arr[count].cost){
      count++;
    }
    file.close();
  }
  return count;
}
  
void printList(Data arr[], int num)
{
  cout << fixed << showpoint << setprecision(2);
  cout << endl << setw(20) << right << arr[num].name;
  cout << setw(20) << right << arr[num].manufacturer;
  cout << setw(20) << right << arr[num].quantity;
  cout << setw(20) << right << arr[num].cost;
  arr[num].totalValue = (arr[num].quantity * arr[num].cost);
  cout << setw(20) << right << arr[num].totalValue;
}

void printOrder(Data arr[], int num)
{
  int amount;
  
  cout << fixed << showpoint << setprecision(2);
  cout << endl << setw(20) << right << arr[num].name;
  cout << setw(20) << right << arr[num].manufacturer;
  cout << setw(20) << right << arr[num].quantity;
  cout << setw(20) << right << arr[num].min;
  cout << setw(20) << right << (arr[num].min - arr[num].quantity);
  amount = (arr[num].min - arr[num].quantity) * arr[num].cost;
  cout << setw(20) << right << amount;
}

void selSort(Data arr[], int num)
{
  int minIndex;
  
  for (int i = 0; i < (num - 1); i++){
    minIndex = i;
    for (int j = i + 1; j < num; j++){
      if(arr[j].name < arr[minIndex].name){
        minIndex = j;
      }
    }
    if (minIndex != i){
      swapVal(arr[i], arr[minIndex]);
    }
  }
}

void swapVal(Data& val1, Data& val2)
{
  Data temp = val1;
  val1 = val2;
  val2 = temp;
}
