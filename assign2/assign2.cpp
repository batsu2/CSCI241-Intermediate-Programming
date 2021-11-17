//********************************************************************
// FILE:      assign2.cpp
// AUTHOR:    Bryan Butz
// LOGON ID:  z1836033
// DUE DATE:  2/15/2018
//
// PURPOSE:   This object-oriented program works with the Book and
//            BookStore classes as well as methods and constructors
//            within those classes to determine if an order can be
//            processed. Also includes the use of array of objects as
//            data members and object serialization or "binary I/O"
//********************************************************************

#include <iostream>
#include <cstring>
#include <string>
#include <iomanip>
#include <iostream>
#include <fstream>

#include "Book.h"
#include "BookStore.h"

using namespace std;

int main()
 {

   BookStore bk1( "bookdata" );

   bk1.print();

   bk1.processOrders( "orders.txt" );

   bk1.print();

  return 0;
 }

