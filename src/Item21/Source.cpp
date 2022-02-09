#include<iostream>
class Rational {
public:
	Rational(int numerator = 0, // see Item 24 for why this ctor isn¡¯t declared explicit
		int denominator = 1) :n_(numerator), d_(denominator) {}
	void Print(const Rational& rhs) {
		std::cout << "Love is " << rhs.n_ << "/" << rhs.d_ << std::endl;
	}
private:
	int n_, d_; // numerator and denominator
	friend const Rational operator*(const Rational& lhs, // see Item 3 for why the return type is const
		const Rational& rhs);
};
const Rational operator*(const Rational& lhs, const Rational& rhs) {
	return Rational(std::move(lhs.n_ * rhs.n_),std::move(lhs.d_ * rhs.d_));
}
int main() {
	std::cout << "Item 21: Don¡¯t try to return a reference when you must return an object. " << std::endl;

	Rational yawen(2, 5);
	Rational hangyu(5, 2);
	Rational love = yawen * hangyu;
	love.Print(love);
	return 0;
}