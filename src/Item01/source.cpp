#include <algorithm>
#include <iostream>
#include <memory>
#include <vector>

// Sub-language 1: C
// Blocks, statements, preprocessor, built-in data types, arrays, pointers
void c_sublanguage() {
  int arr[] = {3, 1, 4, 1, 5};
  int* p = arr;
  std::cout << "C sub-language: pointer arithmetic, arr[2] = " << *(p + 2) << "\n";
}

// Sub-language 2: Object-Oriented C++
// Classes, encapsulation, inheritance, polymorphism, virtual functions
class Shape {
 public:
  virtual ~Shape() = default;
  virtual double area() const = 0;
  virtual void describe() const { std::cout << "Shape with area = " << area() << "\n"; }
};

class Circle : public Shape {
 public:
  explicit Circle(double r) : radius_(r) {}
  double area() const override { return 3.14159 * radius_ * radius_; }

 private:
  double radius_;
};

// Sub-language 3: Template C++
// Generic programming, template metaprogramming
template <typename Container>
void print_all(const Container& c) {
  std::cout << "Template C++: [";
  for (auto it = c.begin(); it != c.end(); ++it) {
    if (it != c.begin())
      std::cout << ", ";
    std::cout << *it;
  }
  std::cout << "]\n";
}

// Sub-language 4: The STL
// Containers, iterators, algorithms, function objects
void stl_sublanguage() {
  std::vector<int> v = {5, 2, 8, 1, 9, 3};
  std::sort(v.begin(), v.end());
  std::cout << "STL: sorted vector = ";
  print_all(v);
}

int main() {
  std::cout << "Item 1: View C++ as a federation of languages.\n\n";

  std::cout << "--- C sub-language ---\n";
  c_sublanguage();

  std::cout << "\n--- Object-Oriented C++ ---\n";
  auto shape = std::make_unique<Circle>(5.0);
  shape->describe();

  std::cout << "\n--- Template C++ ---\n";
  std::vector<std::string> words = {"effective", "c++", "federation"};
  print_all(words);

  std::cout << "\n--- The STL ---\n";
  stl_sublanguage();

  return 0;
}
