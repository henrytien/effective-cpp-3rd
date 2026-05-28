---
sidebar_position: 2
---

# Item 50: Understand when it makes sense to replace new and delete

## Concept

There are several valid reasons to write custom `operator new` and `operator delete`: detecting usage errors (overruns, underruns, double deletes), collecting allocation statistics, increasing speed for specific allocation patterns, reducing default memory management overhead, achieving optimal alignment, clustering related objects in memory, or implementing unconventional behavior. However, writing correct replacements is harder than it appears — you must handle alignment requirements, thread safety, and all edge cases. Consider using well-tested allocator libraries before rolling your own.

## Code Example

```cpp
#include <cstddef>
#include <new>

// Custom operator new for debugging: adds signature bytes
// to detect overruns and underruns
static const int signature = 0xDEADBEEF;

void* operator new(std::size_t size) {
    // Allocate extra space for signatures before and after
    std::size_t realSize = size + 2 * sizeof(int);

    void* pMem = std::malloc(realSize);
    if (!pMem) throw std::bad_alloc();

    // Write signatures
    *(static_cast<int*>(pMem)) = signature;
    *(reinterpret_cast<int*>(
        static_cast<char*>(pMem) + sizeof(int) + size)) = signature;

    // Return pointer past the leading signature
    return static_cast<char*>(pMem) + sizeof(int);
}

// Note: this simplified example has alignment issues!
// Production code must ensure proper alignment.
```

[Full source code](https://github.com/henrytien/effective-cpp-3rd/blob/master/src/Item50/source.cpp)

## Things to Remember

- There are many valid reasons for writing custom versions of `new` and `delete`, including improving performance, debugging heap usage errors, and collecting heap usage information.

## Related Items

- [Item 49](../chapter-08/item-49.md) — The new-handler mechanism
- [Item 51](../chapter-08/item-51.md) — Conventions when writing new and delete
- [Item 16](../chapter-03/item-16.md) — Use the same form in corresponding uses of new and delete
