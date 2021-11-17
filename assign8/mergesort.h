/*****************************************************************
 FILE:      mergesort.h
 AUTHOR:    Bryan Butz
 LOGON ID:  z1836033
 DUE DATE:  4/26/18

 PURPOSE:   Contains the template functions used to sort a Vector
            using the mergesort method
*****************************************************************/

#ifndef MERGESORT_H
#define MERGESORT_H

#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include <fstream>

using namespace std;


template <class T>
void mergeSort(vector<T>& , bool (*compare)(const T&, const T&));

template <class T>
void mergeSort(vector<T>& , int , int , bool (*compare)(const T&, const T&));

template <class T>
void merge(vector<T>& , int , int , int , bool (*compare)(const T&, const T&));



/***************************************************************
Function:  mergeSort( vector<T>&, bool )

Use: This sorts the items in a vector object using the merge sort
     algorithm

Arguments: 1. set, a refrence to a vector template object
           2. a pointer to the compare function

Returns: Nothing
***************************************************************/
template <class T>
void mergeSort(vector<T>& set, bool (*compare)(const T&, const T&))
{
  mergeSort(set, 0, set.size()-1, compare);
}

/***************************************************************
Function:  mergeSort( vector<T>&, int, int, bool )

Use: This resursively divides a vector into two subvectors, sorts
     them, and then merges the two sorted subvectors

Arguments: 1. set, a refrence to a vector template object
           2. low, an integer used for the merge sort
           3. high, an integer used for the merge sort
           4. a pointer to the compare function

Returns: Nothing
***************************************************************/
template <class T>
void mergeSort(vector<T>& set, int low, int high, bool (*compare)(const T&, const T&))
{
   int mid;

   if (low < high)
      {
      mid = (low + high) / 2;

      // Divides

      mergeSort(set, low, mid, compare);
      mergeSort(set, mid+1, high, compare);

      // Combine
      merge(set, low, mid, high, compare);
      }
}

/***************************************************************
Function:  merge

Use: This merges two sorted subvectors

Arguments: 1. set, a refrence to a vector template object
           2. low, an integer used for the merge sort
           3. mid, an integer used for the merge sort
           4. high, an integer used for the merge sort
           5. a pointer to the compare function

Returns: Nothing
***************************************************************/
template <class T>
void merge(vector<T>& set, int low, int mid, int high, bool (*compare)(const T&, const T&))
{
   // Create temporary vector to hold merged subvectors
   vector<T> temp(high - low + 1);

   int i = low;      // Subscript for start of left sorted subvector
   int j = mid+1;    // Subscript for start of right sorted subvector
   int k = 0;        // Subscript for start of merged vector

   // While not at the end of either subvector
   while (i <= mid && j <= high)
      {
      if (compare(set[j], set[i]))
         {
         temp[k]=set[j];
         j++;
         k++;
         }
      else
         {
         temp[k]=set[i];
         i++;
         k++;
         }
      }

   // Copy over any remaining elements of left subvector
   while (i <= mid)
      {
      temp[k]=set[i];
      i++;
      k++;
      }

   // Copy over any remaining elements of right subvector
   while (j <= high)
      {
      temp[k]=set[j];
      j++;
      k++;
      }

   // Copy merged elements back into original vector
   for (i = 0, j = low; j <= high; i++, j++)
      set[j]=temp[i];

}

#endif
