// Kevin Bui
// hw_1.cpp
// 10/8/21

// Purpose: The purpose of this program is to take words and numbers from the user
// to create an ad-lib.

// Input: two numbers and 8 variables

// Processing: storing and displaying user inputs

// Output: A wacky paragraph

// Example: On a foggy Saturday morning, a cat named Cheeseburger woke up feeling super hungry.
// After much thinking, Cheeseburger decided to look for green candy canes at a Macy's.
// Cheeseburger ate 400 candy canes, but was still hungry!
// Cheeseburger then found a pile of waffles, and ate so
// many that he gained 900 pounds! Now Cheeseburger is full,
// and heads home for a quick nap before his next meal. The End!

#include <iostream>
#include <string>

using namespace std;

int main()
{
  // Variables
  int amount = 0, pounds = 0;
  string name, weatherAdj, day, animal, color, foodOne, foodTwo , store;
  
  // Welcome message
  cout << "\n\n\n\nHello! Let's create an ad-lib. I need your help with coming up with words\n" 
       << "and numbers to fill out this paragraph. "

  // Input 
       << "\n\nPlease enter:\n\nA name: ";
  getline(cin, name);
  cout << "\nAn adjective for the weather: ";
  getline(cin, weatherAdj);
  cout << "\nA day of the week: ";
  getline(cin, day);
  cout << "\nAn animal: ";
  getline(cin, animal);
  cout << "\nA color: ";
  getline(cin, color);
  cout << "\nA type of food: ";
  getline(cin, foodOne);
  cout << "\nAnother type of food: ";
  getline(cin, foodTwo);
  cout << "\nA store name: ";
  getline(cin, store);
  cout << "\nA number: ";
  cin >> amount;
  cout << "\nAnother number: ";
  cin >> pounds;

  // Output
  cout << "\n\nReady to hear the ad-lib?\n\n\n\n"
       << "On a " << weatherAdj <<" " << day << " morning, a " << animal << " named "
       << name << " woke up feeling super hungry.\nAfter much thinking, "
       << name << " decided to look for " << color <<" " << foodOne << " at a " << store
       << ".\n" << name << " ate " << amount << " " << foodOne << ", but was still hungry!\n"
       << name << " then found a pile of " << foodTwo << ", and ate so\n"
       << "many that " << name << " gained " << pounds << " pounds! Now "
       << name << " is full,\nand heads home for a quick nap before his next meal."
       << "\n\nThe End!\n\nThanks for helping me, Goodbye!\n\n\n ";
       
  return 0;
}
