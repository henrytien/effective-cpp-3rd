#include<iostream>
#include<assert.h>
class Bird {
   // no fly function is declared
};
class FlyingBird : public Bird {
 public:
  virtual void fly();
};
class Penguin : public Bird {
   // no fly function is declared
};

class Rectangle {
 public:
  Rectangle() : height_(5), width_(4) {}
  virtual void setHeight(int newHeight){};
  virtual void setWidth(int newWidth){};
  virtual int height() const { return height_; };  // return current values
  virtual int width() const { return width_; };

 private:
  int height_;
  int width_;
};

//void Rectangle::setHeight(int newHeight) {
//  height_ = newHeight;
//}
//
//void Rectangle::setWidth(int newWidth) {
//  width_ = newWidth;
//}

void MakeBigger(Rectangle& r)  // function to increase r¡¯s area
{
  int oldHeight = r.height();
  r.setWidth(r.width() + 10);     // add 10 to r¡¯s width
  assert(r.height() == oldHeight);  // assert that r¡¯s
}

class Square : public Rectangle {

 public:
  Square() : Rectangle(), height_(4), width_(4) {}
  virtual void setHeight(int newHeight);
  virtual void setWidth(int newWidth);
  virtual int height() const { return height_; }
  virtual int width() const { return width_; };
 private:
  int height_;
  int width_;
};

void Square::setHeight(int newHeight) {
  height_ = newHeight;
}

void Square::setWidth(int newWidth) {
  width_ = newWidth;
}



int main() {
  std::cout << "Item 32: Make sure public inheritance models ¡°is-a.¡±\n";

  Square s;
  assert(s.width() == s.height());  // this must be true for all squares
  MakeBigger(s);                        // by inheritance, s is-a Rectangle,
  // so we can increase its area
  assert(s.width() == s.height());  // this must still be true for all squares

  return 0;
}