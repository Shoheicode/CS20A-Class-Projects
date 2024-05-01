#ifndef PROJECT3_DLLTEST_H
#define PROJECT3_DLLTEST_H

#define MAKE_MEMBERS_PUBLIC


int test_empty(int testNum); 		//0-1
int test_add_front(int testNum);	//0-1
int test_add_rear(int testNum);		//0-1
int test_add(int testNum);			//0-6
int test_search(int testNum);		//0-4
int test_front(int testNum);		//0-1
int test_rear(int testNum);			//0-1
int test_peek(int testNum);			//0-1
int test_remove_front(int testNum); //0-2
int test_remove_rear(int testNum);	//0-2
int test_remove_index(int testNum); //0-7
int test_remove_item(int testNum);	//0-5
int test_print(int testNum);		//0-1
int test_size(int testNum);			//0-1
int test_items(int testNum);		//0-5
int test_copyCtor(int testNum);		//0-2
int test_assgnOper(int testNum);	//0-2
int test_mem_destructor(int testNum);//0
int test_mem_assgnOper(int testNum);//0-1
int test_sub_list(int testNum);		//0-12


#include<iostream>
#include <fstream>
#include <sstream> 
#include<string>
#include<iterator>
#include<vector>
#include<exception>
#include<functional>

#ifdef _MSC_VER // Visual Studio
#define __func__ __FUNCTION__
#endif

#include"debugmem.h"

// Blank out macros if debugmem.h is not included
#ifndef DEBUG_NEW
#define DEBUG_NEW new 
#endif
#ifndef RESET()
#define RESET()
#endif
#ifndef GETMEMORYREPORT()
#define GETMEMORYREPORT()
#endif
#ifndef SIZE()
#define SIZE() 0
#endif

#include"dllist.h"

#include<assert.h>

int runTest(std::function<int(int)> test, int testNum) {
	int retval = 0;
	try {
		retval = test(testNum);
	}
	catch (const std::runtime_error& re) {
		std::cerr << "Runtime error: " << re.what() << std::endl;
		retval = 1;
	}
	catch (const std::exception& ex) {
		std::cerr << "Error occurred: " << ex.what() << std::endl;
		retval = 1;
	}
	catch (...) {
		std::cerr << "Unknown failure occurred. Possible memory corruption" << std::endl;
		retval = 1;;
	}
	return retval;
}


//Test empty
int test_empty(int testNum) {
	std::cout <<__func__ <<testNum << std::endl;
	std::string name = std::string(__func__);
	switch (testNum) {
	case 0: {
		
		DLList<int> * l = new DLList<int>;

		assert(l->empty() == true);

		break;
	}
	case 1: {
		
		//Make some control nodes
		DLList<std::string>::Node* head = new DLList<std::string>::Node;
		DLList<std::string>::Node* second = new DLList<std::string>::Node;
		DLList<std::string>::Node* third = new DLList<std::string>::Node;

		//Link together to make a valid linked list 
		head->itm("first");
		head->prv(nullptr);
		head->nxt(second);

		second->itm("second");
		second->prv(head);
		second->nxt(third);

		third->itm("third");
		third->prv(second);
		third->nxt(nullptr);

		//Assume Constructor Correctly Implemented
		DLList<std::string> * l = new DLList<std::string>;

		//Set up the initial state of the list to test
		l->head = head;
		l->tail = third;
		l->count = 3;

		assert(l->empty() == false);
		break;
	}
	default:
		std::cout << __func__ << " No Such Test: " << testNum << std::endl << std::flush;
		return -1;

	}
	return 0;
}


//Test add_front
int test_add_front(int testNum) {
	std::cout << __func__ << testNum << std::endl;
	std::string name = std::string(__func__);

	switch (testNum) {
	case 0: {

		DLList<int> * l = new DLList<int>;

		l->add_front(99);

		assert(l->head != nullptr);
		assert(l->tail != nullptr);

		assert(l->head->prv() == nullptr);
		assert(l->head->nxt() == nullptr);
		
		assert(l->head->itm() == 99);
		assert(l->count == 1);

		break;
	}
	case 1: {
	
		//Make some control nodes
		DLList<std::string>::Node* head = new DLList<std::string>::Node;
		DLList<std::string>::Node* second = new DLList<std::string>::Node;
		DLList<std::string>::Node* third = new DLList<std::string>::Node;

		//Link together to make a valid linked list 
		head->itm("first");
		head->prv(nullptr);
		head->nxt(second);

		second->itm("second");
		second->prv(head);
		second->nxt(third);

		third->itm("third");
		third->prv(second);
		third->nxt(nullptr);

		//Assume Constructor Correctly Implemented
		DLList<std::string> * l = new DLList<std::string>;

		//Set up the initial state of the list to test
		l->head = head;
		l->tail = third;
		l->count = 3;

		//Now with the list given a complete and correct starting state
		//We can test various member functions for correctness.
		//For example we can use this as one test for add_front;
		l->add_front("Zero");

		//Examing the final state of our list after call
		assert(l->count == 4);
		assert(l->head != nullptr);
		assert(l->head->prv() == nullptr);
		assert(l->head == head->prv());
		assert(l->head->nxt() == head);
		assert(l->head->itm() == "Zero");
		assert(l->tail == third);
		break;
	}
	default:
		std::cout << __func__ << " No Such Test: " << testNum << std::endl << std::flush;
		return -1;

	}
	return 0;
}

//Test add_rear
int test_add_rear(int testNum) {
	std::cout << __func__ << testNum << std::endl;
	std::string name = std::string(__func__);
	switch (testNum) {
	case 0: {

		DLList<int> * l = new DLList<int>;

		l->add_rear(99);
		assert(l->head != nullptr);
		assert(l->tail != nullptr);
		assert(l->head->prv() == nullptr);
		assert(l->head->nxt() == nullptr);
		assert(l->head->itm() == 99);
		assert(l->count == 1);
		break;
	}
	case 1: {

			 //Make some control nodes
		DLList<std::string>::Node* head = new DLList<std::string>::Node;
		DLList<std::string>::Node* second = new DLList<std::string>::Node;
		DLList<std::string>::Node* third = new DLList<std::string>::Node;

		//Link together to make a valid linked list 
		head->itm("first");
		head->prv(nullptr);
		head->nxt(second);

		second->itm("second");
		second->prv(head);
		second->nxt(third);

		third->itm("third");
		third->prv(second);
		third->nxt(nullptr);

		//Assume Constructor Correctly Implemented
		DLList<std::string> * l = new DLList<std::string>;

		//Set up the initial state of the list to test
		l->head = head;
		l->tail = third;
		l->count = 3;

		//Now with the list given a complete and correct starting state
		//We can test various member functions for correctness.
		//For example we can use this as one test for add_rear;
		l->add_rear("forth");

		//Examing the final state of our list after call
		assert(l->count == 4);
		assert(l->head != nullptr);
		assert(l->tail != nullptr);
		assert(l->head == head);
		assert(l->tail->nxt() == nullptr);
		assert(l->tail->itm() == "forth");
		assert(l->tail->prv() == third);
		break;
	}
	default:
		std::cout << __func__ << " No Such Test: " << testNum << std::endl << std::flush;
		return -1;

	}
	return 0;
}

