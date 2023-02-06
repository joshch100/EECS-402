#include <iostream>
#include "RowColumnClass.h"
#include "constants.h"

using namespace std;

//Programmer: Joshua Chang 
//Date: November 2021
//RowColumnClass Header Functions
//Purpose: Deal with setting up/getting locations of rows and columns


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
  rowIndex = inRow;
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




