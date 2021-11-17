/*****************************************************************
 FILE:      Vector3.h
 AUTHOR:    Bryan Butz
 LOGON ID:  z1836033
 DUE DATE:  3/8/18

 PURPOSE:   Contains the declaration for the Vector3 class.
*****************************************************************/

#ifndef VECTOR_H
#define VECTOR_H

#include <cstring>
#include <iostream>

using namespace std;

 class Vector3
   {

   	friend ostream& operator<<(ostream& lhs, const Vector3& rhs);
   	friend Vector3 operator*( double lhs, const Vector3& rhs);

      private:

          double x;
		  double y;
		  double z;


      public:

          Vector3( double x=0.0, double y=0.0, double z=0.0 ); //if no values are passed in, set x,y,& z to 0.0

		  Vector3 operator+( const Vector3& rhs )const;
		  Vector3 operator-( const Vector3& rhs )const;
		  double  operator*( const Vector3& rhs )const;
		  Vector3 operator*( double rhs )const;
		  double operator[]( int sub )const;  //for reading
		  double& operator[]( int sub );      //for writing
		  bool operator==( const Vector3& rhs )const;
  };

#endif
