/*****************************************************************
 FILE:      Circle.cpp
 AUTHOR:    Bryan Butz
 LOGON ID:  z1836033
 DUE DATE:  4/2/18

 PURPOSE:   Contains the implementation for the Circle class.
*****************************************************************/

#include "Circle.h"

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
Circle::Circle( string color, int radius) : Shape( color )
{
   this->radius = radius;
}

/***************************************************************
Method: 

Use: This 

Arguments: None

Returns: Nothing
***************************************************************/
void Circle::print()const
{
    Shape::print();
    cout<< "Circle, radius " << radius<< ", area "<< get_area() << endl;
}

/***************************************************************
Method: 

Use: This 

Arguments: None

Returns: Nothing
***************************************************************/
double Circle::get_area()const
{
   double area = 3.14*radius*radius;

return area;
}
