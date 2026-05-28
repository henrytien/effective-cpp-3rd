---
sidebar_position: 1
---

# Item 18: Make interfaces easy to use correctly and hard to use incorrectly

## Concept

Good interfaces are easy to use correctly and hard to use incorrectly. You should strive for this in all your interfaces. Ways to facilitate correct use include consistency with built-in types and behavioral compatibility with built-in types. Ways to prevent errors include creating new types, restricting operations on types, constraining object values, and eliminating client resource management responsibilities. `std::shared_ptr` supports custom deleters, which prevents cross-DLL problems and can be used to automatically unlock mutexes.

## Code Example

```cpp
#include <memory>

// BAD: Easy to use incorrectly
class Date_Bad {
public:
    Date_Bad(int month, int day, int year);  // which is month? day?
};
// Date_Bad d(30, 3, 1995);  // Oops! Swapped month and day

// GOOD: Wrapper types prevent argument ordering errors
struct Day {
    explicit Day(int d) : val(d) {}
    int val;
};
struct Month {
    explicit Month(int m) : val(m) {}
    int val;
    static Month Jan() { return Month(1); }
    static Month Feb() { return Month(2); }
    // ... etc.
};
struct Year {
    explicit Year(int y) : val(y) {}
    int val;
};

class Date {
public:
    Date(const Month& m, const Day& d, const Year& y);
};

// Now errors are caught at compile time:
// Date d(30, 3, 1995);                    // Error! Won't compile
// Date d(Day(30), Month(3), Year(1995));   // Error! Wrong types
Date d(Month::Jan(), Day(30), Year(1995));  // OK, clear and correct

// Return smart pointers to prevent resource leaks
std::shared_ptr<Investment> createInvestment() {
    return std::make_shared<Investment>();
    // Client can't forget to delete — smart pointer handles it
}
```

[Full source code](https://github.com/henrytien/effective-cpp-3rd/blob/master/src/Item18/source.cpp)

## Things to Remember

- Good interfaces are easy to use correctly and hard to use incorrectly. You should strive for these characteristics in all your interfaces.
- Ways to facilitate correct use include consistency in interfaces and behavioral compatibility with built-in types.
- Ways to prevent errors include creating new types, restricting operations on types, constraining object values, and eliminating client resource management responsibilities.
- `std::shared_ptr` supports custom deleters. This prevents the cross-DLL problem and can be used to automatically unlock mutexes.

## Related Items

- [Item 13](../chapter-03/item-13.md) — Using objects to manage resources
- [Item 15](../chapter-03/item-15.md) — Providing access to raw resources
- [Item 20](../chapter-04/item-20.md) — Pass-by-reference-to-const for interface efficiency
