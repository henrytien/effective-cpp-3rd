---
sidebar_position: 6
---

# Item 46: Define non-member functions inside templates when type conversions are desired

## Concept

When a class template needs to support implicit type conversions on all arguments (e.g., mixed-mode arithmetic), template argument deduction won't perform implicit conversions. The solution is to declare the function as a `friend` inside the class template, making it a non-template function that supports implicit conversions on all arguments. The friend function is typically defined inline inside the class template body (or delegates to a helper template) to ensure the linker can find exactly one definition for each instantiation.

## Code Example

```cpp
template <typename T>
class Rational {
public:
    Rational(const T& numerator = 0, const T& denominator = 1)
        : num_(numerator), den_(denominator) {}

    const T& numerator() const { return num_; }
    const T& denominator() const { return den_; }

    // friend non-member function defined inside the class
    friend Rational operator*(const Rational& lhs, const Rational& rhs) {
        return Rational(lhs.num_ * rhs.num_, lhs.den_ * rhs.den_);
    }

private:
    T num_, den_;
};

// Usage: implicit conversions now work on both arguments
// Rational<int> r(1, 2);
// Rational<int> result = r * 2;  // 2 implicitly converts to Rational<int>
// Rational<int> result2 = 2 * r; // Works too!
```

[Full source code](https://github.com/henrytien/effective-cpp-3rd/blob/master/src/Item46/source.cpp)

## Things to Remember

- When writing a class template that offers functions related to the template that support implicit type conversions on all parameters, define those functions as friends inside the class template.

## Related Items

- [Item 24](../chapter-04/item-24.md) — Declare non-member functions when type conversions should apply to all parameters
- [Item 45](../chapter-07/item-45.md) — Member function templates for compatible types
- [Item 44](../chapter-07/item-44.md) — Factor parameter-independent code out of templates
