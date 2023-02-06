//IF/Else If


#include <iostream>
using namespace std;

//Programmer: Joshua Pang-Yen Chang
//Date: Sep, 2021
//Purpose: To write down some simple prgram that were discussed in the discussion
int main()
{
    const int SMALL = 10;
    const int LARGE = 30;

    int num = 22;
    if(num <= SMALL)
    {
        cout << "Number is small" << endl;
    }
    else if(num >= LARGE)
    {
        cout << "Number is large" << endl;
    }
    else
    {
        cout << "Number is medium" << endl;
    }
    return 0;

}

//Switch Statements 

int main2()
{
    int num = 5;
    switch(num) {
        case 1:
            cout << "Num is 1" << endl;
            break;
        case 3:
            cout << "Num is 3" << endl;
            break;
        case 5:
            cout << "Num is 5" << endl;
        default:
            cout << "Default case" << endl; 
    
    
    }

    return 0;

}


//While Loop

#include <iostream>
using namespace std;

int main3(){
    const int MAX_INDEX = 30;

    int index = 0;

    while(index <= MAX_INDEX){
        cout << index << endl;
        ++index;

    }

    return 0;

}

//Do While Loop

int main4(){
    const int MAX_INDEX = 30;

    int index = 0;

    do{
        cout << index << endl;
        ++index;
    } while (index < MAX_INDEX);


    return 0;

}

//For loops


#include <iostream>
using namespace std;

int main5(){
    const int MAX_INDEX = 30;

    for(int index = 0; index < MAX_INDEX;  ++index){   //(declare and intialize a loop control variable, loop-continuation condition, increment)
         cout << index << endl; //body
    }

    return 0;

}



//Example: Add all the odd numbers 1 to 30 using  for loop
int count = 0;
for(int i=1; int <= 30; i+=2){
    count += i; 
}


//Nested for loop
for(int i=1; i<3; ++i){
    for(int j =1; j<4; ++j){
        cout << i+j << endl;
    }
}


