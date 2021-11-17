
/*****************************************************************
 FILE:      VectorN.cpp
 AUTHOR:    Bryan Butz
 LOGON ID:  z1836033
 DUE DATE:  3/27/18

 PURPOSE:   Contains the implementation for the VectorN class as
            well as friend functions of the VectorN class
*****************************************************************/

#include "VectorN.h"

#include <iomanip>
#include <iostream>
#include <stdexcept>

using namespace std;
using std::out_of_range;

/***************************************************************
Method:  VectorN()

Use: This is the default constructor method for the VectorN class

Arguments: None

Returns: Nothing
***************************************************************/
VectorN::VectorN()
{
  vCapacity = 0;
  vPointer = nullptr;
}

/***************************************************************
Method:  VectorN( const double values[], size_t n )

Use: This is the alternate constructor method for the VectorN class

Arguments: 1. values[], an array of doubles used to fill vPointer
           2. n, a size_t data type used to determine the vector's
              capacity

Returns: Nothing
***************************************************************/
VectorN::VectorN( const double values[], size_t n )
{
 vCapacity = n;

 if( vCapacity == 0 )
   vPointer = nullptr;
 else
 {
   vPointer = new double[vCapacity];

    for( int i = 0; i < vCapacity; i++ )
     {
      vPointer[i] = values[i];
     }
 }
}

/***************************************************************
Method:  VectorN()

Use: This is the copy constructor method for the VectorN class

Arguments: other, a constant refrence to a VectorN object used to
           determine the vector's capacity and vPointer values

Returns: Nothing
***************************************************************/
VectorN::VectorN( const VectorN& other )
{
 vCapacity = other.vCapacity;

 if( vCapacity == 0 )
   vPointer = nullptr;
 else
 {
  vPointer = new double[vCapacity];

   for( int i = 0; i < other.vCapacity; i++ )
    {
      vPointer[i] = other.vPointer[i];
    }
 }
}

/***************************************************************
Method:  ~VectorN()

Use: This is the default destructor method for the VectorN class

Arguments: None

Returns: Nothing
***************************************************************/
VectorN::~VectorN()
{
  clear();
}

/***************************************************************
Function:  operator<<

Use: This friend function of the VectorN class overloads the class
     to use the stream insertion operator (cout<<) with a VectorN
     object

Arguments: 1. lhs, a refrence to an ostream variable
	   2. rhs, a refrence to a constant VectorN object to be
	      printed

Returns: lhs, an ostream variable
***************************************************************/
ostream& operator<<(ostream& lhs, const VectorN& rhs)
{

  lhs << "( " ;

  for( int i = 0; i < rhs.vCapacity; i++ )
  {
   lhs << rhs.vPointer[i] ;

   if( i+1 != rhs.vCapacity ) //Determines if a ", " should be printed
    lhs << ", ";
   else
    lhs << " ";
  }

  lhs << ")" ;

return lhs;
}

/***************************************************************
Method:  clear()

Use: This method clears the data from a VectorN object, sets the
     capacity to 0, and sets the vPointer values to nullptr

Arguments: None

Returns: Nothing
***************************************************************/
void VectorN::clear()
{
  delete vPointer;
  vCapacity = 0;
  vPointer = nullptr;
}

/***************************************************************
Method:  size() const

Use: This method returns the array size of a VectorN object

Arguments: None

Returns: vCapacity, a size_t object that holds the capacity size
         of a VectorN object
***************************************************************/
size_t VectorN::size() const
{
 return vCapacity;
}

/***************************************************************
Method:  operator[]

Use: This method overloads the VectorN class to use the subscript
     opperator ( [] ) with a VectorN object which allows it to
     read the array.

Arguments: sub, an integer that represents the subscript location
           of the values within vPointer

Returns: The value of vPointer[sub]
***************************************************************/
double VectorN::operator[]( int sub )const
{
 return vPointer[sub];
}

