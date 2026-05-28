---
sidebar_position: 7
---

# Item 24: Declare non-member functions when type conversions should apply to all parameters

## Concept

If you need implicit type conversions on all parameters to a function (including the one pointed to by `this`), the function must be a non-member. This commonly arises with arithmetic operators for numeric types. If `operator*` is a member function of `Rational`, then `2 * rational` won't compile because the implicit conversion from `int` to `Rational` cannot be applied to the left-hand operand (`this`). Making `operator*` a non-member allows both operands to undergo implicit conversion.

## Code Example

```cpp
class Rational {
public:
    Rational(int numerator = 0, int denominator = 1)  // non-explicit: allows implicit conversion
        : n(numerator), d(denominator) {}

    int numerator() const { return n; }
    int denominator() const { return d; }

private:
    int n, d;
};

// Non-member: allows implicit conversion on BOTH arguments
const Rational operator*(const Rational& lhs, const Rational& rhs) {
    return Rational(lhs.numerator() * rhs.numerator(),
                    lhs.denominator() * rhs.denominator());
}

void example() {
    Rational oneHalf(1, 2);
    Rational result;

    result = oneHalf * 2;   // OK: 2 implicitly converts to Rational(2)
    result = 2 * oneHalf;   // OK: same implicit conversion on first arg
    // Both work because operator* is a non-member
}
```

[Full source code](https://github.com/henrytien/effective-cpp-3rd/blob/master/src/Item24/source.cpp)

## Things to Remember

- If you need type conversions on all parameters to a function (including the one that would otherwise be pointed to by the `this` pointer), the function must be a non-member.
- This is most commonly relevant for operator overloads for numeric-like classes.

## Related Items

- [Item 23](../chapter-04/item-23.md) — Prefer non-member non-friend functions
- [Item 21](../chapter-04/item-21.md) — Returning objects by value
- [Item 46](../chapter-07/item-46.md) — Define non-member functions inside templates when type conversions are desired
