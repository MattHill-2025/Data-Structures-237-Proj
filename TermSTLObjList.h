/************************************************************/
/* Author: Matthew Hill                                     */
/* Major: Computer Science                                  */
/* Creation Date: October 20, 2022                          */
/* Due Date: October 25, 2022                               */
/* Course: CSC237 010                                       */
/* Professor Name: Dr. Spiegel                              */
/* Assignment: #2                                           */
/* Filename: TermSTLObjList.h                               */
/* Purpose: This is the class decleration for a             */
/*   TermSTLObjList that inherits functions from TermList.  */
/*          and then implements these inherited functions in*/
/*          TermSTLObjList.cpp                              */
/************************************************************/

/** \file TermSTLObjList.h
 * \brief Function/class decleration for TermSTLObjList. (Functions inherited from TermList)
 */

/**
 *\class TermSTLObjList
 *\brief Implementation and decleration of the TermSTLObjList which implements functions from the TermList parent class. This class uses a vector to implements these functions.
 *
 */


#ifndef STLOBJLINK_H
#define STLOBJLINK_H

#include <fstream>
#include <string>
#include <vector>
#include "TermList.h"
#include "term.h"

using namespace std;

class TermSTLObjList : public TermList {
 public:
  //consturctor for a TermSTLObjList
    /**
   *\fn TermSTLObjList
   *Description: The constructor for a TermSTLObjList that creates and empty vector<Term> list\n
   *\param "none" \n
   *\return none. \n
   */
  TermSTLObjList();
  //read info from a file into a TermSTLObjList
      /**
   *\fn readIntoList
   *Description: Reads information from a text file into a vector of terms that store the information\n
   *\param string filename - The name of the file that information is being read from - import \n
   *\return none. \n
   */
  void readIntoList(string filename);
  //print the function iteratively;
      /**
   *\fn printIteratively
   *Description: Prints the data stored in the vector of type term using an iterator\n
   *\param "none" \n
   *\return none. \n
   */
  void printIteratively();
    /**
   *\fn printRecursively
   *Description: This function print the vector of terms using recursion\n
   *\param "none" \n
   *\return none. \n
   */
  void printRecursively();
  //this function is not implimented or used, but included because of inheritance
  //void printPtr();
  //overloaded operator() to solve the polynomial with a given x value
    /**
   *operator()(double x) const
   *\n
   *Description: () solves the polynomial for a vecotr<Term>  with a provided x value. \n
   *\param double x - The value of x in the polynomial - import \n
   *\return result - the sum of the polynomial. \n
   */
  virtual double operator()(double x) const;

private:
  vector<Term> ThePoly;
};

#endif
