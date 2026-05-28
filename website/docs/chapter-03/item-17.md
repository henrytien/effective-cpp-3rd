---
sidebar_position: 5
---

# Item 17: Store newed objects in smart pointers in standalone statements

## Concept

If you combine a `new` expression with other operations in a single statement, an exception thrown between the `new` and the smart pointer construction can lead to a resource leak. C++ compilers have flexibility in the order they evaluate function arguments, so a call like `processWidget(std::shared_ptr<Widget>(new Widget), priority())` could leak if `priority()` throws between the `new` and the `shared_ptr` construction. The fix is to store the newed object in a smart pointer in its own standalone statement.

## Code Example

```cpp
#include <memory>

class Widget { /* ... */ };
int priority() { return 1; }
void processWidget(std::shared_ptr<Widget> pw, int prio) { /* ... */ }

void problematic() {
    // DANGEROUS: potential resource leak!
    // If priority() is called between new Widget and shared_ptr ctor,
    // and priority() throws, the Widget is leaked.
    processWidget(std::shared_ptr<Widget>(new Widget), priority());
}

void safe() {
    // SAFE: standalone statement ensures no leak
    std::shared_ptr<Widget> pw(new Widget);
    processWidget(pw, priority());

    // Even better in C++14+: use make_shared
    processWidget(std::make_shared<Widget>(), priority());
}
```

[Full source code](https://github.com/henrytien/effective-cpp-3rd/blob/master/src/Item17/source.cpp)

## Things to Remember

- Store newed objects in smart pointers in standalone statements. Failure to do this can lead to subtle resource leaks when exceptions are thrown.
- Prefer `std::make_shared` and `std::make_unique` (C++14) which avoid this problem entirely.

## Related Items

- [Item 13](../chapter-03/item-13.md) — RAII and smart pointers for resource management
- [Item 29](../chapter-05/item-29.md) — Exception safety
- [Item 18](../chapter-04/item-18.md) — Making interfaces easy to use correctly
