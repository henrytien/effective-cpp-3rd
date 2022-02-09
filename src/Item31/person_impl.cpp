#include "person_impl.h"

PersonImpl::PersonImpl(const std::string& name,
	const Date& birthday,
	const Address& addr)
	: name_(name),
	date_(birthday), address_(addr) {}

PersonImpl::~PersonImpl() {

}


std::string PersonImpl::birth_date() const {
	return date_.birth_day();
}

std::string PersonImpl::name() const {
	return name_;
}

std::string PersonImpl::address() const {
	return address_.address_name();
}