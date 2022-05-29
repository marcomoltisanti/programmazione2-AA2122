#include <iostream>

class Y {};

class A {
    int data; // private data member
    class B { }; // private nested type
	public:
    enum { a = 100 }; // private enumerator
    friend class X; // friend class forward declaration (elaborated class specifier)
    friend Y; // friend class declaration (simple type specifier) (since c++11)
};
 
class X : A::B { // OK: A::B accessible to friend
    A::B mx; // OK: A::B accessible to member of friend
    class Y {
        A::B my; // OK: A::B accessible to nested member of friend
    };
    int v[A::a]; // OK: A::a accessible to member of friend
	
	public:
		X() {A::a = 22; std::cout << A::a << std::endl;}
};

int main() {
	A::a
}