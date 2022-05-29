#include <iostream>

using namespace std;

class A {
	
	int a = 0;

	public:
		static int b;
		
		A() {
			b++;
		}
		
		void print() {
			cout << "a=" << a << ", b=" << b << ", address(a)=" << &a << ", address(b)=" << &b << endl;
		}
};

int A::b = 0;

int main() {
	
	A a1;
	a1.print();
	A a2;
	a2.print();
	
	A a3;	
	a3.print();
}