#include <iostream>
#include <string>
#include "RowColumnClass.h"
#include "ColorClass.h"
#include "RectangleClass.h"
#include "constants.h"

using namespace std;

//Programmer: Joshua Chang 
//Date: November 2021
//RectangleClass Function Definitions 
//Purpose: Deal with setting up/acquiring rectangle's locations and colortype


RectangleClass::RectangleClass(int upperLeftRow, int upperLeftCol, 
                                int downRightRow, int downRightcol){
  upperLeft.setRowCol(upperLeftRow, upperLeftCol);
  downRight.setRowCol(downRightRow, downRightcol);
}

void RectangleClass::setRectangleColor(int setColor){
  if(setColor == INT_RED){
    recColor.setToRed();
  }
  else if(setColor == INT_GREEN){
    recColor.setToGreen();
  } 
  else if(setColor == INT_BLUE){
    recColor.setToBlue();
  }
  else if(setColor == INT_BLACK){
    recColor.setToBlack();   
  }
  else if(setColor == INT_WHITE){
    recColor.setToWhite();   
  }
} 

RowColumnClass RectangleClass::getUpperLeft(){
  return upperLeft;
} 

RowColumnClass RectangleClass::getDownRight(){
  return downRight;
}


ColorClass RectangleClass::getColor(){
  return recColor;
}





