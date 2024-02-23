// File: TermArrayList.h
// Container of TermArray objects. 

/** \file TermArrayList.h
 * \brief Function/class decleration for TermArrayList. (Functions inherited from TermList) 
 */

/** 
 *\class TermArrayList
 *\brief Implementation and decleration of the TermArrayList which implements functions from the TermList parent class. This class uses an array of objects to implement these functions.
 *
 */
/**********************************/
/* written by Dr.Spiegel          */
/* no edits were made to this file*/
/**********************************/
#ifndef WORDDATALIST_H
#define WORDDATALIST_H

#include <fstream>
#include <string>
#include "TermList.h"
#include "term.h"

using namespace std;

const int MAXTERMS=10;

class TermArrayList : public TermList {
public:
  //constructor for a TermArray list
  /**
   *\fn TermArrayList
   *Description: The constructor for a TermArrayList the initializes numTerms to 0 \n
   *\param "none" \n
   *\return none \n
   */
  TermArrayList();

  //read info from a file into a doubly lined list
    /**
   *\fn readIntoList
   * Description: readIntoList() reads data from a text file into an array of type term which are then sorted and like terms are combnined. This function is inherited from TermList.h \n
   *\param string filename \n
   *\return none. \n
   */
  void readIntoList(string filename);

  // Print the data iteratively
      /**
   *\fn printIteratively
   * Description: printIteratively() prints the data stored in the term array using an iterator. This function is inherited from TermList.h \n
   *\param "none" \n 
   *\return none. \n
   */
  void printIteratively();

  /**
   *\fn printRecursively
   *Description: printRecursively() prints the polynomial stored ThePoly using recursion. This function is inherited from the TermList. \n
   *\param " none" \n
   *\return none \n
   */
  void printRecursively();
  
  // Print the data with a pointer
    /**
   *\fn printPtr
   *Description: printPtr() prints the array of terms using a pointer. This function is inherited from the TermList. \n
   *\param "none" \n
   *\return none. \n
   */
  void printPtr();

  // Evaluate the Polynomial
  /**
   *operator()(double x) const
   *\n
   *Description: () solves the polynomial for a term array list with a provided x value. \n
   *\param double x - The value of x in the polynomial - import \n
   *\return result - the sum of the polynomial. \n
   */
  virtual double operator()(double x) const;

private:
  Term ThePoly[10];
  int numTerms;
  
};
  
#endif
