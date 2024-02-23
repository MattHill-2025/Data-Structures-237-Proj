/************************************************************/
/* Author: Matthew Hill                                     */
/* Major: Computer Science                                  */
/* Creation Date: October 14, 2022                          */
/* Due Date: October 25, 2022                               */
/* Course: CSC237                                           */
/* Professor Name: Dr. Spiegel                              */
/* Assignment: #2                                           */
/* Filename: DblLink.h                                      */
/* Purpose: This program is a template class for a doubly   */
/* linked list. There is also a template class for a pointer*/
/* to the doubly linked list. These store items of <eltType>*/
/* inside of a Node Class which are then created into a     */
/* doubly linekd list.                                      */
/*                                                          */
/* Contributer - Dr. Spiegel                                */
/* The Node class was provided by Dr. Spiegel from his      */
/* public diretory. Also within the creation of the doubly  */
/* linked list class as well as the DbLIterator class many  */
/* functiosn are based on Dr. Spiegel's singly linked list  */
/* class that is within his public directory. Within each   */
/* function documentation there will also be credit to      */
/* fucntions that he has created                            */
/************************************************************/


/** \file DblLink.h
 * \brief Function definitions and implementation of a doubly linked list
 */



// File: Node.h
// Doubly-linked list node definition/implementation
/*****************************************************/
/* This code is copied from Dr.Spiegel's public      */
/* directory. It is used to create a node class that */
/* then gets used to create a doubly linked List     */
/*****************************************************/
/**
 *\class Node
 *\brief Implementation and decleration of a doubly linked list Node.
 *
 */

#include "term.h"
#ifndef NODE_H
#define NODE_H

using namespace std;

// Need to prototype template classes if they are to be friends
template <class eltType> class DblLink;
template <class eltType> class DblLinkIterator;

template <class eltType> class Node
{       private:

    /**
   *\fn Node(eltType info , Node *pLink = 0, Node *rlink = 0)
   *Description: The constructor function for a doubly linked list node
   *\param eltType inf - the information that is stored in the node - import
   *            Node * - pointer to the pervious node(or NULL) - import
   *            Node * - pointer to the next node(or NULL) - import
   *\return none.
   */
                Node(eltType info, Node *pLink = 0, Node *rLink=0)
                                   : data(info), prev(pLink), next(rLink) {};
                eltType data;
                Node*   prev;
                Node*   next;
        friend class DblLink<eltType>;
        friend class DblLinkIterator<eltType>;
};

#endif


/*****************************************************/
/* Author: Matthew Hill                              */
/* Description: This is the decleration of the doubly*/
/* Linked List class.                                */
/*                                                   */
/* Contributer: Dr. Daniel Spiegel                   */
/* Many of the functions are based on Dr. Spiegel's  */
/* singly linked list and will give credit in their  */
/* function documentation                            */
/*****************************************************/

/**
 *\class DblLink
 *\brief Implementation and decleration of a doubly linked list (creation of the list without interaction).
 *
 */

template <class eltType> class DblLink{
    public:
          //contrust empty list
    /**
   *\fn DblLink
   *Description: The constructor for the DblLink<eltType> class, it sets head = NULL and creates and empty list.\n
   *\param "none" \n
   *\return Value: none. \n
   */
          DblLink();
  
          //destructor
    /**
   *\fn  ~DblLink
   *Description: The destructor for the DblLink<eltType> class, it calls the private destroy function which removes everything from the list\n
   *\param "none" \n
   *\return  none. \n
   */
          ~DblLink();

          //assignment operator for deep copy
    /**
   *operator=(const DblLink&)
   *\n
   *Description: Overloaded = operator to do a deep copy of a doubly linked list.\n
   *\param  const DblLink& - the item to be copied - import/export\n
   *\return *this \n
   */
          DblLink& operator=(const DblLink&);

          //check to see if head = NULL
      /**
   *\fn empty
   *Description: Checks if the doubly linked list is empty by checking if head == NULL.\n
   *\param "none" \n
   *\return  none \n
   */
          bool empty();
          //insert something into the list in order
      /**
   *\fn orderedInsert
   *Description: Inserts a new elements into the doubly linked list in ascending order.\n
   *\param eltType - item to be inserted - import \n
   *\return "none" \n
   */
          void orderedInsert(eltType);
          //remove something from the list
    /**
   *\fn remove
   *Description: Removes a specific item from the doubly linked list.\n
   *\param eltType - item to be removed - import \n
   *\return return -1 if item not found or return 0 if item is found.\n
   */
          int remove(eltType);

    private:
          Node<eltType>* head;
          //private function to destroy the list, used for the destructer
      /**
   *\fn destroy
   *Description: Delets every node in the list.\n
   *\param Node<eltType> * - a pointer to a node of eltype - import/export \n
   *\return none. \n
   */
          void destroy(Node<eltType>*);
  
  friend class DblLinkIterator<eltType>;

};

