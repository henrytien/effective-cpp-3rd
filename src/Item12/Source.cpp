#include <iostream>


class Customer {
public:
  Customer():name_("") {}
  Customer(const Customer &rhs);
  Customer &operator=(const Customer &rhs);

private:
  std::string name_;
};

void logCall(const std::string &funcName) {
  std::cout << "Called: " << funcName << std::endl;
}

Customer::Customer(const Customer &rhs) : name_(rhs.name_) {
  logCall("Customer copy constructor");
}

Customer &Customer::operator=(const Customer &rhs) {
  logCall("Customer copy assignment operator");
  name_ = rhs.name_;
  return *this;
}


class PriorityCustomer : public Customer {
public:
  PriorityCustomer(const int n) :priority_(n){};
  PriorityCustomer(const PriorityCustomer &rhs);
  PriorityCustomer &operator=(const PriorityCustomer &rhs);

private:
  int priority_;
};

PriorityCustomer::PriorityCustomer(const PriorityCustomer &rhs):Customer(rhs),priority_(rhs.priority_) {
  logCall("PriorityCustomer copy constructor");
}

PriorityCustomer& PriorityCustomer::operator=(const PriorityCustomer& rhs) {
	
  logCall("PriorityCustomer copy assignment operator");
  Customer::operator=(rhs);			// assign base class parts.
  priority_ = rhs.priority_;

  return *this;
}

int main() {
  std::cout << "Item 12: Copy all parts of an object." << std::endl;
  Customer cus;
  Customer cus1 = cus;
  cus = cus1;
  PriorityCustomer yawen(17);
  PriorityCustomer hangyu = yawen;
  yawen = hangyu;
  return 0;
}