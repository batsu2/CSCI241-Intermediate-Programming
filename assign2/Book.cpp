/*****************************************************************
 FILE:      Book.cpp
 AUTHOR:    Bryan Butz
 LOGON ID:  z1836033
 DUE DATE:  2/15/18

 PURPOSE:   Contains the implementation for the Book class.
*****************************************************************/

#include "Book.h"

#include <iomanip>
#include <iostream>
#include <cstring>


using namespace std;

/***************************************************************
Method:  Book()

Use: This is the default constructor method for the Book class

Arguments: None

Returns: Nothing
***************************************************************/
Book::Book()
{

  strcpy( isbn, "" );
  strcpy( title, "" );
  price = 0.00;
  quantity = 0;

}

/***************************************************************
Method: Book(char [], char [], double, int)

Use: This is the alternate constructor method for the Book class

Arguments: 1. newISBN, a character array that contains the new ISBN
           2. newTitle, a character array that conains the new title
           3. newPrice, a double representing the new price
           4. newQuantity, an integer representing the new quantity

Returns: Nothing
***************************************************************/
Book::Book( const char* newISBN, const char* newTitle, double newPrice, int newQuantity)
{

  strcpy( isbn, newISBN);
  strcpy( title, newTitle);

  setPrice( newPrice );
  setQuantity( newQuantity );

}

/***************************************************************
Method:  char getISBN()

Use: This accessor method returns the isbn data member

Arguments: None

Returns: isbn, a character array of book ISBN data
***************************************************************/
char* Book:: getISBN()
{
return isbn;
}

/***************************************************************
Method:  char getTitle()

Use: This accessor method returns the title data member

Arguments: None

Returns: title, a character array representing various book titles
***************************************************************/
char* Book:: getTitle()
{
return title;
}

/***************************************************************
Method:  double getPrice()

Use: This accessor method returns the price value

Arguments: None

Returns: price, a double value representing book prices
***************************************************************/
double Book:: getPrice()
{
return price;
}

/***************************************************************
Method:  int getQuantity()

Use: This accessor method returns the quantity data member

Arguments: None

Returns: quantity, an integer value representing the quantity of
         a book.
***************************************************************/
int Book:: getQuantity()
{
return quantity;
}

/***************************************************************
Method:  setPrice()

Use: This accessor method adjusts the price value for objects in
     the Book class

Arguments: 1. newPrice, a double representing the new price

Returns: Nothing
***************************************************************/
void Book:: setPrice( double newPrice )
{
 //checks if passed in price is valid
  if( newPrice >= 0 )
    price = newPrice;
  else
    price = 0;
}

/***************************************************************
Method:  setQuantity()

Use: This accessor method adjusts the quantity of books in the
     Book class

Arguments: 1. newQuantity, an integer representing the new
              quantity.

Returns: Nothing
***************************************************************/
void Book:: setQuantity( int newQuantity )
{
 //checks if passed in quantity is valid
  if( newQuantity >= 0 )
    quantity = newQuantity;
  else
    quantity = 0;
}

/***************************************************************
Method:  fulfillOrder()

Use: This accessor method tests an order amount and detracts
     from the quantity in stock if an order is placed

Arguments: 1. quantity, an integer representing the number of
              books to be ordered

Returns: numShipped,an integer representing the number of books
         the bookstore is able to ship out
***************************************************************/
int Book:: fulfillOrder( int orderQuantity )
{
  int shipped = 0;

 //First checks if order quantity  is valid
  if( orderQuantity < 0 )
    return 0;
  else if( orderQuantity <= quantity )
   {
    shipped = orderQuantity;
    quantity = quantity - orderQuantity;

    return shipped;
   }
  else
  {
   shipped = quantity;
   quantity = 0;

   return shipped;
  }
}

/***************************************************************
Method:  void print()

Use: This method prints all data members for the Book class

Arguments: None

Returns: Nothing
***************************************************************/
void Book:: print()
{
  cout<<left<<setw(14)<<getISBN();
  cout<<left<<setw(44)<<getTitle();
  cout<<right<<setw(5)<<setprecision(2)<<fixed<<getPrice();
  cout<<right<<setw(6)<<getQuantity();
}
