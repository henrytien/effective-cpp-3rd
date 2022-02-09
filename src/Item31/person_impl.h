#pragma once
#include<iostream>
#include "address.h"
#include "date.h"
#include <memory>
class PersonImpl {
public:
	PersonImpl(const std::string& name,
		const Date& birthday,
		const Address& addr);
	~PersonImpl();
	void fun() { std::cout << "Have some fun!\n"; }
	std::string name() const;
	std::string birth_date() const;
	std::string address() const;
private:
	std::string name_;  // implementation detail
	Date date_;      // implementation detail
	Address address_;   // implementation detail
};