---
sidebar_position: 3
---

# Item 15: Provide access to raw resources in resource-managing classes

## Concept

RAII classes exist to prevent resource leaks, but many APIs require access to raw resources. You need to provide a way to get at the raw resource. This can be done via explicit conversion (a `get()` member function) or implicit conversion (an `operator` conversion function). Explicit conversion is safer; implicit conversion is more convenient for clients but increases the chance of errors. Generally, explicit conversion via `get()` is preferred.

## Code Example

```cpp
#include <memory>

class Investment {
public:
    virtual ~Investment() = default;
    bool isTaxFree() const { return false; }
};

// Existing C API that expects raw pointer
int daysHeld(const Investment* pi) { return 100; }
bool isTaxFree(const Investment* pi) { return pi->isTaxFree(); }

void example() {
    std::shared_ptr<Investment> pInv(new Investment());

    // Explicit access via get()
    int days = daysHeld(pInv.get());

    // Implicit via operator-> and operator*
    bool taxFree = pInv->isTaxFree();
    bool taxFree2 = (*pInv).isTaxFree();
}

// Custom RAII class with explicit conversion
class Font {
public:
    explicit Font(int fontHandle) : f(fontHandle) {}
    ~Font() { releaseFont(f); }

    int get() const { return f; }  // explicit conversion

private:
    int f;
    static void releaseFont(int) { /* release */ }
};
```

[Full source code](https://github.com/henrytien/effective-cpp-3rd/blob/master/src/Item15/source.cpp)

## Things to Remember

- APIs often require access to raw resources, so each RAII class should offer a way to get at the resource it manages.
- Access may be via explicit conversion (e.g., `get()`) or implicit conversion. In general, explicit conversion is safer, though implicit conversion is more convenient.

## Related Items

- [Item 13](../chapter-03/item-13.md) — RAII and smart pointers
- [Item 14](../chapter-03/item-14.md) — Copying behavior in resource-managing classes
- [Item 18](../chapter-04/item-18.md) — Making interfaces easy to use correctly
