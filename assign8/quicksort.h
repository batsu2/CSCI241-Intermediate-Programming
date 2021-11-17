/*****************************************************************
 FILE:      quicksort.h
 AUTHOR:    Bryan Butz
 LOGON ID:  z1836033
 DUE DATE:  4/26/18

 PURPOSE:   Contains the template functions used to sort a Vector
            using the quicksort method
*****************************************************************/

#ifndef QUICKSORT_H
#define QUICKSORT_H

#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include <fstream>

using namespace std;


template <class T>
void quickSort(vector<T>& , bool (*compare)(const T&, const T&));

template <class T>
void quickSort(vector<T>& , int , int , bool (*compare)(const T&, const T&));

template <class T>
int partition(vector<T>& , int , int , bool (*compare)(const T&, const T&));




/***************************************************************
Function:  quickSort( vector<T>&, bool )

Use: This sorts the items in a vector object using the quick sort
     algorithm

Arguments: 1. set, a refrence to a vector template object to be
              sorted
           2. a pointer to the compare function

Returns: Nothing
***************************************************************/
template <class T>
void quickSort(vector<T>& set, bool (*compare)(const T&, const T&))
{
 quickSort(set, 0, set.size() - 1, compare);
}

/***************************************************************
Function:  quickSort( vector<T>&, int, int, bool )

Use: This performs the recursive calls to implement the quick sort
     algorithm

Arguments: 1. set, a refrence to a vector template object to be
              sorted
           2. start, an integer used to set the path of the sort
           3. end, an integer used to end the path of the sort
           4. a pointer to the compare function

Returns: Nothing
***************************************************************/
template <class T>
void quickSort(vector<T>& set, int start, int end, bool (*compare)(const T&, const T&))
{
int pivotPoint;

   if (start < end)
    {
      pivotPoint = partition(set, start, end, compare);     // Get the pivot point
      quickSort(set, start, pivotPoint - 1, compare);       // Sort first sublist
      quickSort(set, pivotPoint + 1, end, compare);         // Sort second sublist
    }
}

/***************************************************************
Function:  partition

Use: This selects a pivot element and then partitions the vector
     around the pivot point

Arguments: 1. set, a refrence to a vector template object to be
              sorted
           2. start, an integer used to set the path of the sort
           3. end, an integer used to end the path of the sort
           4. a pointer to the compare function

Returns: pivotIndex, an integer representing the subscript of
         the new pivot index
***************************************************************/
template <class T>
int partition(vector<T>& set, int start, int end, bool (*compare)(const T&, const T&))
{
   int pivotIndex, mid;
   T pivotValue, temp;

   mid = (start + end) / 2;

  //Swaps start and mid
   temp = set[start];
   set[start] = set[mid];
   set[mid] = temp;

   pivotIndex = start;
   pivotValue = set[start];

   for (int scan = start + 1; scan <= end; scan++ )
      {
      if (compare(set[scan],  pivotValue))
         {
         pivotIndex++;

        //Swaps pivotIndex and scan
         temp = set[pivotIndex];
         set[pivotIndex] = set[scan];
         set[scan] = temp;
         }
      }

   //Swaps start and pivotIndex
    temp = set[start];
    set[start] = set[pivotIndex];
    set[pivotIndex] = temp;

  return pivotIndex;
}

#endif
