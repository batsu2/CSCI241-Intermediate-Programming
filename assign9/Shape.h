//*****************************************************************
// FILE:      Shape.h
// AUTHOR:    Bryan Butz
// LOGON ID:  z1836033
// DUE DATE:  4/2/18
//
// PURPOSE:   Contains the declaration for the Shape class.
//*****************************************************************

#ifndef SHAPE_H
#define SHAPE_H

#include <string>
#include <vector>

using namespace std;

 class Shape
   {
      private:

          string color;

      public:

          Shape( const string& );
          virtual ~Shape();

          virtual void print()const;
          virtual double get_area()const = 0;

  };

#endif
