#include "user.h"
#include "sorting.h"

#include <fstream>
#define MAX_N 2000

int main(int argc, char* argv[]) {
	
	int n;
	std::string alg = "quicksort";
	if(argc == 1)
		n = MAX_N;
	else if(argc == 2)
		n = std::atoi(argv[1]);
	else if(argc == 3) {
		n = std::atoi(argv[1]);
		alg = std::string(argv[2]);
		if(!(alg == "quicksort" || alg == "insertion" || alg == "all")) {
			std::cout << "./sorting [N_ELEM [(quicksort|insertion|all)]]" << std::endl;
			exit(-1);
		}			
	}	
	
	std::ifstream ifs("utenti.txt", std::ifstream::in);
	
	User *users = new User[n];
	unsigned int count = 0;
	while(ifs.good() && count < n) {
		User u;
		ifs >> u; 
		users[count++] = u;		
		std::cout << u << std::endl;
	}
	
	ifs.close();
			
	if(alg == "quicksort" || alg == "all") {
		User* temp = new User[n];
		for(int i=0; i < n; i++)
			temp[i] = users[i];
		sorting::n_comparisons = 0;
		sorting::n_swaps = 0;
		sorting::quicksort(temp, 0, n-1);
		
		/* Decommenta questo blocco per stampare l'array ordinato
		for(int i=0; i < n; i++) {
			std::cout << "\t" << temp[i] << std::endl;
		}
		*/
		
		std::cout << "It took " << sorting::n_swaps << " swaps to sort " << n << " elements of the array using quicksort" << std::endl;
		std::cout << "It took " << sorting::n_comparisons << " comparisons to sort " << n << " elements of the array using quicksort"<< std::endl;
				
		delete [] temp;
		
	}
	if(alg == "insertion" || alg == "all") {
		User* temp = new User[n];
		for(int i=0; i < n; i++)
			temp[i] = users[i];
	
		sorting::insertionSort(temp, n);
		
		/* Decommenta questo blocco per stampare l'array ordinato
		for(int i=0; i < n; i++) {
			std::cout << "\t" << temp[i] << std::endl;
		}
		*/
		
		std::cout << "It took " << sorting::n_swaps << " swaps to sort " << n << " elements of the array using insertionsort" << std::endl;
		std::cout << "It took " << sorting::n_comparisons << " comparisons to sort " << n << " elements of the array using insertionsort" << std::endl;
		
		delete [] temp;
	}	
	
	delete [] users;
}