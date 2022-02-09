#include "person_interface.h"
std::shared_ptr<Person>  Person::create(const std::string& name, const Date& birthday, const Address& addr) {
	return std::shared_ptr<Person>(new RealPeson(name, birthday,addr));
}

std::string RealPeson::birth_date() const {
	return birthdate_.birth_day();
}

std::string RealPeson::name() const {
	return name_;
}

std::string RealPeson::address() const {
	return address_.address_name();
}

int main() {
	std::cout << "Item 31: Minimize compilation dependencies between files.\n";
	{
		std::string name("ChenYawen");
		Date birth_day;
		Address addr;
		std::shared_ptr<Person> pp(Person::create(name, birth_day, addr));
		std::cout << pp->name() // use the object via the Person interface
			<< " was born on "  
			<< pp->birth_date()
			<< " and now lives at "
			<< pp->address();
	}
	return 0;
}