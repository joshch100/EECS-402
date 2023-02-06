#include <iostream> 
using namespace std;

#include <string>
#include "string.h"


template <class T>
T add(T val1, T val2){
  return val1 + val2;
}

template <class T>
T subtract(T val1, T val2){
  return val1 - val2;
}

int fib(int index){
  //base case 
  if(index <= 1){
    return 1;
  }
  //recusrsive case
  return fib(index - 1) + fib(index - 2);
}




int main(){
  cout << fib(5) << endl;
  double a = 3.4;
  double b = 2;
  string hello = "Hello ";
  string world = "World!";

  cout << add(1, 5) << endl;
  cout << add(3.4, 2.0) <<endl;
  cout << add(hello, world) << endl;
  cout << add(a,b) << endl;

}