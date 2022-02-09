#include<iostream>
#include <cstring>
#include <string>
#include <memory>
#include <algorithm>
template<typename T>
class NamedObject {
public:	
	NamedObject(const NamedObject& rhs);
	//NamedObject(const char* name, const T& value);
	//NamedObject(const std::string& name, const T& value);
	NamedObject(std::string& name, const T& value);
	NamedObject& operator=(const NamedObject& rhs);
	~NamedObject();
private:
	std::string& nameValue;
	T objectValue;
};

// https://isocpp.org/wiki/faq/templates
//template<typename T>
//NamedObject<T>::NamedObject(const char* name, const T& value):nameValue(name),objectValue(value) {
//	std::cout << "const char: " << name << " " << value << std::endl;
//}
//
//template<typename T>
//NamedObject<T>::NamedObject(const std::string& name, const T& value) : nameValue(name), objectValue(value) {
//	std::cout << "const string: " << name << " " << value << std::endl;
//}

template<typename T>
NamedObject<T>::NamedObject(std::string& name, const T& value) : nameValue(name), objectValue(value) {
	std::cout << "reference string: " << name << " " << value << std::endl;
}

template<typename T>
NamedObject<T>::~NamedObject(){}

template<typename T>
NamedObject<T>::NamedObject(const NamedObject& obj):nameValue(obj.nameValue),objectValue(obj.objectValue){
	std::cout << "Copy Constructor" << std::endl;
}
template<typename T>
NamedObject<T>& NamedObject<T>::operator=(const NamedObject& other) {
	std::cout << "Copy Assignment Constructor" << std::endl;
	nameValue = other.nameValue;
	objectValue = other.objectValue;
	return *this;
}

int main()
{
	/*NamedObject<int> nameObj("Hello", 40);
	NamedObject<int> nameObj2(nameObj);
	NamedObject<int> nameObj3 = nameObj2;*/



	std::string newDog("Persephone");
	std::string oldDog("Satch");
	NamedObject<int> p(newDog, 2);
	NamedObject<int> s(oldDog, 36);
	p = s;
	std::cout << "Henry!" << std::endl;
}