/*****************************************************/
/* Author: Matthew Hill                              */
/* Description: This is the decleration of the doubly*/
/* Linked List iterator class.                       */
/*                                                   */
/* Contributer: Dr. Daniel Spiegel                   */
/* Many of the functions are based on Dr. Spiegel's  */
/* singly linked list  iterator and will give credit */
/*  in their function documentation                  */
/*****************************************************/

/**
 *\class DblLinkIterator
 *\brief Implementation and decleration of a doubly linked list iterator class (Allows for access of the information stored in the doubly linked list).
 *
 */

template <typename eltType> class DblLinkIterator
{
	public:
		// Construc a List Iterator
  /**
     *\fn DblLinkIterator
   *Description: Constructor for a doubly linked list iterator object\n
   *\param const DblLink<eltType> &list - a doubly linked list that this object will reference - import/export\n
   *\return none \n
   */
		DblLinkIterator(const DblLink<eltType> &list);

		// Set current to point at the first node of ListRef
  /**
     *\fn start
   *Description: Sets the current pointer to the first item in the list.\n
   *\param "none" \n
   *\return  none \n
   */
		void start();
		// Get the value out of current's node
      /**
   *&operator*()
   *\n
   *Description: Gets the information in the current node.\n
   *\param "none" \n
   *\return current->data \n
   */
                eltType  &operator*();
                //is the list empty
  /**
     *\fn isEmpty
   *Description: Checks if the head of the list is NULL.\n
   *\param "none" \n
   *\return true or false\n
   */
                bool isEmpty();
                //is the current node the first node in the lsit
    /**
     *\fn isFirstNode
   *Description: Checks if the current node is the first node in the list.\n
   *\param "none" \n
   *\return  true or false\n
   */
                bool isFirstNode();
                //is the current node the last node in the list
    /**
     *\fn isLastNode
   *Description: Checks if the current node is the last node in the list.\n
   *\param "none" \n
   *\return true or false\n
   */
                bool isLastNode();
                //is current = NULL
    /**
     *\fn end
   *Description: Checks if current is at the end of the list which happens when current == NULL\n
   *\param "none" \n
   *\return true or false\n
   */
                bool end();
                //overloaded ++ operator. moves current to next node
      /**
   *operator++(int)
   *\n
   *Description: Setes the current pointer to the next item in the list.\n
   *\param int - needed for the overloaded operator to function properly\n
   *\return none.\n
   */
                void operator++(int);
                //overloaded -- operator. moves current to previous node
        /**
   *operator--(int)
   *\n
   *Description: Setes the current pointer to the previous item in the list.\n
   *\param int - needed for the overloaded operator to function properly\n
   *\return none.\n
   */
               void operator--(int);
	private:
		const DblLink<eltType> &ListRef;
		Node<eltType> *current;
};


/****************************************************************/
/* Here is where the function implementation starts             */
/****************************************************************/



/* ****************************************************************
   ****************  DblLink  Implementations *********************
   ****************************************************************/


/*************************************************************************/
/* Function name: DblLink                                                */
/* Description: The constructor for the DblLink<eltType> class, it sets  */
/*              head = NULL. Creates and empty list.                     */
/* Parameters: none                                                      */
/* Return Value: returns nothing, it is the constructor.                 */
/*                                                                       */
/*contributer: This code was taken from Dr.Spiegel's singly linked list  */
/*            class                                                      */
/*************************************************************************/
  template <typename eltType> DblLink<eltType>::DblLink() : head(NULL){}


/*************************************************************************/
/* Function name: ~DblLink                                               */
/* Description: The destructor for the DblLink<eltType> class, it calls  */
/*              the private destroy function which removes everything    */
/*              from the list.                                           */
/* Parameters: none                                                      */
/* Return Value: returns nothing, it is the destructor.                  */
/*                                                                       */
/*contributer: This code was taken from Dr.Spiegel's singly linked list  */
/*            class                                                      */
/*************************************************************************/
template <typename eltType> DblLink<eltType>::~DblLink()
{destroy(head);}


/*************************************************************************/
/* Function name: empty                                                  */
/* Description: Checks if the Dbl is empty by checcking if head == NULL. */
/* Parameters: none                                                      */
/* Return Value: returns True or False                                   */
/*                                                                       */
/*contributer: This code was taken from Dr.Spiegel's singly linked list  */
/*            class                                                      */
/*************************************************************************/
template <typename eltType> inline bool DblLink<eltType>::empty()
{return (head == NULL);}

