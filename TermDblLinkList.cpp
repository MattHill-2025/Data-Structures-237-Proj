/************************************************************/
/* Author: Matthew Hill                                     */
/* Major: Computer Science                                  */
/* Creation Date: October 20, 2022                          */
/* Due Date: October 25, 2022                               */
/* Course: CSC237 010                                       */
/* Professor Name: Dr. Spiegel                              */
/* Assignment: #2                                           */
/* Filename: TermDblLinkList.cpp                            */
/* Purpose: This is the class implimentation for a          */
/*          TermDblLinkList that stores polynomial data,    */
/*          prints the polynomial data, and solves the      */
/*          polynomial.                                     */
/************************************************************/


/** \file TermDblLinkList.cpp
 * \brief TermList subclass implementation definition: Implements the functions that were declared in TermDblLinkList.h
 */



#include <fstream>
#include <iomanip>
#include<iostream>
#include "TermDblLinkList.h"
using namespace std;

/*************************************************************************/
/* Function name: TermDblLinkList                                        */
/* Description: Constructer for a TermDblLinkList that creates a doubly  */
/*             linked list                                               */
/* Parameters: none                                                      */
/* Return Value: none                                                    */
/*************************************************************************/
TermDblLinkList::TermDblLinkList(){
  DblLink<Term> ThePoly;
}


/*************************************************************************/
/* Function name: readIntoList                                           */
/* Description: reads data from a test file into a doubly linked list    */
/*              which are then sorted and like terms are combnined.      */
/*              this function is inherited from TermList.h               */
/* Parameters: string filename - The file to get the data out of         */
/*                                - import                               */
/* Return Value: none                                                    */
/*************************************************************************/
void TermDblLinkList::readIntoList(string filename){
  ifstream source(filename.c_str());
  double coeff;
  int expn;
  
  DblLinkIterator<Term> adder(ThePoly);
  double sum =0;
  Term holder;
  
  while(source >> coeff >> expn){
    int check = 1;
    Term hold(coeff,expn);
    adder.start();
     
    if(adder.isEmpty() == false){
      while(adder.end() == false){
	holder = *adder;
	if(holder.getExponent() == hold.getExponent()){
	  sum = holder.getCoefficient() + hold.getCoefficient();
	  Term Combined(sum, hold.getExponent());
	  ThePoly.remove(*adder);
	  ThePoly.orderedInsert(Combined);
	  check = 0;
	  break;
	}
	adder++;
      }
    }
    
    if(check != 0){
      ThePoly.orderedInsert(hold);
      }
  }

  source.close();
  source.clear();
}
// no implementation included because of inherited function
//void TermDblLinkList::printPtr(){}

void TermDblLinkList::printRecursively(){
  static DblLinkIterator<Term> printer(ThePoly);
  static int i = 0;
  if(i == 0){
    printer.start();
    while(printer.isLastNode() == false){
      printer++;
    }
    i++;
  }
  if(printer.isEmpty() == false){
    if(printer.isFirstNode() == true){
      cout << *printer;
      return;
    }
    cout << *printer << " + ";
    printer--;
  }
  else{
    cout << "Empty List" << endl;
    return;
  }
  printRecursively();
}

/*************************************************************************/
/* Function name: printIteratively                                       */
/* Description: prints the data stored in the doubly linked list using an*/
/*              iterator                                                 */
/* Parameters: none                                                      */
/* Return Value: none                                                    */
/*************************************************************************/
void TermDblLinkList::printIteratively(){
  DblLinkIterator<Term> printer(ThePoly);
  cout << " ---------------------------------" << endl;
  cout << "|Doubly Linked List  Iterative    |" << endl;
  cout << " ---------------------------------" << endl;
  if(printer.isEmpty() == false){
    printer.start();
    while(printer.isLastNode() == false){
      printer++;
    }
    while(printer.isFirstNode() == false){
      cout << *printer << " + ";
      printer--;
    }
    cout << *printer;
  }
  else{
    cout << "empty list" << endl;
  }
  //cout << endl;
  //  cout << endl;
}

/*************************************************************************/
/* Function name: operator ()                                            */
/* Description: solves a polynomial for a doubly linked list from a      */
/*              provided x value                                         */
/* Parameters:double x_value - the value for x to equal in the polynomial*/
/*            - import                                                   */
/* Return Value: result - the sum of the polynomial                      */
/*************************************************************************/
double TermDblLinkList::operator()(double x_value) const{
  double result = 0.0;
  DblLinkIterator<Term> solver(ThePoly);
  Term holder;
  solver.start();
  while(solver.isLastNode() == false){
    //result+=*solver(x);
    holder = *solver;
    solver++;
    result += holder(x_value);
  }
  //solver++;
  holder = *solver;
  result += holder(x_value);
  return(result);
}
