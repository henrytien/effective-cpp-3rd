---
sidebar_position: 1
---

# Item 41: Understand implicit interfaces and compile-time polymorphism

## Concept

Object-oriented programming revolves around explicit interfaces (virtual function signatures) and runtime polymorphism (dynamic dispatch via vtables). Template programming revolves around implicit interfaces (the set of expressions that must be valid for a type) and compile-time polymorphism (template instantiation and overload resolution at compile time). A template parameter doesn't need to inherit from any particular class — it just needs to support the operations the template uses. This is "duck typing" resolved at compile time.

## Code Example

```cpp
// OOP: explicit interface, runtime polymorphism
class Widget {
public:
    virtual ~Widget() = default;
    virtual void draw() const = 0;   // explicit interface
    virtual int size() const = 0;
};

void render(const Widget& w) {
    w.draw();  // runtime polymorphism via vtable
}

// Templates: implicit interface, compile-time polymorphism
template <typename T>
void doProcessing(T& w) {
    // T must support: .size(), .draw(), operator!=, copy
    // This is T's implicit interface — not declared anywhere
    if (w.size() > 10) {
        w.draw();
    }
}
```

[Full source code](https://github.com/henrytien/effective-cpp-3rd/blob/master/src/Item41/source.cpp)

## Things to Remember

- Both classes and templates support interfaces and polymorphism.
- For classes, interfaces are explicit and centered on function signatures. Polymorphism occurs at runtime through virtual functions.
- For template parameters, interfaces are implicit and based on valid expressions. Polymorphism occurs during compilation through template instantiation and function overloading resolution.

## Related Items

- [Item 1](../chapter-01/item-01.md) — Template C++ as a sub-language of C++
- [Item 34](../chapter-06/item-34.md) — Interface inheritance in OOP (explicit interfaces)
- [Item 47](../chapter-07/item-47.md) — Traits classes for type information at compile time
