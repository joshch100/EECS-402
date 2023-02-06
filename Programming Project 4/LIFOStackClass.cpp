#include <iostream>
#include "LinkedNodeClass.h"
#include "SortedListClass.h"
#include "LIFOStackClass.h"

//Programmer: Joshua Chang 
//Date: November 2021
//LifoStackClass Functions Definition
//Purpose: This class will be used to store a simple last-in-first-out 
//stack data structure.


LIFOStackClass::LIFOStackClass(){
  head = 0;
  tail = 0;
}



LIFOStackClass::~LIFOStackClass(){
  clear();
}


void LIFOStackClass::push(const int &newItem){
  LinkedNodeClass *insertPtr;
  if(head ==0 && tail == 0){
    insertPtr = new LinkedNodeClass(0, newItem, 0);
    head = insertPtr;
    tail = insertPtr;
  }
  else{
    insertPtr = new LinkedNodeClass(0, newItem, head);
    insertPtr->setBeforeAndAfterPointers();
    head = insertPtr;
  }
}


bool LIFOStackClass::pop(int &outItem){
  bool successfullyReomvedItem;
  LinkedNodeClass *newHeadPtr;
  
  if(head == 0){    //use head==0 to represent the list is empty
    successfullyReomvedItem = false;
  }
  else{ //last in first out, so we start at the head 
    outItem = head->getValue();
    newHeadPtr = head->getNext();
    delete head; 
    head = newHeadPtr;
    if(head != 0){
      head->setPreviousPointerToNull();
    }
    //Last item in stack
    else{
      tail = 0;
    }
    successfullyReomvedItem = true;
  }
  return successfullyReomvedItem;
}

void LIFOStackClass::print() const{
  LinkedNodeClass *nodePtr;
  nodePtr = head;

  while(nodePtr != 0){
    cout << nodePtr->getValue() << " ";
    nodePtr = nodePtr->getNext();
  }
  cout << endl;
}
    
int LIFOStackClass::getNumElems() const{
  LinkedNodeClass *countPtr;
  int numberOfNodes = 0;

  countPtr = head; //point to the same loc head is pointing to
  while(countPtr != 0){
    numberOfNodes++;
    countPtr = countPtr->getNext();
  }
  return numberOfNodes;
}
   

//Clears the stack to an empty state without resulting in any 
//memory leaks.
void LIFOStackClass::clear(){
  LinkedNodeClass *nodePtr;
  LinkedNodeClass *clearPtr;
  nodePtr = head;
  clearPtr = head;
  while(nodePtr != 0){
    delete clearPtr; //free the memory(value) head is pointing to 
    nodePtr = nodePtr -> getNext();
    clearPtr = nodePtr;
  }
  head = 0;
  tail = 0;
}