/************************************************************/
/* Author: Matthew Hill                                     */
/* Major: Computer Science                                  */
/* Creation Date: October 20, 2022                          */
/* Due Date: October 25, 2022                               */
/* Course: CSC237 010                                       */
/* Professor Name: Dr. Spiegel                              */
/* Assignment: #2                                           */
/* Filename: app.cpp                                        */
/* Purpose: This program gets a users choice of how they    */
/*          want to print and solve a polynomial from three */
/*          options those being a doubly linked list, an    */
/*          array of objects or an STL and each of thoe     */
/*          methods can also solve the polynomial as well   */
/* - Batch mode is also included                            */
/************************************************************/

/**
 * \mainpage Project 3
 *
 * \brief This project prints a polynomial from a file using three different storage methods (STL, Object Array, and Doubly Linked List). These storage methods then each use polymorphism from the TermList class. \n
 * The TermList class can be implemented in three different ways \n
 *    - TermArrayList
 *    - TermSTLObjList
 *    - TermDblLinkList
 *Each of these containers have different implementations for the functions, but they all have similar outputs with the exception of the TermArrayList which includes a print pointer option. \n
 */

/** \file app.cpp
 * \brief This file gets a text file from the user and reads that data in that text file to create a polynomial from different object containers (Vector, Array, Doubly Linked List) and then has different print options that are implemented using a TermList object that points at its sub classes.
 */


#include<iostream>
#include<iomanip>
#include<fstream>
#include"TermList.h"
#include"term.h"
#include "TermDblLinkList.h"
#include"TermArrayList.h"
#include"TermSTLObjList.h"
#include <chrono>

using namespace std;

/*************************************************************************/
/* Function name: printEverything                                        */
/* Description: A function for batch mode which prints all of the        */
/*             possible choices the user could make.                     */
/* Parameters: const string &-  the file name for the data               */
/*             - import/export                                           */
/*           : TermList * - a pointer to a TermList that interacts with  */
/*             the sub classes of TermList. - import                     */
/*           : double - a value that is passed in to solve the polynomial*/
/*             for that given value - import                             */
/* Return Value: none                                                    */
/* - This code was taken from Dr.Spiegel. It was changed for the purposes*/
/* of this porject, but it was origionally written by Dr,Spiegel.        */
/*************************************************************************/
  /**
   *\fn printEverything(const string &, TermList *, double)
   *Description: A function which allows batch mode to work. This function prints all of the possible user choices.\n
   *\param const string & - The file name for the data - import/export \n
   *          TermList * - a pointer to a TermList object that can use the functions of TermList's sub classes. - import \n
   *          double - a value that is used to solve the polynomail for the doubles value. - import \n
   *\return none. \n
   */
void printEverything(const string &, TermList *, double);

/*************************************************************************/
/* Function name: main_menu_switch                                       */
/* Description: prints a menu for the user to then select if they want to*/
/*                     use a doubly linked list, an STL, or an array     */
/* Parameters: none                                                      */
/* Return Value: returns 0 if it broke out of the while loop.            */
/*               returns 1 if user enters the end of the switch case     */
/*************************************************************************/
  /**
   *\fn main_menu_switch()
   *Description: Prints the main menu for the user then to select which object container they wish to use\n
   *\param "none" \n
   *\return returns 0 if it broke out of the while loop or returns 1 and exited the switch case\n
   */
  int main_menu_switch();


/*************************************************************************/
/* Function name: sub_menu_switch_array                                  */
/* Description: prints a menu for the user to then select if they want to*/
/*              print iterativly or using a pointer or solve.            */
/*             (For an Object Array of type Term)                        */
/* Parameters: TermList * - pointer to a TermList that interacts with the*/
/*             subclasses of TermList - import                           */
/*           : string - the filename of the file that the user enters    */
/*             - import.                                                 */
/* Return Value: returns 0 if it broke out of the while loop.            */
/*               returns 1 if user enters the end of the switch case     */
/*************************************************************************/
  /**
   *\fn sub_menu_switch_array(TermList *, string)
   *Description: prints a menu for the user to then select which print method they would like to choose and then solve the polynomial as well. In this case the container will be an array of objects\n
   *\param TermList * - a pointer to a TermList that can use inherited functions from it's subclasses - import/export \n
   *          string - the name of the file that the data will be taken from - import \n
   *\return returns 0 if it broke out of the while loop or it returns 1 if the user exits the switch case \n
   */
int sub_menu_switch_array(TermList *, string);

