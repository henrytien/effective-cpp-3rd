---
sidebar_position: 4
---

# Item 29: Strive for exception-safe code

## Concept

Exception-safe functions offer one of three guarantees: the basic guarantee (invariants preserved, no leaks, but program state may change), the strong guarantee (state is rolled back to before the call if an exception is thrown — commit-or-rollback semantics), or the nothrow guarantee (never throws). The strong guarantee is often implementable via copy-and-swap: make a copy of the object, modify the copy, then swap in a non-throwing swap. A function's exception safety is only as strong as the weakest guarantee of the functions it calls.

## Code Example

```cpp
#include <memory>
#include <mutex>

class PrettyMenu {
public:
    // Strong guarantee via copy-and-swap
    void changeBackground(std::istream& imgSrc) {
        using std::swap;
        Lock ml(&mutex);  // RAII lock

        // Make a copy of the current state
        auto copy = std::make_shared<PMImpl>(*bgImage);

        // Modify the copy (if this throws, original is untouched)
        copy->bgImage.reset(new Image(imgSrc));
        ++copy->imageChanges;

        // Swap — commit the change (noexcept)
        swap(bgImage, copy);
    }

private:
    struct PMImpl {
        std::shared_ptr<Image> bgImage;
        int imageChanges;
    };
    std::mutex mutex;
    std::shared_ptr<PMImpl> bgImage;
};

// Three exception safety levels:
// 1. Basic guarantee: no leaks, invariants preserved
// 2. Strong guarantee: commit or rollback (copy-and-swap)
// 3. Nothrow guarantee: never throws (swap, simple ops on built-ins)
void noThrowFunc() noexcept {
    // Operations guaranteed not to throw
}
```

[Full source code](https://github.com/henrytien/effective-cpp-3rd/blob/master/src/Item29/source.cpp)

## Things to Remember

- Exception-safe functions leak no resources and allow no data structures to become corrupted, even when exceptions are thrown. Such functions offer the basic, strong, or nothrow guarantee.
- The strong guarantee can often be implemented via copy-and-swap, but the strong guarantee is not practical for all functions.
- A function can usually offer a guarantee no stronger than the weakest guarantee of the functions it calls.

## Related Items

- [Item 8](../chapter-02/item-08.md) — Prevent exceptions from leaving destructors
- [Item 11](../chapter-02/item-11.md) — Copy-and-swap for exception-safe assignment
- [Item 13](../chapter-03/item-13.md) — RAII for resource leak prevention
- [Item 25](../chapter-04/item-25.md) — Non-throwing swap
