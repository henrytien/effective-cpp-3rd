#include<iostream>
#include<functional>
#include<string>

// The param ¡°func¡± will take any callable entity
// with a sig consistent with ¡°std::string (int)¡±
void RegisterCallback(std::function<std::string(int)> func) {
	std::cout << "RegisterCallback result: " << func(2) <<"\n";
}

std::string fun(int &n) {
	n++;
	return std::to_string(n);
}

int main() {
	std::cout << "Item 54: Familiarize yourself with the standard library, including TR1.\n";

	RegisterCallback(std::bind(&fun,10));
	return 0;
}