/***************************************************************
Method:  operator[]

Use: This method overloads the VectorN class to use the subscript
     opperator ( [] ) with a VectorN object which allows it to
     write the array.

Arguments: sub, an integer that represents the subscript location
	   of the values within vPointer

Returns: The value of vPointer[sub]
***************************************************************/
double& VectorN::operator[]( int sub )
{
 return vPointer[sub];
}

/***************************************************************
Method:  operator=

Use: This method overloads the VectorN class to use the assignment
     opperator (=) with a VectorN object

Arguments: other, a refrence to a constant VectorN object

Returns: *this, a pointer to a VectorN object
***************************************************************/
VectorN VectorN::operator=( const VectorN& other )
{
 if( this->vPointer == other.vPointer )//if the VectorN arrays are the same
  return *this;

 delete this->vPointer;

 this->vCapacity = other.vCapacity;

 if( vCapacity == 0 )
  this->vPointer = nullptr;
 else
  {
    this->vPointer = new double[vCapacity];

    for( int i = 0; i < vCapacity; i++ )
     {
      this->vPointer[i] = other[i]; //Fills up the new array
     }
   return *this;
  }
}

/***************************************************************
Method:  operator+

Use: This method overloads the VectorN class to use the addition
     opperator (+) with a VectorN object

Arguments: rhs, a refrence to a constant VectorN object

Returns: result, a VectorN object that contains the sum of the
         elements within two VectorN objects
***************************************************************/
VectorN VectorN::operator+( const VectorN& rhs )const
{
int n;
VectorN temp;
VectorN result = *this;

//Checks the capacity of both VectorN objects
// to determine the capacity of temp
if ( result.vCapacity < rhs.vCapacity )
 {
  n = result.vCapacity;
  temp.vPointer = new double[result.vCapacity];
  temp.vCapacity = result.vCapacity;
 }
else
 {
  n = rhs.vCapacity;
  temp.vPointer = new double[rhs.vCapacity];
  temp.vCapacity = rhs.vCapacity;
 }

//Perform addition operation and store in temp
   for( int i = 0; i < n; i++ )
   {
     temp.vPointer[i] = result.vPointer[i] + rhs.vPointer[i];
   }

//Overwrite result's elemets with temp's
result.vCapacity = temp.vCapacity;
result = temp;

return result;
}

/***************************************************************
Method:  operator-

Use: This method overloads the VectorN class to use the subtraction
     opperator (-) with a VectorN object

Arguments: rhs, a refrence to a constant VectorN object

Returns: result, a VectorN object that containst the difference of
         the elements withing two VectorN objects
***************************************************************/
VectorN VectorN::operator-( const VectorN& rhs)const
{
int n;
VectorN temp;
VectorN result = *this;

//Checks the capacity of both VectorN objects
// to determine the capacity of temp
if( result.vCapacity < rhs.vCapacity )
 {
  n = result.vCapacity;
  temp.vPointer = new double[result.vCapacity];
  temp.vCapacity = result.vCapacity;
 }
else
 {
  n = rhs.vCapacity;
  temp.vPointer = new double[rhs.vCapacity];
  temp.vCapacity = rhs.vCapacity;
 }

//Perform subtraction operation and store in temp
  for( int i = 0; i < n; i++ )
  {
   temp.vPointer[i] = result.vPointer[i] - rhs.vPointer[i];
  }

//Overwrite result's elemets with temp's
result.vCapacity = temp.vCapacity;
result = temp;

return result;
}

/***************************************************************
Method:  operator*

Use: This method overloads the VectorN class to use the multiplication
     opperator (*) with a VectorN object. This overloader specificly
     returns the scalar product.

Arguments: rhs, a refrence to a constant VectorN object

Returns: sum, a double that represents the sum of two VectorN
	 objects after their coordinates have been multiplied
***************************************************************/
double VectorN::operator*( const VectorN& rhs)const
{
int n;
VectorN temp;
VectorN result = *this;

//Checks the capacity of both VectorN objects
// to determine the capacity of temp
if ( result.vCapacity < rhs.vCapacity )
 {
  n = result.vCapacity;
  temp.vPointer = new double[result.vCapacity];
  temp.vCapacity = result.vCapacity;
 }
else
 {
  n = rhs.vCapacity;
  temp.vPointer = new double[rhs.vCapacity];
  temp.vCapacity = rhs.vCapacity;
 }

//Perform multiplication and store in temp
   for( int i = 0; i < n; i++ )
   {
     temp.vPointer[i] = result.vPointer[i] * rhs.vPointer[i];
   }

//Overwrite result's elements with temp's
result.vCapacity = temp.vCapacity;
result = temp;

double sum = result.vPointer[0];

  for( int i = 0; i < n; i++ )
   {
      sum = sum + result.vPointer[i+1]; //adds all products to get scalar product
   }

return sum;
}

