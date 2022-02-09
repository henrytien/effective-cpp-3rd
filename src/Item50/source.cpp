#include<iostream>

int main() {
	std::cout << "Item 50: Understand when it makes sense to replace new and delete.\n";

	std::cout << "To detect usage errors.\n";
	std::cout << "To collect statistics about the use of dynamically allocated memory.\n";
	std::cout << "To increase the speed of allocation and deallocation.\n";
	std::cout << "To reduce the space overhead of default memory management.\n";
	std::cout << "To compensate for suboptimal alignment in the default allocator.\n";
	std::cout << "To cluster related objects near one another.\n";
	std::cout << "To obtain unconventional behavior.\n";
	return 0;
}