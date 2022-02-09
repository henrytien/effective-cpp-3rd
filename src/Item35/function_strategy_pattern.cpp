#include <functional>
#include <iostream>
class GameCharacter;
int DefaultHealthCalcFunc(const GameCharacter&);

class GameCharacter {
 public:
  // typedef int (*HealthCalcFunc)(const GameCharacter&);
  typedef std::function<int(const GameCharacter&)> HealthCalcFunc;
  explicit GameCharacter(HealthCalcFunc hcf = DefaultHealthCalcFunc)
      : health_func_(hcf), health_value_(100) {}
  virtual int health_value() const;  // return character¡¯s health value;
  int LoseHealth() const { return health_value_ -= 1; }
  int LoseHealthSlowly() const { return health_value_ -= 10; }
  int LoseHealthQuickly() const { return health_value_ -= 20; }
  int get_health() const { return health_value_; }
  void set_health(int value) const { health_value_ *= value; }

 private:
  HealthCalcFunc health_func_;
  mutable int health_value_;
};

int DefaultHealthCalcFunc(const GameCharacter& gc) {
  return gc.LoseHealth();
}

int GameCharacter::health_value() const {
  return health_func_(*this);
}
struct HealthCalculator {                        // class for health
  int operator()(const GameCharacter& gc) const  // calculation function
  {
    std::cout << "Call HealthCalculator\n";
    return gc.LoseHealth();

  }  // objects
};

short CalcHealth(const GameCharacter& gc) {
  return (short)gc.LoseHealthQuickly();
}

class GameLevel {
 public:
  GameLevel() : level_(1) {}
  float health(const GameCharacter& gc) const {
    std::cout << "Call GameLevel health()\n";
    gc.set_health(1);
    level_ = gc.get_health() / 10;
    return gc.get_health();
  }

  int demage(const GameCharacter& gc) { return gc.get_health() / 2; }

  int get_level() const { return level_; }

 private:
  mutable int level_;
};

class EvilBadGuy : public GameCharacter {
 public:
  explicit EvilBadGuy(HealthCalcFunc hcf = DefaultHealthCalcFunc)
      : GameCharacter(hcf) {}
};

class EyeCandyCharacter : public GameCharacter {  // another character type;
  // assume same constructor as EvilBadGuy
 public:
  explicit EyeCandyCharacter(HealthCalcFunc hcf = DefaultHealthCalcFunc)
      : GameCharacter(hcf) {}
};

int LoseHealthQuicklyFunc(const GameCharacter& gc) {
  return gc.LoseHealthQuickly();
}
int LoseHealthSlowlyFunc(const GameCharacter& gc) {
  return gc.LoseHealthSlowly();
}

int print(int n) {
  return n;
}
int main() {
  std::cout << "Item 35: Consider alternatives to virtual functions.\n";
  /* int (*p)(int) = print;
   int (*q)(int) = &print;*/

  GameLevel current_level;
  GameCharacter game_character(
      std::bind(&GameLevel::health, current_level, std::placeholders::_1));
  std::cout << "game_character's level: " << game_character.health_value()
            << std::endl;

  EvilBadGuy ebg1(LoseHealthQuicklyFunc);
  std::cout << "ebg1's health " << ebg1.health_value() << std::endl;

  EvilBadGuy ebg2(LoseHealthSlowlyFunc);
  std::cout << "ebg2's health " << ebg2.health_value() << std::endl;

  EvilBadGuy ebg3(CalcHealth);  // character using a health calculation function
  std::cout << "ebg3's health " << ebg3.health_value() << std::endl;

  // EyeCandyCharacter ecc1(HealthCalculator());  // character using a
  // calculation function object auto health = HealthCalculator(); std::cout <<
  // "ecc1's health " << health << std::endl;

  EvilBadGuy ebg4(
      std::bind(&GameLevel::demage, current_level, std::placeholders::_1));
  std::cout << "ebg4's health " << ebg4.health_value() << std::endl;

  return 0;
}