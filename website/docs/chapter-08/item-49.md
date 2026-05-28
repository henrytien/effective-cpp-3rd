---
sidebar_position: 1
---

# Item 49: Understand the behavior of the new-handler

## Concept

When `operator new` cannot satisfy a memory allocation request, it calls a new-handler function (set via `std::set_new_handler`) before throwing `std::bad_alloc`. A well-designed new-handler must do one of the following: make more memory available, install a different new-handler, deinstall the new-handler (passing null to set_new_handler), throw bad_alloc (or a derived exception), or not return (abort/exit). You can implement class-specific new-handlers to provide per-type allocation failure behavior by combining a class-specific `operator new` with a RAII handler-swapper.

## Code Example

```cpp
#include <new>
#include <iostream>

// Class-specific new-handler support
class Widget {
public:
    static std::new_handler set_new_handler(std::new_handler p) noexcept {
        std::new_handler old = currentHandler_;
        currentHandler_ = p;
        return old;
    }

    static void* operator new(std::size_t size) {
        // Install Widget's handler, save global handler
        std::new_handler globalHandler =
            std::set_new_handler(currentHandler_);

        void* memory;
        try {
            memory = ::operator new(size);
        } catch (...) {
            std::set_new_handler(globalHandler);  // Restore
            throw;
        }
        std::set_new_handler(globalHandler);  // Restore
        return memory;
    }

private:
    static std::new_handler currentHandler_;
};

std::new_handler Widget::currentHandler_ = nullptr;
```

[Full source code](https://github.com/henrytien/effective-cpp-3rd/blob/master/src/Item49/source.cpp)

## Things to Remember

- `set_new_handler` allows you to specify a function to be called when memory allocation requests cannot be satisfied.
- Nothrow new is of limited utility, because it applies only to memory allocation; associated constructor calls may still throw exceptions.

## Related Items

- [Item 50](../chapter-08/item-50.md) — When to replace new and delete
- [Item 51](../chapter-08/item-51.md) — Conventions when writing new and delete
- [Item 52](../chapter-08/item-52.md) — Placement delete paired with placement new
