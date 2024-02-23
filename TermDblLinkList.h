/************************************************************/
/* Author: Matthew Hill                                     */
/* Major: Computer Science                                  */
/* Creation Date: October 20, 2022                          */
/* Due Date: October 25, 2022                               */
/* Course: CSC237 010                                       */
/* Professor Name: Dr. Spiegel                              */
/* Assignment: #2                                           */
/* Filename: TermDblLinkList.h                              */
/* Purpose: This is the class decleration for a TermDblLink */
/*          List that inherits functions from TermList.     */
/*          and then implements these inherited functions in*/
/*          TermDblLinkList.cpp                             */
/************************************************************/


/** \file TermDblLinkList.h
 * \brief Function/class decleration for TermDblLinkList. (Functions inherited from TermList)
 */

/**
 *\class TermDblLinkList
 *\brief Implementation and decleration of the TermDblLinkList which implements functions from the TermList parent class using a doubly linked list.
 *
 */


#ifndef TERMDBLLINKLIST_h
#define TERMDBLLINKLIST_h

#include <fstream>
#include <string>
#include "DblLink.h"
#include "term.h"
#include "TermList.h"

using namespace std;

class TermDblLinkList : public TermList {
 public:
  //constructor fo a TermDblLinkList
    /**
   *\fn TermDblLinkList
   *Description: This function is the constructor the the TermDblLinkList class\n
   *\param "none" \n
   *\return none. \n
   */
  TermDblLinkList();
  //read info from a file into a doubly linked list
      /**
   *\fn readIntoList
   *Description: This function reads information from a file and stores that information in a doubly linked list that stores terms\n
   *\param string filename - the name of the file that will be read for information - import \n
   *\return none. \n
   */
  void readIntoList(string filename);
  //print the doubly linked list
      /**
   *\fn printIteratively
   *Description: This function prints the data stored in the doubly linked list using iteration\n
   *\param "none" \n
   *\return none. \n
   */
  void printIteratively();

      /**
   *\fn printRecursively
   *Description: This function prints the data stored in the doubly linked list using recursion\n
   *\param none. \n
   *\return none. \n
   */
  void printRecursively();
  
  //this function does not exist but included for inheritance
  //void printPtr();
  //solve the doubly linked list polynomial
    /**
   *operator()(double x) const
   *\n
   *Description: () solves the polynomial for a doubly linked list with a provided x value. \n
   *\param double x - The value of x in the polynomial - import \n
   *\return  result - the sum of the polynomial. \n
   */
  virtual double operator()(double x) const;

private:
  DblLink<Term> ThePoly;

};

#endif
