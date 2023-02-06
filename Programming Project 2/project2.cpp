#include <iostream>

using namespace std;

//Programmer: Joshua Chang 
//Date: October 2021
/*Purpose: To use object-oriented programming to develop some simple classes 
to represent and utilize colors and images.*/ 

const int INITIAL_RGB_VALUE = 1000; //color’s initial RGB values
const int MAX_ALLOWED_COLOR_VAL = 1000; //color's max value
const int MIN_ALLOWED_COLOR_VAL = 0; //color's min value
const int DEFAULT_VALUE = -99999; // the default row and column value
const int NUM_ROWS = 10; //the default 2D array column value
const int NUM_COLS = 18; //the default 2D array row value


//Class Declarations 
class ColorClass{
  private:
    int amountRed; 
    int amountGreen;
    int amountBlue;
    //integer representing the amount of differnet RGB colors
    bool checkInRange(int color); 
    //check if it's a valid value 
    int changeOneColor(int color); 
    //change the value of a single color to another

  public:
    ColorClass();
    ColorClass(int inRed, int inGreen, int inBlue);
    void setToBlack(); //sets the color object to color black
    void setToRed(); //sets the color object to color red
    void setToGreen(); //sets the color object to color green
    void setToBlue(); //sets the color object to color blue
    void setToWhite(); //sets the color object to color white
    bool setTo(int inRed, int inGreen, int inBlue);
    //sets the color object's RGB values to the provided values
    bool setTo(ColorClass &inColor);
    /*sets the color object's RGB values to the same as those in the 
    "inColor" input parameter*/
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
};


class RowColumnClass{
  
  private:
    int rowIndex; //represents the row index of the location
    int columnIndex; //represents the column index of the location
  

  public:
    RowColumnClass();
    //default constructor
    RowColumnClass(int inRow, int inCol);
    //sets the row and column values to the corresponding input valus
   
    void setRowCol(int inRow, int inCol);
    /*sets the row and column values to the 
    corresponding values passed into the constructor*/

    void setRow(int inRow);
    //sets the row value to the corresponding value 
    void setCol(int inCol);
    //sets the column value to the corresponding value 
    int getRow();
    //return the row value to the caller
    int getCol();
    //return the column value to the caller
    void addRowColTo(RowColumnClass &inRowCol);
    /*adds the row and column index values in the input parameter to 
    the row and column index of the object the function is called on*/
    void printRowCol();
    //prints this object's attribute values
};



class ColorImageClass{
  private:
    ColorClass arrayObject[NUM_ROWS][NUM_COLS];
    bool checkInLocation(int locRow, int locCol);
    //check if the location specified is a valid location for the image

  public:  
    ColorImageClass();
    //sets all pixels in the image to black

    void initializeTo(ColorClass &inColor);
    //initializes all image pixels to the color provided via input

    bool addImageTo(ColorImageClass &rhsImg);
    /*adds each pixel's value with the corresponding location 
    in the right hand side input image added to it.*/

    bool addImages(int numImgsToAdd, ColorImageClass imagesToAdd[]);  
    /*sets the image's pixel values to the sum of the corresponding pixels 
    in each image in the imagesToAdd input parameter*/

    bool setColorAtLocation(RowColumnClass &inRowCol, ColorClass &inColor);
    /*sets the pixel at the location specified by the “inRowCol” 
    parameter to the color specified via the “inColor” parameter*/

    bool getColorAtLocation(RowColumnClass &inRowCol, ColorClass &outColor);
    /*sets the output parameter "outColor" to the color of the image 
    pixel at that location*/

    void printImage();
    //prints the contents of the image
};




