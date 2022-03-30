#include "sorting.h"

int main() {
	
	int array[] = {2,5, 10, 200, 23, 87, 3, 8, 6, 22, 19, 42};
	int n = sizeof(array)/sizeof(int);
	printArray(array, n);
	
	//selectionSort(array, n);
	insertionSort(array, n);
	printArray(array, n);
	
}
