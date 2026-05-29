#include <chrono>
#include <iostream>
#include <memory>
#include <vector>

// Inline: compiler replaces the call with the function body
inline int square(int x) {
  return x * x;
}

// Virtual functions cannot be effectively inlined when called through pointers/references
class Base {
 public:
  virtual ~Base() = default;
  virtual int compute(int x) const { return x + 1; }
};

class Derived : public Base {
 public:
  int compute(int x) const override { return x * 2; }
};

// Inlining can increase code size: each call site gets a copy
inline void long_function() {
  volatile int sum = 0;
  for (int i = 0; i < 100; ++i)
    sum += i;
}

// Function pointers defeat inlining
inline void simple_func() {
  std::cout << "called via pointer - not inlined\n";
}

int main() {
  std::cout << "Item 30: Understand the ins and outs of inlining.\n\n";

  // 1. Simple inline works well for small functions
  std::cout << "square(7) = " << square(7) << "\n";

  // 2. Virtual function calls prevent inlining (resolved at runtime)
  std::unique_ptr<Base> bp = std::make_unique<Derived>();
  std::cout << "Virtual call result: " << bp->compute(5) << "\n";

  // But direct calls on concrete types CAN be inlined
  Derived d;
  std::cout << "Direct call result: " << d.compute(5) << "\n";

  // 3. Function pointer calls prevent inlining
  void (*fp)() = simple_func;
  fp();

  // 4. Constructors/destructors are often poor inline candidates
  // because compilers insert exception-safety code invisibly
  std::cout << "\nKey points:\n";
  std::cout << "- inline is a request, not a command\n";
  std::cout << "- Most compilers refuse to inline: virtual calls, recursive functions, loops\n";
  std::cout << "- Function pointers to inline functions may prevent inlining at call site\n";
  std::cout << "- Constructors/destructors often poor candidates (hidden exception code)\n";

  return 0;
}
