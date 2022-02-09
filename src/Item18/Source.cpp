#include<iostream>
#include<memory>

class Investment {
public:
	Investment() {}
	~Investment() {}
	std::shared_ptr<Investment> CreateInvestment(Investment* p);

	static void GetRidOfInvestment(Investment* ptr) {
		ptr->~Investment();
	}
};
std::shared_ptr<Investment> Investment::CreateInvestment(Investment* p) {
	if (p == NULL)
	{
		return NULL;
	}
	//std::shared_ptr<Investment> pInv(static_cast<Investment*>(0), Investment::GetRidOfInvestment);
	std::shared_ptr<Investment> pInv(p, Investment::GetRidOfInvestment);
	return pInv;
}
int main() {
	std::cout << "Item 18: Make interfaces easy to use correctly and hard to use incorrectly." << std::endl;
	Investment().CreateInvestment(new Investment);
	return 0;
}