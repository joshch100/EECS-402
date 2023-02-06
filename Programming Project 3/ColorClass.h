#ifndef _COLORCLASS_H_
#define _COLORCLASS_H_

#include <string>
#include <iostream> 


using namespace std;

//Programmer: Joshua Chang 
//Date: November 2021
//ColorClass Functions Declaration
//Purpose: Deal with setting up, acquiring, and modifying RGB colors 

class ColorClass{
  private:
    int amountRed; 
    int amountGreen;
    int amountBlue;

    //RESUBMISSION UPDATE
    //Deleted int colorIndex, since it does not describe a colour
    //integer representing the amount of differnet RGB colors
    // int colorIndex; 
  
    
  public:
    ColorClass();
    ColorClass(int inRed, int inGreen, int inBlue);
    bool checkInRange(int color); 
    //check if it's a valid value 
    int changeOneColor(int color); 
    //change the value of a single color to another
    void setToBlack(); //sets the color object to color black
    void setToRed(); //sets the color object to color red
    void setToGreen(); //sets the color object to color green
    void setToBlue(); //sets the color object to color blue
    void setToWhite(); //sets the color object to color white

    bool setTo(int inRed, int inGreen, int inBlue);
    //sets the color object's RGB values to the provided values

    void setTo(ColorClass inColor);
    /*sets the color object's RGB values to the same as those in the 
    "inColor" input parameter*/
    /*In this project we change this from bool to void*, and pass Color Class
    by value*/

    bool addColor(ColorClass &rhs);
    /* adds each RGB value with the corresponding value from the input 
    parameter*/

    bool subtractColor(ColorClass &rhs);
    /* subtracts each RGB value with the corresponding value from the input 
    parameter*/
    bool adjustBrightness(double adjFactor);
    /*Adjusts the brightness of by multiplying each of the RGB value with
    the input parameter "adjFactor"*/ 

    void printComponentValues();
    //Prints the component color values

    void readColorValue(ifstream &inFile);
    //Read the infile red, green, blue values


    //RESUBMISSION UPDATE
    //Deleted any functions that are related to colorIndex

    // int getColorIndex();
    // //obtain the colorIndex variable for pattern differentiation 

    // void setColorIndex(int index);
    // //set colorIndex variable to either 0 or 1 

    bool compareColor(ColorClass color);
    //return true if colors are the same

    int getRed();
    //return the amountRed value to the caller
    int getGreen();
    //return the amountGreen to the caller
    int getBlue();
    //return the amountBlue to the caller

};


#endif