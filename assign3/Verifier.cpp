/*****************************************************************
 FILE:      Verifier.cpp
 AUTHOR:    Bryan Butz
 LOGON ID:  z1836033
 DUE DATE:  2/28/18

 PURPOSE:   Contains the implementation for the Verifier class.
*****************************************************************/

#include "Verifier.h"

#include <iomanip>
#include <iostream>
#include <fstream>

using namespace std;

/***************************************************************
Method:  Verifier()

Use: This is the default constructor method for the Verifier class

Arguments: None

Returns: Nothing
***************************************************************/
Verifier::Verifier()
{

 for( int i = 0; i < 9; i++ )
  {
   for( int j = 0; j < 9; j++ )
    sudokuGrid [i] [j] = 0;
  }

}

/***************************************************************
Method:  readGrid( const char* )

Use: This method reads the contents of an input file into the
     elements of a 2-dimensional array

Arguments: 1. fileName, a pointer to a constant character which will
              point to the an array of characters that contains
              the name of a file to use as input.

Returns: Nothing
***************************************************************/
void Verifier::readGrid( const char* fileName )
{
 ifstream inFile;

 inFile.open( fileName );
 if( !inFile )           //If unable to open file
  {
   cerr<<"Error - unable to open input file\n";
   exit(1);
  }

while( inFile )
 {
  for( int i = 0; i < 9; i++ )
   {
     for( int j = 0; j < 9; j++ )
     inFile >> sudokuGrid [i] [j];  //Builds the sudoku grid from a file

  }
 }

inFile.close();
}

/***************************************************************
Method:  printGrid()

Use: This prints out a 2D array of integers in the format of a
     sudoku grid.

Arguments: None

Returns: Nothing
***************************************************************/
void Verifier::printGrid()
{

 cout<< "-------------------------\n";

  for( int i = 0; i < 9; i++ )
   {
     for( int j = 0; j < 9; j++ )
      {

        if( j == 0 || j == 3 || j == 6 ) //Determines if a vertical dividing line should be drawn (extra credit)
          cout<< "| ";


        cout<< sudokuGrid[ i ][ j ] << ' ';


        if( j == 8 ) //If at the end of a line, print a vertical line
          cout<< "|";

        if ( (i == 2 && j == 8) || (i == 5 && j == 8) ) //Determines if a horizonatal dividing line should be drawn (extra credit)
          cout<< "\n-------------------------";

      }
    cout<< endl;
   }
 cout<< "-------------------------\n";
}

/***************************************************************
Method:  verifySolution()

Use: This verifies that a 2D array of integers formated as a sudoku
     puzzle is in fact a valid solution as dictaded by the rules
     of the game.

Arguments: None

Returns: A boolean value of true if the sudoku grid array contains
         a valid solution or false if it does not
***************************************************************/
bool Verifier::verifySolution()
{
int temp[9];
int i = 0;
int j = 0;
int row = 0;
int column = 0;

 //Checking the Rows
for( i = 0; i < 9; i++ )
 {
  for( j = 0; j < 9; j++ )
   {
    temp[j] = sudokuGrid[i][j]; //Builds an array that will represent the
   }                            //row that is to be tested

    if( check(temp) == false )
     return false;
 }


 //Checking the Columns
for( i = 0; i < 9; i++ )
 {
  for( j = 0; j < 9; j++ )
   {
    temp[j] = sudokuGrid[j][i]; //Builds an array that will represent the
   }                            //column that is to be tested

  if( check(temp) == false )
   return false;
 }


 //Checking the subgrids
for( column = 0; column <= 6; column += 3 ) //Column and Row loops set the starting
 {                                          //points for each subgrid square
  for( row = 0; row <= 6; row += 3 )
   {
    for( int k = 0, i = 0; i < 3; i++ )
     {
      for( j = 0; j < 3; j++ )
       {
        temp[k++] = sudokuGrid[row+i][column+j]; //Builds an array that will represent the
       }                                         //area in the subgrid to be tested
     }

    if ( check(temp) == false )
     return false;
   }
 }

return true;
}

/***************************************************************
Method:  check( int [] )

Use: This checks to see if there are any duplicate values in an
     array of integers

Arguments: 1. temp[9], an array of integers to test for duplicates

Returns: A bool value of false if there are duplicates found or
         a bool value of true if there are not dublicates found
***************************************************************/
bool Verifier::check( const int temp[9] )
{
 int testTemp;

 for( int i = 0; i < 9; i++ )
  {
   testTemp = temp[i];

   for (int j = i+1; j  < 9; j++ ) //Loops through and tests for any duplicates
    {                              //of the testTemp variable in the array
     if( temp[j] == testTemp)
      return false;
    }
  }

 return true;
}
