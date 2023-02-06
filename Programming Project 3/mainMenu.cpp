#include <iostream>
#include <string>
#include "mainMenu.h"
#include "constants.h"

using namespace std;

//Programmer: Joshua Chang 
//Date: November 2021
//MainMenu Function Definition
//Purpose: Print the main menu for user and return the answer in an int value

int mainMenu(){
  int answer;
  bool validInputFound;

  cout << "1. Annotate image with rectangle" << endl;
  cout << "2. Annotate image with pattern from file" << endl;
  cout << "3. Insert another image" << endl;
  cout << "4. Write out current image" << endl;
  cout << "5. Exit the program" << endl;
  cout << "Enter int for main menu choice: ";

  validInputFound = false;

  while(!validInputFound){
    cin >> answer;
    if(cin.fail() || answer > EXIT_PROGRAM || answer < EDIT_WITH_RECTANGLE){ 
      cin.clear();
      cin.ignore(200, '\n');
      cout << "Fail state! --" 
      << "Please enter an integer value from 1 to 5: ";
    }
    else{
      validInputFound = true;
    }
  }
  return answer;
}






