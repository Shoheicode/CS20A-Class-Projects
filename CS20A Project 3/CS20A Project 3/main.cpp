
// Choose which run to compile
#define RUN0 //RUN1 RUN2 RUN3




#ifdef RUN0 

#include"dllist.h"
#include"studentinfo.h"
#include<iostream>

int main() {
	std::cout << StudentInfo::Name() << std::endl;
	std::cout << StudentInfo::ID() << std::endl;
	std::cout << "HIHIHI" << std::endl;

	DLList<int> * l = new DLList<int>; //DLList of integers

	l->add_rear(1);
	std::cout<< l->front()<<std::endl;
	l->add_front(5);
	std::cout << l->front() << std::endl;
	l->add_front(7);
	std::cout << l->front() << std::endl;
	l->add_front(42);
	l->add(6, 2);
	//std::cout << l->peek(3) << std::endl;
	l->print();
	/*l->remove_rear();
	std::cout << l->rear() << std::endl;*/

	delete l;

	return 0;

}

#elif defined RUN1

#include"dllist.h"
#include"studentinfo.h"
#include<iostream>
#include<string>

int main() {

	std::cout << StudentInfo::Name() << std::endl;
	std::cout << StudentInfo::ID() << std::endl;

	DLList<std::string> * l = new DLList<std::string>; //DLList of integers

	l->add_rear("Hello");
	l->add_front("World");
	l->add_front("Bob");
	l->add_front("2");

	l->print(); // 2 Bob World Hello

	l->remove_rear();  // Will trip assert if empty
	l->print(); // 2 Bob World 

	std::cout << l->front() << std::endl; // 2

	return 0;

}

#elif defined RUN2

#define MAKE_MEMBERS_PUBLIC
#include"dllist.h"
#include<assert.h>

//Unit test example for push_font on initially empty list

int main() {

	// Step 1: Initial state
	// Assume that constructor implemented properly
	// If you're not sure if the constructor is 
	// implemented properly, STOP, go back and make
	// sure. Luckily the default constructor is 
	// done for you.  But the point remains, never,
	// ever, use a function in a test that isn't itself
	// verified to function according to spec.
	DLList<int> * l = new DLList<int>;


	// Step 2: Execute the function to test
	l->add_front(99);

	// Step 3: Verify what you expect to observe.
	// You must know what is supposed to happen in
	// order to analyze for correctness. Generally, 
	// you must permute all possible combinations
	// of all member variables.
	assert(l->head != nullptr);
	assert(l->tail != nullptr);
	assert(l->count == 1);
	assert(l->head->prv() == nullptr);
	assert(l->head->nxt() == nullptr);
	assert(l->head->itm() == 99);

	return 0;
}

#elif defined RUN3 

#define MAKE_MEMBERS_PUBLIC
#include"dllist.h"
#include<assert.h>
#include<string>

//Unit test example for push_font on initially non empty list

int main() {

	// Step 1: Initial state
	// Same as above, except we must head populate the list
	// However, since we are testing add_front, we cannot
	// use it to generate the initial state of our list
	// to test.  So we have to manually set the initial state
	// in this case we are creating a list with three nodes.
	DLList<std::string>::Node* head = new DLList<std::string>::Node;
	DLList<std::string>::Node* second = new DLList<std::string>::Node;
	DLList<std::string>::Node* third = new DLList<std::string>::Node;

	// We have to manually linked everything together:
	head->itm("first");
	head->prv(nullptr);
	head->nxt(second);

	second->itm("second");
	second->prv(head);
	second->nxt(third);

	third->itm("third");
	third->prv(second);
	third->nxt(nullptr);

	// Now we create  DLList object and inject the initial control state:
	DLList<std::string> * l = new DLList<std::string>;
	l->head = head;
	l->tail = third;
	l->count = 3;

	// Step 2: Now with the list given a complete and correct starting state
	// We can test various member functions for correctness.
	// For example we can use this as one test for add_front;
	l->add_front("Zero");

	// Step 3: Verify:  Technically, we should examine all 
	// member variables, and all nodes' value, nxt, prv pointers
	// to ensure that the add_front didn't mangle any of the
	// internal nodes.  But, this is mostly just to illustrate
	// how you might develop your own tests.  
	assert(l->count == 4);
	assert(l->head->prv() == nullptr);
	assert(l->head == head->prv());
	assert(l->head->nxt() == head);
	assert(l->head->itm() == "Zero");
	assert(l->tail == third);

	return 0;
}
#else
//Run unit tests
#include"listtests.h"

int main() {

	test_add(0);
	//...

	return 0;
}

#endif