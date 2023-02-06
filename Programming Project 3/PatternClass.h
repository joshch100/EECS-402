#ifndef _PATTERNCLASS_H_
#define _PATTERNCLASS_H_

#include <string>
#include "ColorClass.h"

using namespace std;

//Programmer: Joshua Chang 
//Date: November 2021
//PatternClass Functions Declaration
//Purpose: Deal with setting up pattern images, and acquiring its attributes

class PatternClass{
  private:
    int ppmWidth; //the width of the pattern
    int ppmHeight; //the height of the pattern
    int **imgpointer; //pattern pointer is pointing to either integer 0 or 1
    ColorClass patColor; //the color of the pattern

  public:
    PatternClass(); //default constructor
    bool initializePattern(string inputFileName); 
    //intialize pattern and check status
    void setPatternColor(int colorChoice); //set up pattern color 
    int getWidth(); //get width value
    int getHeight(); //get height value
    ColorClass getColor(); //get pattern color 
    int **getpointer(); //get pattern's pointer
};

#endif
  

