---
sidebar_position: 3
---

# Item 51: Adhere to convention when writing new and delete

## Concept

Custom `operator new` must follow specific conventions: it must return the right value (a pointer on success, throw `bad_alloc` on failure), it must handle zero-size requests (treat them as one-byte requests), and it must loop calling the new-handler until memory is available or the handler is null. Custom `operator delete` must safely handle null pointers. Class-specific versions must handle "wrong size" requests by forwarding to the global versions, since derived classes inherit these operators but may have different sizes.

## Code Example

```cpp
#include <new>
#include <cstdlib>

class Base {
public:
    static void* operator new(std::size_t size) {
        // Handle wrong-size requests (from derived classes)
        if (size != sizeof(Base))
            return ::operator new(size);

        // The required loop
        while (true) {
            void* pMem = std::malloc(size);
            if (pMem) return pMem;

            // Allocation failed; call new-handler or throw
            std::new_handler handler = std::get_new_handler();
            if (handler) handler();
            else throw std::bad_alloc();
        }
    }

    static void operator delete(void* pMemory, std::size_t size) noexcept {
        if (!pMemory) return;  // Must handle null

        // Handle wrong-size requests
        if (size != sizeof(Base)) {
            ::operator delete(pMemory);
            return;
        }
        std::free(pMemory);
    }
};
```

[Full source code](https://github.com/henrytien/effective-cpp-3rd/blob/master/src/Item51/source.cpp)

## Things to Remember

- `operator new` should contain an infinite loop trying to allocate memory, should call the new-handler if it can't satisfy a memory request, and should handle requests for zero bytes. Class-specific versions should handle requests for larger blocks than expected.
- `operator delete` should do nothing if passed a pointer that is null. Class-specific versions should handle blocks that are larger than expected.

## Related Items

- [Item 49](../chapter-08/item-49.md) — The new-handler is called in the allocation loop
- [Item 50](../chapter-08/item-50.md) — Reasons to replace new and delete
- [Item 52](../chapter-08/item-52.md) — Placement delete must pair with placement new
