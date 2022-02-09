#include<iostream>
#include<vector>
template<typename C> // this is valid C++
void Print2nd(const C& container)
{
	if (container.size() >= 2) {
		typename C::const_iterator iter(container.begin());
		while (iter != container.end())
		{
			std::cout << *iter << " ";
			++iter;
		}
		std::cout << '\n';
	}
}

template<typename IterT>
void WorkWithIterator(IterT iter)
{
	typename std::iterator_traits<IterT>::value_type temp(*iter);
	/*typedef typename std::iterator_traits<IterT>::value_type value_type;
	value_type temp(*iter);*/
	std::cout << temp << " ";
}

int main() {
	std::cout << "Item 42: Understand the two meanings of typename.\n";

	std::vector<int> v = { 13,14,520,10,07 };
	for (auto iter = v.cbegin(); iter != v.cend(); ++iter)
	{
		WorkWithIterator<std::vector<int>::const_iterator>(iter);
	}
	std::cout << '\n';
	Print2nd(v);

	return 0;
}