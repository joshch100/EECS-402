#include <iostream>
#include "LinkedNodeClass.h"
#include "SortedListClass.h"
#include "FIFOQueueClass.h"


//Programmer: Joshua Chang 
//Date: November 2021
//FIFOQueueClass Functions Definition
//Purpose: This class will be used to store a simple first-in-first-out 
//queue data structure.


FIFOQueueClass::FIFOQueueClass(){
  head = 0;
  tail = 0;
}


FIFOQueueClass::~FIFOQueueClass(){
  clear();
}


void FIFOQueueClass::enqueue(const int &newItem){
  LinkedNodeClass *enqueuePtr;
  if(head == 0 && tail == 0){
    enqueuePtr = new LinkedNodeClass(0, newItem, 0);
    head = enqueuePtr;
    tail = enqueuePtr;
  }
  else{
    enqueuePtr = new LinkedNodeClass(0, newItem, head);
    enqueuePtr->setBeforeAndAfterPointers();
    head = enqueuePtr;
  }
}

 
bool FIFOQueueClass::dequeue(int &outItem){
  bool successfullyReomvedItem;
  LinkedNodeClass *newTailPtr;

  if(tail == 0){ //list is empty
    successfullyReomvedItem = false;
  }
  else{ //first in first out so we deque from tail
    outItem = tail->getValue();
    newTailPtr = tail->getPrev();
    delete tail; 
    tail = newTailPtr;

    //RESUBMISSION CODE UPDATE 
    //Consider dequeing the last item off queue
    if(tail != 0){
      tail->setNextPointerToNull();
    } 
    //Last item in queue
    else{
      head = 0;
    }

    successfullyReomvedItem = true;
  }
  return successfullyReomvedItem;
}


//Here we print from head to tail(First element will be on the lest)
void FIFOQueueClass::print() const{
  LinkedNodeClass *nodePtr;
  nodePtr = head;

  while(nodePtr != 0){
    cout << nodePtr->getValue() << " ";
    nodePtr = nodePtr->getNext();
  }
  cout << endl;
}


int FIFOQueueClass::getNumElems() const{
  LinkedNodeClass *countPtr;
  int numberOfNodes = 0;

  countPtr = head; //point to the same loc head is pointing to
  while(countPtr != 0){
    numberOfNodes++;
    countPtr = countPtr->getNext();
  }
  return numberOfNodes;
}



void FIFOQueueClass::clear(){
  LinkedNodeClass *nodePtr;
  LinkedNodeClass *clearPtr;
  nodePtr = head;
  clearPtr = head;
  while(nodePtr != 0){
    nodePtr = nodePtr -> getNext();
    delete clearPtr;
    clearPtr = nodePtr;
  }
  head = 0;
  tail = 0;
}