/*************************************************************************/
/* Function name: sub_menu_switch_DBL                                    */
/* Description: prints a menu for the user to then select if they want to*/
/*              print iterativly or solve.                               */
/*              (For a Doubly Linked List)                               */
/* Parameters: TermList * - pointer to a TermList that interacts with the*/
/*             subclasses of TermList - import                           */
/*           : string - the filename of the file that the user enters    */
/*             - import.                                                 */
/* Return Value: returns 0 if it broke out of the while loop.            */
/*               returns 1 if user enters the end of the switch case     */
/*************************************************************************/
  /**
   *\fn sub_menu_switch_DBL(TermList *, string)
   *Description: prints a menu for the user to then select which print method they would like to choose and then solve the polynomial as well. In this case the container will be using a doubly linked list\n
   *\param TermList * - a pointer to a TermList that can use inherited functions from it's subclasses - import/export \n
   *          string - the name of the file that the data will be taken from - import \n
   *\return returns 0 if it broke out of the while loop or it returns 1 if the user exits the switch case \n
    */
int sub_menu_switch_DBL(TermList *, string);



/*************************************************************************/
/* Function name: sub_menu_switch_STL                                    */
/* Description: prints a menu for the user to then select if they want to*/
/*              print iterativly or solve.                               */
/*              (For a vector of type term)                              */
/* Parameters: TermList * - pointer to a TermList that interacts with the*/
/*             subclasses of TermList - import                           */
/*           : string - the filename of the file that the user enters    */
/*             - import.                                                 */
/* Return Value: returns 0 if it broke out of the while loop.            */
/*               returns 1 if user enters the end of the switch case     */
/*************************************************************************/
  /**
   *\fn sub_menu_switch_STL(TermList *, string)
   *Description: prints a menu for the user to then select which print method they would like to choose and then solve the polynomial as well. In this case the container will be using a vector.\n
   *\param TermList * - a pointer to a TermList that can use inherited functions from it's subclasses - import/export \n
   *          string - the name of the file that the data will be taken from - import \n
   *\return returns 0 if it broke out of the while loop or it returns 1 if the user exits the switch case \n
   */
int sub_menu_switch_STL(TermList *, string);

/*************************************************************************/
/* Function name: get_file                                               */
/* Description: gets a file from the user and checks if it opens properly*/
/* Parameters: none                                                      */
/* Return Value: returns the file name if it opens correctly             */
/*               returns "no" if the file did not open correctly         */
/*************************************************************************/
  /**
   *\fn get_file
   *Description: gets a file from the user and checks if it opens properly.\n
   *\param "none" \n
   *\return the file name if it opened correctly, if it did not it returns "no" \n
   */
string get_file();

/*************************************************************************/
/* Function name: selection                                              */
/* Description: gets the users choice for a switch case                  */
/* Parameters: char & - a character to store the users choice -          */
/*             import/export                                             */
/* Return Value: void                                                    */
/*************************************************************************/
  /**
   *\fn selection(char &)
   *Description: asks the user for which option they are selecting from the menu's\n
   *\param char & - a character to store the users choice - import/export \n
   *\return none.\n
   */
void selection(char &);

/*************************************************************************/
/* Function name: evaluate                                               */
/* Description: gets the users choice for the polynomial x value         */
/* Parameters: double & - a double to store the users choice for the x   */
/*             value - import/export                                     */
/* Return Value: void                                                    */
/*************************************************************************/
  /**
   *\fn evaluate(double &)
   *Description: gets the users choice for the polynomial x value \n
   *\param double & - a double that stores the users x value - import/export \n
   *\return  none.\n
   */
void evaluate(double &);

  /**
   *\fn print_recursively(TermList *)
   *Description: Calls the print recursively funtion in TermList, but depending on which container the TermList object is pointing at it will call that objects recursive print function. Then it uses chrono to print the time it took to print in microseconds.\n
   *\param TermList * - a pointer to a TermList object that calls subclass print functions. - import \n
   *\return none.\n
   */
void print_recursively(TermList *);

  /**
   *\fn print_iteratively(TermList *)
   *Description: Calls the print iteratively funtion in TermList, but depending on which container the TermList object is pointing at it will call that objects iterative print function. Then it uses chrono to print the time it took to print in microseconds. \n
   *\param TermList * - a pointer to a TermList object that calls subclass print functions. - import \n
   *\return  none.\n
      */
void print_iteratively(TermList *);
  /**
   *\fn print_ptr(TermList *)
   *Description: Calls the print pointer funtion in TermList. This is only used in the Array of Objects. Then it uses chrono to print the time that it took to print in microseconds. \n
   *\param TermList * - a pointer to a TermList object that calls subclass print functions. - import \n
   *\return none.\n
   */
