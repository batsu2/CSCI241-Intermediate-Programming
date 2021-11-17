/*********************************************************************
   PROGRAM:    CSCI 241 Assignment 9
   PROGRAMMER: Bryan Butz
   LOGON ID:   z1836033
   DUE DATE:   5/2/2018

   FUNCTION:   This tests the Shape, Circle, Rectangle, and Triangle
               classes
*********************************************************************/

#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include "Shape.h"
#include "Circle.h"
#include "Rectangle.h"
#include "Triangle.h"

using namespace std;


int main()
{
        Shape *s1[9];

	for( int i = 0; i < 8; i++ )
	 {
                s1[i]= new Circle("blue", 10);
	 	++i;
	 	s1[i]= new Rectangle("green", 5, 7);
	 	++i;
	 	s1[i]= new Triangle("red", 11, 3);
	 }

// Shape* shapePtr = (Shape*) vptr;

	cout<<"Printing all shapes...\n\n";
	for( int i = 0; i < 8; i++ )
	  {
	  	Shape* shapePtr = dynamic_cast<Shape*>(s1[i]);
                if( shapePtr != nullptr )
                 {
                   shapePtr->print();
                 }
            cout<<endl;
	  }

	cout<<"Printing only triangles...\n\n";
	for( int i = 0; i < 8; i++ )
	  {
            
	  }

	for( int i = 0; i < 8; i++ )
	  {
	    delete s1[i];
	  }


//Circle c1("blue", 10);

//c1.print();

return 0;
}
