#include <iostream>
#include "list.h"

int main() {
	
	List<int> lista;
	List<int> listaNonOrdinata;
	
	lista.insertInOrder(10);
	listaNonOrdinata.insertHead(10);
	//std::cout << *lista.getHead() << std::endl;
	lista.insertInOrder(4);	
	listaNonOrdinata.insertHead(4);
	//std::cout << *lista.getHead() << std::endl;
	lista.insertInOrder(-19);
	listaNonOrdinata.insertHead(-19);
	//std::cout << *lista.getHead() << std::endl;
	
	lista.insertInOrder(22);
	listaNonOrdinata.insertHead(22);
	
	std::cout << lista << std::endl;
	std::cout << listaNonOrdinata << std::endl;
	
}