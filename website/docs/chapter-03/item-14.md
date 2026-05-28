---
sidebar_position: 2
---

# Item 14: Think carefully about copying behavior in resource-managing classes

## Concept

Not all resources are heap-based, so smart pointers are not always appropriate for RAII. When writing your own resource-managing class, you must carefully consider what copying means. There are four common approaches: prohibit copying (like mutexes), reference-count the underlying resource (like `std::shared_ptr`), copy the underlying resource (deep copy), or transfer ownership (like `std::unique_ptr`). The choice depends on the resource semantics you want.

## Code Example

```cpp
#include <memory>
#include <mutex>

// Example: RAII class for mutex locking
class Lock {
public:
    explicit Lock(std::mutex& m) : mutexPtr(&m, unlock) {
        mutexPtr.get()->lock();
    }
    // shared_ptr with custom deleter handles reference counting
    // When last Lock is destroyed, the mutex is unlocked
private:
    static void unlock(std::mutex* pm) { pm->unlock(); }
    std::shared_ptr<std::mutex> mutexPtr;
};

// Option 1: Prohibit copying (= delete)
class UniqueResource {
public:
    UniqueResource(const UniqueResource&) = delete;
    UniqueResource& operator=(const UniqueResource&) = delete;
};

// Option 2: Reference-count (shared_ptr with custom deleter)
// Option 3: Deep copy the underlying resource
// Option 4: Transfer ownership (move semantics / unique_ptr)
```

[Full source code](https://github.com/henrytien/effective-cpp-3rd/blob/master/src/Item14/source.cpp)

## Things to Remember

- Copying an RAII object entails copying the resource it manages, so the copying behavior of the resource determines the copying behavior of the RAII object.
- Common RAII class copying behaviors are: disallowing copying, reference counting, deep copying, and transferring ownership of the underlying resource.

## Related Items

- [Item 6](../chapter-02/item-06.md) — Disallowing compiler-generated copy functions
- [Item 13](../chapter-03/item-13.md) — Using objects to manage resources (RAII)
- [Item 15](../chapter-03/item-15.md) — Providing access to raw resources