//Test add
int test_add(int testNum) {
	std::string name = std::string(__func__);
	std::cout << __func__ << testNum << std::endl;
	switch (testNum) {
	case 0: {
		
		DLList<int> * l = new DLList<int>;

		l->add(0, 1);

		assert(l->head != nullptr);
		assert(l->tail != nullptr);

		assert(l->count == 1);
		assert(l->head->itm() == 1);
		assert(l->head == l->tail);
		
		assert(l->head->nxt() == nullptr);
		assert(l->head->prv() == nullptr);
		break;
		
	}
	case 1: {
	
		DLList<int> * l = new DLList<int>;

		l->add(-1, 1);

		assert(l->head != nullptr);
		assert(l->tail != nullptr);

		assert(l->count == 1);
		assert(l->head->itm() == 1);
		assert(l->head == l->tail);
		
		assert(l->head->nxt() == nullptr);
		assert(l->head->prv() == nullptr);
		break;
	}
	case 2: {
		DLList<int> * l = new DLList<int>;

		l->add(99, 1);

		assert(l->head != nullptr);
		assert(l->tail != nullptr);
		assert(l->head->itm() == 1);
		assert(l->count == 1);
		assert(l->head == l->tail);
		assert(l->head->nxt() == nullptr);
		assert(l->head->prv() == nullptr);
		break;
	}
	case 3: {
		//Make some control nodes
		DLList<std::string>::Node* head = new DLList<std::string>::Node;
		DLList<std::string>::Node* second = new DLList<std::string>::Node;

		//Link together to make a valid linked list 
		head->itm("first");
		head->prv(nullptr);
		head->nxt(second);

		second->itm("second");
		second->prv(head);
		second->nxt(nullptr);

		//Assume Constructor Correctly Implemented
		DLList<std::string> * l = new DLList<std::string>;

		//Set up the initial state of the list to test
		l->head = head;
		l->tail = second;
		l->count = 2;

		l->add(0, "Zero");

		//Examing the final state of our list after call
		assert(l->head != nullptr);
		assert(l->tail != nullptr);
		assert(l->count == 3);
		assert(l->head->prv() == nullptr);
		assert(l->head == head->prv());
		assert(l->head->nxt() == head);
		assert(l->head->itm() == "Zero");
		assert(l->tail == second);

		break;
	}
	case 4: {
		DLList<std::string>::Node* head = new DLList<std::string>::Node;
		DLList<std::string>::Node* second = new DLList<std::string>::Node;

		//Link together to make a valid linked list 
		head->itm("first");
		head->prv(nullptr);
		head->nxt(second);

		second->itm("second");
		second->prv(head);
		second->nxt(nullptr);

		//Assume Constructor Correctly Implemented
		DLList<std::string> * l = new DLList<std::string>;

		//Set up the initial state of the list to test
		l->head = head;
		l->tail = second;
		l->count = 2;

		l->add(-1, "Zero");

		//Examing the final state of our list after call
		assert(l->head != nullptr);
		assert(l->tail != nullptr);
		assert(l->count == 3);
		assert(l->head->prv() == nullptr);
		assert(l->head == head->prv());
		assert(l->head->nxt() == head);
		assert(l->head->itm() == "Zero");
		assert(l->tail == second);

		break;
	}
	case 5: {
		DLList<std::string>::Node* head = new DLList<std::string>::Node;
		DLList<std::string>::Node* second = new DLList<std::string>::Node;

		//Link together to make a valid linked list
		head->itm("first");
		head->prv(nullptr);
		head->nxt(second);

		second->itm("second");
		second->prv(head);
		second->nxt(nullptr);

		//Assume Constructor Correctly Implemented
		DLList<std::string> * l = new DLList<std::string>;

		//Set up the initial state of the list to test
		l->head = head;
		l->tail = second;
		l->count = 2;

		l->add(4, "third");
	
		//Examing the final state of our list after call
		assert(l->head != nullptr);
		assert(l->tail != nullptr);
		assert(l->count == 3);
		assert(l->head == head);
		assert(l->tail->nxt() == nullptr);
		assert(l->tail->itm() == "third");
		assert(l->tail->prv() == second);
		break;
	}
	case 6: { 
		DLList<std::string>::Node* head = new DLList<std::string>::Node;
		DLList<std::string>::Node* second = new DLList<std::string>::Node;

		//Link together to make a valid linked list 
		head->itm("first");
		head->prv(nullptr);
		head->nxt(second);

		second->itm("second");
		second->prv(head);
		second->nxt(nullptr);

		//Assume Constructor Correctly Implemented
		DLList<std::string> * l = new DLList<std::string>;

		//Set up the initial state of the list to test
		l->head = head;
		l->tail = second;
		l->count = 2;

		l->add(1, "half");
	
		//Examing the final state of our list after call
		assert(l->count == 3);
		assert(l->head == head);

		assert(l->head != nullptr);
		assert(l->tail != nullptr);

		assert(l->head->prv() == nullptr); 
		assert(l->head->nxt()->itm() == "half"); 
		assert(l->tail->prv() == l->head->nxt()); 
		assert(l->tail == second); 
		assert(l->tail->nxt() == nullptr); 
		assert(l->head->nxt()->nxt() == l->tail); 
		assert(l->head == l->tail->prv()->prv()); 
		break;
	}
	default:
		std::cout << __func__ << " No Such Test: " << testNum << std::endl << std::flush;
		return -1;

	}
	return 0;
}

//Test search
int test_search(int testNum) {
	std::string name = std::string(__func__);
	std::cout << __func__ << testNum << std::endl;
	switch (testNum) {
	case 0: {
		DLList<int> * l = new DLList<int>;

		assert(l->search(100)==-42);

		break;
	}
	case 1: {
		DLList<std::string>::Node* head = new DLList<std::string>::Node;
		DLList<std::string>::Node* second = new DLList<std::string>::Node;
		DLList<std::string>::Node* third = new DLList<std::string>::Node;

		//Link together to make a valid linked list 
		head->itm("first");
		head->prv(nullptr);
		head->nxt(second);

		second->itm("second");
		second->prv(head);
		second->nxt(third);

		third->itm("third");
		third->prv(second);
		third->nxt(nullptr);

		//Assume Constructor Correctly Implemented
		DLList<std::string> * l = new DLList<std::string>;

		//Set up the initial state of the list to test
		l->head = head;
		l->tail = third;
		l->count = 3;

		//Examing the final state of our list after call
		assert(l->search("Zero") == -42);
	
		break;
	}
	case 2: {
		DLList<std::string>::Node* head = new DLList<std::string>::Node;
		DLList<std::string>::Node* second = new DLList<std::string>::Node;
		DLList<std::string>::Node* third = new DLList<std::string>::Node;

		//Link together to make a valid linked list 
		head->itm("first");
		head->prv(nullptr);
		head->nxt(second);

		second->itm("second");
		second->prv(head);
		second->nxt(third);

		third->itm("third");
		third->prv(second);
		third->nxt(nullptr);

		//Assume Constructor Correctly Implemented
		DLList<std::string> * l = new DLList<std::string>;

		//Set up the initial state of the list to test
		l->head = head;
		l->tail = third;
		l->count = 3;

		//Examing the final state of our list after call

		assert(l->search("first") == 0);

		break;
	}
	case 3: {
		DLList<std::string>::Node* head = new DLList<std::string>::Node;
		DLList<std::string>::Node* second = new DLList<std::string>::Node;
		DLList<std::string>::Node* third = new DLList<std::string>::Node;

		//Link together to make a valid linked list 
		head->itm("first");
		head->prv(nullptr);
		head->nxt(second);

		second->itm("second");
		second->prv(head);
		second->nxt(third);

		third->itm("third");
		third->prv(second);
		third->nxt(nullptr);

		//Assume Constructor Correctly Implemented
		DLList<std::string> * l = new DLList<std::string>;

		//Set up the initial state of the list to test
		l->head = head;
		l->tail = third;
		l->count = 3;

		//Examing the final state of our list after call

		assert(l->search("second") == 1);

		break;
	}
	case 4: {
		DLList<std::string>::Node* head = new DLList<std::string>::Node;
		DLList<std::string>::Node* second = new DLList<std::string>::Node;
		DLList<std::string>::Node* third = new DLList<std::string>::Node;

		//Link together to make a valid linked list 
		head->itm("first");
		head->prv(nullptr);
		head->nxt(second);

		second->itm("second");
		second->prv(head);
		second->nxt(third);

		third->itm("third");
		third->prv(second);
		third->nxt(nullptr);

		//Assume Constructor Correctly Implemented
		DLList<std::string> * l = new DLList<std::string>;

		//Set up the initial state of the list to test
		l->head = head;
		l->tail = third;
		l->count = 3;

		//Examing the final state of our list after call
		assert(l->search("third") == 2);
		break;
	}
	default:
		std::cout << __func__ << " No Such Test: " << testNum << std::endl << std::flush;
		return -1;
		

	}
	return 0;
}

//Test front
int test_front(int testNum) {
	std::string name = std::string(__func__);
	std::cout << __func__ << testNum << std::endl;
	switch (testNum) {
	case 0: {
		DLList<std::string>::Node* head = new DLList<std::string>::Node;
		
		head->itm("first");
		head->prv(nullptr);
		head->nxt(nullptr);


		//Assume Constructor Correctly Implemented
		DLList<std::string> * l = new DLList<std::string>;

		//Set up the initial state of the list to test
		l->head = head;
		l->tail = head;
		l->count = 1;

		assert(l->front() == "first");
		break;
	}
	case 1: {
		DLList<std::string>::Node* head = new DLList<std::string>::Node;
		DLList<std::string>::Node* second = new DLList<std::string>::Node;
		DLList<std::string>::Node* third = new DLList<std::string>::Node;

		//Link together to make a valid linked list 
		head->itm("first");
		head->prv(nullptr);
		head->nxt(second);

		second->itm("second");
		second->prv(head);
		second->nxt(third);

		third->itm("third");
		third->prv(second);
		third->nxt(nullptr);

		//Assume Constructor Correctly Implemented
		DLList<std::string> * l = new DLList<std::string>;

		//Set up the initial state of the list to test
		l->head = head;
		l->tail = third;
		l->count = 3;

		assert(l->front() == "first");
		break;
	}

	default:
		std::cout << __func__ << " No Such Test: " << testNum << std::endl << std::flush;
		return -1;
	

	}
	return 0;
}


