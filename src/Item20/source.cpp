#include<iostream>
class Person {
public:
	Person():name_(""),address_("") {}; // parameters omitted for simplicity
	virtual ~Person() {}; // see Item 7 for why this is virtual
private:
	std::string name_;
	std::string address_;
};
class Student : public Person {
public:
	Student():school_name_(""),school_address_("") {}; // parameters again omitted
	virtual ~Student() {};

	//bool ValidateStudent(Student s);
	bool ValidateStudent(const Student &s);
private:
	std::string school_name_;
	std::string school_address_;
};

bool Student::ValidateStudent(const Student &s) {
	return true;
}

int main() {
	std::cout << "Item 20: Prefer pass-by-reference-to-const to pass-by value." << std::endl;

	Student yawen_chen;
	yawen_chen.ValidateStudent(yawen_chen); // This is much more efficient: no constructors or destructors are called.
	return 0;
}