/***************************************************************
Method:  operator*

Use: This method overloads the VectorN class to use the multiplication
     opperator (*) with a VectoN object. This method assumes the
     VectorN object is on the left hand side of the operation

Arguments: rhs, a double value representing the value to multiply
	   the VectorN object by

Returns: result, a VectorN object that contains the product of a
	 VectorN object and a double.
***************************************************************/
VectorN VectorN::operator*( double rhs )const
{
VectorN temp;
VectorN result = *this;

  temp.vPointer = new double[result.vCapacity];
  temp.vCapacity = result.vCapacity;

//Perform multiplication with rhs and store in temp
   for( int i = 0; i < result.vCapacity; i++ )
   {
     temp.vPointer[i] = result.vPointer[i] * rhs;
   }

//Overwrite result's elements with temp's
result.vCapacity = temp.vCapacity;
result = temp;

return result;
}

/***************************************************************
Function:  operator*

Use: This friend function of the VectorN class overloads the class
     to use the multiplication opperator (*) with a VectorN object.
     This method assumes the VectorN object is on the right hand side
     of the operation

Arguments: 1. lhs, a double value representing the value to multiply
              the VectorN object by
	   2. rhs, a constant refrence to a VectorN object that is
              getting multiplied.

Returns: result, a VectorN object that contains the product of a
	 VectorN object and a double.
***************************************************************/
VectorN operator*( double lhs, const VectorN& rhs)
{
VectorN temp;
VectorN result = rhs;

  temp.vPointer = new double[result.vCapacity];
  temp.vCapacity = result.vCapacity;

//Perform multiplication with lhs and store in temp
   for( int i = 0; i < result.vCapacity; i++ )
   {
     temp.vPointer[i] = result.vPointer[i] * lhs;
   }

//Overwrite result's elements with temp's
result.vCapacity = temp.vCapacity;
result = temp;

return result;
}

/***************************************************************
Method:  operator==

Use: This method overloads the VectorN class to use the equality
     opperator (==) with a VectorN object.

Arguments: rhs, a refrence to a constant VectorN object

Returns: a bool value of true if the VectorN objects are equal and
	 false if the objects are not equal
***************************************************************/
bool VectorN::operator==( const VectorN& rhs)const
{
VectorN rightSide = rhs;

if( this->vCapacity != rightSide.vCapacity )
  return false;

 for( int i = 0; i < this->vCapacity; i++ )
   {
     if( this->vPointer[i] != rightSide.vPointer[i] )
     return false;
   }

return true;
}

/***************************************************************
Method:  at()

Use: This variant of the operator[] method error checks the value
     of the subscript requested and returns an out_of_range
     exception if an invalid number is sent

Arguments: sub, an integer that represents the subscript location
           requested

Returns: The value of vPointer[sub]
***************************************************************/
double VectorN::at( int sub )const
{
if( sub < 0 || sub == vCapacity )
  throw out_of_range("subscript out of range\n");
else
  return vPointer[sub];
}

/***************************************************************
Method:  at()

Use: This variant of the operator[] method error checks the value
     of the subscript requested and returns an out_of_range
     exception if an invalid number is sent

Arguments: sub, an integer that represents the subscript location
           requested

Returns: The value of vPointer[sub]
***************************************************************/
double& VectorN::at( int sub )
{
if( sub < 0 || sub == vCapacity )
  throw out_of_range("subscript out of range\n");
else
  return vPointer[sub];
}
