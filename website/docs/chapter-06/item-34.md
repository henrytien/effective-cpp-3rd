---
sidebar_position: 3
---

# Item 34: Differentiate between inheritance of interface and inheritance of implementation

## Concept

When designing a base class, you have three distinct choices for each member function: pure virtual functions provide interface inheritance only (derived classes must implement them), simple virtual functions provide interface inheritance plus a default implementation, and non-virtual functions provide interface inheritance plus a mandatory implementation that derived classes should not override. Understanding these distinctions is crucial for designing class hierarchies that communicate intent clearly and prevent bugs from unintentional reliance on defaults.

## Code Example

```cpp
class Shape {
public:
    virtual ~Shape() = default;

    // Pure virtual: interface only — derived MUST implement
    virtual void draw() const = 0;

    // Simple virtual: interface + default implementation
    virtual void resize(double factor) {
        // Default behavior; derived classes may override
    }

    // Non-virtual: interface + mandatory implementation
    int objectID() const { return id_; }

private:
    int id_;
};

class Circle : public Shape {
public:
    void draw() const override { /* must implement */ }
    // resize() uses default; objectID() is inherited as-is
};
```

[Full source code](https://github.com/henrytien/effective-cpp-3rd/blob/master/src/Item34/source.cpp)

## Things to Remember

- Inheritance of interface is different from inheritance of implementation. Under public inheritance, derived classes always inherit base class interfaces.
- Pure virtual functions specify inheritance of interface only.
- Simple (impure) virtual functions specify inheritance of interface plus inheritance of a default implementation.
- Non-virtual functions specify inheritance of interface plus inheritance of a mandatory implementation.

## Related Items

- [Item 35](../chapter-06/item-35.md) — Consider alternatives to virtual functions (NVI, Strategy)
- [Item 36](../chapter-06/item-36.md) — Never redefine an inherited non-virtual function
- [Item 32](../chapter-06/item-32.md) — Public inheritance models is-a
