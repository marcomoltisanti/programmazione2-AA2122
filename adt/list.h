#ifndef LIST_H
#define LIST_H

#include <iostream>
#include "node.h"

using namespace std;

template <typename T>
class List {
	Node<T>* head;
	
	public:
	
	List() {
		head = nullptr;
	}
	
	bool isEmpty() {
		return head == nullptr;
	}
	
	Node<T> *getHead() const { return head; }
	
	void insert(T val) {
		if(this->isEmpty()) {
			head = new Node<T>(val);
			return;
		}
	}
	
	void insertHead(T val) {	
		Node<T> *temp = new Node<T>(val);
		temp->next = head;
		this->head = temp;
	}
	
	void insertTail(T val) {
		if(this->isEmpty()) {
			this->insertHead(val);
			return;
		}
		
		Node<T> * ptr = head;
		while(ptr->getNext() != nullptr) {
			ptr = ptr->getNext();
		}
		
		Node<T> * temp = new Node<T>(val);
		ptr->next = temp;		
	}
	
	void insertInOrder(T val) {
		
		if(this->isEmpty()) {
			this->insertHead(val);
			return;
		}
		if(val <= head->val) {
			this->insertHead(val);
			return;
		}
		
		Node<T> *ptr = head;
		while(ptr->getNext() && (val >= ptr->val)) {
			
			if(val <= ptr->next->val)
				break;
			
			ptr = ptr->getNext();
		}
		
		if(!(ptr->next)) {
			this->insertTail(val);
			return;
		}
		
		Node<T> *toInsert = new Node<T>(val);
		toInsert->next = ptr->next;
		ptr->next = toInsert;
			
	}
	
	friend ostream& operator<<(ostream& out, const List<T> &list) {
		out << "List head=" << list.head << endl;
		Node<T> *ptr = list.head;
		while(ptr != nullptr) {
			out << "\t" << *ptr << endl;
			ptr = ptr->getNext();
		}
		
		return out;
		
	}
};

#endif