---
sidebar_position: 8
---

# Item 39: Use private inheritance judiciously

## Concept

Private inheritance means "is-implemented-in-terms-of" — it's a pure implementation technique. Unlike public inheritance, the compiler will not implicitly convert a derived class object to a base class object, and all inherited members become private in the derived class. Private inheritance should generally be replaced by composition, but it's necessary when you need access to protected members or need to override virtual functions. It can also enable the Empty Base Optimization (EBO) when composing with an empty class would waste space.

## Code Example

```cpp
class Timer {
public:
    virtual ~Timer() = default;
    void start();
protected:
    virtual void onTick() { /* default tick handler */ }
};

// Private inheritance: need to override onTick but don't want
// clients to use Widget as a Timer
class Widget : private Timer {
private:
    void onTick() override {
        // Update widget state on each tick
    }
};

// Empty Base Optimization example
class Empty {};  // sizeof(Empty) == 1 typically

class HoldsInt {
    int x_;
    Empty e_;  // Wastes space due to alignment
};             // sizeof(HoldsInt) > sizeof(int)

class HoldsIntEBO : private Empty {
    int x_;
};             // sizeof(HoldsIntEBO) == sizeof(int) — EBO applied
```

[Full source code](https://github.com/henrytien/effective-cpp-3rd/blob/master/src/Item39/source.cpp)

## Things to Remember

- Private inheritance means is-implemented-in-terms-of. It's usually inferior to composition, but it makes sense when a derived class needs access to protected base class members or needs to redefine inherited virtual functions.
- Unlike composition, private inheritance can enable the empty base optimization. This can be important for library developers who strive to minimize object sizes.

## Related Items

- [Item 38](../chapter-06/item-38.md) — Composition is the preferred way to model is-implemented-in-terms-of
- [Item 32](../chapter-06/item-32.md) — Public inheritance models is-a (private inheritance does not)
- [Item 40](../chapter-06/item-40.md) — Multiple inheritance judiciously
