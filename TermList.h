// File: TermList.h
// Abstract base class for containers of Terms
// Known subclasses:
//      TermArray
// Coming soon: ParallelArrayTermList, TermVectorList, ...

/** \file TermList.h
 * \brief Parent Class for Term object containers
 */

/**
 *\class TermList
 *\brief Parent Class of the Term objst containers
 *
 */


#ifndef TERMLIST_H
#define TERMLIST_H

#include <fstream>
#include <string>

using namespace std;

class TermList {
public:

  // Place the line of text into the data structure
      /**
   *\fn readIntoList
   *Description: Place the line of text into the data structure \n
   *\param string filename - name of the file to read information from - import\n
   *\return none. \n
   */
  virtual void readIntoList(string filename)=0;
  //
  // Print the data iteratively
        /**
   *\fn printIteratively
   *Description: Print the data iteratively\n
   *\param "none" \n
   *\return none. \n
   */
  virtual void printIteratively()=0;

  // Print the data Iteratively with a pointer
        /**
   *\fn printPtr
   *Description: Print the data iteratively with a pointer\n
   *\param "none" \n
   *\return none. \n
   */
  virtual void printPtr() {}   // not pure virtual; why? I wish I knew\(sorry :(

        /**
   *\fn printRecursively
   *Description: Print the data using recurssion\n
   *\param "none" \n
   *\return none. \n
   */
  virtual void printRecursively() = 0;

  // Evaluate the Polynomial
      /**
   *operator()(double x) const
   *\n
   *Description: () solves the polynomial with a provided x value. \n
   *\param x_value - The value of x in the polynomial - import \n
   *\return result - the sum of the polynomial. \n
   */
  virtual double operator()(double x) const=0;
    
};
  
#endif
