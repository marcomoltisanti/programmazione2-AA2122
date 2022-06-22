#ifndef GRAPH_H
#define GRAPH_H

#include <iostream>

template<typename T>
class Vertex {
	T key;
	
	template<typename U>
	friend class Graph;
	
	public:
	
	Vertex(T key) : key(key) {}
	Vertex() : Vertex(NULL) {}
	
	bool operator==(Vertex<T>& v) {
		return this->key == v.key;
	}
	
	friend std::ostream& operator <<(std::ostream& out, Vertex<T>& v) {
		out << v.key;
		return out;
	}
};

template<typename T>
class Graph {
	
	Vertex<T>** vertices;
	bool** adj;
	int maxSize = 0;
	int nVertices = 0;
	
	public:
	
	Graph(int max_size) : maxSize(max_size) {
		vertices = new Vertex<T>*[max_size];
		adj = new bool*[max_size];
		for(int i=0; i < max_size; i++) {
			adj[i] = new bool[max_size]{0};
			
			//for(int j=0; j < max_size; j++) 
			//	adj[i][j] = false;
		}
	}
	
	void addVertex(T key) {
		if(this->nVertices == this->maxSize) {
			std::cerr << "Graph is full" << std::endl;
			return;
		}
		
		vertices[nVertices++] = new Vertex<T>(key);
			
	}
	
	void addEdge(T key1, T key2) {
		int i = this->search(key1);
		int j = this->search(key2);
		
		if( i != -1 && j != -1) {
			adj[i][j] = true;
			adj[j][i] = true;
		}
		else {
			if(i == -1)
				std::cerr << "There is no vertex with key " << key1 << std::endl;
			else 
				std::cerr << "There is no vertex with key " << key2<< std::endl;
		}
	}
	
	int search(T key) {
		if(this->nVertices == 0) {
			return -1;
		}
		
		for(int i=0; i < this->nVertices; i++) {
			if(vertices[i]->key == key)
				return i;
		}
		
		return -1;
	}
	
	friend std::ostream& operator <<(std::ostream& out, Graph<T>& g) {
		
		for(int i=0; i < g.nVertices; i++) {
			out << "v[" << i << "] = " << *g.vertices[i] << "\t";
		}
		
		out << std::endl;
		
		for(int i = 0; i < g.nVertices; i++) {
			for(int j = 0; j < g.nVertices; j++) {
				if(g.adj[i][j])
					out << "(" << i << ", " << j << ")" << std::endl;
			}
		}
		
		return out;
	}
	
	
};

#endif