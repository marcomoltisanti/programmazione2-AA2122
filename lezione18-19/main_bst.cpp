#include "../adt/bst.h"

int main() {


	BST<int> bst;
	
	try {
		bst.max();
	}
	catch (const char* ex) {
		std::cout << ex << std::endl;
	}
	
	bst.insert(40);
	bst.insert(25);
	bst.insert(21);
	bst.insert(18);
	bst.insert(57);
	bst.insert(36);
	bst.insert(46);
	bst.insert(32);
	bst.insert(78);
	bst.insert(52);
	bst.insert(11);
	bst.insert(44);
	
	bst.inorder();
	
	std::cout << "MIN & MAX" << std::endl << *(bst.min()) << std::endl;
	std::cout << *(bst.max()) << std::endl;
	
	std::cout << "Test successore" << std::endl;
	
	std::cout << "Il successore di " << *(bst.getRoot()) << " è " << *(bst.successor(bst.getRoot())) << std::endl;
	std::cout << "Il successore di " << *(bst.search(40)) << " è " << *(bst.successor(bst.search(21))) << std::endl;
	
	std::cout << "SEARCH" << std::endl;
	std::cout << "search(18)" << (bst.search(18) ? "found" : "not found") << std::endl;
	std::cout << "search(8)" << (bst.search(8) ? "found" : "not found") << std::endl;
	
	std::cout << "Cancellazione 11" << std::endl;
	BSTNode<int>* cancellato1 = bst.remove(11);
	bst.inorder();
	
	std::cout << "Cancellazione 21" << std::endl;
	BSTNode<int>* cancellato2 = bst.remove(21);
	bst.inorder();
	
	std::cout << "Cancellazione 40" << std::endl;
	BSTNode<int>* cancellato3 = bst.remove(40);
	bst.inorder();
}