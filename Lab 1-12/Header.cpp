#include <iostream>
#include "Header.h"
using namespace std;

//destructor
//ทำลาย node
//for (Node<T>* p; !isEmpty(); )
template<class T>
List<T>::~List() {
	for (Node<T>* p; !NULL; ) {
		p = head->next;
		delete head;
		head = p;
	}
}
template<class T>
void List<T>::headPush(T el) {
	//create newnode tmp
	Node<T>* tmp = new Node<T>(el);
	tmp->info = el;
	//if list is empty
	if (tail == 0) {
		tmp->next = head;
		head = tmp;
		tail = head;
	}
	//else 
	else {
		tmp->next = head;
		head->prev = tmp;
		head = tmp;
	}

}
template<class T>
void List<T>::tailPush(T el) {
	//create newnode tmp
	Node<T>* tmp = new Node<T>(el);
	tmp->info = el;
	tmp->next = NULL;
	//if list is empty
	if (head == NULL ) {
		head = tmp;
		tail = head;

	}
	//else
	else {
		tmp->next = NULL;
		tmp->prev = tail;
		tail->next = tmp;
		tail = tail->next;
	}

}
template<class T>
void List<T>::headPop() {

	//create tmp
	Node<T>* tmp = head;
	//int x;
	//if 1 node
	if (head == tail) {
		//x = head->info;
		head = 0;
		tail = 0;

	}
	//else
	else {
		//x = tmp->info;
		head = head->next;
		head->prev = NULL;
	}

	//return tmp->info;
	delete tmp;
	//return x;

}
template<class T>
void List<T>::tailPop() {

	//create tmp
	Node<T>* tmp = head;
	//int x;
	//if 1 node
	if (head == tail) {
		//x = head->info;
		head = 0;
		tail = 0;

		delete tmp;
		//return x;

	}
	//else
	else {

		tail = tail->prev;
		//x = tail->next->info;
		tail->next = NULL;
		delete tail->next;
		//return x;

	}


}
template<class T>
void List<T>::deleteNode(T el) {
	//create cur and dele
	Node<T>* cur = head;
	Node<T>* dele = head;
	//if el = first node
	if (el == head->info) {
		head = dele->next;
		head->prev = NULL;
		cur = dele->next;
		delete dele;
	}
	//else
	else {

		//for find el in a list
		while (cur->next != NULL) {
			//if we found it

			if (cur->next->info == el) {

				if (cur->next == tail) {
					dele = cur->next;
					cur->next = NULL;
					tail = cur;
					delete dele;
					break;
				}
				else {
					//set dele for prepare to delete
					dele = cur->next;
					//change list
					cur->next = dele->next;
					dele->next->prev = cur;
					//delete
					delete dele;
					break;

				}
			}
			cur = cur->next;
			dele = cur;

		}

	}


}
template<class T>
bool List<T>::isInList(T el) {
	//create cur
	Node<T>* cur = head;
	//loop for find el
	while (cur != NULL) {
		//if we found it return true
		if (cur->info == el) {
			return true;
		}
		cur = cur->next;

	}
	return false;

}
//for display
template<class T>
void List<T>::display() {
	Node<T>* cur = head;
	Node<T>* last = tail;
	while (cur != NULL) {
		cout << cur->info;
		cur = cur->next;
		if (cur != NULL) {
			//cout << " -------> ";
			break;
		}
	}
	
	//check node prev
	/*
	cout << "---invert---";
	while (last != NULL) {
		cout << last->info << " ";
		last = last->prev;
	}
	cout << endl;

	*/
}
//for sort
template<class T>
void List<T>::sort() {
	//create cur
	Node<T>* cur = head;
	int num_element = 0;
	int index_smallest;
	//count num of element
	while (cur != NULL) {
		num_element++;
		cur = cur->next;
	}

	//for loop for check every index
	//check 0,1,2,3,4 not 5 because it doesn't element to compare
	for (int index = 0; index < num_element - 1; index++) {
		//find index smallest
		index_smallest = index_of_smallest(index, num_element);

		//swap it
		swap(index, index_smallest);
	}

}
//for swap
template<class T>
void List<T>::swap(T index, T index_small) {
	//create var1 var2
	Node<T>* var1 = head;
	Node<T>* var2 = head;
	//move var1 to index
	for (int i = 0; i < index; i++) {
		var1 = var1->next;
	}
	//move var2 to index_small
	for (int i = 0; i < index_small; i++) {
		var2 = var2->next;
	}
	//swap it
	int tmp = 0;
	tmp = var1->info;
	var1->info = var2->info;
	var2->info = tmp;

}
//for index small
template<class T>
T List<T>::index_of_smallest(T index, T num_element) {
	//create min, check
	Node<T>* min = head;
	Node<T>* check = head;
	//move min
	for (int i = 0; i < index; i++) {
		min = min->next;
	}
	int indexofmin = 0;
	//find more min
	for (int i = index + 1; i < num_element; i++) {
		//move ptrcheck
		for (int j = 0; j < i; j++) {
			check = check->next;

		}
		//compare min or not
		if (check != NULL && check->info < min->info) {
			min = check;
			check = head;
			indexofmin = i;
		}
		check = head;
	}
	if (indexofmin == 0) {
		indexofmin = index;
	}


	//return indexmin
	return indexofmin;
}
//for unique
template<class T>
void List<T>::unique() {
	//create cur
	Node<T>* cur = head;
	int num_element = 0;
	//create tmp for compare is it has unique?
	int tmp_element = 0;
	//create index for define value to compare
	int index = 0;
	int numofdelete = 0;
	//find numofelement
	while (cur != NULL) {
		num_element++;
		tmp_element = num_element;
		cur = cur->next;
	}
	//main function unique
	while (index < num_element) {
		//find numofdelete and delete it
		numofdelete = num_of_delete(index, num_element);
		unique_delete(index, numofdelete);
		//when finish delete set new varriable
		cur = head;
		num_element = 0;
		//count new numofelement
		while (cur != NULL) {
			num_element++;

			cur = cur->next;
		}
		//compare newelement and oldelement
		//if new < old that we delete some unique and then we must setting new varriable for next check
		if (num_element < tmp_element) {
			index = 0;
			tmp_element = num_element;

		}
		else {
			index++;

		}
	}

}
//for num_of_delete
template<class T>
T List<T>::num_of_delete(T index, T num_element) {
	//create min, same
	Node<T>* min = head;
	Node<T>* same = head;
	//move min 
	for (int i = 0; i < index; i++) {
		min = min->next;
	}
	int numofdelete = 0;
	//find and count same num
	for (int i = index + 1; i < num_element; i++) {
		//cout << "same = " << same->info << endl;
		//move same to check each position
		for (int j = 0; j < i; j++) {
			same = same->next;
			//cout << "x" << endl;

		}
		//if we has same number set numofdelete++
		if (same != NULL && same->info == min->info) {
			numofdelete++;
			//cout << "num" << numofdelete << endl;
			same = head;

		}
		same = head;
	}

	return numofdelete;

}
//for unique delete
template<class T>
void List<T>::unique_delete(T indexofdelete, T num_delete) {
	//create var1
	Node<T>* var1 = head;
	//move var1 to correct position
	for (int i = 0; i < indexofdelete; i++) {
		var1 = var1->next;
	}
	//use funcdelete 
	for (int i = 0; i < num_delete; i++) {
		deleteNode(var1->info);
	}
	cout << "deleted" << endl;

}


