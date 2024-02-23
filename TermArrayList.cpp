/************************************************************/
/* Original Author: Dr. Spiegel                             */
/* - This file was changed from the origional file that was */
/* provided in Dr. Spiegel's public directory. All functions*/
/* were written by Dr. Spiegel, but ajustments were made to */
/* get them to work properly for this assignment.           */
/*                                                          */
/* Author: Matthew Hill                                     */
/* Major: Computer Science                                  */
/* Creation Date: October 20, 2022                          */
/* Due Date: October 25, 2022                               */
/* Course: CSC237 010                                       */
/* Professor Name: Dr. Spiegel                              */
/* Assignment: #2                                           */
/* Filename: TermArrayList.cpp                              */
/* Purpose: This is the class implimentation for a          */
/*          TermArrayList that stores polynomial data,      */
/*          prints the polynomial data, and solves the      */
/*          polynomial.                                     */
/************************************************************/

/** \file TermArrayList.cpp
 * \brief TermList subclass implementation definition: Implements the functions that were declared in TermArrayList.h
 */


#include <fstream>
#include <iostream>
#include <iomanip>
#include "TermArrayList.h"

using namespace std;

/*************************************************************************/
/* - function written by Dr. Spiegel                                     */                                       
/* Function name: TermArrayList                                          */
/* Description: Constructer for a TermArrayList that sets the num terms  */
/*              equal to zero because nothing is in the array            */
/* Parameters: none                                                      */
/* Return Value: none                                                    */
/*************************************************************************/
  TermArrayList::TermArrayList()
  { numTerms=0; }


/*************************************************************************/
/* - origional function written by Dr. Spiegel, but adjustments were made*/
/* Function name: readIntoList                                           */
/* Description: reads data from a text file into an array of type term   */
/*              which are then sorted and like terms are combnined.      */
/*              this function is inherited from TermList.h               */
/* Parameters: string filename - The file to get the data out of         */
/*                                - import                               */
/* Return Value: none                                                    */
/*************************************************************************/

  void TermArrayList::readIntoList(string filename)
  { ifstream source(filename.c_str());
    double coeff;
    int expn;
    
    while(source >> coeff >> expn){
      Term T(coeff,expn);
      int check = 0;
      double sum = 0;
      for(int i = 0; i < numTerms; i++){//this loop will check if there are any with matching expn and if so combine
	if(ThePoly[i].getExponent() == T.getExponent()){
	  sum = ThePoly[i].getCoefficient() + T.getCoefficient();
	  Term tholder(sum,T.getExponent());
	  ThePoly[i] = tholder;
	  check = 1;
	}
      }
      //in the case that the list is full it wont add more items
      if(numTerms == 10){
	continue;
      }
      if(check != 1){
	ThePoly[numTerms++]=T;
      }
    }
    source.close();
    source.clear();
    // put the items in sorted order
    for(int i = 0; i < numTerms - 1; i++){
      for(int j = i + 1; j < numTerms; j++){
	if(ThePoly[j].getExponent() > ThePoly[i].getExponent()){
	  swap(ThePoly[j], ThePoly[i]);
	}
      }
    }
  }


/*************************************************************************/
/* - function written by Dr. Spiegel                                     */
/* Function name: printIteratively                                       */
/* Description: prints the data stored in the term array using an        */
/*              iterator                                                 */
/* Parameters: none                                                      */
/* Return Value: none                                                    */
/*************************************************************************/
  void TermArrayList::printIteratively()
//  void printObjectArrayIterator(TermArray ThePoly[], int numTerms)
  { cout<<"---------------------------------"<<endl;
    cout<<"|Object  Array  Iterative       |"<<endl;
    cout<<"---------------------------------"<<endl;
    for(int i=0; i<numTerms; i++) {
//      cout<<" "<<ThePoly[i]<< "    " << ThePoly[i].getArea() << 
//	    		"    " << ThePoly[i].getPerimeter() << endl;
      cout <<  ThePoly[i] << (i < numTerms-1?" + ":"");
    }
    //cout << endl << endl;
}


void TermArrayList::printRecursively()
{ static int i;
  if(i == numTerms){
    i = 0;
    return;
  }
  cout << ThePoly[i];
  if( i != numTerms -1){
    cout << " + ";
  }
  i++;
  printRecursively();
}

/*************************************************************************/
/* - function written by Dr. Spiegel                                     */
/* Function name: printPtr                                               */
/* Description: prints the data stored in the doubly linked list using a */
/*              pointer                                                  */
/* Parameters: none                                                      */
/* Return Value: none                                                    */
/*************************************************************************/
  void TermArrayList::printPtr()
  //void printObjectArrayPointerRecursive(TermArray* ThePoly, int numTerms)
  { cout<<"---------------------------------"<<endl;
    cout<<"|Object  Array  Pointer         |"<<endl;
    cout<<"---------------------------------"<<endl;
    Term *now=ThePoly;
    for(int i=0; i<numTerms; i++)
      cout << " " << *(now++)  << (i < numTerms-1?" +":"");
    cout << endl;// << endl;
  }

/*************************************************************************/
/* - function written by Dr. Spiegel                                     */
/* Function name: operator ()                                            */
/* Description: solves a polynomial for a Term array list from a provided*/
/*              x value                                                  */
/* Parameters:double x_value - the value for x to equal in the polynomial*/
/*            - import                                                   */
/* Return Value: result - the sum of the polynomial                      */
/*************************************************************************/
  double TermArrayList::operator()(double x) const
  { double result=0.0;
    for (int idx=0;idx<numTerms;idx++)
      result+=ThePoly[idx](x);
    return(result);
  }
