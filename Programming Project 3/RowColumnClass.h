#ifndef _ROWCOLUMNCLASS_H_
#define _ROWCOLUMNCLASS_H_


using namespace std;

//Programmer: Joshua Chang 
//Date: November 2021
//RowColumnClass Functions Declaration
//Purpose: Deal with setting up/getting locations of rows and columns


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

#endif