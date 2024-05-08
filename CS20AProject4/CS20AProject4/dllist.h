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

	Node* a = other.head;
	Node* temp = nullptr;
	Node* tempPrev = nullptr;

	while (a != nullptr) {
		if (head == nullptr) {
			head = DEBUG_NEW Node();
			head->itm(a->itm());
			head->nxt(temp);
			tempPrev = head;
		}
		else {
			std::cout << "STUCK HERE" << std::endl;
			temp = DEBUG_NEW Node(a->itm(), tempPrev, nullptr);
			tempPrev->nxt(temp);

			if (a->nxt() == nullptr) {
				std::cout << "HIHIHI" << std::endl;
				tail = temp;
				std::cout << tail->itm() << std::endl;
				break;
			}

			tempPrev = temp;
			temp = temp->nxt();
		}
		a = a->nxt();
	}
	std::cout << "HIHIHI" << std::endl;

}
/* Overloaded assignment operator
*/
template<typename Item>
DLList<Item>& DLList<Item>::operator=(const DLList<Item>& other) {

	if (this != &other) {
		//delete the lists
		Node* tempNode = head;

		while (tempNode != nullptr) {
			Node* bye = tempNode;
			tempNode = tempNode->nxt();
			delete bye;
		}

		count = other.count;

		Node* a = other.head;
		Node* temp = nullptr;
		Node* tempPrev = nullptr;

		while (a != nullptr) {
			if (head == nullptr) {
				head = DEBUG_NEW Node();
				head->itm(a->itm());
				head->nxt(temp);
				tempPrev = head;
			}
			else {
				std::cout << "STUCK HERE" << std::endl;
				temp = DEBUG_NEW Node(a->itm(), tempPrev, nullptr);
				tempPrev->nxt(temp);

				if (a->nxt() == nullptr) {
					std::cout << "HIHIHI" << std::endl;
					tail = temp;
					std::cout << tail->itm() << std::endl;
					break;
				}

				tempPrev = temp;
				temp = temp->nxt();
			}
			a = a->nxt();
		}
		
		
	}

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
		if (head == printNode) {
			std::cout << printNode->itm();
		}
		else {
			std::cout << " " << printNode->itm();
		}
		printNode = printNode->nxt();
	}

}

/* DLList empty
*/
template<typename Item>
bool DLList<Item>::empty() const {

	/*   TODO   */
	if(count > 0){
		return false;
	}
	return true;
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
	if (head == nullptr) {
		head = new Node(itm, nullptr, nullptr);
		tail = head;
		count++;
		return;
	}

	if (idx <= 0) {
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
		Node* newNode = DEBUG_NEW Node(itm, temp->prv(), temp);

		temp->prv()->nxt(newNode);
		temp->prv(newNode);
		count++;
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
		Item retval{};
		return retval;
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
		Item retval{};
		return retval;
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
	//std::cout << "RUNNING PEEK" << std::endl;
	/*   TODO   */
	int i = 0;
	Node* temp = head;
	while (i != idx) {
		temp = temp->nxt();
		i++;
		if (temp == nullptr) {
			Item a = {};
			return a;
		}
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
	while (temp != nullptr) {
		if (temp->itm() == itm) {
			countItems++;
		}
		temp = temp->nxt();
	}
	return countItems;

}
/* DLList search
*/
template<typename Item>
int DLList<Item>::search(const Item &itm) const {

	Node* temp = head;
	int index = 0;
	while (temp != nullptr) {

		if (temp->itm() == itm) {
			return index;
		}

		index++;
		
		temp = temp->nxt();
	}
	return -42;

}

/* DLList remove_front
*/
template<typename Item>
bool DLList<Item>::remove_front() {

	/*   TODO   */
	if (head == nullptr) {
		return false;
	}
	else {
		if (head->nxt() == nullptr) {
			delete head;
			count--;
			head = nullptr;
			tail = nullptr;
			return true;
		}
		Node* temp = head;
		head = head->nxt();
		head->prv(nullptr);

		delete temp;
		count--;
	}
	
	return true;
}
/* DLList remove_rear
*/
template<typename Item>
bool DLList<Item>::remove_rear() {

	if (tail == nullptr) {
		return false;
	}
	else {
		if (tail->prv() == nullptr) {
			delete tail;
			count--;
			head = nullptr;
			tail = nullptr;
			return true;
		}
		Node* temp = tail;
		tail = tail->prv();
		tail->nxt(nullptr);

		delete temp;
		count--;
	}

	return true;
}

/* DLList remove_index
*/
template<typename Item>
bool DLList<Item>::remove_index(int idx) {

	if (idx > count || idx < 0) {
		return false;
	}

	if (head->nxt() == nullptr && head->prv() == nullptr && count == 1) {
		delete head;
		count--;
		head = nullptr;
		tail = nullptr;
		return true;
	}

	int i = 0;
	Node* temp = head;
	while (i != idx) {
		temp = temp->nxt();
		i++;
	}
	if (i == 0) {
		remove_front();
		return true;
	}
	if (i == count - 1) {
		remove_rear();
		return true;
	}

	//makes the next and previous nodes connect
	temp->prv()->nxt(temp->nxt());
	temp->nxt()->prv(temp->prv());
	delete temp;
	count--;

	return true;

}

/* DLList remove_item
*/
template<typename Item>
int DLList<Item>::remove_item(const Item &itm) {

	std::cout << "REMOVING items\n";
	Node* temp = head;
	int index = 0;
	while (temp != nullptr) {

		if (temp->itm() == itm) {
			if (temp == head) {
				remove_front();
				std::cout << "REMOVING FROM FRONT\n";
				return 0;
			}
			if (temp == tail) {
				remove_rear();
				return index;
			}
			std::cout << "HIHIHI" << std::endl;
			temp->prv()->nxt(temp->nxt());
			temp->nxt()->prv(temp->prv());
			delete temp;
			count--;
			return index;
		}

		index++;
		
		temp = temp->nxt();
	}
	std::cout << "END OF REMOVE" << std::endl;

	return -42;

}

/* DLList sub_list
*/
template<typename Item>
bool DLList<Item>::sub_list(const DLList<Item>& sub) {

	if (sub.count == 0) {
		return true;
	}

	int number = 0;
	/*Node* temp1 = head;
	Node* subTemp = sub.head;*/
	int index = 0;
	for (int i = 0; i < count; i++) {
		std::cout << i << std::endl;
		if (peek(i) == sub.peek(index)) {
			index++;
			number++;
			if (number == sub.count) {
				return true;
			}
		}
		else {
			number = 0;
			index = 0;
			if (peek(i) == sub.peek(index)) {
				index++;
				number++;
				if (number == sub.count) {
					return true;
				}
			}
		}
	}

	return false;

}

#endif



























































































// _X_XMMXXI