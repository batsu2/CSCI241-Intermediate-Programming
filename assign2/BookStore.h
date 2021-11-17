/*****************************************************************
 FILE:      BookStore.h
 AUTHOR:    Bryan Butz
 LOGON ID:  z1836033
 DUE DATE:  2/15/18

 PURPOSE:   Contains the declaration for the BookStore class.
*****************************************************************/

#ifndef BOOKSTORE_H
#define BOOKSTORE_H

#include <string>
#include <cstring>

#include "Book.h"

using namespace std;

class BookStore
   {
      private:
        Book inventory[30];
        int numBooks;

      public:
        BookStore();
        BookStore( const string& bookdata );

        int searchForISBN( const char* );
        void sortByISBN();
        void processOrders( const string& );
        void print();
   };

#endif

