---
sidebar_position: 5
---

# Item 36: Never redefine an inherited non-virtual function

## Concept

Non-virtual functions are statically bound, meaning the function called depends on the declared type of the pointer or reference, not the actual runtime type of the object. Redefining a non-virtual function in a derived class creates inconsistent behavior: calling the function through a base pointer invokes the base version, while calling through a derived pointer invokes the derived version — for the same object. This violates the is-a relationship that public inheritance asserts and creates confusion.

## Code Example

```cpp
class Base {
public:
    void doWork() { /* Base version */ }
};

class Derived : public Base {
public:
    void doWork() { /* Derived version — DON'T DO THIS */ }
};

// The problem:
Derived d;
Base* bp = &d;
Derived* dp = &d;

bp->doWork();   // Calls Base::doWork — static binding!
dp->doWork();   // Calls Derived::doWork
// Same object, different behavior depending on pointer type
```

[Full source code](https://github.com/henrytien/effective-cpp-3rd/blob/master/src/Item36/source.cpp)

## Things to Remember

- Never redefine an inherited non-virtual function.

## Related Items

- [Item 32](../chapter-06/item-32.md) — Public inheritance models is-a (non-virtual redefinition breaks this)
- [Item 34](../chapter-06/item-34.md) — Non-virtual functions specify mandatory inherited implementation
- [Item 37](../chapter-06/item-37.md) — Never redefine inherited default parameter values (related static binding issue)
