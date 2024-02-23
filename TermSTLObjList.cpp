/************************************************************/
/* Author: Matthew Hill                                     */
/* Major: Computer Science                                  */
/* Creation Date: October 20, 2022                          */
/* Due Date: October 25, 2022                               */
/* Course: CSC237 010                                       */
/* Professor Name: Dr. Spiegel                              */
/* Assignment: #2                                           */
/* Filename: TermSTLObjList.cpp                             */
/* Purpose: This is the class implimentation for a          */
/*          TermSTLObjList that stores polynomial data,     */
/*          prints the polynomial data, and solves the      */
/*          polynomial.                                     */
/************************************************************/

/** \file TermSTLObjList.cpp
 * \brief TermList subclass implementation definition: Implements the functions that were declared in TermSTLObjList.h
 */


#include"TermSTLObjList.h"
#include<iostream>
#include<fstream>
#include<iomanip>
#include<functional>
#include<algorithm>

using namespace std;

/*************************************************************************/
/* Function name: TermSTLObjList                                         */
/* Description: Constructer for a TermSTLObjList that creates a vector   */
/*             of type term.                                             */
/* Parameters: none                                                      */
/* Return Value: none                                                    */
/*************************************************************************/
TermSTLObjList::TermSTLObjList(){
  vector<Term> ThePoly;
}


/*************************************************************************/
/* Function name: readIntoList                                           */
/* Description: reads data from a test file into a vector of type term   */
/*              which is then sorted and like terms are combnined.       */
/*              this function is inherited from TermList.h               */
/* Parameters: string filename - The file to get the data out of         */
/*                                - import                               */
/* Return Value: none                                                    */
/*************************************************************************/
void TermSTLObjList::readIntoList(string filename){
  ifstream source(filename.c_str());
  double coeff;
  int expn;
  double sum = 0;
  //int STLlength = 0;

  while (source >> coeff >> expn){
    Term hold(coeff,expn);
    int check = 0;

    for(int i = 0; i < ThePoly.size(); i++){
      if(ThePoly[i].getExponent() == hold.getExponent()){
	sum = ThePoly[i].getCoefficient() + hold.getCoefficient();
	Term tholder(sum, hold.getExponent());
	//ThePoly.push_back(tholder);
	ThePoly[i] = tholder;
	check = 1;
      }
    }
    if(check != 1){
      ThePoly.push_back(hold);
    }
    //STLlength++;
  }
  source.close();
  source.clear();

  sort(ThePoly.begin(), ThePoly.end(), greater< Term>());
}


/*************************************************************************/
/* Function name: printIteratively                                       */
/* Description: prints the data stored in the vector of type term list   */
/*              using an iterator                                        */
/* Parameters: none                                                      */
/* Return Value: none                                                    */
/*************************************************************************/
void TermSTLObjList::printIteratively(){
  int plus_or_not = 0;
  cout << " ---------------------------------" << endl;
  cout << "|     STL  Iterative              |" << endl;
  cout << " ---------------------------------" << endl;
  vector<Term>::iterator pointer = ThePoly.begin();
  while(pointer != ThePoly.end()){
    cout << *pointer;
    pointer++;
    if(plus_or_not != ThePoly.size() - 1){
      cout << " + ";
    }
    plus_or_not++;
  }
  //cout << endl;
  //  cout << endl;
}


void TermSTLObjList::printRecursively(){
  static int i;
  static vector<Term>::iterator pointer = ThePoly.begin();
  if(i == ThePoly.size()){
    i = 0;
    return;
  }
  cout << *pointer;
  pointer++;
  if(i != ThePoly.size() - 1){
    cout << " + ";
  }
  i++;
  printRecursively();
}
// function is not implimented, but included due to inheritance
//void TermSTLObjList::printPtr(){
//}


/*************************************************************************/
/* Function name: operator ()                                            */
/* Description: solves a polynomial for a vector of type term list from a*/
/*              provided x value                                         */
/* Parameters:double x_value - the value for x to equal in the polynomial*/
/*            - import                                                   */
/* Return Value: result - the sum of the polynomial                      */
/*************************************************************************/
double TermSTLObjList::operator()(double x) const{
  { double result=0.0;
    for (int idx=0;idx < ThePoly.size(); idx++)
      result+=ThePoly[idx](x);
    return(result);
  }
}
