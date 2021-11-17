//*****************************************************************
// FILE:      Triangle.h
// AUTHOR:    Bryan Butz
// LOGON ID:  z1836033
// DUE DATE:  4/2/18
//
// PURPOSE:   Contains the declaration for the Triangle class.
//*****************************************************************

#ifndef TRIANGLE_H
#define TRIANGLE_H

#include <string>
#include <vector>
#include "Shape.h"

using namespace std;

 class Triangle : public Shape
   {
      private:

         int height;
         int base;

      public:

         Triangle(string, int, int);
         virtual void print()const;
         virtual double get_area()const;

  };

#endif
