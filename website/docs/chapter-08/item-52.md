---
sidebar_position: 4
---

# Item 52: Write placement delete if you write placement new

## Concept

When a `new` expression allocates memory and the constructor throws, the runtime must deallocate the memory using a matching `operator delete`. A "placement" version of `operator new` is any version taking extra parameters beyond `std::size_t`. If you write a placement `operator new`, you must also write a matching placement `operator delete` (same extra parameters) — otherwise memory will leak when constructors throw. Additionally, declaring any `operator new` in a class hides the standard forms, so use `using` declarations to keep them accessible.

## Code Example

```cpp
#include <new>
#include <iostream>

class Widget {
public:
    // Placement new: logs allocation
    static void* operator new(std::size_t size, std::ostream& log) {
        log << "Allocating " << size << " bytes\n";
        return ::operator new(size);
    }

    // Matching placement delete — MUST exist!
    // Called if constructor throws after placement new succeeds
    static void operator delete(void* pMemory, std::ostream& log) noexcept {
        log << "Deallocating due to constructor failure\n";
        ::operator delete(pMemory);
    }

    // Normal delete for regular deallocation
    static void operator delete(void* pMemory) noexcept {
        ::operator delete(pMemory);
    }

    // Unhide standard forms
    using Base = void;  // Placeholder; in practice:
    // static void* operator new(std::size_t size);
    // static void* operator new(std::size_t, void*);
    // static void* operator new(std::size_t, const std::nothrow_t&);
};

// Usage:
// Widget* pw = new (std::cerr) Widget;  // Uses placement new
```

[Full source code](https://github.com/henrytien/effective-cpp-3rd/blob/master/src/Item52/source.cpp)

## Things to Remember

- When you write a placement version of `operator new`, be sure to write the corresponding placement version of `operator delete`. If you don't, your program may experience subtle, intermittent memory leaks.
- When you declare placement versions of `new` and `delete`, be sure not to unintentionally hide the normal versions of those functions.

## Related Items

- [Item 49](../chapter-08/item-49.md) — The new-handler mechanism
- [Item 51](../chapter-08/item-51.md) — Conventions for writing new and delete
- [Item 33](../chapter-06/item-33.md) — Avoid hiding inherited names (same hiding issue with operator new)
