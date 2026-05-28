---
sidebar_position: 4
---

# Item 21: Don't try to return a reference when you must return an object

## Concept

While pass-by-reference is efficient, never return a reference to a local object (it's destroyed when the function exits), a heap-allocated object (who deletes it?), or a local static object (multiple calls share the same object, breaking comparisons). When you need to return a new object, just return it by value. The compiler can often optimize away the copy through Return Value Optimization (RVO) or Named Return Value Optimization (NRVO), making the cost zero in practice.

## Code Example

```cpp
class Rational {
public:
    Rational(int numerator = 0, int denominator = 1)
        : n(numerator), d(denominator) {}

private:
    int n, d;
    friend const Rational operator*(const Rational& lhs, const Rational& rhs);
};

// WRONG: returning reference to local — dangling!
const Rational& operator*(const Rational& lhs, const Rational& rhs) {
    Rational result(lhs.n * rhs.n, lhs.d * rhs.d);
    return result;  // result is destroyed here!
}

// WRONG: returning reference to heap object — leak!
const Rational& operator*(const Rational& lhs, const Rational& rhs) {
    Rational* result = new Rational(lhs.n * rhs.n, lhs.d * rhs.d);
    return *result;  // who calls delete?
}

// CORRECT: return by value — compiler can apply RVO
const Rational operator*(const Rational& lhs, const Rational& rhs) {
    return Rational(lhs.n * rhs.n, lhs.d * rhs.d);
}
```

[Full source code](https://github.com/henrytien/effective-cpp-3rd/blob/master/src/Item21/source.cpp)

## Things to Remember

- Never return a pointer or reference to a local stack object, a reference to a heap-allocated object, or a pointer or reference to a local static object if there is a chance that more than one such object will be needed.
- Return by value and rely on the compiler's RVO to eliminate the copy cost.

## Related Items

- [Item 20](../chapter-04/item-20.md) — Prefer pass-by-reference-to-const (input parameters)
- [Item 3](../chapter-01/item-03.md) — Use const wherever possible
