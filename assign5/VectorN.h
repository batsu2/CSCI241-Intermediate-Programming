/*****************************************************************
 FILE:      VectorN.h
 AUTHOR:    Bryan Butz
 LOGON ID:  z1836033
 DUE DATE:  3/27/18

 PURPOSE:   Contains the declaration for the VectorN class.
*****************************************************************/

#ifndef VECTORN_H
#define VECTORN_H

#include <cstring>
#include <iostream>

using namespace std;

 class VectorN
   {

        friend ostream& operator<<(ostream& lhs, const VectorN& rhs);
        friend VectorN operator*( double lhs, const VectorN& rhs);

      private:

          double* vPointer;
          size_t vCapacity;

      public:

          VectorN();
          VectorN( const double values[], size_t n );
          ~VectorN();

          void clear();
	  size_t size() const;
	  double operator[]( int sub )const; //for reading
          double& operator[]( int sub );     //for writing
	  VectorN( const VectorN& other );
	  VectorN operator=( const VectorN& other );
	  VectorN operator+( const VectorN& rhs )const;
	  VectorN operator-( const VectorN& rhs )const;
          double operator*( const VectorN& rhs )const;
	  VectorN operator*( double rhs )const;
          bool operator==( const VectorN& rhs )const;
          double at( int sub ) const;
          double& at( int sub );


  };

#endif
