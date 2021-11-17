//*****************************************************************
// FILE:      Verifier.h
// AUTHOR:    Bryan Butz
// LOGON ID:  z1836033
// DUE DATE:  2/28/18
//
// PURPOSE:   Contains the declaration for the Verifier class.
//*****************************************************************

#ifndef VERIF_H
#define VERIF_H

#include <cstring>

using namespace std;

 class Verifier
   {
      private:

          int sudokuGrid [9] [9];

          bool check( const int [] ); //extra class used by verifySolution()

      public:

          Verifier();

          void readGrid( const char* );
          void printGrid();
          bool verifySolution();
  };

#endif

