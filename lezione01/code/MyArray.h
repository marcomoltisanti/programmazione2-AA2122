#include <iostream>

template<typename T>
class MyArray {
	int length = 0;
	T* array;
	public:
		MyArray(int n) : length(n) {
			array = new T[length];
		}
		
		void printArray() {
			for(int i=0; i < this->length; i++) {
				std::cout << array[i] << std::endl;
			}
		}
		
		T at(int pos) {
			return array[pos];
		}
		
		void at(int pos, T val) {
			array[pos] = val;
		}
		 
		int size() {
			return length;
		}
		
		T* getPointer() {
			return &array[0]; //array
		}
		
		void copy(MyArray<T> *dst) { //T* array2
			for(int i=0; i < length; i++) {
				dst->at(i, this->array[i]);
			}
		}
		
		
		
};