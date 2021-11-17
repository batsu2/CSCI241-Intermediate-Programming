/*****************************************************************
 FILE:      Shape.cpp
 AUTHOR:    Bryan Butz
 LOGON ID:  z1836033
 DUE DATE:  4/2/18

 PURPOSE:   Contains the implementation for the Shape class.
*****************************************************************/

#include "Shape.h"

#include <iomanip>
#include <iostream>
#include <string>
#include <vector>


using namespace std;

/***************************************************************
Method:  Shape()

Use: This is the default constructor method for the Shape base
     class

Arguments: None

Returns: Nothing
***************************************************************/
Shape::Shape( const string& color )
{
   this->color = color;
}

/***************************************************************
Method:  ~Shape()

Use: This is the default destructor method for the Shape base
     class

Arguments: None

Returns: Nothing
***************************************************************/
Shape::~Shape()
{
}

/***************************************************************
Method:  print()

Use: This is 

Arguments: None

Returns: Nothing
***************************************************************/
void Shape::print()const
{
   cout<< color << " ";
}
