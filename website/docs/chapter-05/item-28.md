---
sidebar_position: 3
---

# Item 28: Avoid returning "handles" to object internals

## Concept

Returning references, pointers, or iterators to internal data violates encapsulation and can lead to dangling handles. Even returning `const` references doesn't prevent dangling if the object is a temporary.

## Code Example

```cpp
class Rectangle {
public:
    // Bad: exposes internals
    Point& upperLeft() const { return pData->ulhc; }

    // Better but still risky with temporaries
    const Point& upperLeft() const { return pData->ulhc; }
};
```

[Full source code](https://github.com/henrytien/effective-cpp-3rd/blob/master/src/Item28/source.cpp)

## Things to Remember

- Avoid returning handles (references, pointers, or iterators) to object internals. It increases encapsulation, helps `const` member functions act `const`, and minimizes dangling handles.

## Related Items

- [Item 3](../chapter-01/item-03.md) — Use const whenever possible
- [Item 22](../chapter-04/item-22.md) — Declare data members private
