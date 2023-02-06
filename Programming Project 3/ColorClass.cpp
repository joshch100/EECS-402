#include <iostream>
#include <fstream>
#include "ColorClass.h"
#include "constants.h"

using namespace std;

//Programmer: Joshua Chang 
//Date: November 2021
//ColorClass Function Definitions
//Purpose: Deal with setting up, acquiring, and modifying RGB colors  


ColorClass::ColorClass(){
  amountRed = INITIAL_RGB_VALUE;
  amountGreen = INITIAL_RGB_VALUE;
  amountBlue = INITIAL_RGB_VALUE;

  //RESUBMISSION UPDATE
  //Deleted colorIndex, since it does not represent a color 
  //colorIndex = PATTERN_DEFAULT_VALUE;
}
    
ColorClass::ColorClass(int inRed, int inGreen, int inBlue){
  amountRed = changeOneColor(inRed);
  amountGreen = changeOneColor(inGreen);
  amountBlue = changeOneColor(inBlue);
}

bool ColorClass::checkInRange(int color){
  if(color > MAX_ALLOWED_VAL || color < MIN_ALLOWED_VAL){
    return false;
  }
  return true;
}

int ColorClass::changeOneColor(int color){
  int colorValue;
  if(checkInRange(color)){
    colorValue = color;
  }
  else if(color > MAX_ALLOWED_VAL){
    colorValue = MAX_ALLOWED_VAL;
  } 
  else{
    colorValue = MIN_ALLOWED_VAL;
  }
  return colorValue;
}
    
void ColorClass::setToBlack(){
  amountRed = MIN_ALLOWED_VAL;
  amountGreen = MIN_ALLOWED_VAL;
  amountBlue = MIN_ALLOWED_VAL;
}

void ColorClass::setToRed(){
  amountRed = MAX_ALLOWED_VAL;
  amountGreen = MIN_ALLOWED_VAL;
  amountBlue = MIN_ALLOWED_VAL;
}

void ColorClass::setToGreen(){
  amountRed = MIN_ALLOWED_VAL;
  amountGreen = MAX_ALLOWED_VAL;
  amountBlue = MIN_ALLOWED_VAL;
}

void ColorClass::setToBlue(){
  amountRed = MIN_ALLOWED_VAL;
  amountGreen = MIN_ALLOWED_VAL;
  amountBlue = MAX_ALLOWED_VAL;
}
    
void ColorClass::setToWhite(){
  amountRed = MAX_ALLOWED_VAL;
  amountGreen = MAX_ALLOWED_VAL;
  amountBlue = MAX_ALLOWED_VAL;
}

bool ColorClass::setTo(int inRed, int inGreen, int inBlue){
/*if all the color parameters are in range, set the color object's RGB 
values to it */
  if(checkInRange(inRed) && checkInRange(inGreen) && checkInRange(inBlue)){
    amountRed = inRed;
    amountGreen = inGreen;
    amountBlue = inBlue;
    return false;
  }
/*if any color is out of range, we deal with it using the changeOneColor()
function */
  else{
    amountRed = changeOneColor(inRed);
    amountGreen = changeOneColor(inGreen);
    amountBlue = changeOneColor(inBlue);
    return true;
  }
}

void ColorClass::setTo(ColorClass inColor){
/*Since ColorClass attributes are always within the valid range, the function 
doesn not need clipping and should always return false.*/
  amountRed = inColor.amountRed;
  amountGreen = inColor.amountGreen;
  amountBlue = inColor.amountBlue;
}

bool ColorClass::addColor(ColorClass &rhs){
  bool trueOrFalse;
  amountRed += rhs.amountRed;
  amountGreen += rhs.amountGreen;
  amountBlue += rhs.amountBlue;
     
  trueOrFalse = setTo(amountRed, amountGreen, amountBlue);
  return trueOrFalse;
}

bool ColorClass::subtractColor(ColorClass &rhs){
  bool trueOrFalse;
  amountRed -= rhs.amountRed;
  amountGreen -= rhs.amountGreen;
  amountBlue -= rhs.amountBlue;
  trueOrFalse = setTo(amountRed, amountGreen, amountBlue);
  return trueOrFalse;
}

bool ColorClass::adjustBrightness(double adjFactor){
  int intAmountRed; //The adjusted brightness value
  int intAmountGreen;
  int intAmountBlue;
  bool trueOrFalse;

  amountRed *= adjFactor;
  amountGreen *= adjFactor;
  amountBlue *= adjFactor;
  //type cast from double to int:
  intAmountRed = int(amountRed);
  intAmountGreen = int(amountGreen);
  intAmountBlue = int(amountBlue);

  trueOrFalse = setTo(intAmountRed, intAmountGreen, intAmountBlue);
  return trueOrFalse;
}


void ColorClass::printComponentValues(){
  cout << "R: " << amountRed << " " << "G: " << amountGreen << " " 
  << "B: " << amountBlue;
}


void ColorClass::readColorValue(ifstream &inFile){
  inFile >> amountRed >> amountGreen >> amountBlue;
}

//RESUBMISSION UPDATE
//Deleted any functions that are related to colorIndex

// int ColorClass::getColorIndex(){
//   return colorIndex;
// }

// void ColorClass::setColorIndex(int index){
//   colorIndex = index;
// }

bool ColorClass::compareColor(ColorClass colorclass){
  if (amountRed != colorclass.amountRed){
    return false;
  }
  else if (amountGreen != colorclass.amountGreen){
    return false;
  }
  else if (amountBlue != colorclass.amountBlue){
    return false;
  }
  else{
    return true;
  }
}

int ColorClass::getRed(){
  return amountRed;
}

int ColorClass::getGreen(){
  return amountGreen;
}

int ColorClass::getBlue(){
  return amountBlue;
}
