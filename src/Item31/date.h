#pragma once
#include<string>
class Date {
 public:
  Date();
  ~Date();
  std::string birth_day() const { return birth_day_; }
 private:
  std::string birth_day_;
};

