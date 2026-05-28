---
sidebar_position: 2
---

# Item 33: Avoid hiding inherited names

## Concept

Name hiding in C++ occurs when a derived class declares a name that matches one in a base class — the derived class name hides all base class overloads of that name, regardless of parameter types. This is a scope-based hiding rule, not an override rule. To make hidden base class names visible again, use `using` declarations in the derived class. This is especially surprising when the base class has overloaded functions and the derived class only redefines one of them.

## Code Example

```cpp
class Base {
public:
    virtual void mf1() { /* ... */ }
    virtual void mf1(int x) { /* ... */ }
    void mf2() { /* ... */ }
};

class Derived : public Base {
public:
    using Base::mf1;    // Make all Base::mf1 overloads visible
    using Base::mf2;    // Unhide Base::mf2

    virtual void mf1() override { /* ... */ } // overrides Base::mf1()
    // Base::mf1(int) is still accessible thanks to using declaration
};
```

[Full source code](https://github.com/henrytien/effective-cpp-3rd/blob/master/src/Item33/source.cpp)

## Things to Remember

- Names in derived classes hide names in base classes. Under public inheritance, this is never desirable.
- To make hidden names visible again, employ `using` declarations or forwarding functions.

## Related Items

- [Item 32](../chapter-06/item-32.md) — Public inheritance models is-a (hiding breaks the contract)
- [Item 36](../chapter-06/item-36.md) — Never redefine an inherited non-virtual function
- [Item 43](../chapter-07/item-43.md) — Accessing names in templatized base classes (similar hiding issues)