void print_ptr(TermList *);


int main(int argc, char *argv[]){
  /**************************************/
  /* this code was taken from Dr.Spiegel*/
  fstream file;
  TermList *ThePoly;
  if(argc>1) //if there was an input on the command line
    { double evalX=atof(argv[2]);
      file.open(argv[1]); //try and open the file
      if (file.fail())       //if the file does not open, terminate
          {
            cout<<"Sorry, the file failed to open."<<endl;
            return 0;
          }
      file.close();
      string fName(argv[1]);
      printEverything(fName,ThePoly,evalX);
      return 0;
    }
  /**************************************/
  main_menu_switch();
  cout << endl;
  return 0;
}

// function for batchmode to work. prints all of the option choices
void printEverything(const string &filename, TermList *ThePoly, double evalX){
  ThePoly = new TermArrayList;
  ThePoly->readIntoList(filename);
  //ThePoly->printIteratively();
  print_iteratively(ThePoly);
  cout<<"---------------------------------"<<endl;
    cout<<"|Object  Array  Recursively      |"<<endl;
  cout<<"---------------------------------"<<endl;
  //ThePoly->printRecursively();
  print_recursively(ThePoly);
  print_ptr(ThePoly);
  cout << "Evaluated: P(" << evalX << ")=" << (*ThePoly)(evalX) << endl;
  //  cout << "Evaluated: P(" << evalX << ")=" << (*ThePoly)(evalX) << endl;
  ThePoly = new TermSTLObjList;
  ThePoly->readIntoList(filename);
  //ThePoly->printIteratively();
  print_iteratively(ThePoly);
  cout<<"---------------------------------"<<endl;
  cout<<"|STL Object Recursively          |"<<endl;
  cout<<"---------------------------------"<<endl;
  //ThePoly->printRecursively();
  print_recursively(ThePoly);
  cout << "Evaluated: P(" << evalX << ")=" << (*ThePoly)(evalX) << endl;
  ThePoly = new TermDblLinkList;
  ThePoly->readIntoList(filename);
  //ThePoly->printIteratively();
  print_iteratively(ThePoly);
  cout<<"---------------------------------"<<endl;
  cout<<"|Doubly linked list Recursively  |"<<endl;
  cout<<"---------------------------------"<<endl;
  //ThePoly->printRecursively();
  print_recursively(ThePoly);
  cout << "Evaluated: P(" << evalX << ")=" << (*ThePoly)(evalX) << endl;
}


// provies the main menu where the uesr then selects which method to print
// and solve the polynomial
int main_menu_switch(){
  char sel;
  string filename = get_file();
  TermList *multi_output;
  if(filename == "no"){
    return 0;}

  while(true){
    cout << endl;
    cout << "1: Object Array" << endl;
    cout << "2: STL Object" << endl;
    cout << "3: Doubly Linked List" << endl;
    cout << "4: Exit" << endl;
    cout << endl;

    selection(sel);
    switch(sel){

    case'1':
      sub_menu_switch_array(multi_output, filename);
      continue;

    case'2':
      sub_menu_switch_STL(multi_output, filename);
      continue;

    case'3':
      sub_menu_switch_DBL(multi_output, filename);
      continue;

    case'4':
      return 1;
  }
  }
  return 0;
}

//menu for the array options for printing and solve
int sub_menu_switch_array(TermList *multi_output, string filename){
  char arrysel;
  TermArrayList ArrList;
  double x_value = 0;

  multi_output = &ArrList;
  multi_output->readIntoList(filename);

  while(true){
    cout << "------------------------------------------------" << endl;
    cout << "Object C++ Array" << endl;
    cout << "------------------------------------------------" << endl;
    cout << "1. Object Array Iterative Print" << endl;
    cout << "2. Object Array Recursively Print" << endl;
    cout << "3. Object Array Pointer Print" << endl;
    cout << "4. Evaluate the Polynomial" << endl;
    cout << "5. Exit Object Array" << endl;

    selection(arrysel);
    switch(arrysel){

    case'1':
      print_iteratively(multi_output);
      //cout << endl;
      continue;

    case'2':
        cout<<"---------------------------------"<<endl;
        cout<<"|Object  Array  Recursively      |"<<endl;
        cout<<"---------------------------------"<<endl;
      print_recursively(multi_output);
      cout << endl;
      continue;

    case'3':
      print_ptr(multi_output);
      cout << endl;
      continue;

    case'4':
      evaluate(x_value);
      cout << "Evaluated: P(" << x_value << ")=" << (*multi_output)(x_value) << endl;
      cout << endl;
      continue;

    case'5':
      return 1;
    }
  }
  return 0;
}

