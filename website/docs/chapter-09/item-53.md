---
sidebar_position: 1
---

# Item 53: Pay attention to compiler warnings

## Concept

Compiler warnings often indicate real problems that, while technically legal C++, are almost certainly not what you intended. A classic example is a function that shadows a base class virtual function instead of overriding it (wrong signature). Different compilers warn about different things and at different levels, so you should compile at the highest warning level practical and strive for warning-free code. Never ignore warnings — understand what each one means and fix the underlying issue.

## Code Example

```cpp
class Base {
public:
    virtual void f(int x) { /* ... */ }
    virtual ~Base() = default;
};

class Derived : public Base {
public:
    // Warning: hides Base::f(int) instead of overriding it!
    // Compiler may warn about this
    virtual void f(double x) { /* ... */ }

    // Fix: use override keyword (C++11+) to catch this at compile time
    // void f(int x) override { /* ... */ }
};

// Compile with high warning levels:
// g++: -Wall -Wextra -Wpedantic
// MSVC: /W4
// clang: -Wall -Wextra -Weverything (aggressive)
```

[Full source code](https://github.com/henrytien/effective-cpp-3rd/blob/master/src/Item53/source.cpp)

## Things to Remember

- Take compiler warnings seriously, and strive to compile warning-free at the maximum warning level supported by your compilers.
- Don't become dependent on compiler warnings, because different compilers warn about different things. Porting to a new compiler may eliminate warning messages you've come to rely on.

## Related Items

- [Item 33](../chapter-06/item-33.md) — Avoid hiding inherited names (a common source of warnings)
- [Item 36](../chapter-06/item-36.md) — Never redefine non-virtual functions (another hiding scenario)
- [Item 54](../chapter-09/item-54.md) — Familiarize yourself with the standard library
