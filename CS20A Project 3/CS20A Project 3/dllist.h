#ifndef FA23_CS20A_LlST_H
#define FA23_CS20A_LlST_H

#include<iostream>
#include<assert.h>
#include "debugmem.h"
#include "debugmem.h"
// Linked DLList object that maintains both head and tail pointers
// and the count of the list.  Note that you have to keep the head,
// tail and count consistent with the intended state of the DLList 
// otherwise very bad things happen. 
template<typename Item>
class DLList {
public:

	DLList();

	DLList(const DLList<Item>& other);

	DLList<Item>& operator=(const DLList<Item>& other);

	~DLList();

	void	print() const;
	bool	empty() const;

	void	add_front(const Item &itm);
	void	add_rear(const Item &itm);
	void	add(int idx, const Item &itm);

	// Note that the user must head ensure the list is not empty
	// prior to calling these functions. 
	Item	front() const;
	Item	rear() const;
	Item	peek(int idx) const;

	int		size() const;
	int		items(const Item &itm) const;

	int		search(const Item &itm) const;

	bool	remove_front();
	bool	remove_rear();
	bool	remove_index(int idx);
	int		remove_item(const Item &itm);


	bool	sub_list(const DLList<Item>& sub);

#ifndef MAKE_MEMBERS_PUBLIC
private:
#endif
	// Forward declare the nodes for our DLList.
	// Will be implemented along with list
	// member functions
	class Node;

	// We'll have both head and tail points for 
	// Fast insertion/deletion from both ends.
	Node*	head;
	Node*	tail;

	// Keep track of number of nodes in the list
	int		count;
};


/* DLList Implementation
//
//  Since DLList is a template class (which is not an actual
//  class yet, not until we actually instantiate the list)
//  we need to keep the implementation together with
//  the definition.  There are ways to simulate having
//  separate "implementation/definition" with templates,
//  but they aren't necessary and can be confusing.
*/

/* Node definition
//		Already implemented, nothing to do here but to use it.
*/
template<typename Item>
class DLList<Item>::Node {
public:
	Node() :next(nullptr), prev(nullptr) {}
	Node(Item i, Node* p, Node* n) : item(i), next(n), prev(p) {}

	Node * nxt() const { return next; }
	void nxt(Node *n) { next = n; }

	Node * prv() const { return prev; }
	void prv(Node *p) { prev = p; }

	Item itm() const { return item; }
	void itm(const Item &i) { item = i; }

private:
	Item  item;
	Node * next;
	Node * prev;
};



/* DLList default constructor
//		Already implemented, nothing to do.
*/
template<typename Item>
DLList<Item>::DLList() :head(nullptr), tail(nullptr), count(0) {
	std::cout << "CONSTRUCTOR RUNNING" << std::endl;
}


/* Copy constructor
*/
template<typename Item>
DLList<Item>::DLList(const DLList<Item>& other) {

	/*   TODO   */
	count = other.count;

	Node a = other.head;
	Node temp = nullptr;
	Node tempPrev;

	while (a != nullptr) {
		if (head == nullptr) {
			head = new Node();
			head->itm = a->itm;
			head->next = temp;
			tempPrev = head;
		}
		else {
			temp = new Node();
			temp->itm = a->itm;

			temp->next = nullptr;
			temp->prev = tempPrev;
			tempPrev = a;
			temp = temp->next;
		}
		a = a->next;
	}


}
/* Overloaded assignment operator
*/
template<typename Item>
DLList<Item>& DLList<Item>::operator=(const DLList<Item>& other) {

	/*   TODO   */
	return *this;
}


/* DLList destructor
*/
template<typename Item>
DLList<Item>::~DLList() {

	/*   TODO   */
	Node* tempNode = head;

	while (tempNode != nullptr) {
		Node* bye = tempNode;
		tempNode = tempNode->nxt();
		delete bye;
	}
	GETMEMORYREPORT();
}

/* DLList print
*/

template<typename Item>
void DLList<Item>::print() const {

	/*   TODO   */
	Node* printNode = head;

	while (printNode != nullptr) {
		std::cout << printNode->itm() << " ";
		printNode = printNode->nxt();
	}

}

/* DLList empty
*/
template<typename Item>
bool DLList<Item>::empty() const {

	/*   TODO   */
	if(count > 0){
		return true;
	}
	return false;
}


