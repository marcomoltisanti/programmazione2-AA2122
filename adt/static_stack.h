#ifndef STATIC_STACK_H
#define STATIC_STACK_H

#include <iostream>

template<typename T>
class StaticStack {
	T* array;
	int top = -1;
	int size = 0;
	int maxSize = -1;
	
	public:
		StaticStack(int _maxSize) : maxSize(_maxSize) {
			array = new T[maxSize];
		}
		
		T getTop() {
			if(isEmpty()) 
				return -1;
			
			return array[top];
		}
		
		void push(T val) {
			if(top == maxSize-1)
				return;
			
			array[++top] = val;
		}
		
		T pop() {
			if(isEmpty()) 
				return -1;
			
			return array[top--];
		}
		
		bool isEmpty() {
			return top == -1;
		}
		
		friend std::ostream& operator<<(std::ostream& out, StaticStack<T>& s) {
			out << "Static Stack: maxSize= " << s.maxSize << std::endl;
			out << "-----" << std::endl;
			for(int i=s.top; i >= 0; i--)
				out << s.array[i] << " - ";
			out << std::endl;
			
			return out;
		}
};

#endif