//Test rear
int test_rear(int testNum) {
	std::string name = std::string(__func__);
	
	std::cout << __func__ << testNum << std::endl;
	switch (testNum) {
	case 0: {
		DLList<std::string>::Node* head = new DLList<std::string>::Node;
		//Link together to make a valid linked list 
		head->itm("first");
		head->prv(nullptr);
		head->nxt(nullptr);

		//Assume Constructor Correctly Implemented
		DLList<std::string> * l = new DLList<std::string>;

		//Set up the initial state of the list to test
		l->head = head;
		l->tail = head;
		l->count = 1;

		assert(l->rear() == "first");
		break;
	}
	case 1: {
		DLList<std::string>::Node* head = new DLList<std::string>::Node;
		DLList<std::string>::Node* second = new DLList<std::string>::Node;
		DLList<std::string>::Node* third = new DLList<std::string>::Node;

		//Link together to make a valid linked list 
		head->itm("first");
		head->prv(nullptr);
		head->nxt(second);

		second->itm("second");
		second->prv(head);
		second->nxt(third);

		third->itm("third");
		third->prv(second);
		third->nxt(nullptr);

		//Assume Constructor Correctly Implemented
		DLList<std::string> * l = new DLList<std::string>;

		//Set up the initial state of the list to test
		l->head = head;
		l->tail = third;
		l->count = 3;

		assert(l->rear() == "third");
		break;
	}

	default:
		std::cout << __func__ << " No Such Test: " << testNum << std::endl << std::flush;
		return -1;

	}
	return 0;
}
//Test peek
int test_peek(int testNum) {
	std::string name = std::string(__func__);
	std::cout << __func__ << testNum << std::endl;
	switch (testNum) {
	case 0: {
		DLList<std::string>::Node* head = new DLList<std::string>::Node;

		//Link together to make a valid linked list 
		head->itm("first");
		head->prv(nullptr);
		head->nxt(nullptr);


		//Assume Constructor Correctly Implemented
		DLList<std::string> * l = new DLList<std::string>;

		//Set up the initial state of the list to test
		l->head = head;
		l->tail = head;
		l->count = 1;

		assert(l->peek(0) == "first");
		break;
	}
	case 1: {
		DLList<std::string>::Node* head = new DLList<std::string>::Node;
		DLList<std::string>::Node* second = new DLList<std::string>::Node;
		DLList<std::string>::Node* third = new DLList<std::string>::Node;

		//Link together to make a valid linked list 
		head->itm("first");
		head->prv(nullptr);
		head->nxt(second);

		second->itm("second");
		second->prv(head);
		second->nxt(third);

		third->itm("third");
		third->prv(second);
		third->nxt(nullptr);

		//Assume Constructor Correctly Implemented
		DLList<std::string> * l = new DLList<std::string>;

		//Set up the initial state of the list to test
		l->head = head;
		l->tail = third;
		l->count = 3;

		assert(l->peek(0) == "first");
		assert(l->peek(1) == "second");
		assert(l->peek(2) == "third");
		break;
	}
	
	default:
		std::cout << __func__ << " No Such Test: " << testNum << std::endl << std::flush;
		return -1;
	}
	return 0;
}

//Test remove_front
int test_remove_front(int testNum) {
	std::string name = std::string(__func__);
	std::cout << __func__ << testNum << std::endl;
	switch (testNum) {
	case 0: {
		DLList<int> * l = new DLList<int>;
		assert(l->remove_front() == false);
		break;
	}
	case 1: {
		DLList<std::string>::Node* head = new DLList<std::string>::Node;

		//Link together to make a valid linked list 
		head->itm("first");
		head->prv(nullptr);
		head->nxt(nullptr);


		//Assume Constructor Correctly Implemented
		DLList<std::string> * l = new DLList<std::string>;

		//Set up the initial state of the list to test
		l->head = head;
		l->tail = head;
		l->count = 1;

		assert(l->remove_front() == true);
		assert(l->count == 0);
		assert(l->head == nullptr);
		assert(l->tail == nullptr);
		break;
	}
	case 2: {
		DLList<std::string>::Node* head = new DLList<std::string>::Node;
		DLList<std::string>::Node* second = new DLList<std::string>::Node;
		DLList<std::string>::Node* third = new DLList<std::string>::Node;

		//Link together to make a valid linked list 
		head->itm("first");
		head->prv(nullptr);
		head->nxt(second);

		second->itm("second");
		second->prv(head);
		second->nxt(third);

		third->itm("third");
		third->prv(second);
		third->nxt(nullptr);

		//Assume Constructor Correctly Implemented
		DLList<std::string> * l = new DLList<std::string>;

		//Set up the initial state of the list to test
		l->head = head;
		l->tail = third;
		l->count = 3;

		assert(l->remove_front() == true);
		assert(l->count == 2);
		assert(l->head == second);
		assert(l->tail == third);
		assert(l->head->prv() == nullptr);
		break;
	}
	
	default:
		std::cout << __func__ << " No Such Test: " << testNum << std::endl << std::flush;
		return -1;

	}
	return 0;
}
//Test remove_rear
int test_remove_rear(int testNum) {
	std::string name = std::string(__func__);
	std::cout << __func__ << testNum << std::endl;
	switch (testNum) {
	case 0: {
		DLList<int> * l = new DLList<int>;
		assert(l->remove_rear() == false);
		break;

	}
	case 1: {
		DLList<std::string>::Node* head = new DLList<std::string>::Node;

		//Link together to make a valid linked list 
		head->itm("first");
		head->prv(nullptr);
		head->nxt(nullptr);


		//Assume Constructor Correctly Implemented
		DLList<std::string> * l = new DLList<std::string>;

		//Set up the initial state of the list to test
		l->head = head;
		l->tail = head;
		l->count = 1;

		assert(l->remove_rear() == true);
		assert(l->count == 0);
		assert(l->head == nullptr);
		assert(l->tail == nullptr);
		break;
	}
	case 2: {
		DLList<std::string>::Node* head = new DLList<std::string>::Node;
		DLList<std::string>::Node* second = new DLList<std::string>::Node;
		DLList<std::string>::Node* third = new DLList<std::string>::Node;

		//Link together to make a valid linked list 
		head->itm("first");
		head->prv(nullptr);
		head->nxt(second);

		second->itm("second");
		second->prv(head);
		second->nxt(third);

		third->itm("third");
		third->prv(second);
		third->nxt(nullptr);

		//Assume Constructor Correctly Implemented
		DLList<std::string> * l = new DLList<std::string>;

		//Set up the initial state of the list to test
		l->head = head;
		l->tail = third;
		l->count = 3;

		assert(l->remove_rear() == true);
		assert(l->count == 2);
		assert(l->head == head);
		assert(l->tail == second);
		assert(l->tail->nxt() == nullptr);
		break;
	}
	default:
		std::cout << __func__ << " No Such Test: " << testNum << std::endl << std::flush;
		return -1;
	}
	return 0;
}


