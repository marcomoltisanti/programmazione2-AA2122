#include <iostream>

using namespace std;
template<typename T> void swap(T var1, T var2) {
	cout << "swap " << var1 << " and " << var2 << endl; 
	T temp = var1;
	var1 = var2;
	var2 = temp;
}

template <typename T> 
class A {
	public:
	T attributo;
}


template <class tipo_dato, int lunghezza>
class MyArray {
	tipo_dato *array;
	int lunghezza;
	public:
	MyArray() { array = new [lunghezza]; }
}

MyArray<int, 10> a;
MyArray<int, 20> b;
MyArray<double, 10> c;
MyArray<double, 10> d;

a == b --> false

int main() {
	swap(3,4);
	swap<char>('a','b');
	swap(3.1, 2.3);
	swap<int>(4,5);
}


class A {
	private:
	
	int n = 10;
	friend void set_member(A& a, int val) {
		a.n = val;
	}
	
	public:
	void set_n(int val) {
		n = val;
	}
};