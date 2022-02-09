#include <iostream>
class Base {
 public:
  virtual void mf1() = 0;
  virtual void mf1(int) { std::cout << "Base:mf1(int)\n"; }
  virtual void mf2() { std::cout << "Base:mf2()\n"; };
  void mf3() { std::cout << "Base:mf3()\n"; };
  void mf3(double) { std::cout << "Base:mf3(double)\n"; };

 private:
  int x_;
};
class Derived : public Base {
 public:
  using Base::mf1;
  using Base::mf3;
  virtual void mf1() { std::cout << "Derived:mf1()\n"; }
  void mf3() { std::cout << "Derived:mf3()\n"; }
  void mf4() { std::cout << "Derived:mf4()\n"; }
};

int main() {
  std::cout << "Item 33: Avoid hiding inherited names.\n";

  Derived d;
  int x = 10;
  d.mf1();
  d.mf1(x);

  d.mf2();

  d.mf3();
  d.mf3(x);
  return 0;
}