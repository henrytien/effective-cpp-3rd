#include <iostream>

class Widget {
public:
  Widget(const std::string &str, const int n):str_(str),num_(n) {}
  Widget &operator=(const Widget &rhs) // return type is a reference to
  {
    this->num_ = rhs.num_;             // the current class
    this->str_ = rhs.str_;
    return *this;                      // return the left-hand object
  }
  Widget &operator+=(const Widget &rhs) // the convention applies to
  {                                     // +=, -=, *=, etc.
    return *this;
  }
  void Print(const Widget &rhs) {
    std::cout <<  rhs.str_ << " " << rhs.num_ << std::endl;
  }

private:
  std::string str_;
  int num_;
};

int main() {
  std::cout << "Item 10: Have assignment operators return a reference to *this."
            << std::endl;

  Widget widget("hangyutian",27);
  widget.Print(widget);
  Widget widget1("yawenchen", 17);
  widget1.Print(widget1);
  widget = widget1;
  std::cout << "assignment after: " << std::endl;
  widget.Print(widget);
  return 0;
}