int test_remove_index(int testNum) {
	std::string name = std::string(__func__);
	std::cout << __func__ << testNum << std::endl <<std::flush;
	switch (testNum) {
	case 0: {
		DLList<int> * l = new DLList<int>;
		assert(l->remove_index(-1) == false);
		break;
	}
	case 1: {
		DLList<int> * l = new DLList<int>;
		assert(l->remove_index(9999) == false);
		break;
	}
	case 2: {
		DLList<std::string>::Node* head = new DLList<std::string>::Node;

		//Link together to make a valid linked list 
		head->itm("first");
		head->prv(nullptr);
		head->nxt(nullptr);

		//Assume Constructor Correctly Implemented
		DLList<std::string> * l = new DLList<std::string>;

		//Set up the initial state of the list to test
		l->head = head;
		l->tail = head;
		l->count = 1;

		assert(l->remove_index(-1) == false);

		break;
	}
	case 3: {
		DLList<std::string>::Node* head = new DLList<std::string>::Node;

		//Link together to make a valid linked list 
		head->itm("first");
		head->prv(nullptr);
		head->nxt(nullptr);


		//Assume Constructor Correctly Implemented
		DLList<std::string> * l = new DLList<std::string>;

		//Set up the initial state of the list to test
		l->head = head;
		l->tail = head;
		l->count = 1;

		assert(l->remove_index(9999) == false);

		break;
	}
	case 4: {
		DLList<std::string>::Node* head = new DLList<std::string>::Node;

		//Link together to make a valid linked list 
		head->itm("first");
		head->prv(nullptr);
		head->nxt(nullptr);


		//Assume Constructor Correctly Implemented
		DLList<std::string> * l = new DLList<std::string>;

		//Set up the initial state of the list to test
		l->head = head;
		l->tail = head;
		l->count = 1;

		assert(l->remove_index(0) == true);
		assert(l->count == 0);
		assert(l->head == nullptr);
		assert(l->tail == nullptr);
		break;
	}
	case 5: {
		DLList<std::string>::Node* head = new DLList<std::string>::Node;
		DLList<std::string>::Node* second = new DLList<std::string>::Node;
		DLList<std::string>::Node* third = new DLList<std::string>::Node;

		//Link together to make a valid linked list 
		head->itm("first");
		head->prv(nullptr);
		head->nxt(second);

		second->itm("second");
		second->prv(head);
		second->nxt(third);

		third->itm("third");
		third->prv(second);
		third->nxt(nullptr);

		//Assume Constructor Correctly Implemented
		DLList<std::string> * l = new DLList<std::string>;

		//Set up the initial state of the list to test
		l->head = head;
		l->tail = third;
		l->count = 3;

		assert(l->remove_index(0) == true);
		assert(l->count == 2);
		assert(l->head == second);
		assert(l->head->prv() == nullptr);
		assert(l->tail == third);
		break;

	}
	case 6: {
		DLList<std::string>::Node* head = new DLList<std::string>::Node;
		DLList<std::string>::Node* second = new DLList<std::string>::Node;
		DLList<std::string>::Node* third = new DLList<std::string>::Node;

		//Link together to make a valid linked list 
		head->itm("first");
		head->prv(nullptr);
		head->nxt(second);

		second->itm("second");
		second->prv(head);
		second->nxt(third);

		third->itm("third");
		third->prv(second);
		third->nxt(nullptr);

		//Assume Constructor Correctly Implemented
		DLList<std::string> * l = new DLList<std::string>;

		//Set up the initial state of the list to test
		l->head = head;
		l->tail = third;
		l->count = 3;

		assert(l->remove_index(2) == true);
		assert(l->count == 2);
		assert(l->head == head);
		assert(l->tail->nxt() == nullptr);
		assert(l->tail == second);
		break;

	}
	case 7: { 
		DLList<std::string>::Node* head = new DLList<std::string>::Node;
		DLList<std::string>::Node* second = new DLList<std::string>::Node;
		DLList<std::string>::Node* third = new DLList<std::string>::Node;

		//Link together to make a valid linked list 
		head->itm("first");
		head->prv(nullptr);
		head->nxt(second);

		second->itm("second");
		second->prv(head);
		second->nxt(third);

		third->itm("third");
		third->prv(second);
		third->nxt(nullptr);

		//Assume Constructor Correctly Implemented
		DLList<std::string> * l = new DLList<std::string>;

		//Set up the initial state of the list to test
		l->head = head;
		l->tail = third;
		l->count = 3;

		assert(l->remove_index(1) == true);
		assert(l->count == 2);

		assert(l->head == head);
		assert(l->tail == third);

		assert(l->head->nxt() == third);
		assert(l->tail->prv() == head);
		break;


	}
	default:
		std::cout << __func__ << " No Such Test: " << testNum << std::endl << std::flush;
		return -1;

	}
	return 0;
}

