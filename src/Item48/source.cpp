#include <iostream>
template<unsigned n> // general case: the value of
struct Factorial { // Factorial<n> is n times the value of Factorial<n-1>
	enum { value = n * Factorial<n - 1>::value };
};
template<> // special case: the value of Factorial<0> is 1
struct Factorial<0> {
	enum { value = 1 };
};

int main()
{
	std::cout << "Item 48: Be aware of template metaprogramming.\n";

	std::cout << Factorial<10>::value << std::endl;

	return 0;
}


