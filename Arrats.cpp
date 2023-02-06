#include <iostream> //Req'd for cout
#include <cmath>
using namespace std;
 


 //One Problem - What Is The Output?
// int main(void){
// const int SIZE = 5;
// int i;
// int iary[SIZE] = {2,4,6,8,10};

// while (i < SIZE){
//     cout << iary[i] << endl;
//     i++; 
//     }
// return 0; 

// }



//Another Problem – What Is The Output?
int main(void){
const int SIZE = 5;
int i = 0;
int iary[SIZE] = {2,4,6,8,10};

while (i < SIZE) {
    cout << iary[i] << endl;
    iary[i]++  ; 
    }
return 0; 
}