int test_remove_item(int testNum) {
	std::string name = std::string(__func__);
	std::cout << __func__ << testNum << std::endl << std::flush;
	switch (testNum) {
	case 0: {//Test with empty list
		DLList<int> * l = new DLList<int>;
		assert(l->remove_item(1) == -1);
		break;
	}
	case 1: {
		DLList<std::string>::Node* head = new DLList<std::string>::Node;

		//Link together to make a valid linked list 
		head->itm("first");
		head->prv(nullptr);
		head->nxt(nullptr);

		//Assume Constructor Correctly Implemented
		DLList<std::string> * l = new DLList<std::string>;

		//Set up the initial state of the list to test
		l->head = head;
		l->tail = head;
		l->count = 1;

		assert(l->remove_item("second") == -42);

		break;
	}

	case 2: {
		DLList<std::string>::Node* head = new DLList<std::string>::Node;

		//Link together to make a valid linked list 
		head->itm("first");
		head->prv(nullptr);
		head->nxt(nullptr);


		//Assume Constructor Correctly Implemented
		DLList<std::string> * l = new DLList<std::string>;

		//Set up the initial state of the list to test
		l->head = head;
		l->tail = head;
		l->count = 1;

		assert(l->remove_item("first") == 0);
		assert(l->count == 0);
		assert(l->head == nullptr);
		assert(l->tail == nullptr);
		break;
	}
	case 3: {
		DLList<std::string>::Node* head = new DLList<std::string>::Node;
		DLList<std::string>::Node* second = new DLList<std::string>::Node;
		DLList<std::string>::Node* third = new DLList<std::string>::Node;

		//Link together to make a valid linked list 
		head->itm("first");
		head->prv(nullptr);
		head->nxt(second);

		second->itm("second");
		second->prv(head);
		second->nxt(third);

		third->itm("third");
		third->prv(second);
		third->nxt(nullptr);

		//Assume Constructor Correctly Implemented
		DLList<std::string> * l = new DLList<std::string>;

		//Set up the initial state of the list to test
		l->head = head;
		l->tail = third;
		l->count = 3;

		assert(l->remove_item("first") == 0);
		assert(l->count == 2);
		assert(l->head == second);
		assert(l->head != nullptr);
		assert(l->head->prv() == nullptr);
		assert(l->tail == third);
		break;

	}
	case 4: {
		DLList<std::string>::Node* head = new DLList<std::string>::Node;
		DLList<std::string>::Node* second = new DLList<std::string>::Node;
		DLList<std::string>::Node* third = new DLList<std::string>::Node;

		//Link together to make a valid linked list 
		head->itm("first");
		head->prv(nullptr);
		head->nxt(second);

		second->itm("second");
		second->prv(head);
		second->nxt(third);

		third->itm("third");
		third->prv(second);
		third->nxt(nullptr);

		//Assume Constructor Correctly Implemented
		DLList<std::string> * l = new DLList<std::string>;

		//Set up the initial state of the list to test
		l->head = head;
		l->tail = third;
		l->count = 3;

		assert(l->remove_item("third") == 2);
		assert(l->count == 2);
		assert(l->head == head);
		assert(l->tail != nullptr);
		assert(l->tail->nxt() == nullptr);
		assert(l->tail == second);
		break;

	}
	case 5: {
		DLList<std::string>::Node* head = new DLList<std::string>::Node;
		DLList<std::string>::Node* second = new DLList<std::string>::Node;
		DLList<std::string>::Node* third = new DLList<std::string>::Node;

		//Link together to make a valid linked list 
		head->itm("first");
		head->prv(nullptr);
		head->nxt(second);

		second->itm("second");
		second->prv(head);
		second->nxt(third);

		third->itm("third");
		third->prv(second);
		third->nxt(nullptr);

		//Assume Constructor Correctly Implemented
		DLList<std::string> * l = new DLList<std::string>;

		//Set up the initial state of the list to test
		l->head = head;
		l->tail = third;
		l->count = 3;

		assert(l->remove_item("second") == 1);
		assert(l->count == 2);

		assert(l->head == head);
		assert(l->tail == third);

		assert(l->head != nullptr);
		assert(l->tail != nullptr);
		assert(l->head->nxt() == third);
		assert(l->tail->prv() == head);

		break;


	}
	default:
		std::cout << __func__ << " No Such Test: " << testNum << std::endl << std::flush;
		return -1;

	}
	return 0;
}
int test_print(int testNum) {
	std::string name = std::string(__func__);
	std::cout << __func__ << testNum << std::endl << std::flush;
	switch (testNum) {
	case 0: {

		std::string test_string1("Tom Dick Mary"); 
		std::stringstream buffer(test_string1);
		std::vector<std::string> test_vector{ std::istream_iterator<std::string>(buffer), std::istream_iterator<std::string>() };
		buffer.str("");

		DLList<std::string>::Node* head = new DLList<std::string>::Node;
		DLList<std::string>::Node* second = new DLList<std::string>::Node;
		DLList<std::string>::Node* third = new DLList<std::string>::Node;

		//Link together to make a valid linked list 
		head->itm(test_vector[0]);
		head->prv(nullptr);
		head->nxt(second);

		second->itm(test_vector[1]);
		second->prv(head);
		second->nxt(third);

		third->itm(test_vector[2]);
		third->prv(second);
		third->nxt(nullptr);

		//Assume Constructor Correctly Implemented
		DLList<std::string> * l = new DLList<std::string>;

		//Set up the initial state of the list to test
		l->head = head;
		l->tail = third;
		l->count = 3;

		std::streambuf * old = std::cout.rdbuf(buffer.rdbuf());

		l->print();
		std::cout.rdbuf(old);

		std::string text = buffer.str();

		std::vector<std::string> ret{ std::istream_iterator<std::string>(buffer),
			std::istream_iterator<std::string>() };

		assert(text.length() == test_string1.length());
		assert(text == test_string1);
		for (int i = 0; i < ret.size(); i++) {
			assert(ret[i] == test_vector[i]);
		}



		break;

	}
	case 1: {

		std::string test_string1("");
		std::stringstream buffer(test_string1);
		std::vector<std::string> test_vector{ std::istream_iterator<std::string>(buffer), std::istream_iterator<std::string>() };
		buffer.str("");

		//Assume Constructor Correctly Implemented
		DLList<std::string> * l = new DLList<std::string>;

		//hijack cout buffer
		std::streambuf * old = std::cout.rdbuf(buffer.rdbuf());

		l->print();

		//restore cout buffer
		std::cout.rdbuf(old);

		std::string text = buffer.str();
		std::vector<std::string> ret{ std::istream_iterator<std::string>(buffer),
			std::istream_iterator<std::string>() };

		assert(text.length() == test_string1.length() );
		assert(text == test_string1);
		for (int i = 0; i < ret.size(); i++) {
			assert(ret[i] == test_vector[i]);
		}

		break;
	}
	default:
		std::cout << __func__ << " No Such Test: " << testNum << std::endl << std::flush;
		return -1;

	}
	return 0;

}
int test_size(int testNum) {
	std::string name = std::string(__func__);
	std::cout << __func__ << testNum << std::endl << std::flush;
	switch (testNum) {
	case 0: {

		DLList<int>::Node* head = new DLList<int>::Node;
		DLList<int>::Node* second = new DLList<int>::Node;
		DLList<int>::Node* third = new DLList<int>::Node;

		//Link together to make a valid linked list 
		head->itm(2);
		head->prv(nullptr);
		head->nxt(second);

		second->itm(4);
		second->prv(head);
		second->nxt(third);

		third->itm(76);
		third->prv(second);
		third->nxt(nullptr);

		//Assume Constructor Correctly Implemented
		DLList<int> * l = new DLList<int>;

		//Set up the initial state of the list to test
		l->head = head;
		l->tail = third;
		l->count = 3;

		assert(l->size() == 3);

		break;

	}
	case 1: {
		DLList<std::string> * l = new DLList<std::string>;
		assert(l->size() == 0);
		break;
	}
	default:
		std::cout << __func__ << " No Such Test: " << testNum << std::endl << std::flush;
		return -1;

	}
	return 0;

}
int test_items(int testNum) {
	std::string name = std::string(__func__);
	std::cout << __func__ << testNum << std::endl << std::flush;
	switch (testNum) {
	case 0: {

		DLList<int>::Node* head = new DLList<int>::Node;
		DLList<int>::Node* second = new DLList<int>::Node;
		DLList<int>::Node* third = new DLList<int>::Node;

		//Link together to make a valid linked list 
		head->itm(2);
		head->prv(nullptr);
		head->nxt(second);

		second->itm(4);
		second->prv(head);
		second->nxt(third);

		third->itm(76);
		third->prv(second);
		third->nxt(nullptr);

		//Assume Constructor Correctly Implemented
		DLList<int> * l = new DLList<int>;

		//Set up the initial state of the list to test
		l->head = head;
		l->tail = third;
		l->count = 3;

		assert(l->items(42) == 0);

		break;

	}
	case 1: {
		DLList<int> * l = new DLList<int>;
		assert(l->items(10) == 0);
		break;
	}
	case 2: {

		DLList<int>::Node* head = new DLList<int>::Node;

		//Link together to make a valid linked list 
		head->itm(2);
		head->prv(nullptr);
		head->nxt(nullptr);

		//Assume Constructor Correctly Implemented
		DLList<int> * l = new DLList<int>;

		//Set up the initial state of the list to test
		l->head = head;
		l->tail = head;
		l->count = 1;

		assert(l->items(8) == 0);
		break;
	}
	case 3: {

		DLList<int>::Node* head = new DLList<int>::Node;

		//Link together to make a valid linked list 
		head->itm(2);
		head->prv(nullptr);
		head->nxt(nullptr);

		//Assume Constructor Correctly Implemented
		DLList<int> * l = new DLList<int>;

		//Set up the initial state of the list to test
		l->head = head;
		l->tail = head;
		l->count = 1;

		assert(l->items(2) == 1);
		break;
	}
	case 4: {
		
		DLList<int>::Node* head = new DLList<int>::Node;
		DLList<int>::Node* second = new DLList<int>::Node;
		DLList<int>::Node* third = new DLList<int>::Node;

		//Link together to make a valid linked list 
		head->itm(2);
		head->prv(nullptr);
		head->nxt(second);

		second->itm(4);
		second->prv(head);
		second->nxt(third);

		third->itm(76);
		third->prv(second);
		third->nxt(nullptr);

		//Assume Constructor Correctly Implemented
		DLList<int> * l = new DLList<int>;

		//Set up the initial state of the list to test
		l->head = head;
		l->tail = third;
		l->count = 3;

		assert(l->items(2) == 1);
		break;
	}
	case 5: {
		
		DLList<int>::Node* head = new DLList<int>::Node;
		DLList<int>::Node* second = new DLList<int>::Node;
		DLList<int>::Node* third = new DLList<int>::Node;

		//Link together to make a valid linked list 
		head->itm(2);
		head->prv(nullptr);
		head->nxt(second);

		second->itm(2);
		second->prv(head);
		second->nxt(third);

		third->itm(2);
		third->prv(second);
		third->nxt(nullptr);

		//Assume Constructor Correctly Implemented
		DLList<int> * l = new DLList<int>;

		//Set up the initial state of the list to test
		l->head = head;
		l->tail = third;
		l->count = 3;

		assert(l->items(2) == 3);
		break;
	}
	default:
		std::cout << __func__ << " No Such Test: " << testNum << std::endl << std::flush;
		return -1;

	}
	return 0;

}

int test_copyCtor(int testNum) {
	std::string name = std::string(__func__);
	std::cout << __func__ << testNum << std::endl << std::flush;
	switch (testNum) {
	case 0: {

		DLList<int> * l = new DLList<int>;
		DLList<int> * p = new DLList<int>(*l);

		//Set up the initial state of the list to test
		assert(p->head==nullptr);
		assert(p->tail == nullptr);
		assert(p->count == 0);

		break;

	}

	case 1: {


		DLList<int>::Node* head = new DLList<int>::Node;
		DLList<int>::Node* second = new DLList<int>::Node;
		DLList<int>::Node* third = new DLList<int>::Node;

		//Link together to make a valid linked list 
		head->itm(2);
		head->prv(nullptr);
		head->nxt(second);

		second->itm(4);
		second->prv(head);
		second->nxt(third);

		third->itm(76);
		third->prv(second);
		third->nxt(nullptr);

		//Assume Constructor Correctly Implemented
		DLList<int> * l = new DLList<int>;

		//Set up the initial state of the list to test
		l->head = head;
		l->tail = third;
		l->count = 3;
		 
		DLList<int> * p = new DLList<int>(*l);

		assert(p->head != nullptr );
		assert(p->tail != nullptr);
		assert(p->count == 3);

		assert(p->head->itm() == head->itm());
		assert(p->head->nxt()->itm() == second->itm());
		assert(p->tail->prv()->itm() == second->itm());
		assert(p->tail->itm() == third->itm());

		assert(p->head != head);
		assert(p->tail != third);

		break;


	}
	case 2: {
		DLList<int>::Node* head = new DLList<int>::Node;
		DLList<int>::Node* second = new DLList<int>::Node;
		DLList<int>::Node* third = new DLList<int>::Node;

		//Link together to make a valid linked list 
		head->itm(2);
		head->prv(nullptr);
		head->nxt(second);

		second->itm(4);
		second->prv(head);
		second->nxt(third);

		third->itm(76);
		third->prv(second);
		third->nxt(nullptr);

		//Assume Constructor Correctly Implemented
		DLList<int> * l = new DLList<int>;

		//Set up the initial state of the list to test
		l->head = head;
		l->tail = third;
		l->count = 3;

		DLList<int> * p = new DLList<int>(*l);

		assert(p->head != nullptr);
		assert(p->tail != nullptr);
		assert(p->count == 3);

		assert(p->head->itm() == head->itm());
		assert(p->head->nxt()->itm() == second->itm());
		assert(p->tail->prv()->itm() == second->itm());
		assert(p->tail->itm() == third->itm());


		//check aliasing
		assert(p->head != head);
		assert(p->head != second);
		assert(p->head != third);

		assert(p->head->nxt() != head);
		assert(p->head->nxt() != second);
		assert(p->head->nxt() != third);

		assert(p->tail != head);
		assert(p->tail != second);
		assert(p->tail != third);

		break;
	}
	default:
		std::cout << __func__ << " No Such Test: " << testNum << std::endl << std::flush;
		return -1;

	}
	return 0;

}


