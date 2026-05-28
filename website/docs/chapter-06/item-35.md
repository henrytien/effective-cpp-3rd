---
sidebar_position: 4
---

# Item 35: Consider alternatives to virtual functions

## Concept

Virtual functions are not the only way to achieve polymorphic behavior. The Non-Virtual Interface (NVI) idiom uses a non-virtual public function that calls a private virtual function, giving the base class control over before/after logic. The Strategy pattern (via function pointers or `std::function`) decouples the algorithm from the class hierarchy entirely. These alternatives provide greater flexibility in controlling when and how customization occurs, and allow runtime swapping of behavior.

## Code Example

```cpp
#include <functional>

// NVI idiom: non-virtual interface wraps virtual implementation
class GameCharacter {
public:
    int healthValue() const {
        // "before" logic
        int result = doHealthValue();
        // "after" logic
        return result;
    }
    virtual ~GameCharacter() = default;
private:
    virtual int doHealthValue() const { return 10; }
};

// Strategy via std::function — runtime-swappable behavior
class FlexibleCharacter {
public:
    using HealthCalcFunc = std::function<int(const FlexibleCharacter&)>;

    explicit FlexibleCharacter(HealthCalcFunc hcf)
        : healthFunc_(std::move(hcf)) {}

    int healthValue() const { return healthFunc_(*this); }
private:
    HealthCalcFunc healthFunc_;
};
```

[Full source code (classic strategy)](https://github.com/henrytien/effective-cpp-3rd/blob/master/src/Item35/classic_strategy_pattern.cpp)

[Full source code (std::function strategy)](https://github.com/henrytien/effective-cpp-3rd/blob/master/src/Item35/function_strategy_pattern.cpp)

## Things to Remember

- Alternatives to virtual functions include the NVI idiom and various forms of the Strategy design pattern. The NVI idiom is itself a form of the Template Method design pattern.
- A disadvantage of moving functionality from a member function to a function outside the class is that the non-member function lacks access to the class's non-public members.
- `std::function` objects act like generalized function pointers. Such objects support all callable entities compatible with a given target signature.

## Related Items

- [Item 34](../chapter-06/item-34.md) — Inheritance of interface vs implementation (what virtual functions mean)
- [Item 38](../chapter-06/item-38.md) — Composition as an alternative to inheritance
- [Item 41](../chapter-07/item-41.md) — Implicit interfaces and compile-time polymorphism
