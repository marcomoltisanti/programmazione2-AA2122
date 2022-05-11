#ifndef DL_NODE
#define DL_NODE

#include <iostream>

template <typename T>
class DLNode {
	T val;
	DLNode<T> *next;
	DLNode<T> *prev;
	
	template <typename U>
	friend class DLList;
	
	public:
	
	DLNode(T val) : val(val), next(nullptr), prev(nullptr) {}
	
	DLNode<T>* getNext() const { return this->next; }
	DLNode<T>* getPrev() const { return this->prev; }
	
	
	friend std::ostream& operator<<(std::ostream& out, const DLNode<T> &node) {
		out << "dlnode@" << &node << " val=" << node.val << " - next=" << node.next << " - prev=" << node.prev;
		return out;
	}
};

#endif