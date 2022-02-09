#pragma once
#include<string>
class Address {
 public:
  Address();
  ~Address();
  std::string address_name() const { return address_name_; }
 private:
  std::string address_name_;
};

