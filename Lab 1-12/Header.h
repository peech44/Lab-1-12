#pragma once
#ifndef LIST
#define LIST

template<class T>
class Node {
public:
	T info;
	Node<T>* next, * prev;
	Node<T>() { next = prev = 0; }
	Node<T>(T el, Node<T>* n = 0, Node<T>* p = 0) { info = el; next = n; prev = p; }
};

template<class T>
class List {
public:
	List() { head = tail = 0; }
	~List();
	T isEmpty() { return head == 0; }
	void headPush(T); //Add element to front of list
	void tailPush(T); //Add element to tail of list
	void headPop(); //Remove and return element from front of list
	void tailPop(); //Remove and return element from tail of list
	void deleteNode(T); //Delete a particular value
	bool isInList(T); //Check if a particular value is in the list
	void sort();// sort linked list
	void swap(T, T); // swap data
	T index_of_smallest(T, T); //return index small
	void unique(); //unique a number
	T num_of_delete(T, T); //return number for delete
	void unique_delete(T, T); //delete same number

	void display();     //display

private:
	Node<T>* head, * tail;
};





#endif //LIST