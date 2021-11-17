/*****************************************************************
 FILE:      Vector3.cpp
 AUTHOR:    Bryan Butz
 LOGON ID:  z1836033
 DUE DATE:  3/8/18

 PURPOSE:   Contains the implementation for the Vector3 class as
 	    well as friend functions of the Vector3 class
*****************************************************************/

#include "Vector3.h"

#include <iomanip>
#include <iostream>

using namespace std;

/***************************************************************
Method:  Vector3()

Use: This is the default constructor method for the Vector3 class

Arguments: 1. newX, a double value representing the new x coordinate
	   2. newY, a double value representing the new y coordinate
	   3. newZ, a double value representing the new z coordinate

Returns: Nothing
***************************************************************/
Vector3::Vector3( double newX, double newY, double newZ )
{
  x = newX;
  y = newY;
  z = newZ;

}

/***************************************************************
Function:  operator<<

Use: This friend function of the Vector3 class overloads the class
     to use the stream insertion operator (cout<<) with a Vector3
     object

Arguments: 1. lhs, a refrence to an ostream variable
	   2. rhs, a refrence to a constant Vector3 object to be
	      printed

Returns: lhs, an ostream variable
***************************************************************/
ostream& operator<<(ostream& lhs, const Vector3& rhs)
{

   lhs << "( " << rhs.x << ", " << rhs.y << ", " << rhs.z << " )";

return lhs;
}

/***************************************************************
Method:  operator+

Use: This method overloads the Vector3 class to use the addition
     opperator (+) with a Vector3 object

Arguments: rhs, a refrence to a constant Vector3 object

Returns: result, a Vector3 object that containst the sum of two
         x coordinates, the sum of two y coordinates, and the sum
         of two z coordinates.
***************************************************************/
Vector3 Vector3::operator+( const Vector3& rhs)const
{
Vector3 result = *this;

   result.x = rhs.x + result.x;
   result.y = rhs.y + result.y;
   result.z = rhs.z + result.z;

return result;
}

/***************************************************************
Method:  operator-

Use: This method overloads the Vector3 class to use the subtraction
     opperator (-) with a Vector3 object

Arguments: rhs, a refrence to a constant Vector3 object

Returns: result, a Vector3 object that containst the difference of two
	 x coordinates, the difference of two y coordinates, and the
	 difference of two z coordinates.
***************************************************************/
Vector3 Vector3::operator-( const Vector3& rhs)const
{
Vector3 result = *this;

   result.x = result.x - rhs.x;
   result.y = result.y - rhs.y;
   result.z = result.z - rhs.z;

return result;
}

/***************************************************************
Method:  operator*

Use: This method overloads the Vector3 class to use the multiplication
     opperator (*) with a Vector3 object. This overloader specificly
     returns the scalar product.

Arguments: rhs, a refrence to a constant Vector3 object

Returns: sum, a double that represents the sum of two Vector3
	 objects after their coordinates have been multiplied
***************************************************************/
double Vector3::operator*( const Vector3& rhs)const
{
Vector3 result = *this;

	result.x = result.x * rhs.x;
	result.y = result.y * rhs.y;
	result.z = result.z * rhs.z;

	double sum = result.x + result.y + result.z; //adds all products to get scalar product

return sum;
}

/***************************************************************
Method:  operator*

Use: This method overloads the Vector3 class to use the multiplication
     opperator (*) with a Vector3 object. This method assumes the
     Vector3 object is on the left hand side of the operation

Arguments: rhs, a double value representing the value to multiply
	   the Vector3 object by

Returns: result, a Vector3 object that contains the product of a
         Vector3 object and a double.
***************************************************************/
Vector3 Vector3::operator*( double rhs )const
{
Vector3 result = *this;
Vector3 rightSide( rhs, rhs, rhs );

	result.x = result.x * rightSide.x;
	result.y = result.y * rightSide.y;
	result.z = result.z * rightSide.z;

return result;
}

/***************************************************************
Function:  operator*

Use: This friend function of the Vector3 class overloads the class
     to use the multiplication opperator (*) with a Vector3 object.
     This method assumes the Vector3 object is on the right hand side
     of the operation

Arguments: 1. lhs, a double value representing the value to multiply
	      the Vector3 object by
	   2. rhs, a constant refrence to a Vector3 object that is
	      getting multiplied.

Returns: result, a Vector3 object that contains the product of a
	 Vector3 object and a double.
***************************************************************/
Vector3 operator*( double lhs, const Vector3& rhs)
{
Vector3 result = rhs;
Vector3 leftSide( lhs, lhs, lhs );

	result.x = leftSide.x * result.x;
	result.y = leftSide.y * result.y;
	result.z = leftSide.z * result.z;

return result;
}

/***************************************************************
Method:  operator[]

Use: This method overloads the Vector3 class to use the subscript
     opperator ( [] ) with a Vector3 object which allows it to
     read the array.

Arguments: sub, an integer that represents the subscript location
           of x, y, and z to 0, 1, and 2 respectively

Returns: x if the passed in subscript number is 0, y if the passed
	 in subscript number is 1, and z if the passed in subscript
         number is 2. x, y, and z are considered double variables.
***************************************************************/
double Vector3::operator[]( int sub )const
{
 if( sub == 0 )
   return x;
 else if( sub == 1)
   return y;
 else
   return z;
}

/***************************************************************
Method:  operator[]

Use: This method overloads the Vector3 class to use the subscript
     opperator ( [] ) with a Vector3 object which allows it to
     write the array.

Arguments: sub, an integer that represents the subscript location
	   of x, y, and z to 0, 1, and 2 respectively

Returns: x if the passed in subscript number is 0, y if the passed
         in subscript number is 1, and z if the passed in subscript
	 number is 2. x, y, and z are considered double variables.
***************************************************************/
double& Vector3::operator[]( int sub )
{
 if( sub == 0 )
   return x;
 else if( sub == 1 )
   return y;
 else
   return z;
}

/***************************************************************
Method:  operator==

Use: This method overloads the Vector3 class to use the equality
     opperator (==) with a Vector3 object.

Arguments: rhs, a refrence to a constant Vector3 object

Returns: a bool value of true if the Vector3 objects are equal and
	 false if the objects are not equal
***************************************************************/
bool Vector3::operator==( const Vector3& rhs)const
{
return ( this->x == rhs.x && this->y == rhs.y && this->z == rhs.z );
}
