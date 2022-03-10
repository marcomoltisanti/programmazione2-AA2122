#include <iostream>

int main() {
	
	int array1[100];
	int array2[] = { 11, 12, 13, 14 };
	std::cout << sizeof(array1) << std::endl;
	std::cout << sizeof(array2) << std::endl;
	
	int n_array2 = sizeof(array2)/sizeof(int);
	
	std::cout << "La dimensione di array2 è: " << n_array2 << std::endl;
	
	for(int i=0; i < 100; i++) {
		array1[i] = i;
		std::cout << "\t" << array1[i] << std::endl;
	}
	
	for(int i=0; i < n_array2; i++) {
		std::cout << "\t" << array2[i] << std::endl; 
	}
	
	int* array3 = new int[100];
	
	std::cout << sizeof(*array3) * 100 << std::endl;
	
	
	for(int i=0; i < 100; i++) {
		array3[i] = i;
		std::cout << "\t" << array3[i] << std::endl;
	}
	
	delete [] array3; 	
}