// File: Node.h
// Doubly-linked list node definition/implementation
/** \file Node.h
 * \brief Creates a node with a previous and next pointer which will be implemented in DblLink.h
 */


#ifndef NODE_H
#define NODE_H

//using namespace std;

// Need to prototype template classes if they are to be friends
template <class eltType> class DblLink;
template <class eltType> class DblLinkIterator;

template <class eltType> class Node
{	private:
		Node(eltType info, Node *pLink = 0, Node *rLink=0) 
				   : data(info), prev(pLink), next(rLink) {};
		eltType data;
		Node*	prev; 
		Node*	next;
	friend class DblLink<eltType>;
	friend class DblLinkItr<eltType>;
};

#endif

