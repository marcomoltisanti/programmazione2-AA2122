#include "MyArray.h"

int main() {
	MyArray<int> ma(10);
	ma.printArray();
	ma.at(0, 10);
	ma.at(1, 10);
	ma.printArray();
	
	MyArray<int> ma2(10);
	
	ma2.printArray();
	ma.copy(&ma2);
	ma2.printArray();
}