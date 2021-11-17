/*****************************************************************
 FILE:      Queue.h
 AUTHOR:    Bryan Butz
 LOGON ID:  z1836033
 DUE DATE:  4/19/18

 PURPOSE:   Contains the declaration for the Queue class as well
            as the Node structure declaration
*****************************************************************/

#ifndef QUEUE_H
#define QUEUE_H

#include <iostream>
#include <stdexcept>
#include <iomanip>

using namespace std;
using std::out_of_range;


/***************************************************************
*               Node Structure Declaration                     *
***************************************************************/
template <class T>
struct Node
   {
    T data;
    Node<T>* next;
    Node(const T& = T(), Node<T>* next = nullptr);
   };

/***************************************************************
Method:  Node

Use: This is the default constructor method for the Node structure

Arguments: 1. newData, a constant refrence to a template data type
           2. newNext, a pointer to a Node template object

Returns: Nothing
***************************************************************/
template <class T>
Node<T>::Node(const T& newData, Node<T>* newNext)
   {
    data = newData;
    next = newNext;
   }

/***************************************************************
*                  Queue Class Declaration                     *
***************************************************************/

template <class T>
class Queue;

template <class T>
std::ostream& operator<<(std::ostream&, const Queue<T>&);

template <class T>
class Queue
   {
    friend std::ostream& operator<< <>(std::ostream&, const Queue<T>&);

   private:

      size_t quSize;
      Node<T>* qFront;
      Node<T>* qBack;

      void copyList(const Queue<T>&);

   public:

      Queue();
      Queue(const Queue<T>&);
      ~Queue();
      Queue<T>& operator=(const Queue<T>&);

      bool empty() const;
      size_t size() const;
      void push(const T&);
      void pop();
      const T& front() const;
      const T& back() const;
      void clear();

   };


//**************************************************************
//
// Queue template class method definitions
//
//**************************************************************

/***************************************************************
Method:  Queue

Use: This is the default constructor method for the Queue class

Arguments: None

Returns: Nothing
***************************************************************/
template <class T>
Queue<T>::Queue()
   {
    quSize = 0;
    qFront = nullptr;
    qBack = nullptr;
   }

/***************************************************************
Method:  Queue( const Queue& )

Use: This is the copy constructor method for the Queue class

Arguments: other, a refrence to a constant Queue object

Returns: Nothing
***************************************************************/
template <class T>
Queue<T>::Queue( const Queue& other )
  {
   qFront = nullptr;
   qBack = nullptr;
   quSize = 0;
   copyList(other);
  }


/***************************************************************
Method:  copyList

Use: This copies the linked list from other to the *this object

Arguments: other, a constant refrence to a Queue template object

Returns: Nothing
***************************************************************/
template <class T>
void Queue<T>::copyList(const Queue<T>& other)
 {
  Node<T>* ptr;

  for (ptr = other.qFront; ptr != nullptr; ptr = ptr->next)
    push(ptr->data);
 }

/***************************************************************
Method:  ~Queue

Use: This is the default destructor method for the Queue class

Arguments: None

Returns: Nothing
***************************************************************/
template <class T>
Queue<T>::~Queue()
 {
  clear();
 }

/***************************************************************
Method:  size() const

Use: This method returns the size of a Queue object

Arguments: None

Returns: quSize, a size_t variable that represents the number of
         nodes in a Queue linked list object
***************************************************************/
template <class T>
size_t Queue<T>::size() const
 {
  return quSize;
 }

/***************************************************************
Method:  empty() const

Use: This tests if a Queue linked list object is emtpy or not

Arguments: None

Returns: a bool value of true if the Queue object is empty or
         false if it is not
***************************************************************/
template <class T>
bool Queue<T>::empty() const
 {
  if( quSize == 0 )
   return true;
  else
   return false;
 }

/***************************************************************
Method:  push( const T& )

Use: This adds a node to a Queue linked list object

Arguments: val, a refrence to a constant T variable

Returns: Nothing
***************************************************************/
template <class T>
void Queue<T>::push(const T& val)
 {
    Node<T>* newNode = new Node<T>(val);

  if (empty())
    qFront = newNode;
  else
    qBack->next = newNode;

  qBack = newNode;
  ++quSize;
 }

/***************************************************************
Method:  pop()

Use: This removes a node from the queue linked list, testing for
     underflow errors

Arguments: None

Returns: Nothing
***************************************************************/
template <class T>
void Queue<T>::pop()
 {
 if ( empty() )
    throw underflow_error("Queue underflow on pop()");

 // Remove first node in list
 Node<T>* delNode = qFront;
 qFront = qFront->next;

 // If queue is now empty, makes sure both pointers are nullptr
 if (qFront == nullptr)
    qBack = nullptr;

 delete delNode;

 --quSize;
 }

/***************************************************************
Method:  front() const

Use: This returns the front node in a queue linked list, testing
     for underflow errors

Arguments: None

Returns: quArray[qfront], the front node in the queue linked list
***************************************************************/
template <class T>
const T& Queue<T>::front() const
 {
  if( empty() )
    throw underflow_error("Queue underflow on front()");

  return qFront->data;
 }

/***************************************************************
Method:  back() const

Use: This returns the back node in a queue linked list, testing
     for underflow errors

Arguments: None

Returns: quArray[qback], the back node in the queue linked list
***************************************************************/
template <class T>
const T& Queue<T>::back() const
 {
  if( empty() )
    throw underflow_error("Queue underflow on back()");

  return qBack->data;
 }

/***************************************************************
Method:  operator=( const Queue<T>& )

Use: This assignment operator method assigns the values in one
     queue object to another queue object

Arguments: other, a refrence to a constant Queue template object

Returns: a refrence to a Queue template object
***************************************************************/
template <class T>
Queue<T>& Queue<T>::operator=( const Queue<T>& other )
 {
   if (this != &other)
    {
     clear();
     copyList(other);
    }

  return *this;
 }

/***************************************************************
Method:  clear()

Use: This clears all the data members within a Queue class object

Arguments: None

Returns: Nothing
***************************************************************/
template <class T>
void Queue<T>::clear()
 {
  quSize = 0;
  qFront = 0;
  qBack = 0;
 }

/***************************************************************
Method:  operator<<( ostream& , const Queue<T>& )

Use: This method overloads the output operator (cout<<) to print
     a Queue linked list's elements

Arguments: 1. lhs, a refrence to an ostream object
           2. rhs, a refrence to a constant Queue template object

Returns: lhs, a refrence to an ostream object
***************************************************************/
template <class T>
ostream& operator<<(std::ostream& lhs, const Queue<T>& rhs)
 {
  Node<T>* ptr;

  for (ptr = rhs.qFront; ptr != nullptr; ptr = ptr->next)
     lhs << ptr->data << ' ';

  return lhs;
 }

#endif
