#include <iostream>
#include <string>
#include "colorSelect.h"

using namespace std;

//Programmer: Joshua Chang 
//Date: November 2021
//colorSelect Function Definitions
/*Purpose: Print out the options for user to select color*/

void colorSelect(string methodSelect){
  cout << "1. Red" << endl;
  cout << "2. Green" << endl;
  cout << "3. Blue" << endl;
  cout << "4. Black" << endl;
  cout << "5. White" << endl;
  
  if(methodSelect == "rectangle"){
    cout << "Enter int for rectangle color: ";
  }
  else if(methodSelect == "pattern"){
    cout << "Enter int for pattern color: ";
  }
  else if(methodSelect == "transparency"){
    cout << "Enter int for transparency color: ";
  }

}