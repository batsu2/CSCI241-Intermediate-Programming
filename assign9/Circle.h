//*****************************************************************
// FILE:      Circle.h
// AUTHOR:    Bryan Butz
// LOGON ID:  z1836033
// DUE DATE:  4/2/18
//
// PURPOSE:   Contains the declaration for the Circle class.
//*****************************************************************

#ifndef CIRCLE_H
#define CIRCLE_H

#include <vector>
#include <string>
#include "Shape.h"

using namespace std;

 class Circle : public Shape
   {
      private:

         int radius;

      public:

        Circle( string, int );
        virtual void print()const;
        virtual double get_area()const;
  };

#endif
