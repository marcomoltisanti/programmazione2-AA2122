// Array 02: Passaggio di array come parametro (meglio di array_passaggio)
// e uso di riferimento per inizializzazione

/*ESERCIZIO:
Scrivere un programma che sfrutta un metodo ‘leggiElementi()’ per inizializzare un array 
di double di dimensione non nota, chiedendo all’utente di inserire un valore per volta fino 
a quando non viene inserito il valore zero. Successivamente, stampare gli elementi mediante 
un altro metodo ‘stampaElementi()’
*/

#include <iostream>

#define MAX_N 100

using namespace std;

void leggiElementi(double v[], int num) {
	//consentire all'utente di inserire gli elementi desiderati all'interno dell'array va_arg
	//devo tenere traccia di quanti elementi vengono inseriti
	
	cout << "indirizzo della variabile num in leggiElementi = " << &num << endl;
	
	num = 0;
	double temp;
	
	for(int i=0; i < MAX_N; i++) {
		cout << "Inserire un elemento. Inserire 0 per terminare l'inserimento: ";
		cin >> temp;
		if(temp == 0)
			break;
		else {
			v[i] = temp;
			num++;
		}
	}
}

void stampaElementi(double v[], int num) {
	for(int i =0; i < num; i++) {
		cout << "Elemento " << i <<"-esimo = " << v[i] << endl;
	}
	cout << endl;
}

int main() {
	
	double array[MAX_N];
	int num;
	cout << "indirizzo della variabile num nel main = " << &num << endl;
	leggiElementi(array, num);
	stampaElementi(array, num);
	
	cout << array[67] << endl;
}