int test_assgnOper(int testNum) {
	std::string name = std::string(__func__);
	std::cout << __func__ << testNum << std::endl << std::flush;
	switch (testNum) {
	case 0: {

		DLList<int> * l = new DLList<int>;
		DLList<int> * p = new DLList<int>;

		*p = *l;
		//Set up the initial state of the list to test

		assert(p->head == nullptr);
		assert(p->tail == nullptr);
		assert(p->count == 0);

		break;

	}

	case 1: {

		DLList<int>::Node* head = new DLList<int>::Node;
		DLList<int>::Node* second = new DLList<int>::Node;
		DLList<int>::Node* third = new DLList<int>::Node;

		//Link together to make a valid linked list 
		head->itm(2);
		head->prv(nullptr);
		head->nxt(second);

		second->itm(4);
		second->prv(head);
		second->nxt(third);

		third->itm(76);
		third->prv(second);
		third->nxt(nullptr);

		//Assume Constructor Correctly Implemented
		DLList<int> * l = new DLList<int>;

		//Set up the initial state of the list to test
		l->head = head;
		l->tail = third;
		l->count = 3;

		DLList<int> * p = new DLList<int>;

		*p = *l;

		assert(p->head != nullptr);
		assert(p->tail != nullptr);
		assert(p->count == 3);

		assert(p->head->itm() == head->itm());
		assert(p->head->nxt()->itm() == second->itm());
		assert(p->tail->prv()->itm() == second->itm());
		assert(p->tail->itm() == third->itm());

		assert(p->head != head);
		assert(p->tail != third);

		break;


	}
	
	case 2: {
		DLList<int>::Node* head = new DLList<int>::Node;
		DLList<int>::Node* second = new DLList<int>::Node;
		DLList<int>::Node* third = new DLList<int>::Node;

		//Link together to make a valid linked list 
		head->itm(2);
		head->prv(nullptr);
		head->nxt(second);

		second->itm(4);
		second->prv(head);
		second->nxt(third);

		third->itm(76);
		third->prv(second);
		third->nxt(nullptr);

		//Assume Constructor Correctly Implemented
		DLList<int> * l = new DLList<int>;

		//Set up the initial state of the list to test
		l->head = head;
		l->tail = third;
		l->count = 3;

		DLList<int> * p = new DLList<int>;

		*p = *l;

		assert(p->head != nullptr);
		assert(p->tail != nullptr);
		assert(p->head->nxt() != nullptr);
		assert(p->tail->prv() != nullptr);

		assert(p->count == 3);

		assert(p->head->itm() == head->itm());
		assert(p->head->nxt()->itm() == second->itm());
		assert(p->tail->prv()->itm() == second->itm());
		assert(p->tail->itm() == third->itm());


		//check aliasing
		assert(p->head != head);
		assert(p->head != second);
		assert(p->head != third);

		assert(p->head->nxt() != head);
		assert(p->head->nxt() != second);
		assert(p->head->nxt() != third);

		assert(p->tail != head);
		assert(p->tail != second);
		assert(p->tail != third);

		break;
	}
	default:
		std::cout << __func__ << " No Such Test: " << testNum << std::endl << std::flush;
		return -1;

	}
	return 0;

}


int test_mem_destructor(int testNum) {
	std::string name = std::string(__func__);
	std::cout << __func__ << testNum << std::endl << std::flush;
	switch (testNum) {
	case 0: {
		RESET();
		DLList<int>::Node* head = DEBUG_NEW DLList<int>::Node;
		DLList<int>::Node* second = DEBUG_NEW DLList<int>::Node;
		DLList<int>::Node* third = DEBUG_NEW DLList<int>::Node;

		//Link together to make a valid linked list 
		head->itm(2);
		head->prv(nullptr);
		head->nxt(second);

		second->itm(4);
		second->prv(head);
		second->nxt(third);

		third->itm(76);
		third->prv(second);
		third->nxt(nullptr);

		//Assume Constructor Correctly Implemented
		{
			DLList<int> * l = new DLList<int>;

			//Set up the initial state of the list to test
			l->head = head;
			l->tail = third;
			l->count = 3;

			//destructor
			delete l;
		} 

		//GETMEMORYREPORT();
		if (SIZE() != 0) {
			std::cerr << "Destructor: Memory Leak detected" << std::endl;
		}
		assert(SIZE() == 0);

		break;

	}

	default:
		std::cout << __func__ << " No Such Test: " << testNum << std::endl << std::flush;
		return -1;

	}
	return 0;
}

int test_mem_assgnOper(int testNum) {
	std::string name = std::string(__func__);
	std::cout << __func__ << testNum << std::endl << std::flush;
	switch (testNum) {
	case 0: {
		//Assume Constructor Correctly Implemented
		DLList<int> * l = new DLList<int>;
		DLList<int> * p = new DLList<int>;

		RESET(); 

		DLList<int>::Node* head = DEBUG_NEW DLList<int>::Node;
		DLList<int>::Node* second = DEBUG_NEW DLList<int>::Node;
		DLList<int>::Node* third = DEBUG_NEW DLList<int>::Node;

		//Link together to make a valid linked list 
		head->itm(2);
		head->prv(nullptr);
		head->nxt(second);

		second->itm(4);
		second->prv(head);
		second->nxt(third);

		third->itm(76);
		third->prv(second);
		third->nxt(nullptr);


		//Set up the initial state of the list to test
		l->head = head;
		l->tail = third;
		l->count = 3;
				
		*l = *p;

		//GETMEMORYREPORT();
		if (SIZE() != 0) {
			std::cerr << "Assign Op: Memory Leak detected" << std::endl;
		}
		assert(SIZE() == 0);
		break;
	}
	case 1: {

		//Assume Constructor Correctly Implemented
		DLList<int> * l = new DLList<int>;

		RESET();
		DLList<int>::Node* head = DEBUG_NEW DLList<int>::Node;
		DLList<int>::Node* second = DEBUG_NEW DLList<int>::Node;
		DLList<int>::Node* third = DEBUG_NEW DLList<int>::Node;

		//Link together to make a valid linked list 
		head->itm(2);
		head->prv(nullptr);
		head->nxt(second);

		second->itm(4);
		second->prv(head);
		second->nxt(third);

		third->itm(76);
		third->prv(second);
		third->nxt(nullptr);

	
		//Set up the initial state of the list to test
		l->head = head;
		l->tail = third;
		l->count = 3;
		//GETMEMORYREPORT();

		*l = *l;
		if (SIZE() != 3) {
			std::cerr << "Assign Op: Improper assignment" << std::endl;
		}
		assert(SIZE() == 3);
		break;
	}
	default:
		std::cout << __func__ << " No Such Test: " << testNum << std::endl << std::flush;
		return -1;
	}
	return 0;

}

