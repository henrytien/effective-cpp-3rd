#include <functional>
#include <iostream>
namespace classic_strategy_pattern {
class GameCharacter;
int DefaultHealthCalcFunc(const GameCharacter&);
class HealthCalcFunc {
 public:
  virtual int calc(const GameCharacter& gc) const {
    std::cout << "Call Base::HealthCalcFunc calc\n";
    return /*gc.get_health() **/ 0.8;
  }
};
class GameCharacter {
 public:
  explicit GameCharacter(HealthCalcFunc* hcf)
      : health_func_(hcf), health_value_(100) {}
  virtual int health_value() const;  // return character¡¯s health value;
  int LoseHealth() const { return health_value_ -= 1; }
  int LoseHealthSlowly() const { return health_value_ -= 10; }
  int LoseHealthQuickly() const { return health_value_ -= 20; }
  int get_health() const { return health_value_; }

 private:
  HealthCalcFunc* health_func_;
  mutable int health_value_;
};

int DefaultHealthCalcFunc(const GameCharacter& gc) {
  return gc.LoseHealth();
}

int GameCharacter::health_value() const {
  return health_func_->calc(*this);
}

short CalcHealth(const GameCharacter& gc) {
  return (short)gc.LoseHealthQuickly();
}

class SlowerHeathLoser : public HealthCalcFunc {
 public:
  virtual int calc(const GameCharacter& gc) const {
    std::cout << "Call SlowerHeathLoser calc\n";

    return gc.get_health() * 0.9;
  }
};

class FastHealthLoser : public HealthCalcFunc {
 public:
  virtual int calc(const GameCharacter& gc) const {
    std::cout << "Call FastHealthLoser calc\n";
    return gc.get_health() * 0.7;
  }
};

class EvilBadGuy : public GameCharacter {
 public:
  explicit EvilBadGuy(HealthCalcFunc* hcf /*= DefaultHealthCalcFunc*/)
      : GameCharacter(hcf) {}
};

class EyeCandyCharacter : public GameCharacter {  // another character type;
  // assume same constructor as EvilBadGuy
 public:
  explicit EyeCandyCharacter(HealthCalcFunc* hcf /*= DefaultHealthCalcFunc*/)
      : GameCharacter(hcf) {}
};

int test() {
  // int main() {
  std::cout << "Item 35: Consider alternatives to virtual functions.\n";

  FastHealthLoser fast;
  EvilBadGuy ebg3(&fast);
  ebg3.health_value();
  return 0;
}
}  // namespace classic_strategy_pattern