//menu options for the doubly linked list for printing and solve
int sub_menu_switch_DBL(TermList *multi_output, string filename){
  char DBLsel;
  TermDblLinkList DblList;
  double x_value = 0;
  double sum = 0;
  multi_output = &DblList;
  multi_output->readIntoList(filename);

  while(true){
    cout << "------------------------------------------------" << endl;
    cout << "Doubly Linked List" << endl;
    cout << "------------------------------------------------" << endl;
    cout << "1. Object Array Iterative Print" << endl;
    cout << "2. Recursive Array print" << endl;
    cout << "3. Evaluate the Polynomial" << endl;
    cout << "4. Exit Object Array" << endl;

    selection(DBLsel);
    switch(DBLsel){

    case'1':
      //multi_output->printIteratively();
      print_iteratively(multi_output);
      cout << endl;
      continue;

    case'2':
      cout<<"---------------------------------"<<endl;
      cout<<"|Object  Array  Recursively      |"<<endl;
      cout<<"---------------------------------"<<endl;
      print_recursively(multi_output);
      cout << endl;
      continue;

    case'3':
      evaluate(x_value);
      cout << "Evaluated: P(" << x_value << ")=";
      sum = (*multi_output)(x_value);
      cout << sum << endl;
      cout << endl;
      continue;

    case'4':
      return 1;
    }
  }
  return 0;
}


// menu options for the STL list for printing and solve
int sub_menu_switch_STL(TermList *multi_output, string filename){
  char STLsel;
  TermSTLObjList STLList;
  double x_value = 0;

  multi_output = &STLList;
  multi_output->readIntoList(filename);

  while(true){
    cout << "------------------------------------------------" << endl;
    cout << "STL Object" << endl;
    cout << "------------------------------------------------" << endl;
    cout << "1. Object Array Iterative Print" << endl;
    cout << "2. Object Array Recursive Print" << endl;
    cout << "3. Evaluate the Polynomial" << endl;
    cout << "4. Exit Object Array" << endl;

    selection(STLsel);
    switch(STLsel){

    case'1':
      print_iteratively(multi_output);
      cout << endl;
      continue;

    case'2':
        cout<<"---------------------------------"<<endl;
        cout<<"|Object  Array  Recursively      |"<<endl;
        cout<<"---------------------------------"<<endl;
        print_recursively(multi_output);
        cout << endl;
        continue;

    case'3':
      evaluate(x_value);
      cout << "Evaluated: P(" << x_value << ")=" << (*multi_output)(x_value) << endl;
      cout << endl;
      continue;

    case'4':
      return 1;
    }
  }
  return 0;
}

// gets the file from the user and checks if it opens
string get_file(){
  string file_to_open;
  fstream file;
  string check = "no";
  cout << "Enter File Name" << endl;
  getline(cin,file_to_open);
  file.open(file_to_open.c_str());
  if(file.fail()){
    cout << "Sorry, file failed to open..." << endl;
    return check;
  }
  file.close();
  return file_to_open;
}

// gets the users selection for all of the switch cases
void selection(char &sel){
  cout << ">";
  cin >> sel;
}

// gets the users selection for the x value of the polynomial
void evaluate(double &evalx){
  cout <<"x = ";
  cin >> evalx;
}


void print_recursively(TermList *multi_output){
  using namespace std::chrono ;
  auto begin = high_resolution_clock::now();
  multi_output->printRecursively();
  auto end = high_resolution_clock::now();
  auto ticks = duration_cast<microseconds>(end-begin) ;
  cout << endl;
  cout << "It took " << ticks.count() << " microseconds" << endl;
  cout << endl;
}

void print_iteratively(TermList *multi_output){
  using namespace std::chrono ;

  auto begin = high_resolution_clock::now();
  multi_output->printIteratively();
  auto end = high_resolution_clock::now();
  auto ticks = duration_cast<microseconds>(end-begin) ;
  cout << endl;
  cout << "It took " << ticks.count() << " microseconds" << endl;
  cout << endl;
}

void print_ptr(TermList *multi_output){
  using namespace std::chrono ;

  auto begin = high_resolution_clock::now();
  multi_output->printPtr();
  auto end = high_resolution_clock::now();
  auto ticks = duration_cast<microseconds>(end-begin) ;
  cout << "It took " << ticks.count() << " microseconds" << endl;
  cout << endl;
}