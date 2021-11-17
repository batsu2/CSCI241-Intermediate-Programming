/*********************************************************************
   PROGRAM:    CSCI 241 Assignment 1
   PROGRAMMER: Bryan Butz
   LOGON ID:   z1836033
   DUE DATE:   2/1/2018

   FUNCTION:   This program tests functions for manipulating C
               strings.
*********************************************************************/

#include <iostream>
#include <cstring>
#include <cctype>

using std::cin;
using std::cout;
using std::endl;

// Add your function prototypes here
bool equals(const char* str1, const char* str2);
bool equalsIgnoreCase(const char* str1, const char*str2);
int indexOf(const char* str, char ch);
int lastIndexOf(const char* str, char ch);
bool startsWith(const char* str, const char* prefix);
bool endsWith(const char* str, const char* suffix);

int main()
   {
   int index;

   // Tests 1a - 1d: Test the equals() function
   cout << "Test 1a: ";
   if (equals("catapult", "catapult"))
      cout << "correct\n";
   else
      cout << "incorrect\n";

   cout << "Test 1b: ";
   if (!equals("catapult", "catamaran"))
      cout << "correct\n";
   else
      cout << "incorrect\n";

   cout << "Test 1c: ";
   if (!equals("cat", "catamaran"))
      cout << "correct\n";
   else
      cout << "incorrect\n";

   cout << "Test 1d: ";
   if (!equals("catapult", "cat"))
      cout << "correct\n";
   else
      cout << "incorrect\n";

   cout << endl;

   // Tests 2a - 2d: Test the equalsIgnoreCase() function
   cout << "Test 2a: ";
   if (equalsIgnoreCase("catapult", "CATAPULT"))
      cout << "correct\n";
   else
      cout << "incorrect\n";

   cout << "Test 2b: ";
   if (!equalsIgnoreCase("catapult", "Catamaran"))
      cout << "correct\n";
   else
      cout << "incorrect\n";

   cout << "Test 2c: ";
   if (!equalsIgnoreCase("Cat", "Catamaran"))
      cout << "correct\n";
   else
      cout << "incorrect\n";

   cout << "Test 2d: ";
   if (!equalsIgnoreCase("Catapult", "Cat"))
      cout << "correct\n";
  else
      cout << "incorrect\n";

   cout << endl;

   // Tests 3a - 3d: Test the indexOf() function
   cout << "Test 3a: ";
   index = indexOf("adamant", 'a');
   if (index == 0)
      cout << "correct\n";
   else
      cout << "incorrect - index returned was " << index << ", not 0\n";

   cout << "Test 3b: ";
   index = indexOf("adamant", 'm');
   if (index == 3)
      cout << "correct\n";
   else
      cout << "incorrect - index returned was " << index << ", not 3\n";

   cout << "Test 3c: ";
   index = indexOf("adamant", 't');
   if (index == 6)
      cout << "correct\n";
   else
      cout << "incorrect - index returned was " << index << ", not 6\n";

   cout << "Test 3d: ";
   index = indexOf("adamant", 'x');
   if (index == -1)
      cout << "correct\n";
   else
      cout << "incorrect - index returned was " << index << ", not -1\n";

   cout << endl;

   // Tests 4a - 4d: Test the lastIndexOf() function
   cout << "Test 4a: ";
   index = lastIndexOf("adamant", 't');
   if (index == 6)
      cout << "correct\n";
   else
      cout << "incorrect - index returned was " << index << ", not 6\n";

   cout << "Test 4b: ";
   index = lastIndexOf("adamant", 'm');
   if (index == 3)
      cout << "correct\n";
   else
      cout << "incorrect - index returned was " << index << ", not 3\n";

   cout << "Test 4c: ";
   index = lastIndexOf("adamant", 'a');
   if (index == 4)
      cout << "correct\n";
   else
      cout << "incorrect - index returned was " << index << ", not 4\n";

   cout << "Test 4d: ";
   index = lastIndexOf("adamant", 'x');
   if (index == -1)
      cout << "correct\n";
   else
      cout << "incorrect - index returned was " << index << ", not -1\n";

   cout << endl;

   // Tests 5a - 5c: Test the startsWith() function
   cout << "Test 5a: ";
   if (startsWith("your house", "your"))
      cout << "correct\n";
   else
      cout << "incorrect\n";

   cout << "Test 5b: ";
   if (!startsWith("my house", "your"))
      cout << "correct\n";
   else
      cout << "incorrect\n";

   cout << "Test 5c: ";
   if (!startsWith("you", "your"))
      cout << "correct\n";
   else
      cout << "incorrect\n";

   cout << endl;

   // Tests 6a - 6c: Test the endsWith() function
   cout << "Test 6a: ";
   if (endsWith("your house", "house"))
      cout << "correct\n";
   else
      cout << "incorrect\n";

   cout << "Test 6b: ";
   if (!endsWith("your mouse", "house"))
      cout << "correct\n";
   else
      cout << "incorrect\n";

   cout << "Test 6c: ";
   if (!endsWith("use", "house"))
      cout << "correct\n";
   else
      cout << "incorrect\n";

   return 0;
   }

