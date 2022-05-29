#include <iostream>

void fun() {
	int a = 0;
	std::cout << "non static function a=" << a << std::endl;
	a++;
}




void fun_static() {
	
	static int a = 0;
	std::cout << "static access to a=" << a << std::endl;
	a++;
}

int main() {
	for(int i=0; i<5; i++) {
		fun_static();
		fun();
	}
	
}