int test_sub_list(int testNum) {
	std::cout << __func__ << testNum << std::endl;
	std::string name = std::string(__func__);
	switch (testNum) {
	case 0: {

		DLList<int> * l = new DLList<int>;
		l->head = nullptr;
		l->tail = nullptr;
		l->count = 0;

		DLList<int> * sub = new DLList<int>;
		sub->head = nullptr;
		sub->tail = nullptr;
		sub->count = 0;

		assert(l->sub_list(*sub) == true);

		break;
	}
	case 1: {

		//Make some control nodes
		DLList<int>::Node* head = new DLList<int>::Node;
		DLList<int>::Node* second = new DLList<int>::Node;
		DLList<int>::Node* third = new DLList<int>::Node;

		//Link together to make a valid linked list 
		head->itm(1);
		head->prv(nullptr);
		head->nxt(second);

		second->itm(2);
		second->prv(head);
		second->nxt(third);

		third->itm(3);
		third->prv(second);
		third->nxt(nullptr);

		//Assume Constructor Correctly Implemented
		DLList<int> * l = new DLList<int>;

		//Set up the initial state of the list to test
		l->head = head;
		l->tail = third;
		l->count = 3;

		DLList<int> * sub = new DLList<int>;
		sub->head = nullptr;
		sub->tail = nullptr;
		sub->count = 0;

		assert(l->sub_list(*sub) == true);
		break;
	}
	case 2: {

		//Make some control nodes
		DLList<int>::Node* head = new DLList<int>::Node;
		DLList<int>::Node* second = new DLList<int>::Node;
		DLList<int>::Node* third = new DLList<int>::Node;

		//Link together to make a valid linked list 
		head->itm(1);
		head->prv(nullptr);
		head->nxt(second);

		second->itm(2);
		second->prv(head);
		second->nxt(third);

		third->itm(3);
		third->prv(second);
		third->nxt(nullptr);

		//Assume Constructor Correctly Implemented
		DLList<int> * sub = new DLList<int>;

		//Set up the initial state of the list to test
		sub->head = head;
		sub->tail = third;
		sub->count = 3;

		DLList<int> * l = new DLList<int>;
		l->head = nullptr;
		l->tail = nullptr;
		l->count = 0;

		assert(l->sub_list(*sub) == false);
		break;
	}
	case 3: {

		//Make some control nodes
		DLList<int>::Node* node = new DLList<int>::Node;

		node->itm(1);
		node->prv(nullptr);
		node->nxt(nullptr);

		DLList<int> * l = new DLList<int>;
		l->head = node;
		l->tail = node;
		l->count = 1;


		DLList<int>::Node* sub_node = new DLList<int>::Node;

		//Assume Constructor Correctly Implemented
		DLList<int> * sub = new DLList<int>;

		sub_node->itm(1);
		sub_node->prv(nullptr);
		sub_node->nxt(nullptr);

		//Set up the initial state of the list to test
		sub->head = sub_node;
		sub->tail = sub_node;
		sub->count = 1;

		assert(l->sub_list(*sub) == true);
		break;
	}
	case 4: {

		//Make some control nodes
		DLList<int>::Node* node = new DLList<int>::Node;

		node->itm(0);
		node->prv(nullptr);
		node->nxt(nullptr);

		DLList<int> * l = new DLList<int>;
		l->head = node;
		l->tail = node;
		l->count = 1;


		DLList<int>::Node* sub_node = new DLList<int>::Node;

		//Assume Constructor Correctly Implemented
		DLList<int> * sub = new DLList<int>;

		sub_node->itm(1);
		sub_node->prv(nullptr);
		sub_node->nxt(nullptr);

		//Set up the initial state of the list to test
		sub->head = sub_node;
		sub->tail = sub_node;
		sub->count = 1;

		assert(l->sub_list(*sub) == false);
		break;
	}
	case 5: {

		//Make some control nodes
		DLList<int>::Node* node1 = new DLList<int>::Node;
		DLList<int>::Node* node2 = new DLList<int>::Node;
		DLList<int>::Node* node3 = new DLList<int>::Node;

		node1->itm(1);
		node1->prv(nullptr);
		node1->nxt(node2);

		node2->itm(2);
		node2->prv(node1);
		node2->nxt(node3);

		node3->itm(3);
		node3->prv(node2);
		node3->nxt(nullptr);

		DLList<int> * l = new DLList<int>;
		l->head = node1;
		l->tail = node3;
		l->count = 3;

		DLList<int>::Node* sub_node1 = new DLList<int>::Node;
		DLList<int>::Node* sub_node2 = new DLList<int>::Node;

		//Assume Constructor Correctly Implemented
		DLList<int> * sub = new DLList<int>;

		sub_node1->itm(1);
		sub_node1->prv(nullptr);
		sub_node1->nxt(sub_node2);

		sub_node2->itm(2);
		sub_node2->prv(sub_node1);
		sub_node2->nxt(nullptr);

		//Set up the initial state of the list to test
		sub->head = sub_node1;
		sub->tail = sub_node2;
		sub->count = 2;

		assert(l->sub_list(*sub) == true);
		break;
	}
	case 6: {

		//Make some control nodes
		DLList<int>::Node* node1 = new DLList<int>::Node;
		DLList<int>::Node* node2 = new DLList<int>::Node;
		DLList<int>::Node* node3 = new DLList<int>::Node;

		node1->itm(1);
		node1->prv(nullptr);
		node1->nxt(node2);

		node2->itm(2);
		node2->prv(node1);
		node2->nxt(node3);

		node3->itm(3);
		node3->prv(node2);
		node3->nxt(nullptr);

		DLList<int> * l = new DLList<int>;
		l->head = node1;
		l->tail = node3;
		l->count = 3;

		DLList<int>::Node* sub_node1 = new DLList<int>::Node;
		DLList<int>::Node* sub_node2 = new DLList<int>::Node;

		//Assume Constructor Correctly Implemented
		DLList<int> * sub = new DLList<int>;

		sub_node1->itm(2);
		sub_node1->prv(nullptr);
		sub_node1->nxt(sub_node2);

		sub_node2->itm(3);
		sub_node2->prv(sub_node1);
		sub_node2->nxt(nullptr);

		//Set up the initial state of the list to test
		sub->head = sub_node1;
		sub->tail = sub_node2;
		sub->count = 2;

		assert(l->sub_list(*sub) == true);
		break;
	}
	case 7: {

		//Make some control nodes
		DLList<int>::Node* node1 = new DLList<int>::Node;
		DLList<int>::Node* node2 = new DLList<int>::Node;
		DLList<int>::Node* node3 = new DLList<int>::Node;

		node1->itm(1);
		node1->prv(nullptr);
		node1->nxt(node2);

		node2->itm(2);
		node2->prv(node1);
		node2->nxt(node3);

		node3->itm(3);
		node3->prv(node2);
		node3->nxt(nullptr);

		DLList<int> * l = new DLList<int>;
		l->head = node1;
		l->tail = node3;
		l->count = 3;

		DLList<int>::Node* sub_node1 = new DLList<int>::Node;
		DLList<int>::Node* sub_node2 = new DLList<int>::Node;
		DLList<int>::Node* sub_node3 = new DLList<int>::Node;

		//Assume Constructor Correctly Implemented
		DLList<int> * sub = new DLList<int>;

		sub_node1->itm(1);
		sub_node1->prv(nullptr);
		sub_node1->nxt(sub_node2);

		sub_node2->itm(2);
		sub_node2->prv(sub_node1);
		sub_node2->nxt(sub_node3);

		sub_node3->itm(3);
		sub_node3->prv(sub_node2);
		sub_node3->nxt(nullptr);

		//Set up the initial state of the list to test
		sub->head = sub_node1;
		sub->tail = sub_node3;
		sub->count = 3;

		assert(l->sub_list(*sub) == true);
		break;
	}
	case 8: {

		//Make some control nodes
		DLList<int>::Node* node1 = new DLList<int>::Node;
		DLList<int>::Node* node2 = new DLList<int>::Node;
		DLList<int>::Node* node3 = new DLList<int>::Node;

		node1->itm(1);
		node1->prv(node2);
		node1->nxt(nullptr);

		node2->itm(2);
		node2->prv(node1);
		node2->nxt(node3);

		node3->itm(3);
		node3->prv(node2);
		node3->nxt(nullptr);

		DLList<int> * l = new DLList<int>;
		l->head = node1;
		l->tail = node3;
		l->count = 3;

		DLList<int>::Node* sub_node1 = new DLList<int>::Node;
		DLList<int>::Node* sub_node2 = new DLList<int>::Node;
		DLList<int>::Node* sub_node3 = new DLList<int>::Node;
		DLList<int>::Node* sub_node4 = new DLList<int>::Node;

		//Assume Constructor Correctly Implemented
		DLList<int> * sub = new DLList<int>;

		sub_node1->itm(1);
		sub_node1->prv(nullptr);
		sub_node1->nxt(sub_node2);

		sub_node2->itm(2);
		sub_node2->prv(sub_node1);
		sub_node2->nxt(sub_node3);

		sub_node3->itm(3);
		sub_node3->prv(sub_node2);
		sub_node3->nxt(sub_node4);

		sub_node4->itm(4);
		sub_node4->prv(sub_node3);
		sub_node4->nxt(nullptr);

		//Set up the initial state of the list to test
		sub->head = sub_node1;
		sub->tail = sub_node4;
		sub->count = 4;

		assert(l->sub_list(*sub) == false);
		break;
	}
	case 9: {

		//Make some control nodes
		DLList<int>::Node* node1 = new DLList<int>::Node;
		DLList<int>::Node* node2 = new DLList<int>::Node;
		DLList<int>::Node* node3 = new DLList<int>::Node;
		DLList<int>::Node* node4 = new DLList<int>::Node;
		DLList<int>::Node* node5 = new DLList<int>::Node;
		DLList<int>::Node* node6 = new DLList<int>::Node;

		node1->itm(1);
		node1->prv(node2);
		node1->nxt(nullptr);

		node2->itm(2);
		node2->prv(node1);
		node2->nxt(node3);

		node3->itm(2);
		node3->prv(node2);
		node3->nxt(node4);

		node4->itm(3);
		node4->prv(node3);
		node4->nxt(node5);

		node5->itm(2);
		node5->prv(node4);
		node5->nxt(node6);

		node6->itm(3);
		node6->prv(node5);
		node6->nxt(nullptr);

		DLList<int> * l = new DLList<int>;
		l->head = node1;
		l->tail = node6;
		l->count = 6;

		DLList<int>::Node* sub_node1 = new DLList<int>::Node;
		DLList<int>::Node* sub_node2 = new DLList<int>::Node;
		DLList<int>::Node* sub_node3 = new DLList<int>::Node;

		//Assume Constructor Correctly Implemented
		DLList<int> * sub = new DLList<int>;

		sub_node1->itm(1);
		sub_node1->prv(nullptr);
		sub_node1->nxt(sub_node2);

		sub_node2->itm(2);
		sub_node2->prv(sub_node1);
		sub_node2->nxt(sub_node3);

		sub_node3->itm(3);
		sub_node3->prv(sub_node2);
		sub_node3->nxt(nullptr);


		//Set up the initial state of the list to test
		sub->head = sub_node1;
		sub->tail = sub_node3;
		sub->count = 3;

		assert(l->sub_list(*sub) == false);
		break;
	}
	case 10: {

		//Make some control nodes
		DLList<int>::Node* node1 = new DLList<int>::Node;
		DLList<int>::Node* node2 = new DLList<int>::Node;
		DLList<int>::Node* node3 = new DLList<int>::Node;
		DLList<int>::Node* node4 = new DLList<int>::Node;
		DLList<int>::Node* node5 = new DLList<int>::Node;
		DLList<int>::Node* node6 = new DLList<int>::Node;

		node1->itm(1);
		node1->prv(nullptr);
		node1->nxt(node2);

		node2->itm(2);
		node2->prv(node1);
		node2->nxt(node3);

		node3->itm(3);
		node3->prv(node2);
		node3->nxt(node4);

		node4->itm(2);
		node4->prv(node3);
		node4->nxt(node5);

		node5->itm(2);
		node5->prv(node4);
		node5->nxt(node6);

		node6->itm(3);
		node6->prv(node5);
		node6->nxt(nullptr);

		DLList<int> * l = new DLList<int>;
		l->head = node1;
		l->tail = node6;
		l->count = 6;

		DLList<int>::Node* sub_node1 = new DLList<int>::Node;
		DLList<int>::Node* sub_node2 = new DLList<int>::Node;
		DLList<int>::Node* sub_node3 = new DLList<int>::Node;

		//Assume Constructor Correctly Implemented
		DLList<int> * sub = new DLList<int>;

		sub_node1->itm(1);
		sub_node1->prv(nullptr);
		sub_node1->nxt(sub_node2);

		sub_node2->itm(2);
		sub_node2->prv(sub_node1);
		sub_node2->nxt(sub_node3);

		sub_node3->itm(3);
		sub_node3->prv(sub_node2);
		sub_node3->nxt(nullptr);


		//Set up the initial state of the list to test
		sub->head = sub_node1;
		sub->tail = sub_node3;
		sub->count = 3;

		assert(l->sub_list(*sub) == true);
		break;
	}
	case 11: {

		//Make some control nodes
		DLList<int>::Node* node1 = new DLList<int>::Node;
		DLList<int>::Node* node2 = new DLList<int>::Node;
		DLList<int>::Node* node3 = new DLList<int>::Node;
		DLList<int>::Node* node4 = new DLList<int>::Node;
		DLList<int>::Node* node5 = new DLList<int>::Node;
		DLList<int>::Node* node6 = new DLList<int>::Node;

		node1->itm(1);
		node1->prv(nullptr);
		node1->nxt(node2);

		node2->itm(2);
		node2->prv(node1);
		node2->nxt(node3);

		node3->itm(1);
		node3->prv(node2);
		node3->nxt(node4);

		node4->itm(2);
		node4->prv(node3);
		node4->nxt(node5);

		node5->itm(3);
		node5->prv(node4);
		node5->nxt(node6);

		node6->itm(3);
		node6->prv(node5);
		node6->nxt(nullptr);

		DLList<int> * l = new DLList<int>;
		l->head = node1;
		l->tail = node6;
		l->count = 6;

		DLList<int>::Node* sub_node1 = new DLList<int>::Node;
		DLList<int>::Node* sub_node2 = new DLList<int>::Node;
		DLList<int>::Node* sub_node3 = new DLList<int>::Node;

		//Assume Constructor Correctly Implemented
		DLList<int> * sub = new DLList<int>;

		sub_node1->itm(1);
		sub_node1->prv(nullptr);
		sub_node1->nxt(sub_node2);

		sub_node2->itm(2);
		sub_node2->prv(sub_node1);
		sub_node2->nxt(sub_node3);

		sub_node3->itm(3);
		sub_node3->prv(sub_node2);
		sub_node3->nxt(nullptr);


		//Set up the initial state of the list to test
		sub->head = sub_node1;
		sub->tail = sub_node3;
		sub->count = 3;

		assert(l->sub_list(*sub) == true);
		break;
	}
	case 12: {

		//Make some control nodes
		DLList<int>::Node* node1 = new DLList<int>::Node;
		DLList<int>::Node* node2 = new DLList<int>::Node;
		DLList<int>::Node* node3 = new DLList<int>::Node;
		DLList<int>::Node* node4 = new DLList<int>::Node;
		DLList<int>::Node* node5 = new DLList<int>::Node;
		DLList<int>::Node* node6 = new DLList<int>::Node;

		node1->itm(1);
		node1->prv(nullptr);
		node1->nxt(node2);

		node2->itm(2);
		node2->prv(node1);
		node2->nxt(node3);

		node3->itm(1);
		node3->prv(node2);
		node3->nxt(node4);

		node4->itm(1);
		node4->prv(node3);
		node4->nxt(node5);

		node5->itm(2);
		node5->prv(node4);
		node5->nxt(node6);

		node6->itm(3);
		node6->prv(node5);
		node6->nxt(nullptr);

		DLList<int> * l = new DLList<int>;
		l->head = node1;
		l->tail = node6;
		l->count = 6;

		DLList<int>::Node* sub_node1 = new DLList<int>::Node;
		DLList<int>::Node* sub_node2 = new DLList<int>::Node;
		DLList<int>::Node* sub_node3 = new DLList<int>::Node;

		//Assume Constructor Correctly Implemented
		DLList<int> * sub = new DLList<int>;

		sub_node1->itm(1);
		sub_node1->prv(nullptr);
		sub_node1->nxt(sub_node2);

		sub_node2->itm(2);
		sub_node2->prv(sub_node1);
		sub_node2->nxt(sub_node3);

		sub_node3->itm(3);
		sub_node3->prv(sub_node2);
		sub_node3->nxt(nullptr);


		//Set up the initial state of the list to test
		sub->head = sub_node1;
		sub->tail = sub_node3;
		sub->count = 3;

		assert(l->sub_list(*sub) == true);
		break;
	}
	default:
		std::cout << __func__ << " No Such Test: " << testNum << std::endl << std::flush;
		return -1;

	}


	return 0;
}

#endif
