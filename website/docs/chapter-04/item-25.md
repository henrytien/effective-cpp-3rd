---
sidebar_position: 8
---

# Item 25: Consider support for a non-throwing swap

## Concept

The default `std::swap` copies three objects, which can be expensive for types that use the pimpl (pointer to implementation) idiom. You can provide an efficient swap by specializing `std::swap` for your type (or providing a member swap that the specialization calls). For class templates, you cannot partially specialize function templates, so you provide a non-member swap in your namespace and rely on argument-dependent lookup (ADL). The key rule: never throw from swap, because it is used to provide strong exception safety.

## Code Example

```cpp
#include <algorithm>

class WidgetImpl {
public:
    // ... lots of data
private:
    int a, b, c;
    std::vector<double> v;
};

class Widget {
public:
    Widget(const Widget& rhs);
    Widget& operator=(const Widget& rhs) {
        Widget temp(rhs);
        swap(temp);         // copy-and-swap idiom
        return *this;
    }

    void swap(Widget& other) noexcept {
        using std::swap;
        swap(pImpl, other.pImpl);  // just swap pointers — fast!
    }

private:
    WidgetImpl* pImpl;
};

// Non-member swap in the same namespace
void swap(Widget& a, Widget& b) noexcept {
    a.swap(b);
}

// Also specialize std::swap
namespace std {
    template<>
    void swap<Widget>(Widget& a, Widget& b) noexcept {
        a.swap(b);
    }
}

// Calling code should use:
template<typename T>
void doSomething(T& obj1, T& obj2) {
    using std::swap;   // make std::swap available
    swap(obj1, obj2);  // ADL finds the best swap
}
```

[Full source code](https://github.com/henrytien/effective-cpp-3rd/blob/master/src/Item25/source.cpp)

## Things to Remember

- Provide a `swap` member function when `std::swap` would be inefficient for your type. Make sure your swap doesn't throw exceptions.
- If you offer a member swap, also offer a non-member swap that calls the member. For classes (not templates), specialize `std::swap` too.
- When calling swap, employ a `using` declaration for `std::swap`, then call swap without namespace qualification (enables ADL).

## Related Items

- [Item 11](../chapter-02/item-11.md) — Copy-and-swap idiom for self-assignment safety
- [Item 29](../chapter-05/item-29.md) — Exception safety (swap is used for the strong guarantee)
- [Item 20](../chapter-04/item-20.md) — Efficiency considerations for user-defined types
