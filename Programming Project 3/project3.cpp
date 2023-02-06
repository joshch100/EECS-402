#include <iostream>
#include <fstream>
#include <string> 
#include "constants.h"
#include "RowColumnClass.h"
#include "ColorClass.h"
#include "RectangleClass.h"
#include "PatternClass.h"
#include "ColorImageClass.h"
#include "mainMenu.h"
#include "colorSelect.h"
#include "CheckCin.h"

using namespace std;

//Programmer: Joshua Chang 
//Date: November 2021
/*Purpose: Use dynamic allocation of arrays, file input/output, implementation 
of multiple files to modify images*/ 


int main(){
  string fileName;
  ColorImageClass fileImage;
  cout << "Enter string for PPM image file name to load: ";
  cin >> fileName;

  if(fileImage.initializeImage(fileName)){
    int option = 0;
    //If user did not choose 5.exit the program, then the program will not stop
    while(option != EXIT_PROGRAM){ 
      option = mainMenu(); 
      //Choosed main option 1 to edit with rectangle  
      if(option == EDIT_WITH_RECTANGLE){
        int chosenMethod = 0; //Inialize the choesnMethod to zero 
        int leftCornerRow = 0; //Intialize all row and column values to zero
        int lefCornerCol = 0;
        int rightCornerRow = 0;
        int rightCornerCol = 0;
        bool setUpCondition = SETUP_FAILED;

        cout << "1. Specify upper left and lower right corners of rectangle" 
        << endl; 
        cout << "2. Specify upper left corner and dimensions of rectangle"
        << endl;
        cout << "3. Specify extent from center of rectangle" << endl;
        cout << "Enter int for rectangle specification method: ";
        cin >> chosenMethod;
      
        if(cin.fail() || chosenMethod > EXTENT_FROM_CENTER || 
                          chosenMethod < UPPER_LEFT_DOWN_RIGHT){
          cin.clear();
          cin.ignore(200, '\n'); 
          cout << "Fail state! --Expected an integer value from 1 to 3!" 
          << endl;
        }
        else{ 
          //choosed method 1 or 2
          if(chosenMethod != EXTENT_FROM_CENTER){
            cout << "Enter upper left corner row and column: ";
            cin >> leftCornerRow;
            if(!checkCinFailOrNot("integer")){
              cin >> lefCornerCol;
              if(!checkCinFailOrNot("integer")){
                //choosed method 1
                if(chosenMethod == UPPER_LEFT_DOWN_RIGHT){
                  cout << "Enter lower right corner row and column: ";
                  cin >> rightCornerRow;
                  if(!checkCinFailOrNot("integer")){
                    cin >> rightCornerCol;
                    if(!checkCinFailOrNot("integer")){
                      setUpCondition = SETUP_SUCCESS;
                    }
                  }
                }  
                //choosed method 2
                if(chosenMethod == UPPER_LEFT_DIMENSIONS){
                  cout << "Enter int for number of rows: ";
                  cin >> rightCornerRow;
                  if(!checkCinFailOrNot("integer")){
                    rightCornerRow = rightCornerRow + leftCornerRow; 
                    cout << "Enter int for number of columns: ";
                    cin >> rightCornerCol; 
                    if(!checkCinFailOrNot("integer")){
                      rightCornerCol = rightCornerCol + lefCornerCol; 
                      setUpCondition = SETUP_SUCCESS;
                    }
                  }
                }
              }   
            }
          }
                
          //choosed method 3
          else{
            int centerRow;
            int centerCol;
            int halfRow;
            int halfCol;
            cout << "Enter rectangle center row and column: ";
            cin >> centerRow;
            if(!checkCinFailOrNot("integer")){
              cin >> centerCol;
              if(!checkCinFailOrNot("integer")){
                cout << "Enter int for half number of rows: ";
                cin >> halfRow;
                if(!checkCinFailOrNot("integer")){
                  cout << "Enter int for half number of columns: ";
                  cin >> halfCol;
                  if(!checkCinFailOrNot("integer")){
                    leftCornerRow = centerRow - halfRow;
                    lefCornerCol = centerCol - halfCol;
                    rightCornerRow = centerRow + halfRow;
                    rightCornerCol = centerCol + halfCol;
                    setUpCondition = SETUP_SUCCESS;
                  }           
                }
              }
            }
          }
        }
        //choose rectangle color 
        if(setUpCondition == SETUP_SUCCESS){
          int colorInt; 
          int fillOption;
          colorSelect("rectangle");
          cin >> colorInt;
          RectangleClass rec(leftCornerRow, lefCornerCol,
                                rightCornerRow, rightCornerCol);
        
          rec.setRectangleColor(colorInt);
          cout << "1. No" << endl;
          cout << "2. Yes" << endl;
          cout << "Enter int for rectangle fill option: ";
          cin >> fillOption;
          if(!checkCinFailOrNot("integer")){
            if(fillOption == FILL_NO){
              fileImage.drawRecOnImage(rec, REC_NOT_FILLED);
            }
            if(fillOption == FILL_YES){
              fileImage.drawRecOnImage(rec, REC_IS_FILLED);
            } 
          }
        }
      }

      //Choosed main option 2 to annotate with pattern 
      if(option == EDIT_WITH_PATTERN){
        string patternFileName;
        PatternClass patternMade;
        int patternStartRow;
        int patternStarTCol;
        int colorSelection;

        cout << "Enter string for file name containing pattern: ";
        cin >> patternFileName;

        if(patternMade.initializePattern(patternFileName)){
          cout << "Enter upper left corner of pattern row and column: ";
          cin >> patternStartRow;
          if(!checkCinFailOrNot("integer")){
            cin >> patternStarTCol; 
            if(!checkCinFailOrNot("integer")){
              colorSelect("pattern");
              cin >> colorSelection; 
              if(!checkCinFailOrNot("integer")){
                patternMade.setPatternColor(colorSelection);
                fileImage.drawPattern(patternMade, patternStartRow, 
                                                   patternStarTCol);
              }
            }
          }
        }   
        else{
          cout << "Please submit a correct file!" << endl;
        }
      }

      //Choosed main option 3 to insert another image 
      if(option == INSERT_ANOTHER_IMAGE){
        string imageFileName;
        ColorImageClass imageFile;
        int insertStartRow;
        int insertStartCol;
        int transparencyColor;

        cout << "Enter string for file name of PPM image to insert: ";
        cin >> imageFileName;
        if(!checkCinFailOrNot("string")){
          if(imageFile.initializeImage(imageFileName)){
            cout << "Enter upper left corner to insert image row and column: ";
            cin >> insertStartRow;
            if(!checkCinFailOrNot("integer")){
              cin >> insertStartCol;
              if(!checkCinFailOrNot("integer")){
                colorSelect("transparency");
                cin >> transparencyColor;
                if(!checkCinFailOrNot("integer")){
                  imageFile.setTransparencyColor(transparencyColor);
                  fileImage.insertImage(imageFile, insertStartRow,  
                                                  insertStartCol);
                }
              }
            }    
          }
        }  
        else{
        cout << "Please submit a correct file!" << endl;
        }
      }

      //Choosed main option 4 to write out current image
      if(option == WRITE_OUT_CURRENT){
        string outPutString;
        cout << "Enter string for PPM file name to output: ";
        cin >> outPutString;
        if(!checkCinFailOrNot("string")){
          //RESUBMISSION UPDATE
          fileImage.writeImageToFile(outPutString);
        }
      }

    
    }
    //choosed main option 5 to exit the program
    if(option == EXIT_PROGRAM){
      cout << "Thank you for using this program" << endl;
    }
  }
  cin.clear();
  cin.ignore(200, '\n');
}