#ifdef ANDREW_TEST 
#include "andrewTest.h" 
#else
int main()
{
  ColorClass testColor;
  RowColumnClass testRowCol;
  RowColumnClass testRowColOther(111, 222);
  ColorImageClass testImage;
  ColorImageClass testImages[3];

  //Test some basic ColorClass operations...
  cout << "Initial: ";
  testColor.printComponentValues();
  cout << endl;

  testColor.setToBlack();
  cout << "Black: ";
  testColor.printComponentValues();
  cout << endl;

  testColor.setToGreen();
  cout << "Green: ";
  testColor.printComponentValues();
  cout << endl;

  testColor.adjustBrightness(0.5);
  cout << "Dimmer Green: ";
  testColor.printComponentValues();
  cout << endl;

  //Test some basic RowColumnClass operations...
  cout << "Want defaults: ";
  testRowCol.printRowCol();
  cout << endl;

  testRowCol.setRowCol(2, 8);
  cout << "Want 2,8: ";
  testRowCol.printRowCol();
  cout << endl;

  cout << "Want 111, 222: ";
  testRowColOther.printRowCol();
  cout << endl;

  testRowColOther.setRowCol(4, 2);
  testRowCol.addRowColTo(testRowColOther);
  cout << "Want 6,10: ";
  testRowCol.printRowCol();
  cout << endl;

  //Test some basic ColorImageClass operations...
  testColor.setToRed();
  testImage.initializeTo(testColor);

  testRowCol.setRowCol(555, 5);
  cout << "Want: Color at [555,5]: Invalid Index!" << endl;
  cout << "Color at ";
  testRowCol.printRowCol();
  cout << ": ";
  if (testImage.getColorAtLocation(testRowCol, testColor))
  {
    testColor.printComponentValues();
  }
  else
  {
    cout << "Invalid Index!";
  }
  cout << endl;

  testRowCol.setRow(4);
  cout << "Want: Color at [4,5]: R: 1000 G: 0 B: 0" << endl;
  cout << "Color at ";
  testRowCol.printRowCol();
  cout << ": ";
  if (testImage.getColorAtLocation(testRowCol, testColor))
  {
    testColor.printComponentValues();
  }
  else
  {
    cout << "Invalid Index!";
  }
  cout << endl;

  //Set up an array of images of different colors
  testColor.setToRed();
  testColor.adjustBrightness(0.25);
  testImages[0].initializeTo(testColor);
  testColor.setToBlue();
  testColor.adjustBrightness(0.75);
  testImages[1].initializeTo(testColor);
  testColor.setToGreen();
  testImages[2].initializeTo(testColor);

  //Modify a few individual pixel colors
  testRowCol.setRowCol(4, 2);
  testColor.setToWhite();
  testImages[1].setColorAtLocation(testRowCol, testColor);

  testRowCol.setRowCol(2, 4);
  testColor.setToBlack();
  testImages[2].setColorAtLocation(testRowCol, testColor);

  //Add up all images in testImages array and assign result
  //to the testImage image
  testImage.addImages(3, testImages);
  
  //Check some certain values
  cout << "Added values:" << endl;
  for (int colInd = 0; colInd < 8; colInd += 2)
  {
    testRowCol.setRowCol(4, colInd);
    cout << "Color at ";
    testRowCol.printRowCol();
    cout << ": ";
    if (testImage.getColorAtLocation(testRowCol, testColor))
    {
      testColor.printComponentValues();
    }
    else
    {
      cout << "Invalid Index!";
    }
    cout << endl;
  }
  
  for (int rowInd = 0; rowInd < 8; rowInd += 2)
  {
    testRowCol.setRowCol(rowInd, 4);
    cout << "Color at ";
    testRowCol.printRowCol();
    cout << ": ";
    if (testImage.getColorAtLocation(testRowCol, testColor))
    {
      testColor.printComponentValues();
    }
    else
    {
      cout << "Invalid Index!";
    }
    cout << endl;
  }
  
  cout << "Printing entire test image:" << endl;
  testImage.printImage();

  return 0;
}
#endif





//ColorClass Function Definitions 
bool ColorClass::checkInRange(int color){
  if(color > MAX_ALLOWED_COLOR_VAL || color < MIN_ALLOWED_COLOR_VAL){
    return false;
  }
  return true;
}
    
int ColorClass::changeOneColor(int color){
  int colorValue;
  if(checkInRange(color)){
    colorValue = color;
  }
  else if(color > MAX_ALLOWED_COLOR_VAL){
    colorValue = MAX_ALLOWED_COLOR_VAL;
  } 
  else{
    colorValue = MIN_ALLOWED_COLOR_VAL;
  }
  return colorValue;
}

ColorClass::ColorClass(){
  amountRed = INITIAL_RGB_VALUE;
  amountGreen = INITIAL_RGB_VALUE;
  amountBlue = INITIAL_RGB_VALUE;
}
    
ColorClass::ColorClass(int inRed, int inGreen, int inBlue){
  amountRed = changeOneColor(inRed);
  amountGreen = changeOneColor(inGreen);
  amountBlue = changeOneColor(inBlue);
}
    
void ColorClass::setToBlack(){
  amountRed = MIN_ALLOWED_COLOR_VAL;
  amountGreen = MIN_ALLOWED_COLOR_VAL;
  amountBlue = MIN_ALLOWED_COLOR_VAL;
}

void ColorClass::setToRed(){
  amountRed = MAX_ALLOWED_COLOR_VAL;
  amountGreen = MIN_ALLOWED_COLOR_VAL;
  amountBlue = MIN_ALLOWED_COLOR_VAL;
}

void ColorClass::setToGreen(){
  amountRed = MIN_ALLOWED_COLOR_VAL;
  amountGreen = MAX_ALLOWED_COLOR_VAL;
  amountBlue = MIN_ALLOWED_COLOR_VAL;
}

void ColorClass::setToBlue(){
  amountRed = MIN_ALLOWED_COLOR_VAL;
  amountGreen = MIN_ALLOWED_COLOR_VAL;
  amountBlue = MAX_ALLOWED_COLOR_VAL;
}
    
