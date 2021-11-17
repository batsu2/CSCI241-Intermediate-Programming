//*****************************************************************
// FILE:      Book.h
// AUTHOR:    Bryan Butz
// LOGON ID:  z1836033
// DUE DATE:  2/15/18
//
// PURPOSE:   Contains the declaration for the Book class.
//*****************************************************************

#ifndef BOOK_H
#define BOOK_H

#include <cstring>

using namespace std;

 class Book
   {
      private:

          char isbn[11];
          char title[41];
          double price;
          int quantity;

      public:

          Book();
          Book( const char* , const char* , double, int);

          char* getISBN();
          char* getTitle();
          double getPrice();
          int getQuantity();
          void setPrice( double );
          void setQuantity ( int );
          int fulfillOrder( int );

          void print();
  };

#endif

