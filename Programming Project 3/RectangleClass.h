#ifndef _RECTANGLECLASS_H_
#define _RECTANGLECLASS_H_
#include <string>
#include "ColorClass.h"
#include "RowColumnClass.h"


using namespace std;

//Programmer: Joshua Chang 
//Date: November 2021
//RectangleClass Functions Declaration
//Purpose: Deal with setting up/acquiring rectangle's locations and colortype


class RectangleClass{
  private:
    RowColumnClass upperLeft; //rectangle's upperleft location
    RowColumnClass downRight; //rectangle's downright location
    ColorClass recColor; //the color of the rectangle

  public:
    RectangleClass(int upperLeftRow, int upperLeftCol, 
                   int downRightRow, int downRightcol); 
    void setRectangleColor(int colorChoice); // choose color
    RowColumnClass getUpperLeft(); //get the upperLeft value of a rectangle
    RowColumnClass getDownRight(); //get the downRight value of a rectangle
    ColorClass getColor(); //get the recColor value of a rectangle
};


#endif