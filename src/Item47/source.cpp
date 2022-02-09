#include<iostream>
#include<vector>

namespace henry {

	/* Now C++ reference have two versions.
	https://en.cppreference.com/w/cpp/iterator/advance
	*/

	template<typename IterT, typename DistT> // use this impl for
	void DoAdvance(IterT& iter, DistT d, // random access
		std::random_access_iterator_tag) // iterators
	{
		iter += d;
	}
	template<typename IterT, typename DistT> // use this impl for
	void DoAdvance(IterT& iter, DistT d, // bidirectional
		std::bidirectional_iterator_tag) // iterators
	{
		if (d >= 0) { while (d--) ++iter; }
		else { while (d++) --iter; }
	}
	template<typename IterT, typename DistT> // use this impl for
	void DoAdvance(IterT& iter, DistT d, // input iterators
		std::input_iterator_tag)
	{
		if (d < 0) {
			throw std::out_of_range("Negative distance"); // see below
		}
		while (d--) ++iter;
	}

	template<typename IterT, typename DistT>
	void advance(IterT& iter, DistT d)
	{
		DoAdvance( // call the version
			iter, d, // of DoAdvance
			typename // that is
			std::iterator_traits<IterT>::iterator_category() // appropriate for
		); // iter¡¯s iterator
	} // category
}

int main() {
	std::cout << "Item 47: Use traits classes for information about types.\n";

	// Vector container
	std::vector<int> vec;

	// Initialising vector
	for (int i = 0; i < 10; i++)
		vec.push_back(i * 10);

	// Printing the vector elements
	for (int i = 0; i < 10; i++) {
		std::cout << vec[i] << " ";
	}

	std::cout << std::endl;

	// Declaring the vector iterator
	std::vector<int>::iterator it = vec.begin();

	// Printing alternate elements
	while (it < vec.end()) {
		std::cout << *it << " ";
		henry::advance<std::vector<int>::iterator, int>(it, 2);
	}
	return 0;
}