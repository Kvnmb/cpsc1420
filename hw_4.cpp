// Kevin Bui
// hw_4.cpp
// 11/19/21

// Purpose: the purpose of this program is to play a memory game with the user, where they try to find
// the matching positions of 6 pairs of cards. The game keeps track of score and when the user wins,
// tells the player how many tries it takes to win.

// Input: the user inputs a number between 1-3 for the row selection, and a number between 1-4 for column
// selection. The user also inputs 'y' or 'n' to determine a replay of the game.

// Processing: the program uses the random number function to decide which file to play the game with,
// make sure the user input for rows and columns is within the boundaries, makes sure that the row and column
// selection has not already been picked or removed, and displays the card at the chosen location. A loop
// determines whether the game ends or continues based on how many cards are left.

// Output: the program outputs the contents of the arrays, and after the game is over, outputs how many tries
// the user took to finish the game, with a minimum score of 6.


#include <iostream>
#include <iomanip>
#include <fstream>
#include <ctime>
#include <cstdlib>

using namespace std;

const int ROW = 3;
const int COLUMN = 4;

void wait(int); // function that pauses program for x seconds

void welcome(); // welcome message

void bye(); // goodbye message

int randomNum(); // generates and returns a number between 1 and 2

ifstream fileOpen(); // opens one of two files and returns the file

void readFile(char [][COLUMN], ifstream); // prints the contents of file into array

void fill(char [][COLUMN]); // fills array with '*' 

void display(char [][COLUMN]); // displays the contents of an array

int inputRow(); // takes row input, returns the int

int inputCol(); // takes column inputm returns the int

bool guess(char [][COLUMN], char [][COLUMN]); // takes user's guesses to play game,
// if game is over it returns 'true'

int main()
{
  char answers[ROW][COLUMN], game[ROW][COLUMN], choice = 'y'; // arrays for holding answers and to display
  int turns = 0; // counts score
  bool gameEnd = false; // determine if game continues

  welcome();

  while(choice == 'y'){ // replay loop
    turns = 0;
    gameEnd = false;

    readFile(answers, fileOpen()); // reads file into array

    fill(game); // fills array with '*'

    cout << endl << endl;

    while(gameEnd == false){ // keeps game going until done
      gameEnd = guess(answers, game);
      turns++;
    }

    cout << "\n\nYou win! it took you " << turns << " tries.\n\nWould you like to play again? (y/n): " ;
    cin >> choice;
  }

  bye();

  return 0;
}



// FUNCTIONS

void wait(int seconds) // parameter is how many seconds to wait
{
  clock_t endwait;
  endwait = clock() + seconds * CLOCKS_PER_SEC;

  while(clock() < endwait)
    {
    }
}

void welcome() // welcome message
{
  cout << "\n\nHello! Let's play a memory game. Guess the locations of matching card"
       << "\npairs in as few tries as possible. Good luck!\n\n" ;
}

void bye() // goodbye message
{
  cout << "\n\nThank you for playing! Goodbye!\n\n\n" ;
}

int randomNum() // generates a random number between 1 and 2, returns 1 or 2
{
  int fileNum = 0;
  unsigned seed = time(0);

  srand(seed); // for actual randomness
  fileNum = (rand() % (2 - 1 + 1)) + 1;

  return fileNum;
}

ifstream fileOpen() // opens file and returns the file 
{
  ifstream file;
 int num = randomNum();
  
  if(num == 1){
    file.open("p4data1.dat");
  }else if(num == 2){
    file.open("p4data2.dat");
  }
  return file;
}

void readFile(char arr[][COLUMN], ifstream file) // reads files into array, parameters are an array and a file
{
  for(int x = 0; x < ROW; x++){
    for(int y = 0; y < COLUMN; y++){
      file >> arr[x][y]; // loop to read into elements
    }
  }
  file.close();
}

void fill(char arr[][COLUMN]) // fills an array with '*' to start game
{
  for(int x = 0; x < ROW; x++){
    for(int y = 0; y < COLUMN; y++){
      arr[x][y] = '*';
    }
  }
}

void display(char arr[][COLUMN]) // displays array
{
  cout << endl;
  
  for(int x = 0; x < ROW; x++){
    for(int y = 0; y < COLUMN; y++){
      cout << setw(3) << arr[x][y];
    }
    cout << endl;
  }
  cout << endl << endl;
}

int inputRow() // takes input for which row, returns row - 1 
{
  int row = 0;
  while(row < 1 || row > 3){
    cout << "\n\nPlease input a row # between 1 and 3: " ;
    cin >> row;
  }
  return row - 1;
}

int inputCol() // input for columns, returns col - 1
{
  int col = 0;
  while(col < 1 || col > 4){
    cout << "\n\nPlease input a column # between 1 and 4: " ;
    cin >> col;
  }
  return col - 1;
}

// function that plays the game, returns a bool value of true or false,
// parameters are the main array and the hidden array

bool guess(char arrMain[][COLUMN], char arrHidden[][COLUMN])
{
  int rowOne = 0, colOne = 0, rowTwo = 0, colTwo = 0;
  bool gameEnd = false;

  display(arrHidden);
  
  rowOne = inputRow();
  colOne = inputCol();

  while(arrHidden[rowOne][colOne] == '_'){ // makes sure input is valid
    cout << "\n\nThat card has already been removed, please try again.\n" ;
    rowOne = inputRow();
    colOne = inputCol();
  }
  
  arrHidden[rowOne][colOne] = arrMain[rowOne][colOne];

  display(arrHidden);
  
  rowTwo = inputRow();
  colTwo = inputCol();

  while(arrHidden[rowTwo][colTwo] == '_'){
    cout << "\n\nThat card has already been removed, please try again.\n" ;
    rowOne = inputRow();
    colOne = inputCol();
  }

  while(rowOne == rowTwo && colOne == colTwo){ // makes sure input is valid
    cout << "\n\nYou picked the same rows and columns! Please input the second set again.\n\n" ;
    rowTwo = inputRow();
    colTwo = inputCol();
  }

  arrHidden[rowTwo][colTwo] = arrMain[rowTwo][colTwo];
  display(arrHidden);

  if(arrHidden[rowOne][colOne] == arrHidden[rowTwo][colTwo]){ // checks for if answer is right or wrong
    cout << "\n\nThe two cards match and are removed.\n\n" ;
    arrHidden[rowOne][colOne] = '_';
    arrHidden[rowTwo][colTwo] = '_';
  }else{
    cout << "\n\nThe two cards do not match. Pausing for 5 seconds...\n" ;
    wait(5);
    arrHidden[rowOne][colOne] = '*';
    arrHidden[rowTwo][colTwo] = '*';
  }

  for(int x = 0; x < ROW; x++){ // checks for if the game is over
    for(int y = 0; y < COLUMN; y++){
      if(arrHidden[x][y] != '*'){
        gameEnd = true;
      }else{
        gameEnd = false;
        break;
      }
    }
  }
  return gameEnd;
}
