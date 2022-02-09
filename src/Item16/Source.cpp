#include <iostream>

int main() {
	std::cout << "Item 16: Use the same form in corresponding uses of new and delete." << std::endl;

	typedef std::string address_lines[4];
	
	std::string* pal = new address_lines;

	delete[] pal;
	//delete pal; // undefined!
	return 0;
}