/*************************************************************************/
/* Function name: =                                                      */
/* Description: Overloaded = operator to do a deep copy of a DBL.        */
/* Parameters: const DblLink<eltType> & - the item to be copied          */  
/*             import/export                                             */
/* Return Value: returns *this                                           */
/*                                                                       */
/*contributer: This code was taken from Dr.Spiegel's singly linked list  */
/*            class                                                      */
/*************************************************************************/
template <typename eltType> DblLink<eltType> &DblLink<eltType>::operator =(const DblLink<eltType>& del)
{	if (this != &del)
	{	destroy(head);
		head = copy(del.head);
	}
	return *this;
}



/*************************************************************************/
/* Function name: destroy                                                */
/* Description: Deltes evey item in the list.                            */
/* Parameters: Node<eltType> * - a pointer of type Node<eltType>         */
/*             import/export                                             */
/* Return Value: nothing - void                                          */
/*                                                                       */
/*contributer: This code was taken from Dr.Spiegel's singly linked list  */
/*            class                                                      */
/*************************************************************************/
template <class eltType> 
void DblLink<eltType>::destroy(Node<eltType> *listPtr)
{	while (listPtr != NULL)	
	{	Node<eltType> *doomed = listPtr;
		listPtr = listPtr->next;
		delete doomed;
	}
}


/*************************************************************************/
/* Function name: orderedInsert                                          */
/* Description: Inserts a new element into the DBL in ascending order    */
/* Parameters: eltType - item : the item to be inserted - import         */
/* Return Value: nothing - void                                          */
/*                                                                       */
/*contributer: This code was taken from Dr.Spiegel's singly linkedd list */
/*            class. Modifications were made to make this work for a     */
/*            doubly linked list class.                                  */
/*************************************************************************/
template <typename eltType> void DblLink<eltType>::orderedInsert(eltType item){
  if(empty() || item < head->data){
    Node<eltType>* current = head;//edit ->next
    Node<eltType>* last = NULL;//edit ->prev
    
    if(!empty()){
      current->prev = new Node<eltType>(item,last,current);
      current = current->prev;
      head = current;
    }
    else{
      head = new Node<eltType>(item, last, current);
      }
  }
  else{
    Node<eltType>* current = head->next;
    Node<eltType>* last = head;
    while( current != NULL && item > current->data){
      last = current;
      current = current->next;
    }
    last->next = new Node<eltType>(item, last, current);
    if(current != NULL){
      last = last->next;
      current->prev = last;
    }
  }
}


/*************************************************************************/
/* Function name: remove                                                 */
/* Description: Remove a specific item from the DBL if found if not it   */
/*              prints that the item was not found.                      */
/* Parameters: eltType item - item that is to be removed from the list   */
/*             - import                                                  */
/* Return Value: nothing - void                                          */
/*                                                                       */
/*contributer: This code was taken from Dr.Spiegel's singly linekd list  */
/*            class, but modifications were made to make this function   */
/*            work with a doubly linked list class.                      */
/*************************************************************************/
template <typename eltType> int DblLink<eltType>::remove(eltType item)
{	Node<eltType>*	ptr = head;
	Node<eltType>*	trailp = NULL;
	while ( ptr != NULL && ptr->data != item )
	{	trailp = ptr;
		ptr = ptr->next;
	}
	if(ptr == NULL){
	  cout << item << " not found" << endl;
	  return -1;
	}
	if (ptr == head && ptr->next != NULL){
		head = head->next;// x is first in the LinkedList
		head->prev = NULL;
		delete ptr;
	}
	
	else{
	  if(ptr == head && ptr->next == NULL){
	    trailp = head;
	    head = NULL;
	    delete trailp;
	  }
	  else{
	  Node<eltType>* doomed = ptr;
	  trailp->next = ptr->next;
	  ptr = ptr->next;
	  if( ptr != NULL){
	    ptr->prev = trailp;
	  }
	  delete doomed;
	  }
	}
	return 0;
}

/* ****************************************************************
   ************** List Iterator Implementations *******************
   ****************************************************************/

/*************************************************************************/
/* Function name: DblLinkIterator                                        */
/* Description: Constructor for a DBL iterator.                          */
/* Parameters: const DblLink<eltType> &list - a doubly linked list -     */
/*             import/export                                             */
/* Return Value: nothing                                                 */
/*                                                                       */
/*contributer: This code was taken from Dr.Spiegel's singly linekd list  */
/*            iterator class with modifications to fit a doubly linked   */
/*            list iterator.                                             */
/*************************************************************************/
template <typename eltType> DblLinkIterator<eltType>::DblLinkIterator(const DblLink<eltType> &list):
  ListRef(list),current(NULL){}