/* DLList add_front
*/
template<typename Item>
void DLList<Item>::add_front(const Item &itm) {

	/*   TODO   */
	if (head == nullptr) {
		head = DEBUG_NEW Node();
		head->itm(itm);
		tail = head;
		count++;
	}
	else {
		Node* temp = DEBUG_NEW Node();
		Node* copy = head;
		temp->itm(itm);

		temp->nxt(copy);
		copy->prv(temp);

		head = temp;
		count++;
	}

	GETMEMORYREPORT();
}

/* DLList add_rear
*/
template<typename Item>
void DLList<Item>::add_rear(const Item &itm) {

	/*   TODO   */
	if (tail == nullptr) {
		tail = DEBUG_NEW Node();
		head = tail;
		tail->itm(itm);
		count++;
	}
	else {
		Node* temp = DEBUG_NEW Node();
		Node* copy = tail;
		temp->itm(itm);

		temp->prv(copy);
		copy->nxt(temp);

		tail = temp;
		count++;
	}

}

/* DLList add
*/
template<typename Item>
void DLList<Item>::add(int idx, const Item &itm) {

	/*   TODO   */
	if (idx < 0) {
		add_front(itm);
	}
	else if (idx > count) {
		add_rear(itm);
	}
	else {
		int i = 0;
		Node* temp = head;
		while (i != idx) {
			temp = temp->nxt();
			i++;
		}
		Node* newNode = new Node(itm, temp->prv(), temp);

		temp->prv()->nxt(newNode);
		temp->prv(newNode);
	}

}

/*  DLList front
*/
template<typename Item>
Item DLList<Item>::front() const {
	// Force check that the head is pointing to a Node
	// Typical solution for deployement code is to throw
	// exceptions, but since we haven't covered that yet
	// we'll make due with assert, which is used for testing
	//assert(head != nullptr);
	if (head != nullptr) {
		return head->itm();
	}
	else {
		return 1;
	}

	/*   TODO   */
	Item retval{};
	return retval;
}

/* DLList rear
*/
template<typename Item>
Item DLList<Item>::rear() const {

	// Force check that the tail is pointing to a Node
	// Typical solution for deployement code is to throw
	// exceptions, since we haven't covered that yet
	// we'll make due with assert, which is used for testing
	//assert(tail != nullptr);

	if (tail != nullptr) {
		return tail->itm();
	}
	else {
		return 1;
	}

	/*   TODO   */
	Item retval{};
	return retval;

}

/* DLList peek
*/
template<typename Item>
Item DLList<Item>::peek(int idx) const {

	// Force index to be correct before getting the Item
	// Typical solution for deployement code is to throw
	// exceptions, since we haven't covered that yet
	// we'll make due with assert, which is used for testing
	//assert(idx >= 0 && idx < count);

	/*   TODO   */
	int i = 0;
	Node* temp = head;
	while (i != idx) {
		temp = temp->nxt();
		i++;
	}

	return temp->itm();
}

/* DLList size
*/
template<typename Item>
int DLList<Item>::size() const {

	/*   TODO   */
	return count;
}
template<typename Item>
int DLList<Item>::items(const Item &itm) const {

	/*   TODO   */
	int countItems = 0;
	Node* temp = head;
	while (temp != nullptr;) {
		temp = temp->nxt();
		i++;
	}
	Node* newNode = new Node(itm, temp->prv(), temp);

	temp->prv()->nxt(newNode);
	temp->prv(newNode);
	return retval;

}
/* DLList search
*/
template<typename Item>
int DLList<Item>::search(const Item &itm) const {

	/*   TODO   */
	int retval = 8675309;
	return retval;
}

/* DLList remove_front
*/
template<typename Item>
bool DLList<Item>::remove_front() {

	/*   TODO   */
	bool retval = false;
	return retval;
}
/* DLList remove_rear
*/
template<typename Item>
bool DLList<Item>::remove_rear() {

	/*   TODO   */
	bool retval = false;
	return retval;
}

/* DLList remove_index
*/
template<typename Item>
bool DLList<Item>::remove_index(int idx) {

	/*   TODO   */

	bool retval = false;
	return retval;

}

/* DLList remove_item
*/
template<typename Item>
int DLList<Item>::remove_item(const Item &itm) {

	/*   TODO   */
	int retval = 9000;
	return retval;

}

/* DLList sub_list
*/
template<typename Item>
bool DLList<Item>::sub_list(const DLList<Item>& sub) {
	
	/*   TODO   */
	bool retval = true;
	return retval;
}

#endif



























































































// _X_XMMXXI