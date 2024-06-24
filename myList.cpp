#include <iostream>
#include <utility>
#include <string>
#include "myList.hpp"
#include "myInteger.hpp"

// default constructor 
template <typename T>
MyList<T>::MyList() {
  // initialises the variables declared in the header file
  head = nullptr;
  tail = nullptr;
  numNodes = 0;
}

// copy constructor
template <typename T>
MyList<T>::MyList(const MyList& other) : MyList() {
  // Begins at the head of 'other' and copies each element to the new list
  Node *current = other.head;
  while(current != nullptr){
    push_back(current->data);
    current = current->next;
  }
}

// assignment operator
template <typename T>
MyList<T>& MyList<T>::operator=(MyList other) {
  // swap all nodes of the first List with the 'other' List 
  std::swap(head, other.head);
  std::swap(tail, other.tail);
  std::swap(numNodes, other.numNodes);
  return *this;
}


// destructor
template <typename T>
MyList<T>::~MyList() {
  // removes the tail node until the list is empty
  while(!empty()){
    pop_back();
  }
}

// constructor from an initializer list
template <typename T>
MyList<T>::MyList(std::initializer_list<T> vals) : MyList() {
  //pushes each value of the initializer list to the back of the new List
  for(const auto &val : vals){
    push_back(val);
  }
}

// push back
template <typename T>
void MyList<T>::push_back(T val) {
  // Create the new node to be added to the end of the list,
  // data of the node is set to the val parameter.
  Node *newNode = new Node(val);
  if(empty()){
    head = tail = newNode;
  } else {
    // update the necessary pointers to point to the new node and visa versa
    tail->next = newNode;
    newNode->prev = tail;
    tail = newNode;
  }
  numNodes++;
}

// pop back
template <typename T>
void MyList<T>::pop_back() {
  Node *oldTail = tail; // Store a pointer to the current tail
  tail = tail->prev;
  //Check the new tail node exists
  if(tail != nullptr){
    tail->next = nullptr; // if new tail does exist, set next pointer to null
  } else {
    head = nullptr; // if the new tail doesnt exist, the list is empty
                    // and head is set to null
  }
  
  delete oldTail;
  numNodes--;
}

template <typename T>
void MyList<T>::push_front(T val) {
  // Create the new node to be added to the front of the list,
  // data of the node is set to the val parameter
  Node *newNode = new Node(val);
  if(empty()){
    head = tail = newNode;
  } else {
    // update the necessary pointers to point to the new node and visa versa
    newNode->next = head;
    head->prev = newNode;
    head = newNode;
  }
  numNodes++;
}


template <typename T>
void MyList<T>::pop_front() {
  Node *oldHead = head; // Store a pointer to the current head
  head = head->next;
  // Check the new head node exists
  if(head != nullptr){
    head->prev = nullptr; // if new head does exist, set next pointer to null
  } else {
    tail = nullptr; // if the new head doesnt exist, the list is empty
                    // and tail is set to null
  }
  delete oldHead;
  numNodes--;
}

// return the first element by reference
template <typename T>
T& MyList<T>::front() {
  return head->data;
}

// return the first element by const reference
template <typename T>
const T& MyList<T>::front() const {
  return head->data;
}

// return the last element by reference
template <typename T>
T& MyList<T>::back() {
  return tail->data;
}

// return the last element by const reference
template <typename T>
const T& MyList<T>::back() const {
  return tail->data;
}

// return a boolean depending on if the list is empty
template <typename T>
bool MyList<T>::empty() const {
  return numNodes == 0;
}

// return the number of elements in the list
template <typename T>
int MyList<T>::size() const {
  return numNodes;
}

// These lines let the compiler know with which types we will be
// instantiating MyList
template class MyList<int>;
template class MyList<std::string>;
template class MyList<MyInteger>;