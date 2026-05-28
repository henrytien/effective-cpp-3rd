---
sidebar_position: 1
---

# Item 32: Make sure public inheritance models "is-a"

## Concept

Public inheritance asserts an "is-a" relationship: every object of the derived class is also an object of the base class. This is the Liskov Substitution Principle — anywhere a base class object is expected, a derived class object must work correctly. If you cannot truthfully say that a derived class "is-a" base class in every context, public inheritance is the wrong tool. Classic pitfalls include modeling Square as publicly inheriting from Rectangle, or Penguin from Bird (if Bird has a fly method).

## Code Example

```cpp
class Bird {
public:
    virtual ~Bird() = default;
    // Not all birds can fly — design matters
};

class FlyingBird : public Bird {
public:
    virtual void fly() { /* ... */ }
};

class Penguin : public Bird {
    // Correct: Penguin is-a Bird, but not a FlyingBird
};

// Function expecting a base class reference
void feedBird(const Bird& b) {
    // Works with any Bird — Penguin included
}
```

[Full source code](https://github.com/henrytien/effective-cpp-3rd/blob/master/src/Item32/source.cpp)

## Things to Remember

- Public inheritance means "is-a." Everything that applies to base classes must also apply to derived classes, because every derived class object is a base class object.

## Related Items

- [Item 36](../chapter-06/item-36.md) — Never redefine an inherited non-virtual function (preserves is-a contract)
- [Item 38](../chapter-06/item-38.md) — Model "has-a" through composition when is-a doesn't apply
- [Item 39](../chapter-06/item-39.md) — Private inheritance for is-implemented-in-terms-of
