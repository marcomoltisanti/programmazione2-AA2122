#include <iostream>

using namespace std;
class A {
	private:
		void private_fun() { cout << "funzione private di A" << endl; }
		virtual void private_virtual_fun() { cout << "funzione private virtual di A" << endl; }
	protected:
	int n = 0;
	
	public:
		A() { std::cout << "costruttore di A" << std::endl; }
		virtual void stampa() {  cout << "sono la classe A, n=" << n << endl; }
		virtual void incrementa() {  n++; }
		int getN() { cout << "return " << n << endl; return n;}
		void call_private() { 
			private_fun(); 
		}
		
		void call_private_virtual() {
			private_virtual_fun();
		}
};

class B : public A {
	public:
	B() { cout << "costruttore di B" << endl; }
	void stampa() {  cout << "sono la classe B, n=" << n << endl; }
	int getN() { cout << "return -1" << endl; return -1; }
	void private_virtual_fun() override { cout << "funzione private virtual di B" << endl;}
	
};


int main() {
	cout << "oggetto di classe A" << endl;
	A a;
	a.stampa();
	a.incrementa();
	a.getN();

	cout << "oggetto di classe B" << endl;
	B b;
	b.stampa();
	b.incrementa();
	b.getN();
	
	cout << "assegno sia &a che &b ad un puntatore a un oggetto di classe A" << endl; 
	
	A *pa = &a;
	A *pb = &b;
	
	pa->stampa();
	pb->stampa();
	//non essendo virtual, quando assegno il puntatore alla classe A viene chiamato il metodo di A
	pa->getN();
	pb->getN();
	
	cout << "assegno sia &a che &b ad un riferimento a un oggetto di classe A" << endl; 
	
	A& ra = a;
	A& rb = b;
	
	ra.stampa();
	rb.stampa();
	ra.getN();
	rb.getN();
	
	pb->call_private();
	pb->call_private_virtual();
}
