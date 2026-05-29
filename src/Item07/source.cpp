#include <iostream>
class TimeKeeper {
public:
  TimeKeeper() {}
  virtual ~TimeKeeper() {}
};
class AtomicClock : public TimeKeeper {};
class WaterClock : public TimeKeeper {};
class WristWatch : public TimeKeeper {};

class AWOW {
public:
  virtual void fun() = 0;
  virtual ~AWOW() = 0;
};
class BWOW : public AWOW {};
int main() {
  // BWOW b = new BWOW();
  /* If derived class do not redefine virtual function of base class,
      then no compilation error but derived class also becomes abstract
      just like the base class.*/
  std::cout << "Henry" << std::endl;
  return 0;
}