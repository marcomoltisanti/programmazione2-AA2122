#include <iostream>

int fibonacci(int n) {
	if(n == 0 || n == 1)
		return 1;
	return fibonacci(n-1) + fibonacci(n-2);
}


int fibonacci_iterativa(int n) {
	if(n == 0 || n == 1)
		return 1;
	
	//sum_1 rappresenta il valore della sequenza di fibonacci fino alla i-1esima iterazione
	//sum_2 rappresenta il valore della sequenza di fibonacci fino alla i-2esima iterazione
	int sum_1 = 1, sum_2 = 1, x;
	
	for(int i=2; i <= n; i++) {
		x = sum_2;
		sum_2 = sum_1;
		sum_1 = x + sum_2;
	}
	
	return sum_1;
}

int main() {
	std::cout << "ricorsiva" << std::endl;
	int fib2 = fibonacci_iterativa(2000);
	std::cout << "fine ricorsiva" << std::endl;
	std::cout << "iterativa" << std::endl;
	int fib3 = fibonacci(2000);
	std::cout << "fine iterativa" << std::endl;
	int fib10 = fibonacci_iterativa(10);
	
	std::cout << "il secondo fibonacci è " << fib2 << std::endl;
	std::cout << "il terzo fibonacci è " << fib3 << std::endl;
	std::cout << "il decimo fibonacci è " << fib10 << std::endl;
	
	
}