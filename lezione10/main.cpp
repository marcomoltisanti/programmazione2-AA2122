#include "studente.h"

void fun() {
	Studente s1;
	Studente s2("A", "B", 19, "a@unict.it", "100000769");
	Studente s3 = s2;
	
	s1.Persona::print();
	s1.print();
	s2.print();
	s3.print();
}

int main() {
	//while(true)
		fun();
	std::cout << "finito" << std::endl;
	
}