/*************************************************************************/
/* Function name: start                                                  */
/* Description: Sets the current pointer equal to the first item.        */
/* Parameters: none                                                      */
/* Return Value: nothing - void                                          */
/*                                                                       */
/*contributer: This code was taken from Dr.Spiegel's singly linekd list  */
/*            iterator class with modifications to fit a doubly linked   */
/*            list iterator.                                             */
/*************************************************************************/
template <typename eltType> void DblLinkIterator<eltType>::start(void){
  current = ListRef.head;
}


/*************************************************************************/
/* Function name: operator *                                             */
/* Description: gets the current pointers data                           */
/* Parameters: none                                                      */
/* Return Value: the data of the current pointer                         */
/*                                                                       */
/*contributer: This code was taken from Dr.Spiegel's singly linekd list  */
/*            iterator class with modifications to fit a doubly linked   */
/*            list iterator.                                             */
/*************************************************************************/
template <typename eltType> eltType &DblLinkIterator<eltType>::operator*(){
  return current->data;
}

/*************************************************************************/
/* Function name: isEmpty                                                */
/* Description: Checks if the head of the list is NULL                   */
/* Parameters: none                                                      */
/* Return Value: true or false - depending on list                       */
/*                                                                       */
/*contributer: This code was taken from Dr.Spiegel's singly linekd list  */
/*            iterator class with modifications to fit a doubly linked   */
/*            list iterator.                                             */
/*************************************************************************/
template <typename eltType> bool DblLinkIterator<eltType>::isEmpty(void){
  if(ListRef.head == NULL){
    return true;
  }
  else{
    return false;
  }
}

/*************************************************************************/
/* Function name: isLastNode                                             */
/* Description: returns true if current is the last node                 */
/* Parameters: none                                                      */
/* Return Value: True or false                                           */
/*                                                                       */
/*contributer: This code was taken from Dr.Spiegel's singly linekd list  */
/*            iterator class with modifications to fit a doubly linked   */
/*            list iterator.                                             */
/*************************************************************************/
template <typename eltType> bool DblLinkIterator<eltType>::isLastNode(void){
  Node<eltType> *last = current;
  if(last->next == NULL)
    return true;
  else
    return false;
}


/*************************************************************************/
/* Function name: isFirstNode                                            */
/* Description: returns true if current is the first node                */
/* Parameters: none                                                      */
/* Return Value: True or false                                           */
/*                                                                       */
/*contributer: This code was taken from Dr.Spiegel's singly linekd list  */
/*            iterator class with modifications to fit a doubly linked   */
/*            list iterator.                                             */
/*************************************************************************/
template <typename eltType> bool DblLinkIterator<eltType>::isFirstNode(void){
  Node<eltType> *first = current;
  if(first->prev == NULL)
    return true;
  else
    return false;
}


/*************************************************************************/
/* Function name: end                                                    */
/* Description: returns true if current = NULL which means either the    */
/*             list is empty or you reached the end of the list.         */
/* Parameters: none                                                      */
/* Return Value: True or false                                           */
/*                                                                       */
/*contributer: This code was taken from Dr.Spiegel's singly linekd list  */
/*            iterator class with modifications to fit a doubly linked   */
/*            list iterator.                                             */
/*************************************************************************/
template <typename eltType> bool DblLinkIterator<eltType>::end(void){
  Node<eltType> *last = current;
  if(last == NULL)
    return true;
  else
    return false;
 
}

/*************************************************************************/
/* Function name: operator ++                                            */
/* Description: sets current pointer to the next item in the list        */
/* Parameters: none                                                      */
/* Return Value:none - void                                              */
/*                                                                       */
/*contributer: This code was taken from Dr.Spiegel's singly linekd list  */
/*            iterator class with modifications to fit a doubly linked   */
/*            list iterator. Origionally it was a function, but for      */
/*            this project the ++ operator was instead overloaded.       */
/*************************************************************************/
template <typename eltType> void DblLinkIterator<eltType>::operator++(int){
  current = current->next;
}

/*************************************************************************/
/* Function name: operator --                                            */
/* Description: sets current pointer to the previous item in the list    */
/* Parameters: none                                                      */
/* Return Value:none - void                                              */
/*                                                                       */
/*contributer: This code was taken from Dr.Spiegel's singly linekd list  */
/*            iterator class with modifications to fit a doubly linked   */
/*            list iterator. Origionally it was a function, but for      */
/*            this project the -- operator was instead overloaded.       */
/*************************************************************************/
template <typename eltType> void DblLinkIterator<eltType>::operator--(int){
  current = current->prev;
}
