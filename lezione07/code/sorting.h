#include <iostream>

void swap(int &a, int &b) {
	int temp = a;
	a = b;
	b = temp;
}

void selectionSort(int array[], int n) {
	int indexMin;
	
	for(int i=0; i < n; i++) {
		indexMin = i;
		for(int j=i+1; j < n; j++) {
			if(array[j] < array[indexMin])
				indexMin = j;
		}
		
		swap(array[i], array[indexMin]);
	}
}

void insertionSort(int array[], int n) {
	int temp, j;
	
	for(int i=1; i < n; i++) {
		temp = array[i];
		for(j=i; j > 0; j--) {
			if(temp < array[j-1])
				array[j] = array[j-1];
			else 
				break;
		}
		array[j] = temp;
	}
}

void printArray(int array[], int n) {
	
	for(int i=0; i < n; i++) {
		std::cout << array[i] << "\t";
	}
	std::cout << std::endl;
}