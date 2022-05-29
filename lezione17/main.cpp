#include "queue.h"
#include "static_queue.h"

int main() {

	Queue<int> q;
	q.enqueue(10);
	q.enqueue(12);
	q.enqueue(14);
	q.enqueue(16);
	
	std::cout << q << std::endl;	
	
	DLNode<int> ptr = q.dequeue();
	std::cout << ptr << std::endl;
	ptr = q.dequeue();
	std::cout << ptr << std::endl;
	
	StaticQueue<int> sq(5);
	
	sq.enqueue(1);
	sq.enqueue(2);
	sq.enqueue(3);
	sq.enqueue(4);
	sq.enqueue(5);
	std::cout << sq << std::endl;
	
	int v = sq.dequeue();
	
	std::cout << sq << std::endl;
	
	sq.enqueue(6);
	
	std::cout << sq << std::endl;
	
}