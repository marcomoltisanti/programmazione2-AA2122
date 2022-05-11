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
	
	void removeHead() {
		if(this->isEmpty()) {
			cout << "Empty list!" << endl;
			return;
		}
		
		Node<T> *temp = head;
		head = head->next;
		
		delete temp;
	}
	
	void removeTail() {
		if(this->isEmpty()) {
			cout << "Empty list!" << endl;
			return;
		}
		
		Node<T> *cur = head;
		Node<T> *prev = nullptr;
		while(cur->next) {
			prev = cur;
			cur = cur->next;			
		}
		
		prev->next = nullptr;
		delete cur;
	}
	
	void remove(T val) {
		
		if(this->isEmpty()) {
			cout << "Empty list!" << endl;
			return;
		}
		
		if(head->val == val) {
			this->removeHead();
			return;
		}
		
		Node<T> *cur = head;
		Node<T> *prev = nullptr;
		while(cur->next && cur->val != val) {
			prev = cur;
			cur = cur->next;
		}
		
		if(!(cur->next) && cur->val != val) {
			cout << "Element with value " << val << "not found" << endl;
			return;
		}
		
		prev->next = cur->next;
		delete cur;
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