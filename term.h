/***************************************************************
Author:         Dr. Spiegel 
Filename:       Term.h   
Purpose:        A Term holds one term of a polynomial. A term 
		can be created, evaluated, compared, and printed
***************************************************************/

/** \file term.h
 * \brief The creation of a Term object that holds a polynomial
 */

/**
 *\class Term
 *\brief Creation of a Term object that holds a single element in a polynomial
 *
 */

#ifndef TERM_H
#define TERM_H

#include <iostream>

using namespace std;

class Term
{
public:
	//Constructor
    /**
   *\fn Term
   *Description: The constructor for a Term object that stores an element of a polynomial\n
   *\param double - coefficient - import \n
   *          : int - expoenent - import \n
   *\return none. \n
   */
	Term(double=0, int=0); 	//default value of 0x^0

	//Gets (No sets in immutable object)
    /**
   *\fn getCoefficient
   *Description: get the double value that is the coefficient of the polynomial element.\n
   *\param "none" \n
   *\return double - the double value stored in a specific Term\n
   */
	double getCoefficient() const; 		//returns the coefficient
      /**
   *\fn getExponent
   *Description: get the int value that is the expoenent of the polynomial element.\n
   *\param "none" \n
   *\return int  - the integer value stored in a specific Term.\n
   */
	int getExponent() const; 		//returns the exponent

	//evaluate
    /**
   *operator()(double x) const
   *\n
   *Description: Evaluates the term by the input number \n
   *\param double x  - the number to evaluate to \n
   *\return the sum of the evaluated term \n
   */
	double operator()(double x) const; 	// evaluation of term
	
	//other
	// does exponent match the parameter? Note signature ==(Term&,int)
      /**
   *operator==(int value)
   *\n
   *Description: Compares an int against the exponent \n
   *\param int value - the number to compare the exponent by\n
   *\return true if match // false if doesnt match \n
   */
	bool operator==(int value); 
	// does exponent match that of the param?  Signature: ==(Term,Term)
        /**
   *operator==(const Term &right)
   *\n
   *Description: Compares an int against the exponent \n
   *\param const Term &- Term that is to be comared to\n
   *\return true if match // false if doesnt match \n
   */
	bool operator==(const Term &right); 
	// is this term's exponent less than right's? Signature <(Term&,Term&)
  /**
     *operator<(Term &right)
   *\n
   *Description: Compare two terms based on exponenet\n
   *\param Term & - the term on the right which will be comparing.\n
   *\return true if less than // false if greater than\n
   */
	bool operator<(Term &right);
	// is this term's exponent less than right? Signature: <(Term&,int)
  /**
   *operator<(int right)
   *\n
   *Description: Compare Term's exponenet to an int\n
   *\param int value - the calue to make the comparison\n
   *\return true if less than // false if greater than\n
   */
        bool operator<(int right);

      /**
     *operator>(Term &right) const
   *\n
   *Description: Compare two terms based on exponenet\n
   *\param Term & - the term on the right which will be comparing.\n
   *\return true if less than // false if greater than\n
   */
        bool operator>(Term &right);
  /**************************************************************************/
  /*both of these fucntions were added to the term class so the doubly      */
  /*linked list class would wokr properly.                                  */
  /**************************************************************************/
        // is this terms exponent greater than right? const implementation
    /**
     *operator>(const Term &right) const
   *\n
   *Description: Compare two terms based on exponenet\n
   *\param Term & - the term on the right which will be comparing.\n
   *\return true if less than // false if greater than\n
   */
        bool operator>(const Term &right) const;
        // is this terms exponenet not equal to the right's? signature: !=(const Term Term&)
    /**
     *operator!=(const Term &right)
   *\n
   *Description: Compare if two terms do not have equal exponents\n
   *\param const Term & - the term on the right which will be comparing.\n
   *\return true if not equal // false if equal \n
   */
        bool operator!=(const Term &right);
  
private:
	double coefficient; //holds the coefficient value
	int exponent; //holds the exponent value

};
	// Stream insert a term
  /**
   *ostream &operator<<(ostream &output, const Term &term)
   *\n
   *Description: for output\n
   *\param ofstream & output - \n
   * const Term &term - the term object to be outputted
   *\return output \n
   */

	ostream &operator<<(ostream &output,const Term &term); 
#endif
