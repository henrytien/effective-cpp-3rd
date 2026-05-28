---
sidebar_position: 6
---

# Item 10: Have assignment operators return a reference to *this

## Concept

The convention for assignment operators (including `=`, `+=`, `-=`, `*=`, etc.) is to return a reference to `*this`. This enables chaining of assignments like `x = y = z = 15`. All built-in types follow this convention, and so do all types in the standard library. While the convention is not enforced by the compiler, following it ensures your types work seamlessly with idiomatic C++ code.

## Code Example

```cpp
class Widget {
public:
    // Standard copy assignment
    Widget& operator=(const Widget& rhs) {
        // ... assignment logic ...
        return *this;  // return reference to left-hand object
    }

    // Also applies to +=, -=, *=, etc.
    Widget& operator+=(const Widget& rhs) {
        // ... addition logic ...
        return *this;
    }

    // Even applies to unconventional parameter types
    Widget& operator=(int rhs) {
        // ... assignment logic ...
        return *this;
    }
};

// Now chaining works as expected:
Widget w1, w2, w3;
w1 = w2 = w3;  // equivalent to w1 = (w2 = w3)
```

[Full source code](https://github.com/henrytien/effective-cpp-3rd/blob/master/src/Item10/source.cpp)

## Things to Remember

- Have assignment operators return a reference to `*this`.
- This applies to all assignment operators, not just the standard form (`operator=`).

## Related Items

- [Item 11](../chapter-02/item-11.md) — Handle assignment to self in operator=
- [Item 12](../chapter-02/item-12.md) — Copy all parts of an object
