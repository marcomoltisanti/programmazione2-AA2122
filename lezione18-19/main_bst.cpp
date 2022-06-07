#include "../adt/bst.h"

int main() {


	BST<int> bst;
	
	bst.insert(10);
	bst.insert(4);
	bst.insert(6);
	bst.insert(12);
	bst.insert(14);
	bst.insert(5);
	bst.insert(18);
	bst.insert(3);
	
	bst.inorder();
	
	std::cout << "MIN & MAX" << std::endl << *(bst.min()) << std::endl;
	std::cout << *(bst.max()) << std::endl;
	
	std::cout << "Test successore" << std::endl;
	
	std::cout << "Il successore di " << *(bst.getRoot()) << " è " << *(bst.successor(bst.getRoot())) << std::endl;
	std::cout << "Il successore di " << *(bst.search(5)) << " è " << *(bst.successor(bst.search(5))) << std::endl;
	
	std::cout << "SEARCH" << std::endl;
	std::cout << "search(18)" << (bst.search(18) ? "found" : "not found") << std::endl;
	std::cout << "search(8)" << (bst.search(8) ? "found" : "not found") << std::endl;
	
	
	
}