#include <iostream>
#include <string>
#include <fstream>
#include "ColorImageClass.h"
#include "constants.h"
#include "RowColumnClass.h"
#include "ColorClass.h"
#include "RectangleClass.h"
#include "PatternClass.h"

using namespace std;

//Programmer: Joshua Chang 
//Date: November 2021
//ColorImageClass Function Definitions
//Purpose: Deal with inputting/outputting images and modifying images 

ColorImageClass::ColorImageClass(){
  imgpointer = 0;
}
  

bool ColorImageClass::checkInLocation(int locRow, int locCol){
  if(locRow > (NUM_ROWS - 1) || locCol > (NUM_COLS - 1)){
    return false;
  }
  else{
    return true;
  }
}


bool ColorImageClass::initializeImage(string inputFileName){ 
  ifstream inFile;
  string checkendoffile;
  inFile.open(inputFileName.c_str());

  //Check opening file resulted in a file stream in a good state
  if(inFile.fail()){
    cout << "Unable to open input file!" << endl;
    return SETUP_FAILED;
  }

  inFile >> imageMagicNumber;
  if(imageMagicNumber != "P3"){
    cout << "Error found when trying to read magic number - expected P3" 
    << " but found " << imageMagicNumber << endl;
    return SETUP_FAILED;
  }

  inFile >> ppmWidth;
  //check width value is correct
  if(ppmWidth <= 0){
    cout << "Error found when trying to read the width value - expected"
    << " a postive integer but found " << ppmWidth << endl;
    return SETUP_FAILED;
  }
  else{
    inFile >> ppmHeight;
    //check height value is correct
    if(ppmWidth <= 0){
      cout << "Error found when trying to read the height value - expected"
      << " a postive integer but found " << ppmHeight << endl;
      return SETUP_FAILED;
    }
  } 

  inFile >> colorShades;
  //check colorShades value is in range
  if(colorShades > MAX_ALLOWED_VAL || colorShades < MIN_ALLOWED_VAL){
    cout << "Error found when trying to read the colorShades value - expcted" 
    << "value between 0 and 250, but found " << colorShades << endl; 
    return SETUP_FAILED;                                                 
  }

  
  else{
    imgpointer = new ColorClass*[ppmHeight];
    int i; //loop variable i 
    int j; //loop variable j 
    
    for(i = 0; i < ppmHeight; i++){
      imgpointer[i] = new ColorClass[ppmWidth];             
    } 
    for(i = 0; i < ppmHeight; i++){
      for(j = 0; j < ppmWidth; j++){
        imgpointer[i][j].readColorValue(inFile);
          //use colorclass function to read
      }
    } 

              
    //Error check if eof
    inFile >> checkendoffile;
    if(checkendoffile != ""){
      cout << "Error-Eof reached!" << endl;
      cout << "The RGB values does not match image size!";
      return SETUP_FAILED;
    } 
    inFile.clear();
    inFile.ignore(200, '\n');    
    inFile.close();
    
    return SETUP_SUCCESS;    
  }
}

void ColorImageClass::drawRecOnImage(RectangleClass &recImg, bool filledOrNot){
  int i;
  int j;
  int startRow;
  int endRow;
  int startCol;
  int endCol;
  startRow = recImg.getUpperLeft().getRow();
  endRow = recImg.getDownRight().getRow();
  startCol = recImg.getUpperLeft().getCol();
  endCol = recImg.getDownRight().getCol();
  //RESUBMISSION UPDATE
  //Check rectangle row and col is in range
  if(checkRowColIndex(endRow, endCol)){
    if(filledOrNot == REC_IS_FILLED){
      for(i = startRow; i < endRow + 1; i++){
        for(j = startCol; j < endCol + 1; j++){
          imgpointer[i][j].setTo(recImg.getColor()); 
        }
      }
    } 
    
    if(filledOrNot == REC_NOT_FILLED){
      for(j = startCol; j < endCol + 1; j++){
        imgpointer[startRow][j].setTo(recImg.getColor());
        imgpointer[endRow][j].setTo(recImg.getColor());
      }
      for(i = startRow; i < endRow + 1; i++){
        imgpointer[i][startCol].setTo(recImg.getColor());
        imgpointer[i][endCol].setTo(recImg.getColor());  
      }
    }
  }
  else{
  cout << "Error! Rectangle row and column value is out of image's range!" 
  << endl;
  }  
}



