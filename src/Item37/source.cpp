#include <iostream>
#define ShapeColor(DO) \
  DO(Red)              \
  DO(Green)            \
  DO(Blue)

#define MAKE_ENUM(VAR) VAR,
enum MetaSyntacticVariable { ShapeColor(MAKE_ENUM) };

#define MAKE_STRINGS(VAR) #VAR,
const char* const MetaSyntacticVariableNames[] = {ShapeColor(MAKE_STRINGS)};

// a class for geometric shapes
// class Shape {
// public:
//  enum ShapeColor { Red, Green, Blue };
//  // all shapes must offer a function to draw themselves
//  virtual void draw(ShapeColor color = Red) const = 0;
//};
//
// class Rectangle : public Shape {
// public:
//  // notice the different default parameter value ¡ª bad!
//  virtual void draw(ShapeColor color = Green) const {
//    std::cout << "Call Rectangle draw()"
//              << " color is " << MetaSyntacticVariableNames[color] <<
//              std::endl;
//  }
//};
// class Circle : public Shape {
// public:
//     virtual void draw(ShapeColor color) const {
//    std::cout << "Call Circle draw()" <<
//        " color is " << MetaSyntacticVariableNames[color] << std::endl;
//  }
//};

class Shape {
 public:
  enum ShapeColor { Red, Green, Blue };
  void draw(ShapeColor color = Red) const  // now non-virtual
  {
    do_draw(color);  // calls a virtual
  }

 private:
  virtual void do_draw(
      ShapeColor color) const = 0;  // the actual work is done in this func
};
class Rectangle : public Shape {
 public:
  void draw(ShapeColor color = Green) const { do_draw(color); }

 private:
  virtual void do_draw(
      ShapeColor color) const;  // note lack of a default param val.
};

void Rectangle::do_draw(ShapeColor color) const {
  std::cout << "Call Rectangle draw()"
            << " color is " << MetaSyntacticVariableNames[color] << std::endl;
}

int main() {
  std::cout << "Item 37: Never redefine a function¡¯s inherited default "
               "parameter value.\n";

  //{
  //  Shape* ps;                  // static type = Shape*
  //  Shape* pc = new Circle;     // static type = Shape*
  //  Shape* pr = new Rectangle;  // static type = Shape*
  //  pc->draw(Shape::Red);
  //  pr->draw(); //a default parameter value from a base class. default
  //  parameter values are statically bound.
  //}

  {
      Shape* ps;                  // static type = Shape*
      Shape* pr = new Rectangle;  // static type = Shape*
      pr->draw(Shape::Green);
  }
  return 0;
}