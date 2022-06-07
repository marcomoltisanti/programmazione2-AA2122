#ifndef BST_H
#define BST_H

#include "bst_node.h"
#include <iostream>

template<typename T>
class BST {
	BSTNode<T>* root;
	
	public:
	
	BST() {
		root = nullptr;
	}
	
	bool isEmpty() {
		return root == nullptr;
	}
	
	BSTNode<T>* getRoot() {
		return this->root;
	}
	
	void insert(T key) {
		if(this->isEmpty()) {
			root = new BSTNode<T>(key);
			return;
		}
		insert(root, key);
	}
	
	//la mia procedura ricorsiva deve avere due parametri:
	//il valore da inserire e la radice del sottoalbero 
	
	void insert(BSTNode<T>* ptr, T key) {
		if(ptr->left == nullptr && key <= ptr->key) {
			ptr->left = new BSTNode<T>(key);
			ptr->left->setParent(ptr);
			return;
		}
		if(ptr->right == nullptr && key > ptr->key) {
			ptr->right = new BSTNode<T>(key);
			ptr->right->parent = ptr;
			return;
		}
		else if(key <= ptr->key)
			insert(ptr->left, key);
		else
			insert(ptr->right, key);
	}
	
	void visit(BSTNode<T>* node) {
		std::cout << *node << std::endl;
	}
	
	void inorder(BSTNode<T>* ptr) {
		if(ptr == nullptr)
			return;
		
		inorder(ptr->left);
		visit(ptr);
		inorder(ptr->right);
	}
	
	void inorder() {
		inorder(root);
	}
	
	//IMPLEMENTARE PREORDER E POSTORDER
	
	BSTNode<T>* min() {
		return min(root);
	}
	
	BSTNode<T>* min(BSTNode<T>* from) {
		if(isEmpty()) {
			return NULL;
		}
		
		BSTNode<T>* ptr = from;
		while(ptr->left) {
			ptr = ptr->left;
		}
		
		return ptr;
	}
	
	BSTNode<T>* max() {
		return max(root);
	}
	
	BSTNode<T>* max(BSTNode<T>* from) {
		if(isEmpty()) {
			return NULL;
		}
		
		BSTNode<T>* ptr = from;
		while(ptr->right) {
			ptr = ptr->right;
		}
		
		return ptr;
	}
	
	BSTNode<T>* successor(BSTNode<T>* x) {
		if(this->isEmpty()) {
			return nullptr;
		}
		
		// 1. x ha un sottoalbero destro
		
		if(x->right) 
			return this->min(x->right);
		
		// 2. x non ha un sottoalbero destro
		// il successore di x è l'antenato più prossimo di x
		// il cui figlio sinistro è anche un antenato di x
		
		BSTNode<T>* y = x->parent;
		
		while(x != nullptr && x == y->right) {
			x = y;
			y = y->parent;
		}
		
		return y;
		
	}
	
	BSTNode<T>* search(T key) {
		return search(root, key);
	}
	
	BSTNode<T>* search(BSTNode<T>* ptr, T key) {
		if(ptr == nullptr) 
			return nullptr;
		if(ptr->key == key)
			return ptr;
		
		if(key <= ptr->key)
			return search(ptr->left, key);
		else
			return search(ptr->right, key);
		
		return nullptr;
	}
	
	
};
#endif