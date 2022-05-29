#include <iostream>

using namespace std;

class Persona {
	
	string nome;
	string cognome;
	
	public:
		Persona(string n, string c) : nome(n), cognome(c) {}
		
		string getNome() const {
			return this->nome;
		}
		
		
	
};


int main() {
	
	const Persona p("nome1", "cognome1");
	string x = p.getNome();
	
	x = "marco"; 
	
	cout << x << endl;
}