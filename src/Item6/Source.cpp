#include<iostream>
class Uncopyable
{
public:
	Uncopyable() {}
	~Uncopyable(){}
	Uncopyable(const Uncopyable&) = delete;
	Uncopyable& operator=(const Uncopyable&) = delete;
private:
	/*Uncopyable(const Uncopyable&);
	Uncopyable& operator=(const Uncopyable&);*/
};

class HomeForSale :private Uncopyable
{
public:
	HomeForSale(){}
	~HomeForSale(){}

private:

};

int main() {
	HomeForSale a;
	HomeForSale b;
	//a = b; 
	std::cout << "Henry, How are you?" << std::endl;
	return 0;
	 
}