#include <iostream>

//binarySearch
//supponiamo che l'array sia già ordinato
bool ricercaBinaria(int array[], int n, int key) {
	bool found = false;
	
	//n/2 = (n-0)/2
	//int midpoint = n/2; //floor(n/2)
	int start = 0;
	int end = n;
	
	while(!found && (start != end)) {
			
		int midpoint = start + ((end-start)/2); // (start+end)/2
		
		std::cout << "start = " << start << ", end = " << end << ", midpoint = " << midpoint << std::endl;
		if(array[midpoint] == key) 
			found = true;
		else if(key < array[midpoint]) {
			//considerare la metà inferiore
			//aggiornare end e midpoint
			end = midpoint;
			//midpoint = (end-start)/2;
		}
		else {
			//considerare la metà superiore
			//aggiornare start e midpoint
			start=midpoint+1;
			//midpoint = (end-start)/2;
		}
		
		
	}
	//verificare ad ogni iterazione se key >= array[n/2]
	
	return found;
}


int main() {
	
	int array[] = {1,2,3,4,5,7,8,9,10,11};
	
	bool found = ricercaBinaria(array, 10, 4);
	
	std::cout << found << std::endl;
}