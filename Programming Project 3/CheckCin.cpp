#include <iostream>
#include <string>
#include "CheckCin.h"
#include "constants.h"

using namespace std;

//Programmer: Joshua Chang 
//Date: November 2021
//CheckCin Function Definitions
/*Purpose: Check whether the input from user is a correct type, if it's in fail 
state print an error and which type we expect them to type in*/

bool checkCinFailOrNot(string checkType){
  if(cin.fail()){
    cin.clear();
    cin.ignore(200, '\n');  
    if(checkType == "integer"){
      cout << "Fail state! --Expected a positive integer value! "
      << endl;
    }
    if(checkType == "string"){
      cout << "Fail state! --Expected a string! " << endl;
    }
    return CIN_FAILED;
  }
  return CIN_NOT_FAILED;
}






