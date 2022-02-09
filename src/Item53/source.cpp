#include<iostream>
class B {
public:
	virtual void f() const { std::cout << "Call B::f()\n"; };
};
class D : public B {
public:
	virtual void f() const { std::cout << "Call D::f()\n"; };
private:
	int n_;
};
int main() {
	std::cout << "Item 53: Pay attention to compiler warnings.\n";
	D d;
	const D t = d;
	t.f();
	return 0;
}