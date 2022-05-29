#include "persona.h"

#ifndef STUDENTE_H
#define STUDENTE_H

class Studente : public Persona {
	std::string matricola;
	
	public:
		
		Studente() : Persona() {}
		Studente(std::string n, std::string c, int e, std::string email, std::string m) :
			Persona(n, c, e, email), matricola(m) {}
		Studente(const Studente &s) : Persona(s) {
			matricola = s.matricola;
			//temperatura = new int[100];
		}
		
		void print() {
			Persona::print();
			std::cout << " la mia matricola è " << matricola << std::endl;
		}
};

#endif