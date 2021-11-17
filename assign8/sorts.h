/*****************************************************************
 FILE:      sorts.h
 AUTHOR:    Bryan Butz
 LOGON ID:  z1836033
 DUE DATE:  4/26/18

 PURPOSE:   Contains the template functions used to read a series
            of items from an input file, compare them, and print
            them
*****************************************************************/

#ifndef SORT_H
#define SORT_H

#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include <fstream>

using namespace std;

template <class T>
bool lessThan( const T&, const T& );

template <class T>
bool greaterThan( const T&, const T& );

template <class T>
void buildList( vector<T>&, const char* );

template <class T>
void printList( const vector<T>&, int, int );


/***************************************************************
Function:  buildList

Use: This builds a vector object by reading in a number of items of
     any data type from a file.

Arguments: 1. set, a refrence to a vector template object
           2. fileName, a pointer to a constant char which contains
              the name of a file to be read

Returns: Nothing
***************************************************************/
template <class T>
void buildList( vector<T>& set, const char* fileName )
{
 T item;
 ifstream inFile;

//Opens file and tests for failure
 inFile.open(fileName);
   if (!inFile)
      {
       cout << "Error - unable to open input file" << fileName << "\n";
       exit(1);
      }

  inFile >> item;
//Reads and stores data from the bookdata file
   while (inFile)
      {
       set.push_back(item);
       inFile >> item;
      }

 inFile.close();
}

/***************************************************************
Function:  printList

Use: This loops through a vector object, printing it's elements

Arguments: 1. set, A refrence to a constant vector template object
           2. itemWidth, an integer used to represent the setw
              width depending on the data type
           3. numPerLine, an integer used to represent the number
              of data values to be printed per line

Returns: Nothing
***************************************************************/
template <class T>
void printList( const vector<T>& set, int itemWidth, int numPerLine )
{
 int i = 0;

  while( i < (int) set.size() )
     {
      cout << setw(itemWidth) << set[i] << ' ';
      i++;
      if (i % numPerLine == 0)
         cout << endl;
     }

   if (i % numPerLine != 0)
      cout << endl;
}

/***************************************************************
Function:  lessThan

Use: This compares two template objects and returns whether item1
     is less than item2 or not

Arguments: 1. item1, a refrence to a constant template object to be
              tested
           2. item2, a refrence to a constant template object used
              to compare with item1

Returns: A bool value of true if item1 is less than item2 or false
         if item1 is not less than item2
***************************************************************/
template <class T>
bool lessThan(const T& item1, const T& item2)
{
 return( item1 < item2 );
}

/***************************************************************
Function:  greaterThan

Use: This compares two template objects and returns whether item1
     is greater than item2 or not

Arguments: 1. item1, a refrence to a constant template object to be
              tested
           2. item2, a refrence to a constant template object used
              to compare with item1

Returns: A bool value of true if item1 is greater than item2 or false
         if item1 is not greater than item2
***************************************************************/
template <class T>
bool greaterThan(const T& item1, const T& item2)
{
 return( item1 > item2 );
}


#endif
