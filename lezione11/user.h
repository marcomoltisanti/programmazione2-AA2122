#include <iostream>
#include <string>

#ifndef USER_H
#define USER_H

class User {
	private:
		unsigned int id;
		std::string surname;
		std::string name;
		double popularity;
			
		inline int compareTo(const User &other) {
			if(this->popularity > other.popularity)
				return 1;
			else if(this->popularity < other.popularity)
				return -1;
			else return 0;
		}
		
	public:
	
		User(unsigned int _id, std::string _surname, std::string _name, double _popularity) :
			id(_id), surname(_surname), name(_name), popularity(_popularity) {}
		
		User() : User(0, "", "", 0.0) {}
		
		friend std::istream &operator>>(std::istream &input, User &user) {
			std::string id_string, pop_string;
			std::getline(input, id_string, ';');
			std::getline(input, user.surname, ';');
			std::getline(input, user.name, ';');
			std::getline(input, pop_string);
			user.id = std::atoi(id_string.c_str());
			user.popularity = std::atof(pop_string.c_str());
						
			return input;
			
		}
		
		friend std::ostream &operator<<(std::ostream &output, const User &user) {
			output << "ID: " << user.id << ", " << user.surname << " " << user.name << ", Popularity: " << user.popularity;
			return output;
		}
		
		bool operator<(const User &other) {
			return this->compareTo(other) < 0;
		}
		
		bool operator>(const User &other) {
			return this->compareTo(other) > 0;
		}
		
		bool operator==(const User &other) {
			return this->compareTo(other) == 0;
		}
		
};

#endif