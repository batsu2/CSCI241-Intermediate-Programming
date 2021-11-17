/*****************************************************************
 FILE:      Queue.h
 AUTHOR:    Bryan Butz
 LOGON ID:  z1836033
 DUE DATE:  4/10/18

 PURPOSE:   Contains the declaration for the Queue class.
*****************************************************************/

#ifndef QUEUE_H
#define QUEUE_H

#include <iostream>
#include <stdexcept>
#include <iomanip>

using namespace std;
using std::out_of_range;

template <class T>
class Queue;

template <class T>
std::ostream& operator<<(std::ostream&, const Queue<T>&);

template <class T>
class Queue
   {
   friend std::ostream& operator<< <>(std::ostream&, const Queue<T>&);

   private:

      T* quArray;
      size_t quSize;
      size_t quCapacity;
      int qFront;
      int qBack;

   public:

      Queue();
      Queue(const Queue<T>&);
      ~Queue();
      Queue<T>& operator=(const Queue<T>&);

      bool empty() const;
      size_t size() const;
      size_t capacity() const;

      void push(const T&);
      void pop();
      const T& front() const;
      const T& back() const;
      void clear();

      void reserve(size_t);
   };


//********************************************************************
//
// Queue template class method definitions
//
//********************************************************************

/***************************************************************
Method:  Queue

Use: This is the default constructor method for the Queue class

Arguments: None

Returns: Nothing
***************************************************************/
template <class T>
Queue<T>::Queue()
{
   quCapacity = 0;
   quSize = 0;
   quArray = nullptr;
   qFront = 0;
   qBack = quCapacity - 1;
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
   quCapacity = other.quCapacity;
   quSize = other.quSize;
   quArray = new T[quCapacity];

   for (size_t i = 0; i < quCapacity; ++i)
      quArray[i] = other.quArray[i];

   qFront = other.qFront;
   qBack = other.qBack;
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
 delete[] quArray;
}

/***************************************************************
Method:  size() const

Use: This method returns the size of a Queue object

Arguments: None

Returns: quSize, a size_t variable that represents the number of
         variables in a Queue object
***************************************************************/
template <class T>
size_t Queue<T>::size() const
{
 return quSize;
}

/***************************************************************
Method:  capacity() const

Use: This method returns the maximum capacity of a Queue class
     object

Arguments: None

Returns: quCapacity, a size_t varibale that represents the
         maximum number of variable slots in a Queue class object
***************************************************************/
template <class T>
size_t Queue<T>::capacity() const
{
return quCapacity;
}

/***************************************************************
Method:  empty() const

Use: This tests if a Queue class object is emtpy or not

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

Use: This adds a variable to a queue, reserving more space if
     needed

Arguments: val, a refrence to a constant T variable

Returns: Nothing
***************************************************************/
template <class T>
void Queue<T>::push(const T& val)
{
   // If queue is full, allocate additional storage
   if ( quSize == quCapacity)
      {
      if ( quCapacity == 0 )
         reserve( 1 );
      else
         reserve( quCapacity * 2 );
      }
   // Otherwise, increment back and insert value
   qBack = (qBack + 1) % quCapacity;
   quArray[qBack] = val;
   ++quSize;
}

/***************************************************************
Method:  reserve( size_t )

Use: This method reserves more space in a queue if push() was
     called but quArray is full

Arguments: n, a size_t object used to determine the reserve size

Returns: Nothing
***************************************************************/
template <class T>
void Queue<T>::reserve( size_t n )
{
if (n < quSize || n == quCapacity)
      return;

   T* tempArray = new T[n];

   int current = qFront;

   for (size_t i = 0; i < quSize; i++)
      {
      tempArray[i] = quArray[current];
      current = (current + 1) % quCapacity;
      }

   quCapacity = n;
   qFront = 0;
   qBack = quSize - 1;
   delete[] quArray;
   quArray = tempArray;
}

/***************************************************************
Method:  pop()

Use: This removes an item from the front of the queue, testing for
     underflow errors

Arguments: None

Returns: Nothing
***************************************************************/
template <class T>
void Queue<T>::pop()
{
// If empty, throw exception
if ( empty() )
   throw underflow_error("queue underflow on pop()");

qFront = (qFront + 1) % quCapacity;
--quSize;
}

/***************************************************************
Method:  front() const

Use: This returns the back item of the queue, testing for underflow
     errors

Arguments: None

Returns: quArray[qfront], the front element in the queue array
***************************************************************/
template <class T>
const T& Queue<T>::front() const
{
// If empty, throw exception
 if( empty() )
   throw underflow_error("queue underflow on front()");

return quArray[qFront];
}

/***************************************************************
Method:  back() const

Use: This returns the back item in a queue, testing for underflow
     errors

Arguments: None

Returns: quArray[qback], the back item in the queue array
***************************************************************/
template <class T>
const T& Queue<T>::back() const
{
// If empty, throw exception
 if( empty() )
   throw underflow_error("queue underflow on back()");

return quArray[qBack];
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
if( this->quArray == other.quArray )//if the queue arrays are the same
  return *this;

 this->quCapacity = other.quCapacity;
 this->quSize = other.quSize;
 this->quArray = new int[other.quCapacity];

  for (size_t i = 0; i < quCapacity; ++i)
   {
    quArray[i] = other.quArray[i];
   }

 qFront = other.qFront;
 qBack = other.qBack;

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
 qBack = ( quCapacity - 1 );
 quArray = nullptr;
}

/***************************************************************
Function:  operator<<( ostream& , const Queue<T>& )

Use: This friend function of the Queue class overloads the output
     operator (cout<<) to print a Queue array's elements

Arguments: 1. lhs, a refrence to an ostream object
           2. rhs, a refrence to a constant Queue template object

Returns: lhs, a refrence to an ostream object
***************************************************************/
template <class T>
ostream& operator<<( std::ostream& lhs, const Queue<T>& rhs )
{
 size_t current, i;

for (current = rhs.qFront, i = 0; i < rhs.quSize; ++i)
   {
     // Print queue element at subscript i
     lhs << rhs.quArray[current] << ' ';

     // Increment i, wrapping around to front of queue array if necessary
     current = (current + 1) % rhs.quCapacity;
   }

 return lhs;
}

#endif
