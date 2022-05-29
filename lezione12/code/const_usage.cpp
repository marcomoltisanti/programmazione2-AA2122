#include <iostream>

using namespace std;

const int a = 1002; //il valore assegnato alla variabile a è immutabile


const int fun(const int a) {
	return a * 2;
}


int main() {
	//a = 10; //ERRORE: a è una variabile di sola lettura
	
	int b = 10;
	
	const int* c;
	c = &b; //PUNTATORE A VALORE COSTANTE
	b = 20;
	//*c = 30;
	
	int* const d = &b; //PUNTATORE COSTANTE A VALORE
	int x = 99;
	
	
	const int* const e = &x;
	
	//*e = 18;
	//e = &b;
	
	cout << b << ", " << *c << endl;
	cout << b << ", " << *d << endl;
	
	const int y = fun(b);
	
	y = 12;
	
}

