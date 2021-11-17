/*****************************************************************
 FILE:      Rectangle.cpp
 AUTHOR:    Bryan Butz
 LOGON ID:  z1836033
 DUE DATE:  4/2/18

 PURPOSE:   Contains the implementation for the Rectangle class.
*****************************************************************/

#include "Rectangle.h"

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
Rectangle::Rectangle( string color, int width, int height) : Shape( color )
{
	this->width = width;
	this->height = height;
}

/***************************************************************
Method: 

Use: This 

Arguments: None

Returns: Nothing
***************************************************************/
void Rectangle::print()const
{
	Shape::print();
	cout<< "Rectangle, height "<< height << ", width "<< width << ", area "<< get_area() << endl;
}

/***************************************************************
Method: 

Use: This 

Arguments: None

Returns: Nothing
***************************************************************/
double Rectangle::get_area()const
{
    double area = width * height;

return area;
}