// Add your function definitions here
//*******************************************************
// bool equals(const char* str1, const char* str2)
//
// Use: This compares the C string str1 to the C string str2
//
// Parameters: 1. str1, A C string representing the first string
//             2. str2, A C string representing the second string
//
// Returns: A bool value of true or false depending on if
//          the C strings are considered equal or not
//*******************************************************
bool equals (const char* str1, const char* str2)
{
  int m = strcmp(str1, str2);

   if (m < 0)
      return false;
   else if(m > 0)
      return false;
   else
      return true;
}

//*******************************************************
// bool equalsIgnoreCase(const char* str1, const char* str2)
//
// Use: This compares the C string str1 to the C string
//      str2, ignoring case considerations.
//
// Parameters: 1. str1, A C string representing the first string
//             2. str2, A C string representing the second string
//
// Returns: A bool value of true or false depending on if
//          the C strings are considered equal or not
//*******************************************************
bool equalsIgnoreCase(const char* str1, const char* str2)
{
  int i;

    if (strlen(str1) != strlen(str2))
      return false;

    for (i = 0; str1[i] != '\0' && str2[i] != '\0'; i++)
      {
       if (tolower(str1[i]) != tolower(str2[i]))
          return false;
      }

 return true;
}

//*******************************************************
// int indexOf(const char* str, char ch)
//
// Use: This returns the index  within the C string str
//      of the FIRST occurence of the character ch.
//
// Parameters: 1. str, A C string to be tested
//             2. ch, A character to compare with the C string
//
// Returns: The letter space of the first occurance of
//          the testing character
//*******************************************************
int indexOf(const char* str, char ch)
{
  int i;

    for (i = 0; str[i] != '\0'; i++)
     {
       if (str[i] == (int) ch)
        return i;
     }

 return -1;
}

//*******************************************************
// int lastIndexOf(const char* str, char ch)
//
// Use: This returns the index within the C string str of
//      the LAST occurence of the character ch.
//
// Parameters: 1. str, A C string to be tested
//             2. ch, A character to compare with the C string
//
// Returns: The letter space of the last occurans of
//          the testing character
//*******************************************************
int lastIndexOf(const char* str, char ch)
{
  int i;

   //This loops through the C string to find the
   //possition of the NULL value
    for (i = 0; str[i] != '\0'; i++)
      { }

    for (i = i; i != 0; i--)
      {
        if (str[i] == (int) ch)
          return i;
      }

 return -1;
}

//*******************************************************
// bool startsWith(const char* str, const char* prefix)
//
// Use: This funciton tests if a C string starts with
//      a specific prefix
//
// Parameters: 1. str, A C string to be tested
//             2. prefix, A C string prefix to compare to
//
// Returns: A bool value of true if the C string contains
//          the prefix and false if it does not contain it
//*******************************************************
bool startsWith(const char* str, const char* prefix)
{
 int i;

  for (i = 0; prefix[i] != '\0'; i++)
   {
    if (str[i] != prefix[i])
       return false;
   }

 return true;
}

//*******************************************************
// bool endsWith(const char* str, const char* suffix)
//
// Use: This function tests if a C string ends with a
//      specific suffix
//
// Parameters: 1. str, A C string to be tested
//             2. suffix, A C string suffix to compare to
//
// Returns: A bool value of true if the C string contains
//          the suffix and false if it does not contain it
//*******************************************************
bool endsWith(const char* str, const char* suffix)
{
 int i, j;

  //These loops look for the possition
  //of the NULL character in str and suffix
   for (i = 0; str[i] != '\0'; i++)
      {}

   for (j = 0; suffix[j] != '\0'; j++)
      {}

   while (j >= 0)
   {
    if (str[i] != suffix[j])
     return false;

    i--;
    j--;
   }

 return true;
}

