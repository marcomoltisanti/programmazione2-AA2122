#ifndef LNODE_H
#define LNODE_H

#include <iostream>

using namespace std;

template <typename T>
class Node {
	T val;
	Node<T>* next;
	
	template<typename U>
	friend class List;
	
	public:
	
	Node(T val) : val(val) {
		next = nullptr;
	}
	
	Node<T>* getNext() const { return this->next; }
	
	friend ostream& operator<<(ostream& out, const Node<T> &node) {
		out << "node@" << &node << " val=" << node.val << " - next=" << node.next;
		return out;
	}
};

#endif