void ColorImageClass::drawPattern(PatternClass &patImage, int startRow, 
                                                    int startCol){
  int i;
  int j;
  int endRow = startRow + patImage.getHeight();
  int endCol = startCol + patImage.getWidth();
  //RESUBMISSION UPDATE
  //Check pattern row and col is in range
  if(checkRowColIndex(endRow, endCol)){
    for(i = startRow; i < endRow; i++){
      for(j = startCol; j < endCol; j++){
        //RESUBMISSION UPDATE
        if((patImage.getpointer()[i - startRow][j-startCol]) == 1){        
        imgpointer[i][j].setTo(patImage.getColor());
        }
      }
    }
  }
  else{
  cout << "Error! Pattern row and column value is out of image's range!" 
  << endl;  
  }
}
  


void ColorImageClass::insertImage(ColorImageClass &colorImage, int startRow
                                                        , int startCol){
  // this color image has transparency color
  int i;
  int j;
  int endRow = startRow + colorImage.getHeight();
  int endCol = startCol + colorImage.getWidth();
  //RESUBMISSION UPDATE
  //Check inserted image row and col is in range
  if(checkRowColIndex(endRow, endCol)){
    for(i = startRow; i < endRow; i++){
      for(j = startCol; j < endCol; j++){
          // check pixels'comparison result before setting
        if(!(colorImage.getpointer()[i - startRow][j - startCol]
                                    .compareColor(colorImage.transParency))){
          imgpointer[i][j].setTo(colorImage.getpointer()[i - startRow][j 
                                                              - startCol]);   
        }
      }
    }
  }
  else{
  cout << "Error! Image row and column value is out of orginal image's range!" 
  << endl;
  }
     
}



void ColorImageClass::setTransparencyColor(int setColor){
  if(setColor == INT_RED){
    transParency.setToRed();
  }
  else if(setColor == INT_GREEN){
    transParency.setToGreen();
  } 
  else if(setColor == INT_BLUE){
    transParency.setToBlue();
  }
  else if(setColor == INT_BLACK){
    transParency.setToBlack();   
  }
  else if(setColor == INT_WHITE){
    transParency.setToWhite();   
  }
}


ColorClass **ColorImageClass::getpointer(){
  return imgpointer;
}

string ColorImageClass::getType(){
  return imageMagicNumber;
}

int ColorImageClass::getWidth(){
  return ppmWidth;
}

int ColorImageClass::getHeight(){
  return ppmHeight;
}

int ColorImageClass::getColorShades(){
  return colorShades;
}

//RESUBMISSION

bool ColorImageClass::checkRowColIndex(int RowIndex, int ColIndex){
  if(RowIndex <= 0 || RowIndex < ppmHeight){
    if(ColIndex <= 0 || ColIndex < ppmWidth){
    return ROWCOL_INRANGE;
    }
  }  
  return ROWCOL_OUTOFRANGE;
}



//RESUBMISSION UPDATE
void ColorImageClass::writeImageToFile(string outputFileName){
  ofstream outFile;
  outFile.open(outputFileName.c_str()); 
  /*remeber that the file stream “open” methods require 
  a filename input as a C-string*/ 
  if(outFile.fail()){
    cout << "Unable to open output file" << endl;
  }
  else{
    outFile << imageMagicNumber << endl; 
    outFile << ppmWidth << " ";
    outFile << ppmHeight << endl;
    outFile << colorShades << endl;

    int i;
    int j; 

    for(i = 0; i < ppmHeight; i++){
      for(j = 0; j < ppmWidth; j++){
        outFile << imgpointer[i][j].getRed() << " " <<
        imgpointer[i][j].getGreen() << " " <<
        imgpointer[i][j].getBlue() << " ";
      }    
    }
  }
  outFile.close();
}




