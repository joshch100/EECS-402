#ifndef _COLORIMAGECLASS_H_
#define _COLORIMAGECLASS_H_

#include <string>
#include "ColorClass.h"
#include "RectangleClass.h"
#include "PatternClass.h"


using namespace std;

//Programmer: Joshua Chang 
//Date: November 2021
//ColorImageClass Functions Declaration
//Purpose: Deal with inputting/outputting images and modifying images 


class ColorImageClass{
  private:
    string imageMagicNumber;
    int ppmWidth;
    int ppmHeight;
    int colorShades;
    ColorClass **imgpointer;
    ColorClass transParency;

  public:  
    ColorImageClass();
    //default constructor 

    bool checkInLocation(int locRow, int locCol);
    //check if the location specified is a valid location for the image

    bool initializeImage(string inputFileName);
    //check the input file is succesfully constructed

    void drawRecOnImage(RectangleClass &recImg, bool filledOrNot);
    //draw a rectangle on a image
    
    void drawPattern(PatternClass &patImage, int startRow, int startCol);

    void insertImage(ColorImageClass &colorImage, int startRow
                                                , int startCol);

    void initializeTo(ColorClass &inColor);
    //initializes all image pixels to the color provided via input

    bool addImageTo(ColorImageClass &rhsImg);
    /*adds each pixel's value with the corresponding location 
    in the right hand side input image added to it.*/

    bool addImages(int numImgsToAdd, ColorImageClass imagesToAdd[]);  
    /*sets the image's pixel values to the sum of the corresponding pixels 
    in each image in the imagesToAdd input parameter*/

    void setTransparencyColor(int colorChoice); //set up transparency color  

    ColorClass **getpointer(); //get the pointer of the colorImage class

    string getType(); //get the imageMagicNumber value from the colorImage 

    int getWidth(); //get the Width value from the colorImage

    int getHeight(); //get the Height value from the colorImage

    int getColorShades(); //get the colorShades value from the colorImage

    //RESUBMISSION UPDATE
    /*check that each row and column values are within the height and width of 
    the image*/
    bool checkRowColIndex(int RowIndex, int ColIndex); 
    
    //RESUBMISSION UPDATE
    /*output the image to file and passing a file name*/
    void writeImageToFile(string outputFileName);


};

#endif
