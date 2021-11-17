//*****************************************************************
// FILE:      Rectangle.h
// AUTHOR:    Bryan Butz
// LOGON ID:  z1836033
// DUE DATE:  4/2/18
//
// PURPOSE:   Contains the declaration for the Rectangle class.
//*****************************************************************

#ifndef RECTANGLE_H
#define RECTANGLE_H

#include <string>
#include <vector>
#include "Shape.h"

using namespace std;

 class Rectangle : public Shape
   {
      private:

         int height;
         int width;

      public:

         Rectangle(string, int, int);
         virtual void print()const;
         virtual double get_area()const;

  };

#endif
