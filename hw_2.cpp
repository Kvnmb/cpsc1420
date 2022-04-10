// Kevin Bui
// hw_2.cpp
// 10/14/21

// Purpose: this program plays a guessing numbers game with the user

// Input: lower and upper bound for the game, guesses, and option to replay

// Processing: randomized number within bounds set by user, if-statements
// to determine how close user's guess is to the correct answer

// Output: Program tells user whether their guess is too high or too
// low, or the guess is correct and asks if the user wants to play again

// Example: bounds: 1 and 2, guess = 1, output: Correct! You win!


#include <iostream>
#include <cstdlib>
#include <string>
using namespace std;

int main()
{
  // variables
  int min = 0, max = 0, guess = 0, answer = 0;
  char replay = 'y';

  // welcome message
  cout << "\n\n\nHello! Let's play a guessing game! Guess the right number and win!\n\n\n" ;

  // replay loop
  while(replay == 'y')
    {
      // inputs
      cout << "\n\nSet the lower bound: " ;
      cin >> min;
      cout << "\n\nSet the upper bound: " ;
      cin >> max;
      cout << "\n\nI'm thinking of a number between " << min << " and " << max << ": " ;

      // calculation for random number
      answer = rand() % (max - min + 1) + min;
      
      // prevents a new round ending due to previous guess being the new answer
      guess = 0;

      // guess loop until correct
      while(guess != answer)
        {
          cin >> guess;
          if(guess > answer){
            cout << "\n\nToo high! Guess again: " ;
          }else if(guess < answer){
            cout << "\n\nToo low! Guess again: " ;
          }
        }

      // input for replay
      cout << "\n\nCorrect! You win! " ;
      cout << "\n\nPlay again?(y/n): " ;
      cin >> replay;
    }

  // goodbye message
  cout << "\n\n\nGoodbye!\n\n\n" ;

  return 0;
}
