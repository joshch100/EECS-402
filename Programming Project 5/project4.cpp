#include <iostream>
#include "SortedListClass.h"
#include "LinkedNodeClass.h"
#include "FIFOQueueClass.h"

//Programmer: Joshua Chang 
//Date: November 2021
//Project 4 Main Function
//Purpose: To test the funcionality of linked data structures 


using namespace std;

//Do NOT remove any of the preprocessor directives in this file.
//They should not affect your ability to write test code in your
//main function below, and they must be in your submitted main
//file exactly as provided to you with the project.
#ifdef ANDREW_TEST
#include "andrewTest.h"
#else 

int main()
{
  int outVal = 0;
  int theVal = 0;
  //This is just a placeholder main function - it does exceptionally
  //little actual testing, so you'll want to add your own tests here.
  //Feel free to leave your tests in the version of this file you
  //submit, but we will not be running your main function, so the
  //output, etc., of your main doesn't need to match anything from
  //a sample output, etc.
  SortedListClass<int> testList;
  
  //test SortedListClass
  testList.printForward();
  testList.insertValue(42);

  testList.printForward();
  

  testList.insertValue(10000);
  
  testList.insertValue(15);
  testList.printForward();
  testList.printBackward();
  cout << "there are elements: " << testList.getNumElems() << endl;

  testList.insertValue(20);
  testList.insertValue(15);
  testList.insertValue(3);
  testList.printForward();
  testList.removeFront(theVal);
  cout << "Reomved from front: " << theVal << endl;
  
  testList.removeLast(theVal);
  cout << "Removed from last: " << theVal << endl;
  testList.printForward();

  testList.getElemAtIndex(2, outVal);
  cout << "Get Element Index at 2: " << outVal << endl;


  SortedListClass<char> testList2;
  
  //test SortedListClass
  testList2.printForward();
  testList2.insertValue('a');

  
  

  testList2.insertValue('b');
  
  testList2.printForward();




  

  //test LIFOStackClass
  // cout << "LIFO Stack Class: " << endl;
  // int outItem;

  // LIFOStackClass<int> testLifo;

  // testLifo.print();

  // testLifo.push(20);

  // testLifo.print();

  // testLifo.push(200);

  // testLifo.print();

  // testLifo.push(55);

  // testLifo.print();

  // testLifo.pop(outItem);

  // testLifo.print();

  // cout << "This is the last in first out item: " << outItem << endl;

  // testLifo.pop(outItem);
  
  // cout << "This is the last in first out item: " << outItem << endl;

  // testLifo.print();

  // testLifo.pop(outItem);

  // cout << "This is the last in first out item: " << outItem << endl;



  // cout << "Total LIFO elements are: " << testLifo.getNumElems() << endl;

  
  // testLifo.pop(outItem);

  // cout << "This is the last in first out item: " << outItem << endl;


  
  
  //test FIFOQueue Class
  FIFOQueueClass<int> testFIFO;
  cout << "FIFO Stack Class: " << endl;
  int outItem2;

  testFIFO.print();

  // //dequeue when it's empty
  // testFIFO.dequeue(outItem2);
  // cout << "This is the dequeue item: " << outItem2 << endl;

  testFIFO.enqueue(90);
  testFIFO.print();
  testFIFO.enqueue(20);
  testFIFO.enqueue(45);
  testFIFO.enqueue(70);
  testFIFO.enqueue(30);
  testFIFO.print();

  testFIFO.dequeue(outItem2);
  cout << "This is the dequeue item: " << outItem2 << endl;

  testFIFO.dequeue(outItem2);
  cout << "This is the dequeue item: " << outItem2 << endl;
  testFIFO.dequeue(outItem2);
  cout << "This is the dequeue item: " << outItem2 << endl;
  testFIFO.dequeue(outItem2);
  cout << "This is the dequeue item: " << outItem2 << endl;
 

  testFIFO.print();


  //dequeue the last item 
  testFIFO.dequeue(outItem2);
  cout << "This is the dequeue item: " << outItem2 << endl;


  //dequeue the value off queue that has been emptied 
  testFIFO.dequeue(outItem2);
  cout << "This is the dequeue item: " << outItem2 << endl;

  testFIFO.print();

  cout << "Total FIFO elements are: " << testFIFO.getNumElems() << endl;
  
  return 0;
}

#endif