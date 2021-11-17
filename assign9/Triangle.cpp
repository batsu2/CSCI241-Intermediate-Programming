/*****************************************************************
 FILE:      Triangle.cpp
 AUTHOR:    Bryan Butz
 LOGON ID:  z1836033
 DUE DATE:  4/2/18

 PURPOSE:   Contains the implementation for the Triangle class.
*****************************************************************/

#include "Triangle.h"

#include <iomanip>
#include <iostream>
#include <string>
#include <vector>


using namespace std;

/***************************************************************
Method: 

Use: This 

Arguments: None

Returns: Nothing
***************************************************************/
Triangle::Triangle( string color, int base, int height) : Shape( color )
{
	this->base = base;
	this->height = height;
}

/***************************************************************
Method: 

Use: This 

Arguments: None

Returns: Nothing
***************************************************************/
void Triangle::print()const
{
	Shape::print();
	cout<< "Triangle, height "<< height << ", base "<< base << ", area "<< get_area() << endl;
}

/***************************************************************
Method: 

Use: This 

Arguments: None

Returns: Nothing
***************************************************************/
double Triangle::get_area()const
{
    double area = (base*height) / 2 ;

return area;
}
