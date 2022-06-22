#ifndef GRAPH_LIST_H
#define GRAPH_LIST_H

#include <iostream>
#include "./list.h"

//ESTENDO LA CLASSE List IN MODO DA AVERE IL
//VERTICE NELLA head E LA LISTA DI ADIACENZA NEI SUCCESSORI
template<typename T>
class GraphVertex : public List<T> {
	protected:
	bool verbose;
	
	public:
	GraphVertex(T key, bool verbose=false) : List<T>(), verbose(verbose) {
		List<T>::insert(key);
	}
	
	friend std::ostream& operator<<(std::ostream& out, const GraphVertex<T>& v) {
		if(v.verbose) {
			out << "Graph Vertex with key " << v.head->getVal() << ": " << std::endl;
			out << "\tAdjacency List: ";
			Node<T> *ptr = v.getHead();
			while(ptr) {
				out << " -> " << ptr->getVal() ;
				ptr = ptr->getNext();
			}
		}
		else {
			Node<T> *ptr = v.getHead();
			out << ptr->getVal() << ": ";
			if(ptr->getNext()) {
				ptr = ptr->getNext();
				while(ptr->getNext()) {
					out << ptr->getVal() << ", ";
					ptr = ptr->getNext();
				}
				out << ptr->getVal();
			}
			else 
				out << "/";
			
			
		}
		
		return out;
	}
};

template<typename T>
class GraphList {
	List< GraphVertex<T> > vertices;
	int nVertices = 0;
	bool isOriented;
	bool verbose;
	
	public:
		GraphList(bool isOriented=true, bool verbose=false) : 
			isOriented(isOriented), verbose(verbose) {}
		
		void addVertex(T key) {
			GraphVertex<T> toAdd(key, verbose);
			vertices.insertTail(toAdd);
			nVertices++;
		}
		
		void addEdge(T key1, T key2) {
			
			Node< GraphVertex<T> > *node1 = this->search(key1);
			Node< GraphVertex<T> > *node2 = this->search(key2);
			
			if(node1 && node2) {
				node1->getVal().insertTail(key2);
				if(!this->isOriented) {
					node2->getVal().insertTail(key1);
				}
			}
			
		}
		
		Node< GraphVertex<T> >* search(T key) {
			if(nVertices == 0)
				return NULL;
			
			Node< GraphVertex<T> > *ptr = vertices.getHead();
			while(ptr) {
				if(key == ptr->getVal().getHead()->getVal())
					return ptr;
				
				ptr = ptr->getNext();
			}
			
			return NULL;
			
		}
		
		friend std::ostream& operator<<(std::ostream& out, GraphList<T>& g) {
			out << g.vertices;
			
			return out;
		}
		
};

#endif