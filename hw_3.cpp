// Kevin Bui
// hw_3.cpp
// 11/4/21

// Purpose: the purpose of this program is to simulate the game
// "Chutes and Ladders", where the first person to reach square
// 100 is the winner.

// Input: The players input their names and press enter to "spin".

// Processing: The program takes the names to indicate whose turn
// it is, and enter will generate a random number between 1 and 6 to
// simulate a dice roll. If the player lands on a square that is
// either a chute or a ladder, the player's position will move to the
// corresponding square. The process repeats until a player reaches 100.

// Output: The screen will display the players' turn, spin output, and
// new position.



#include <iostream>
#include <cstdlib>
#include <string>
#include <ctime>

using namespace std;

// Function prototypes
void welcome(); // welcome function

void goodbye(); // goodbye function

int spin(); // generates a dice roll

string nameOne(); // asks player 1 for their name

string nameTwo(); // asks player 2 for their name

void winner(int, string); // declaration for winner

int chute(int); // checks player squares for a chute

int ladder(int); // checks player squares for a ladder

int turn(int, string); // generates player's turn (int is player square, string is name)

int main()
{
  int locationOne = 0, locationTwo = 0; // location of players to be used in functions
  string playerOne, playerTwo; // names of players to be used in functions
  char choice = 'y'; // replay option
  unsigned seed = time(0); // truly random sequence for program

  srand(seed); // seeds the random number generator
  
  welcome();

  // name functions
  playerOne = nameOne();
  playerTwo = nameTwo();

  // replay loop
  while(choice == 'y'){
    locationOne = 0; // resets location every iteration
    locationTwo = 0;

    // while loop for playing until winner is found
    while(locationOne != 100 && locationTwo != 100){
      locationOne = turn(locationOne, playerOne); // location is equal to result of function
      if(locationOne == 100){
        break; // breaks the loop so that loop does not reiterate
      }
      locationTwo = turn(locationTwo, playerTwo);
      if(locationTwo == 100){
        break;
      }
    }
    cout << "\n\nWould you like to play again?(y/n): " ;
    cin >> choice;
  }
  
  
  goodbye();
  
  return 0;
}



void welcome()
{
  cout << "\n\nHello! Welcome to the Chutes and Ladders game. Both players start at 0, "
       << "and the first one to 100 wins the game.\n\n" ;
  // outputs welcome message
}

void goodbye()
{
  cout << "\n\nThank you for playing! Goodbye!\n\n" ;
  // outputs goodbye message
}

void winner(int location, string name) // inputs are the player square and the player name
{
  if(location == 100){
    cout << "\n\n" << name << ", you win!\n\n" ; // outputs a win message
  }
}

int spin()
{
  int roll = (rand() % (6 - 1 + 1)) + 1; // simulated dice roll
  return roll; // returns a number between 1-6
}

string nameOne() // first name function
{
  string name;
  cout << "\n\nPlayer 1, please input your name: " ;
  getline(cin, name);
  return name; // returns the first player's name
}

string nameTwo() // second name function
{
  string name;
  cout << "\n\nPlayer 2, please input your name: " ;
  getline(cin, name);
  return name; // returns the second player's name
}

int turn(int location, string name) // function for players' turn
{
  int roll = 0;
  cout << "\n\n" << name << ", it is your turn. Press ENTER to spin: " ;
  cin.get(); // lets player "spin"
  roll = spin();
  cout << "You rolled a " << roll << "." ;
  if(location + roll > 100){ // keeps value from going over 100
    cout << "\nThe spin is ignored because the result will be greater "
         << "than 100: you are still at " << location << "." ;
  }else{
    location += roll;
    location = chute(location); // location is checked by chute and ladder function for possible changes
    location = ladder(location);
    cout << "\nYour new location is: " << location << "." ;
  }
  winner(location, name); // checks for winner
  return location; // returns the value of the location variable
}


int chute(int location) // input is the player square + the roll
{
  // checks for possible chutes
  if(location == 98){
    cout << "\nYou landed on a chute, and have to move down" ;
    location -= 20;
  }else if(location == 95){
    cout << "\nYou landed on a chute, and have to move down." ;
    location -= 20;
  }else if(location == 93){
    cout << "\nYou landed on a chute, and have to move down." ;
    location -= 20;
  }else if(location == 87){
    cout << "\nYou landed on a chute, and have to move down." ;
    location -= 63;
  }else if(location == 64){
    cout << "\nYou landed on a chute, and have to move down." ;
    location -= 4;
  }else if(location == 62){
    cout << "\nYou landed on a chute, and have to move down." ;
    location -= 43;
  }else if(location == 56){
    cout << "\nYou landed on a chute, and have to move down." ;
    location -= 3;
  }else if(location == 49){
    cout << "\nYou landed on a chute, and have to move down." ;
    location -= 38;
  }else if(location == 48){
    cout << "\nYou landed on a chute, and have to move down." ;
    location -= 22;
  }else if(location == 16){
    cout << "\nYou landed on a chute, and have to move down." ;
    location -= 10;
  }else{
    location = location;
  }
  return location; // returns new or original player square
}
    
int ladder(int location) // input is player square + roll
{
  // checks for possible ladders
  if(location == 1){
    cout << "\nYou landed on a ladder, and get to move up!" ;
    location += 37;
  }else if(location == 4){
    cout << "\nYou landed on a ladder, and get to move up!" ;
    location += 10;
  }else if(location == 9){
    cout << "\nYou landed on a ladder, and get to move up!" ;
    location += 12;
  }else if(location == 23){
    cout << "\nYou landed on a ladder, and get to move up!" ;
    location += 21;
  }else if(location == 28){
    cout << "\nYou landed on a ladder, and get to move up!" ;
    location += 56;
  }else if(location == 36){
    cout << "\nYou landed on a ladder, and get to move up!" ;
    location += 8;
  }else if(location == 51){
    cout << "\nYou landed on a ladder, and get to move up!" ;
    location += 15;
  }else if(location == 71){
    cout << "\nYou landed on a ladder, and get to move up!" ;
    location += 19;
  }else if(location == 80){
    cout << "\nYou landed on a ladder, and get to move up!" ;
    location += 20;
  }else{
    location = location;
  }
  return location; // returns a new or original player square
}

