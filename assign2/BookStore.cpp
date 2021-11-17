/*****************************************************************
 FILE:      BookStore.cpp
 AUTHOR:    Bryan Butz
 LOGON ID:  z1836033
 DUE DATE:  2/15/18

 PURPOSE:   Contains the implementation for the BookStore class.
*****************************************************************/

#include "BookStore.h"

#include <iomanip>
#include <iostream>
#include <cstring>
#include <fstream>


using namespace std;

/***************************************************************
Method:  BookStore()

Use: This is the default constructor method for the BookStore class

Arguments: None

Returns: Nothing
***************************************************************/
BookStore::BookStore()
{
 numBooks = 0; //since all Book data members were initialized with
               //0 or "", setting numBooks to 0 is all that is needed
}

/***************************************************************
Method:  BookStore( const string& database )

Use: This is the alternate constructor method for the BookStore class

Arguments: 1. bookdata, a const string refrence that contains the
              name of an existing database file.

Returns: Nothing
***************************************************************/
BookStore::BookStore( const string& bookdata )
{
  ifstream inFile;

//Opens file and tests for failure
 inFile.open(bookdata);
   if (!inFile)
      {
       cerr << "Error - unable to open input file\n";
       exit(1);
      }

//Reads and stores data from the bookdata file
   while (inFile)
      {
       inFile.read((char*) this, sizeof(BookStore));
       numBooks++;
      }

 inFile.close();

sortByISBN();
}

/***************************************************************
Method:  void print()

Use: This method prints the book ISBN, title, price, and quantity
     of each Book object in the BookStore inventory.

Arguments: None

Returns: Nothing
***************************************************************/
void BookStore:: print()
{
 cout<<"*****************Book Inventory Listing*********************\n\n";
 cout<<left<<setw(14)<<"ISBN"<<setw(44)<<"Title";
 cout<<right<<setw(5)<<"Price"<<setw(8)<<"Qty\n\n";

 for (int i = 2; i != numBooks; i++)
   {
    inventory[i].print();
    cout<<endl;
   }

 cout<<endl;
}

/***************************************************************
Method:  void sortByISBN()

Use: This method sorts an array of Book objects in ascending order
     by ISBN

Arguments: None

Returns: Nothing
***************************************************************/
void BookStore::sortByISBN()
{
  int i, j;
  Book Bk; //Book object to use as middle-man when swapping elements

   for (i = 1; i < numBooks; i++)
      {
       Bk = inventory[i];

        //Insertion sort algorithm to sort ISBN in ascending order
       for (j = i; (j > 0) && (strcmp(inventory[j-1].getISBN(), Bk.getISBN()) > 0); j--)
          inventory[j] = inventory[j-1];

       inventory[j] = Bk;
      }
}

/***************************************************************
Method:  int searchForISBN( const char* )

Use: This method searches a database of Book objects

Arguments: 1. isbn[], a character array containing the ISBN of
              a book to search

Returns: mid, the result of the binary search which flags the
         location in the database of Book objects OR if the ISBN
         number could not be found through the binary search a
         value of -1 is returned
***************************************************************/
int BookStore::searchForISBN( const char* isbn )
{
  int low = 0;
  int high = numBooks - 1;
  int mid;

   while (low <= high)
      {
       mid = (low + high) / 2;

       //compares the passed in c string to all ISBN c strings
       //in the inventory database. Saves result into compare
       int compare = strcmp( isbn, inventory[mid].getISBN() );

       if ( compare == 0 )
          return mid;

       if ( compare < 0 )
          high = mid - 1;
       else
          low = mid + 1;
      }

return -1;
}

/***************************************************************
Method:  void processOrders( const string& )

Use: This method reads order records and processes whether the
     order can be filled or not

Arguments: 1. orders, a reference to a constant string object
              that contains the name of a file of order records

Returns: Nothing
***************************************************************/
void BookStore::processOrders( const string& orders )
{
  ifstream inFile;
  char orderNumber[7];
  char isbn[11];
  int orderQuantity;
  int numShipped;

 //Open file and tests for failure
   inFile.open("orders.txt");
  if (!inFile)
     {
      cerr << "Error - unable to open input file\n";
      exit(1);
     }

   cout<<"Order Listing\n\n";

   inFile >> orderNumber;

   while (inFile)
      {
       inFile >> isbn;
       inFile >> orderQuantity;

       int index = searchForISBN(isbn);

      if (index == -1)  //If the isbn of the order doesn't match any in the database
         cout<<"Order #"<< orderNumber << ": error - ISBN "<< isbn<<" does not exist\n";
      else
         {  //Accepts as a valid order, adjusts quantity, and prints the order results
          numShipped = inventory[index].fulfillOrder(orderQuantity);
          cout<< "Order #"<< orderNumber << ": ISBN "<< isbn <<", " << numShipped << " of " << orderQuantity;
          cout<< " shipped, Order total: $"<< (numShipped * inventory[index].getPrice()) << endl;
         }

       inFile >> orderNumber;
      }

 cout<<endl;
inFile.close();
}
