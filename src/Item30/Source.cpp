#include<iostream>

template<typename T> // an explicit inline
inline const T& max(const T& a, const T& b) // request: std::max is
{
	return a < b ? b : a;
} // preceded by ¡°inline¡±

inline void f() { std::cout << "Call f()" << std::endl; }

int main() {
	std::cout << "Item 30: Understand the ins and outs of inlining." << std::endl;

	std::cout << max<double>(22.1, 100.10) << std::endl;

	void (*pf)() = f;
	pf(); // You are so strong.

	return 0;
}