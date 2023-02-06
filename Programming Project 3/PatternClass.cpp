#include <iostream>
#include <fstream>
#include <string>
#include "PatternClass.h"
#include "ColorClass.h"
#include "constants.h"
#include "RowColumnClass.h"
#include "RectangleClass.h"
#include "ColorImageClass.h"

using namespace std;

//Programmer: Joshua Chang 
//Date: November 2021
//PatternClass Function Definitions
//Purpose: Deal with setting up pattern images, and acquiring its attributes


PatternClass::PatternClass(){
  imgpointer = 0;
}
  
bool PatternClass::initializePattern(string inputFileName){
  ifstream inFile;
  string checkendoffile;
  inFile.open(inputFileName.c_str());
  if(inFile.fail()){
    cout << "Unable to open input file!" << endl;
    return SETUP_FAILED;
  }

  inFile >> ppmWidth;
  if(inFile.fail() || ppmWidth <= 0){
    cout << "Fail state! --Expected width as a positive integer!" << endl;
    return SETUP_FAILED;
  }
  else{
    inFile >> ppmHeight;
    if(inFile.fail() || ppmHeight <= 0){
      cout << "Fail state! --Expected height as a positive integer!" << endl;
      return SETUP_FAILED;
    }
  }

  imgpointer = new int*[ppmHeight];
  int i; //loop variable i 
  int j; //loop variable j 
  int intFileVal; //the value from the file
 
  for(i = 0; i < ppmHeight; i++){
    imgpointer[i] = new int[ppmWidth];             
  } 
  for(i = 0; i < ppmHeight; i++){
    for(j = 0; j < ppmWidth; j++){
      inFile >> intFileVal;
      if(inFile.fail()){
        cout << "Error when reading file! -exepected an integer value 0 or 1!"
        << " but found " << intFileVal << endl;
        return SETUP_FAILED;
      }
      else if((intFileVal != 0) && (intFileVal != 1)){
        cout << "Error found when trying to read the pattern value - expected"
        << " 0 or 1 but found " << intFileVal << endl;  
        return SETUP_FAILED; 
      }
      else{
        imgpointer[i][j] = intFileVal;
      }
    }
  }   
  
  inFile >> checkendoffile;
  if(checkendoffile != ""){
    cout << "Error-Eof reached!";
    cout << "The pattern values does not match the pattern size!";
    return SETUP_FAILED;
  } 

  inFile.clear();
  inFile.ignore(200, '\n'); 
  inFile.close(); 
  return SETUP_SUCCESS;    
}


void PatternClass::setPatternColor(int setColor){
  if(setColor == INT_RED){
    patColor.setToRed();
  }
  else if(setColor == INT_GREEN){
    patColor.setToGreen();
  } 
  else if(setColor == INT_BLUE){
    patColor.setToBlue();
  }
  else if(setColor == INT_BLACK){
    patColor.setToBlack();   
  }
  else if(setColor == INT_WHITE){
    patColor.setToWhite();   
  }
} 

int PatternClass::getWidth(){
  return ppmWidth;
}

int PatternClass::getHeight(){
  return ppmHeight;
}

ColorClass PatternClass::getColor(){
  return patColor;
}

int **PatternClass::getpointer(){
  return imgpointer;
}