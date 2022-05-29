#include <iostream>

using namespace std;

class Base {
	public:
	int n = 0;
};

class Der1 : virtual public Base {};
class Der2 : public virtual Base {};
class Der3 : public Base {};

class Multipla : Der1, Der2, Der3 {
	public:
	Multipla() {
		Der1::n = 1;
		Der2::n = 2;
		Der3::n = 3;
		
		cout << Der1::n << Der2::n <<  Der3::n << endl;
	}
};

/*

class A {
	public:
		A() { cout << "costruttore di A" << endl; }
		virtual void stampa() = 0;
};

class B : virtual public A{
	public:
		B() { cout << "costruttore di B" << endl; }
		void stampa() { cout << "sono la classe B" << endl; }
};

class C : virtual public A{
	public:
		C() { cout << "costruttore di C" << endl; }
		void stampa() { cout << "sono la classe C" << endl; }
};

class D : public B, public C {
	public:
		D() { cout << "costruttore di D" << endl; }
};
*/
int main() {
	Multipla m;
	
	//D d;
}