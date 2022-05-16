#include "stack.h"
#include <iostream>


int main() {
	
	Stack<int> s;
	
	s.push(10);
	s.push(11);
	s.push(12);
	s.push(13);
	s.push(14);
	
	std::cout << s << std::endl;
	
	s.pop();
	s.pop();
	
	std::cout << s << std::endl;
	
	Node<int> *top = s.top();
	std::cout << *top << std::endl;
	
	
	
}