#include <iostream>

int fattoriale(int n) {
	if(n == 0)
		return 1;
	return n*fattoriale(n-1);
}

int main() {
	
	int fatt2 = fattoriale(2);
	int fatt3 = fattoriale(3);
	int fatt10 = fattoriale(10);
	
	std::cout << "il fattoriale di 2 è " << fatt2 << std::endl;
	std::cout << "il fattoriale di 3 è " << fatt3 << std::endl;
	std::cout << "il fattoriale di 10 è " << fatt10 << std::endl;
	
	
}