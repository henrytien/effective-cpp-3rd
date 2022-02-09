#include <iostream>
class Shape {
 public:
  Shape() : object_id_(0) {}
  virtual void draw() const = 0;
  virtual void error(const std::string& msg) { std::cout << "Oops, error!\n"; };
  int objectID() const { object_id_; }

 private:
  int object_id_;
};

void Shape::draw() const {
  std::cout << "Shape::draw() is pure virtual function.\n";
}
class Rectangle : public Shape {
 public:
  Rectangle() { draw(); }
  virtual void draw() const { std::cout << "Call Rectangle draw()\n"; }
};
class Ellipse : public Shape {
  virtual void draw() const { std::cout << "Call Ellipse draw()\n"; }
};

class Airport {
 public:
  Airport(const std::string& name) : airport_name_(name) {}
  std::string airport_name() const { return airport_name_; }

 private:
  std::string airport_name_;
};

class Airplane {
 public:
  virtual void fly(const Airport& destination) = 0;

 protected:
  void DefaultFly(const Airport& destination);
};

void Airplane::fly(const Airport& destination) {
  std::cout << "Airplane::fly\n";
}

void Airplane::DefaultFly(const Airport& destination) {
  std::cout << destination.airport_name() << " Airplane::DefaultFly\n";
}

class ModelA : public Airplane {
 public:
  virtual void fly(const Airport& destination) { DefaultFly(destination); }
};
class ModelB : public Airplane {
 public:
  virtual void fly(const Airport& destination) { DefaultFly(destination); }
};

class ModelC : public Airplane {
 public:
  virtual void fly(const Airport& destination) {
    std::cout << destination.airport_name() << " I can't fly,lol!\n";
  }
};

int main() {
  std::cout << "Item 34: Differentiate between inheritance of interface and "
               "inheritance of implementation.\n";

  // Shape* ps = new Shape;
  Shape* ps1 = new Rectangle;
  ps1->draw();

  Shape* ps2 = new Ellipse;
  ps2->draw();

  ps1->Shape::draw();

  ModelA().fly(Airport("Shanghai Pudong International Airport"));
  ModelB().fly(Airport("Beijing Capital International Airport"));
  ModelC().fly(Airport("Home"));

  return 0;
}
