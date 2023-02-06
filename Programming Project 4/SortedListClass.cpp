#include "SortedListClass.h"
#include "LinkedNodeClass.h"
#include <iostream> 

using namespace std;

//Programmer: Joshua Chang 
//Date: November 2021
//SortedListClass Function Definitions
//Purpose: The sorted list class does not store any data directly. Instead,
//it contains a collection //contains one element

SortedListClass::SortedListClass(){
  head = 0;
  tail = 0;
}

SortedListClass::SortedListClass(const SortedListClass &rhs){ 
  head = 0;
  tail = 0;
  LinkedNodeClass *nodePtr = rhs.head;
	while(nodePtr != 0){
    int valToInsert = nodePtr->getValue();
		this->insertValue(valToInsert); //insert the value from rhs
    //function insertValue will help us create new pointers to make a copy
		nodePtr = nodePtr->getNext();
	}
}

SortedListClass::~SortedListClass(){
  clear();
}

void SortedListClass::clear(){
  LinkedNodeClass *nodePtr;
  LinkedNodeClass *clearPtr;
  nodePtr = head;
  clearPtr = head;
  while(nodePtr != 0){
    nodePtr = nodePtr->getNext();
    delete clearPtr;
    clearPtr = nodePtr;
  }
  head = 0;
  tail = 0;
}

  
void SortedListClass::insertValue(const int &valToInsert){
  LinkedNodeClass *insertPtr;

  if(head == 0 && tail == 0){ 
    insertPtr = new LinkedNodeClass(0, valToInsert, 0);
    head = insertPtr;
    tail = insertPtr;
  }
  
  else{
    LinkedNodeClass *nodePtr;
    nodePtr = head;

    while(nodePtr!=0 && nodePtr->getValue() <= valToInsert){
      nodePtr = nodePtr->getNext();
    }

    //Insert from front
    if(nodePtr == head){
      insertPtr = new LinkedNodeClass(0, valToInsert, head);
      insertPtr->setBeforeAndAfterPointers();
      head = insertPtr; //change head to point to where insertPtr is pointing to 
    }

    //insert from last position
    else if(nodePtr == 0){ //the last node, so nodePtr would be zero
      insertPtr = new LinkedNodeClass(tail, valToInsert, 0);
      insertPtr->setBeforeAndAfterPointers();
      tail = insertPtr;
    } 
    else{
      //insert in the middle
      insertPtr = new LinkedNodeClass(nodePtr->getPrev(), valToInsert, nodePtr);
      insertPtr->setBeforeAndAfterPointers();
    }
  }
} 


 
void SortedListClass::printForward() const{
  LinkedNodeClass *nodePtr;
  nodePtr = head;

  cout << "Forward List Contents Follow:" << endl;

  while(nodePtr != 0){
    cout << "  " << nodePtr->getValue() << endl; 
    nodePtr = nodePtr->getNext();
  }
  cout << "End Of List Contents" << endl;
}


void SortedListClass::printBackward() const{
  LinkedNodeClass *nodePtr;
  nodePtr = tail;

  cout << "Backward List Contents Follow:" << endl;

  while(nodePtr != 0){
    cout << "  " << nodePtr->getValue() << endl;
    nodePtr = nodePtr->getPrev();
  }
  cout << "End Of List Contents" << endl;
}


bool SortedListClass::removeFront(int &theVal){
  bool successfullyReomvedItem;
  LinkedNodeClass *newHeadPtr;
  
  //if the list was empty:
  if(head == 0){    //use head == 0 to represent the list is empty
    successfullyReomvedItem = false;
  }
  else{
    theVal = head->getValue();
    newHeadPtr = head->getNext();
    delete head; //delete the value that head is pointing to
    head = newHeadPtr;
    
    //handling condition: last node being deleted  
    if(head != 0){
      head->setPreviousPointerToNull();
    }
    else{
      tail = 0;
    }
    successfullyReomvedItem = true;
  }
  return successfullyReomvedItem;
}

 
bool SortedListClass::removeLast(int &theVal){
  bool successfullyReomvedItem;
  LinkedNodeClass *newTailPtr;
  
  //if the list was empty
  if(tail == 0){
    successfullyReomvedItem = false;
  }
  else{
    theVal = tail->getValue();
    newTailPtr = tail->getPrev();
    delete tail; 
    tail = newTailPtr;

    //handling condition: last node being deleted  
    if(tail != 0){
      tail->setNextPointerToNull();
    }
    else{
      head = 0;
    }
    successfullyReomvedItem = true;
  }
  return successfullyReomvedItem;
}


   
int SortedListClass::getNumElems() const{
  LinkedNodeClass *countPtr;
  int numberOfNodes = 0;

  countPtr = head;
  while(countPtr != 0){
    numberOfNodes++;
    countPtr = countPtr->getNext();
  }
  return numberOfNodes;
}



bool SortedListClass::getElemAtIndex(const int index, int &outVal) const{
  bool successfullyGetIndex;
  if(index >= getNumElems()){
    successfullyGetIndex = false;
  }
  else if(index < 0){
    successfullyGetIndex = false;
  }
  else{
    int numberOfIndex = 0;
    LinkedNodeClass *indexPtr;
    indexPtr = head; //point to where head is pointing to
    while(indexPtr != 0){
      if(numberOfIndex == index){
        outVal = indexPtr->getValue();
        successfullyGetIndex = true;
        return successfullyGetIndex; 
      }
      numberOfIndex++;
      indexPtr = indexPtr->getNext();
    }
  }
  return successfullyGetIndex; 
}


    