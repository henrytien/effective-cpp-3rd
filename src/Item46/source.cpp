#include <iostream>

template<typename T> class Rational;
template<typename T>
const Rational<T> DoMultiply(const Rational<T>& lhs, const Rational<T>& rhs);


template<typename T>
class Rational {
public:
	Rational(const T& numerator = 0, // see Item20 for why params
		const T& denominator = 1); // are now passed by reference
	const T numerator() const { return n_; } // see Item28 for why return
	const T denominator() const { return d_; } // values are still passed by value, Item 3 for why they¡¯re const


	//template<typename T> // Interesting is here.
	friend const Rational<T> operator*(const Rational<T>& lhs,
		const Rational<T>& rhs)
	{
		//return Rational(lhs.numerator() * rhs.numerator(), lhs.denominator() * rhs.denominator());
		return DoMultiply(lhs, rhs);
	}
private:
	T n_;
	T d_;
};
template<typename T> // define helper template in header file if necessary
const Rational<T> DoMultiply(const Rational<T>& lhs,
	const Rational<T>& rhs)
{
	return Rational<T>(lhs.numerator() * rhs.numerator(),
		lhs.denominator() * rhs.denominator());
}
template<typename T>
Rational<T>::Rational(const T& numerator /* = 0 */, const T& denominator /* = 1 */) {
	n_ = numerator;
	d_ = denominator;
}



int main() {
	std::cout << "Item 46: Define non-member functions inside templates when type conversions are desired.\n";

	Rational<int> one_half(1, 2);
	Rational<int> result = one_half * 2;
	Rational<int> ans = result * 3.3;
	return 0;
}