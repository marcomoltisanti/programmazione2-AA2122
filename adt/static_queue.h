#ifndef STATIC_QUEUE
#define STATIC_QUEUE

#define MAX_SIZE 1000

#include <iostream>

template<typename T>
class StaticQueue {
	
	T* array;
	int size = 0;
	int maxSize = MAX_SIZE;
	
	int head = -1;
	int tail = -1;
	
	public:
	
	StaticQueue(int maxSize = MAX_SIZE) :  maxSize(maxSize) {
		this->array = new T[maxSize];
	}
	
	void enqueue(T val) {
		if(size == maxSize) {
			std::cout << "Queue is full" << std::endl;
			return;
		}
		if(head == -1)
			head = 0;
		
		tail = (++tail % maxSize);
		array[tail] = val;
		size++;
	}
	
	T dequeue() {
		if(size == 0) {
			std::cout << "Queue is empty" << std::endl;
			return 0;
		}
		
		T val = array[head];
		head = (++head % maxSize);
		size--;
		return val;
	}
	
	friend std::ostream& operator<<(std::ostream& out, StaticQueue<T>& queue) {
		if(queue.size == 0)
			return out << "Queue is empty" << std::endl;
		
		out << "Static Queue - size=" << queue.size << ", maxSize=" << queue.maxSize << std::endl;
		
		for(int i=queue.head, count=0; count < queue.size; count++) {
			out << "queue["<< i << "] = " << queue.array[i] << std::endl;
			i = (i+1) % queue.maxSize;
		}
		
		return out;
		
	}

	
};

#endif