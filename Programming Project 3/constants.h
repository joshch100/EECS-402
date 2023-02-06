#ifndef _CONSTANTS_H_
#define _CONSTANTS_H_

//Programmer: Joshua Chang 
//Date: November 2021
//Constants Declaration

const int INITIAL_RGB_VALUE = 255; //color’s initial RGB values
const int MAX_ALLOWED_VAL = 255; //color's max value
const int MIN_ALLOWED_VAL = 0; //color's min value
const int DEFAULT_VALUE = -99999; // the default row and column value
const int NUM_ROWS = 10; //the default 2D array column value 
const int NUM_COLS = 18; //the default 2D array row value


//Choice max and min value for the menu
const int EDIT_WITH_RECTANGLE = 1;
const int EDIT_WITH_PATTERN = 2;
const int INSERT_ANOTHER_IMAGE = 3;
const int WRITE_OUT_CURRENT = 4;
const int EXIT_PROGRAM = 5;

/*Pattern default value, we set to 0, which means the pixel should be not 
affected by the pattern.*/
const int PATTERN_DEFAULT_VALUE = 0;

//Choice for rectangle specification
const int UPPER_LEFT_DOWN_RIGHT = 1; 
const int UPPER_LEFT_DIMENSIONS = 2; 
const int EXTENT_FROM_CENTER = 3; 

//Color int respresentation 
const int INT_RED = 1; 
const int INT_GREEN = 2; 
const int INT_BLUE = 3; 
const int INT_BLACK = 4; 
const int INT_WHITE = 5; 

//Filled selection
const int FILL_NO = 1;
const int FILL_YES = 2;

//Rectangle filled or not boolean
const bool REC_IS_FILLED = true;
const bool REC_NOT_FILLED = false;

//Vaules that show cin fail or not
const bool CIN_FAILED = true;
const bool CIN_NOT_FAILED = false;

//Values that show if row and column values are within image's height and width
const bool ROWCOL_INRANGE = true;
const bool ROWCOL_OUTOFRANGE = false;

//Values that show whether Image or Pattern is setup successfully or not
const bool SETUP_SUCCESS = true;
const bool SETUP_FAILED = false;

#endif