---
sidebar_position: 3
---

# Item 7: Declare destructors virtual in polymorphic base classes

## Concept

When a derived class object is deleted through a pointer to a base class with a non-virtual destructor, the behavior is undefined — typically the derived part of the object is never destroyed. Any class with virtual functions should almost certainly have a virtual destructor. Conversely, classes not designed to be base classes or not designed to be used polymorphically should not declare virtual destructors, because virtual functions add the overhead of a vptr (virtual table pointer).

## Code Example

```cpp
class TimeKeeper {
public:
    TimeKeeper() {}
    virtual ~TimeKeeper() {}  // virtual destructor is essential
    virtual void getCurrentTime() const = 0;
};

class AtomicClock : public TimeKeeper {
public:
    ~AtomicClock() override { /* cleanup atomic clock resources */ }
    void getCurrentTime() const override { /* ... */ }
};

// Correct usage with polymorphic deletion
TimeKeeper* ptk = new AtomicClock();
delete ptk;  // Correctly calls ~AtomicClock() then ~TimeKeeper()

// Without virtual destructor, this would be undefined behavior!
```

[Full source code](https://github.com/henrytien/effective-cpp-3rd/blob/master/src/Item07/source.cpp)

## Things to Remember

- Polymorphic base classes should declare virtual destructors. If a class has any virtual functions, it should have a virtual destructor.
- Classes not designed to be base classes or not designed to be used polymorphically should not declare virtual destructors.
- Don't inherit from classes with non-virtual destructors (e.g., `std::string`, STL containers).

## Related Items

- [Item 5](../chapter-02/item-05.md) — Compiler-generated destructors are non-virtual by default
- [Item 9](../chapter-02/item-09.md) — Virtual function behavior during construction and destruction
- [Item 34](../chapter-06/item-34.md) — Differentiate between inheritance of interface and implementation
