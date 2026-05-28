---
sidebar_position: 1
---

# Item 13: Use objects to manage resources

## Concept

Resource Acquisition Is Initialization (RAII) is the cornerstone of resource management in C++. By placing resources inside objects, you rely on C++'s automatic destructor invocation to ensure resources are released regardless of how control leaves a block. Smart pointers (`std::unique_ptr` and `std::shared_ptr`) are the most common RAII objects for heap-allocated memory. Resources are acquired during construction and released during destruction, making leaks nearly impossible.

## Code Example

```cpp
#include <memory>

class Investment {
public:
    virtual ~Investment() = default;
};

class StockInvestment : public Investment { /* ... */ };

// Factory function returning a smart pointer
std::unique_ptr<Investment> createInvestment() {
    return std::make_unique<StockInvestment>();
}

void f() {
    // RAII: resource acquired in initialization, released on scope exit
    auto pInv = createInvestment();

    // Use pInv...
    // No matter how we leave this block (return, exception, etc.),
    // the Investment object is automatically deleted
}

// For shared ownership:
void g() {
    std::shared_ptr<Investment> pInv1 = createInvestment();
    std::shared_ptr<Investment> pInv2 = pInv1;  // reference count = 2
    // Object deleted when last shared_ptr goes out of scope
}
```

[Full source code](https://github.com/henrytien/effective-cpp-3rd/blob/master/src/Item13/source.cpp)

## Things to Remember

- To prevent resource leaks, use RAII objects that acquire resources in their constructors and release them in their destructors.
- Two commonly useful RAII classes are `std::shared_ptr` and `std::unique_ptr`. `std::shared_ptr` is usually the better choice for shared ownership; `std::unique_ptr` for exclusive ownership.

## Related Items

- [Item 14](../chapter-03/item-14.md) — Copying behavior in resource-managing classes
- [Item 15](../chapter-03/item-15.md) — Providing access to raw resources
- [Item 17](../chapter-03/item-17.md) — Storing newed objects in smart pointers in standalone statements
- [Item 18](../chapter-04/item-18.md) — Making interfaces easy to use correctly