void ColorClass::setToWhite(){
  amountRed = MAX_ALLOWED_COLOR_VAL;
  amountGreen = MAX_ALLOWED_COLOR_VAL;
  amountBlue = MAX_ALLOWED_COLOR_VAL;
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

bool ColorClass::setTo(ColorClass &inColor){
/*Since ColorClass attributes are always within the valid range, the function 
doesn not need clipping and should always return false.*/
  amountRed = inColor.amountRed;
  amountGreen = inColor.amountGreen;
  amountBlue = inColor.amountBlue;
  return false;
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
  cout << "R: " << amountRed << " " << "G: " <<  amountGreen << " " 
  << "B: " << amountBlue;
}




//RowColumnClass Function Definitions 
RowColumnClass::RowColumnClass(){
  //sets both the row and column value of the newly 
  //created RowColumnClass object to -99999.
  rowIndex = DEFAULT_VALUE;
  columnIndex = DEFAULT_VALUE;
}

RowColumnClass::RowColumnClass(int inRow, int inCol){
  //sets the row and column values to the 
  //corresponding values passed into the constructor
  rowIndex = inRow;
  columnIndex = inCol;
}

void RowColumnClass::setRowCol(int inRow, int inCol){
  rowIndex = inRow;
  columnIndex = inCol;
}

void RowColumnClass::setRow(int inRow){
  rowIndex =inRow;
}
      
void RowColumnClass::setCol(int inCol){
  columnIndex = inCol;
}

int RowColumnClass::getRow(){
  return rowIndex;
}

int RowColumnClass::getCol(){
  return columnIndex;
}

void RowColumnClass::addRowColTo(RowColumnClass &inRowCol){ 
  rowIndex += inRowCol.rowIndex;
  columnIndex += inRowCol.columnIndex;
}


void RowColumnClass::printRowCol(){
  cout << "[" << rowIndex << "," << columnIndex << "]";
}


//ColorImageClass Function Definitions
bool ColorImageClass::checkInLocation(int locRow, int locCol){
  if(locRow > (NUM_ROWS-1) || locCol > (NUM_COLS-1)){
    return false;
  }
  else{
    return true;
  }
}

ColorImageClass::ColorImageClass() {
  int i; //loop variable i 
  int j; //loop variable j 
  for(i = 0; i < NUM_ROWS; i++){
    for(j = 0; j < NUM_COLS; j++){
      arrayObject[i][j].setToBlack();
    }
  }  
}
  

void ColorImageClass::initializeTo(ColorClass &inColor){
  int i; //loop variable i 
  int j; //loop variable j 
  for(i = 0; i<NUM_ROWS; i++){
    for(j = 0; j<NUM_COLS; j++){
      arrayObject[i][j].setTo(inColor);
    }
  }
}


bool ColorImageClass::addImageTo(ColorImageClass &rhsImg){
  bool trueOrFalse;
  int i; //loop variable i 
  int j; //loop variable j 
  for(i = 0; i<NUM_ROWS; i++){
    for(j = 0; j<NUM_COLS; j++){
      trueOrFalse = arrayObject[i][j].addColor(rhsImg.arrayObject[i][j]);
    }
  }
  return trueOrFalse;
}

bool ColorImageClass::addImages(int numImgsToAdd, 
                     ColorImageClass imagesToAdd[]){   //why there is no "&" here
  bool trueOrFalse;
  int i; //loop variable i 
  int j; //loop variable j 
  int k; //loop variable k

  for(i = 0; i<NUM_ROWS; i++){
    for(j = 0; j<NUM_COLS; j++){
      arrayObject[i][j].setToBlack();
    }
  }
  for(k=0; k<numImgsToAdd; k++){
    trueOrFalse = addImageTo(imagesToAdd[k]);
  }
  return trueOrFalse;
}


bool ColorImageClass::setColorAtLocation(RowColumnClass &inRowCol
                                            , ColorClass &inColor){   
  int rowValue = inRowCol.getRow();
  int colValue = inRowCol.getCol();

  if(checkInLocation(rowValue, colValue)){
    arrayObject[rowValue][colValue].setTo(inColor);
    return true;
  }
  return false;
}

bool ColorImageClass::getColorAtLocation(RowColumnClass &inRowCol, 
                                             ColorClass &outColor){
  int rowValue = inRowCol.getRow();
  int colValue = inRowCol.getCol();

  if(checkInLocation(rowValue, colValue)){
    outColor.setTo(arrayObject[rowValue][colValue]);
    return true;
  }
  return false;
}

void ColorImageClass::printImage(){
  int i; //loop variable i 
  int j; //loop variable j 
  for(i = 0; i<NUM_ROWS; i++){
    for(j = 0; j<NUM_COLS; j++){
      arrayObject[i][j].printComponentValues();
      if(j<NUM_COLS-1){
        cout << "--" ;
      }
    }
    cout << endl;
  }
}