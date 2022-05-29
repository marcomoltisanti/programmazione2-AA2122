#include <iostream>
#include "list.h"

int main() {
	
	List<int> lista;
	
	lista.insertHead(10);
	std::cout << *lista.getHead() << std::endl;
	lista.insertHead(4);	
	std::cout << *lista.getHead() << std::endl;
	lista.insertHead(-19);
	std::cout << *lista.getHead() << std::endl;
	
	lista.insertTail(22);
	
	std::cout << lista << std::endl;
	
}