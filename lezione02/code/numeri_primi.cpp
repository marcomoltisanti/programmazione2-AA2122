// Esercizio: definire un metodo che stampa i numeri primi fino ad n
/*
Vengono presentati 3 metodi:

1) dato num in [2, n] cerco un suo divisore in [2, num/2] se non lo trovo allora num e' primo;
2) dato num in [2, n] cerco un suo divisore in [2, sqrt(num)] se non lo trovo allora num e' primo;
3) Crivello di Eratostene o metodo del setaccio (2 implementazioni):
    per ogni num in [2, n] elimino i suoi multipli, quelli che rimangono sono primi.
	
*/

#include <iostream>

void numeriprimi_1(int primes[], int &count, int n) {
	
	count = 0;
	
	for(int i=2; i <= n; i++) {
		bool is_prime = true;
	
		for(int j=2; j <= i/2; j++) {
			if(i % j == 0) {
				is_prime = false;
				break;
			}
		}
		
		if(is_prime)  {
			
			primes[count++] = i;
			std::cout << i << " is prime" << std::endl;
		}
	}
}

void numeri_primi_2(int primes[], int &count, int n) {
	count = 0;
	
	for(int i=2; i <= n; i++) {
		bool is_prime = true;
	
		for(int j=2; j <= sqrt(i); j++) {
			if(i % j == 0) {
				is_prime = false;
				break;
			}
		}
		
		if(is_prime)  {
			
			primes[count++] = i;
			std::cout << i << " is prime" << std::endl;
		}
	}
}

void eratostene(int* vec,int n) {

  	int i,j;
 	for(i=2; i<=n; i++)
        //se v[i] non e' zero allora e' stato escluso
        // perche' multiplo di un altro
		if(vec[i]==0)
            // questo ciclo e' O(n/i)
            //elenco tutti i multipli di 'i' minori di n e li escludo (se esistono)
            for(j=2*i; j<=n; j+=i) // j=2*i, 3*i, 4*i,...
            //imposto v[j] a 1, cioè escludo i suoi multipli
                vec[j]=1;

    // Stampo
    for(i=2; i<=n; i++)
        if(vec[i]==0 && PRINT) //se il numero è primo
        printf("%d\t",i);   //stampo i risultati
}


int main() {
	
	int primes[100];
	int count;
	numeriprimi_1(primes, count, 7);
	std::cout << "There are " << count << " prime numbers less than 100" << std::endl;
	for(int i=0; i < count; i++)
		std::cout << primes[i] << " ";
	std::cout << std::endl;
	
}