#include <iostream>

// Scenario 1: Hiding inherited virtual (common warning with -Woverloaded-virtual)
class Base {
public:
    virtual ~Base() = default;
    virtual void display(int x) const {
        std::cout << "Base::display(int): " << x << "\n";
    }
};

class Derived : public Base {
public:
    // This HIDES Base::display(int) rather than overriding it!
    // Compilers warn: "Derived::display(double) hides Base::display(int)"
    // Fix: use 'override' or add a using declaration
    void display(double x) const {
        std::cout << "Derived::display(double): " << x << "\n";
    }

    // Proper override
    void display(int x) const override {
        std::cout << "Derived::display(int) override: " << x << "\n";
    }
};

// Scenario 2: Shadowing (-Wshadow)
int calculate(int outer) {
    int result = 0;
    for (int i = 0; i < outer; ++i) {
        // int outer = 10; // WARNING: declaration shadows parameter 'outer'
        result += i;
    }
    return result;
}

// Scenario 3: Signed/unsigned comparison (-Wsign-compare)
bool check_bounds(int index, std::size_t size) {
    // Mixing signed and unsigned: 'index' could be negative
    // Compiler warns if we do: if (index < size)
    if (index < 0) return false;
    return static_cast<std::size_t>(index) < size;
}

// Scenario 4: Unused parameter (-Wunused-parameter)
// Fix: use [[maybe_unused]] attribute (C++17)
void callback([[maybe_unused]] int event_id, const std::string& message) {
    std::cout << "Event: " << message << "\n";
}

int main() {
    std::cout << "Item 53: Pay attention to compiler warnings.\n\n";

    // Demonstrate the hiding issue
    Derived d;
    Base& b = d;
    b.display(42);      // Calls Derived::display(int) via virtual dispatch
    d.display(3.14);    // Calls Derived::display(double)
    d.display(10);      // Calls Derived::display(int)

    std::cout << "\ncalculate(5) = " << calculate(5) << "\n";
    std::cout << "check_bounds(3, 10) = " << check_bounds(3, 10) << "\n";

    callback(1, "compiler warnings are your friend");

    std::cout << "\nKey compiler flags for warnings:\n";
    std::cout << "  MSVC: /W4 /WX (warnings as errors)\n";
    std::cout << "  GCC/Clang: -Wall -Wextra -Wpedantic -Werror\n";
    std::cout << "  Useful extras: -Wshadow -Woverloaded-virtual -Wsign-compare\n";

    return 0;
}
