/* Wordlist source file
*
*	This file will contain the function definitions you will implement.
*	The function signitures may NOT be changed.  You may create your own
*	helper functions and include them in this file.
*
*	In addition to the specific instructions for each function, no function
*	should cause any memory leaks or alias list in any way that would result
*	in undefined behavior.
*
*	Topics: Multilevel Pointers, Dynamic Allocation, Classes
*
*/
// MS VS does not like cstring functions, this is to tell it to chill out.
#ifdef _MSC_VER  //  Microsoft Visual C++

#define _CRT_SECURE_NO_DEPRECATE

#else  // not Microsoft Visual C++, so assume UNIX interface

#endif
#define WORDLIST_H

#ifdef ONLINE_HELP
#define CLASS_PROJECT
#include"self_sabotage.h"
#else
// Do not include any other libraries
#include"wordlist.h"
#include "debugmem.h"
#include<iostream>
#include<cstring>
using std::cout;
using std::endl;
using std::strcat;
using std::strcmp;
using std::strcpy;
using std::strlen;
#endif

// Function:  resize
int Wordlist::resize(int amt) {

	// --- TODO --- 

	if (amt > 0) {
		allocated += amt;
		char** tempList = list;
		list = DEBUG_NEW char*[allocated];
		for (int i = 0; i < allocated-amt; i++) {
			list[i] = tempList[i];
		}

		delete tempList;
		return 1;
	}
	else {
		for (int i = allocated - 1; i > allocated - amt; i++) {
			if (list[i][0] != '\0') {
				return -1;
			}
			
		}
	}
	allocated += amt;

	return 1;

}

// Function: Wordlist Constructor
Wordlist::Wordlist(const int cap) {

	// --- TODO --- 
	size = 0;
	allocated = cap;
	list = DEBUG_NEW char* [allocated];
	char c[] = "";// Make each an empty string
	for (int i = 0; i < allocated; i++) {
		char* a = DEBUG_NEW char[20];
		strcpy(a, c);
		list[i] = a;
	}
	if (list[0][0] == '\0') {
		cout << "HIHIHIaldjklajfklsd" << endl;
	}
	cout << list[0] << endl;

	GETMEMORYREPORT();

}

// Function: Wordlist Copy Constructor
Wordlist::Wordlist(const Wordlist& other) {
	cout << "COPY CONSTRUCTOR" << endl;
	// --- TODO --- 
	size = other.size;
	allocated = other.allocated;
	list = DEBUG_NEW char*[allocated];

	for (int i = 0; i < allocated; i++) {
		//cout << "HIHIHI" << endl;
		char* a = DEBUG_NEW char[20];
		strcpy(a, other.list[i]);
		list[i] = a;
	}

	GETMEMORYREPORT();
}

// Funtion: Assignment Operator
Wordlist& Wordlist::operator=(const Wordlist& other) {
	cout << "ASSIGNMENT OPERATOR" << endl;
	// --- TODO --- 
	return *this;

}

// Function: Wordlist Destructor.
Wordlist::~Wordlist() {

	// --- TODO --- 
	cout << "DESTRUCTOR" << endl;
	cout << allocated << endl;

	for (int i = 0; i < allocated; i++) {
		cout << "I AM RUNNING" << endl;
		//cout << &list[i] << endl;
		cout << i << endl;
		delete list[i];
	}

	//cout << list[0];

	delete list;

	GETMEMORYREPORT();

}

// Function: display
int	Wordlist::display() const {

	// --- TODO --- 
	for (int i = 0; i < size; i++) {
		cout << list[i] << " ";
	}
	cout << endl;
	return size;

}

// Function: at
const char* Wordlist::at(const int index) const {

	// --- TODO --- 
	if (index < allocated-1 && !(index < 0)) {
		return list[index];
	}
	return nullptr;

}

// Function: stored
int	Wordlist::stored() const {

	// --- TODO --- 
	return size;
}

// Function: space
int	Wordlist::space() const {

	// --- TODO --- 
	int space = allocated - size;
	return space;

}

// Function: insert
int	Wordlist::insert(const int index, const char word[]) {
	cout << "INSERT FUNCTION" << endl;
	bool changeSize = false;

	if (word[0] == '\0') {
		return 0;
	}

	// --- TODO --- 
	if (size + 1 > allocated) {
		resize(1);
		changeSize = true;
		return 0;
	}
	char* a = DEBUG_NEW char[20];

	strcpy(a, word);

	if (index < 0) {
		cout << "I AM LESS THAN THIS";
		char* temp2 = list[0];
		size++;
		for (int i = 0; i < size; i++) {
			temp2 = list[i];
			list[i] = a;
			a = temp2;
		}

		delete a;

		cout << "I HAVE SUCCEEDED I THINK" << endl;

		for (int i = 0; i < size; i++) {
			cout << list[i] << endl;
		}
		return 2;

	}

	if (index == 0 && list[0][0] == '\0') {
		delete list[0];
		list[0] = a;
		size++;
		return 2;
	}
	else {
		if (list[index][0] != '\0') {
			int x = index + 1;

			while (list[x][0] != '\0') {
				x++;
			}

			delete list[x];
			list[x] = a;

			cout << &list[x] << endl;
			size++;
			return 2;
		}
		else {
			delete list[index];
			list[index] = a;
		}
	}

	if (changeSize) {
		return 3;
	}
	GETMEMORYREPORT();

	return 0;

}

// Funtion: erase
int	Wordlist::erase(const char word[]) {

	// --- TODO --- 
	if (list == nullptr) {
		return -3;
	}
	else {
		for (int i = 0; i < size; i++) {
			if (word == list[i]) {
				
			}
		}
	}

	int dummyreturnval = -9000;
	return dummyreturnval;

}

// Function: interleave
int	Wordlist::interleave(const Wordlist& other) {

	return 0;
}

// Function: search
int Wordlist::search(const char word[]) const {

	// --- TODO --- 
	int dummyreturnval = -9000;
	return dummyreturnval;

}

// Funtion: sort
int	Wordlist::sort(const int mode) {

	// --- TODO --- 
	int dummyreturnval = -9000;
	return dummyreturnval;

}
// Funtion: yoink
int	Wordlist::yoink(const char word[], Wordlist& other) {

	// --- TODO --- 
	int dummyreturnval = -9000;
	return dummyreturnval;

}
