using namespace std;
#include <iostream>
#include <string>
#include <fstream>

// file name will be given in the command line
int main(int argc, char * argv[]) {//what star means there? 
    // TODO:
    // Error check argc

    if(argc != 2){
        cout << "Error: incorrect command line arguments" << endl;
        return 0;
    }


    // Open file and error check

    ifstream infile;
    string fileName = argv[1];
    infile.open(fileName.c_str());

    if(infile.fail()){
        cout << "Error: unable to open file" << endl;
        return 0;
   }


    // Read in data (error check as you go) and calculate average

    int sum = 0;
    int count = 0;
    int currentNum = 0;

    while(!infile.eof()){
        infile >> currentNum;

        if(infile.fail()){
            cout << "Non integer in file" << endl;
            return 0;
        }

        sum += currentNum;
        count ++;
    }


    // Write average to cout
    cout << (sum / count) << endl;



    // Close file
    infile.close();

    
    return 0;
}