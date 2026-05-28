---
sidebar_position: 6
---

# Item 37: Never redefine a function's inherited default parameter value

## Concept

Default parameter values are statically bound, even when the function they're attached to is virtual (dynamically bound). This means that if you override a virtual function and give it a different default parameter value, calling the function through a base class pointer or reference will use the base class's default value — even though the derived class's function body executes. This mismatch between static default binding and dynamic function binding leads to confusing and error-prone behavior.

## Code Example

```cpp
class Shape {
public:
    enum Color { Red, Green, Blue };
    virtual void draw(Color c = Red) const = 0;
    virtual ~Shape() = default;
};

class Circle : public Shape {
public:
    // BAD: redefining default parameter
    void draw(Color c = Green) const override {
        // If called via Shape*, default is Red (base class), not Green!
    }
};

// The problem:
Shape* sp = new Circle;
sp->draw();  // Calls Circle::draw(Red) — not Green!
             // Dynamic binding picks Circle::draw
             // Static binding picks Shape's default: Red
```

[Full source code](https://github.com/henrytien/effective-cpp-3rd/blob/master/src/Item37/source.cpp)

## Things to Remember

- Never redefine an inherited default parameter value, because default parameter values are statically bound, while virtual functions — the only functions you should be overriding — are dynamically bound.

## Related Items

- [Item 36](../chapter-06/item-36.md) — Never redefine an inherited non-virtual function (static binding issue)
- [Item 35](../chapter-06/item-35.md) — NVI idiom as a solution (base controls defaults via non-virtual wrapper)
- [Item 34](../chapter-06/item-34.md) — Interface vs implementation inheritance
