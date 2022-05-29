#ifndef QUEUE_H
#define QUEUE_H

#include "dllist.h"
#include <iostream>

template<typename T>
class Queue : protected DLList<T> {
	protected:
	int size = 0;
	
	public:
	
	Queue() : DLList<T>() {}
	
	void enqueue(T val) {
		DLList<T>::insertTail(val);
		size++;
	}
	
	DLNode<T> dequeue() {
		
		if(isEmpty())
			return 0;
		
		DLNode<T> ptr = *(DLList<T>::head);
		DLList<T>::removeHead();
		size--;
		return ptr;
	}
	
	bool isEmpty() {
		return size == 0;
	}
	
	friend std::ostream& operator<<(std::ostream& out, Queue<T>& queue) {
		out << "Queue starting at " << &(queue.head);
		DLNode<T> *ptr = queue.head;
		while(ptr) {
			out << *ptr << std::endl;
			ptr = ptr->getNext();
		}
		return out;
	}
};

#endif