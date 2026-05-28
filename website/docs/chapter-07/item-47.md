---
sidebar_position: 7
---

# Item 47: Use traits classes for information about types

## Concept

Traits classes make information about types available at compile time, enabling template code to make decisions based on type properties without runtime overhead. The iterator_traits pattern is the canonical example: it provides information like value_type, iterator_category, etc., for any iterator type — including raw pointers — through template specialization. Combined with overload resolution or `if constexpr`, traits enable writing a single algorithm that adapts optimally to different type categories at compile time.

## Code Example

```cpp
#include <iterator>
#include <type_traits>

// Using iterator_traits to dispatch based on iterator category
template <typename IterT, typename DistT>
void doAdvance(IterT& iter, DistT d, std::random_access_iterator_tag) {
    iter += d;  // O(1) for random access
}

template <typename IterT, typename DistT>
void doAdvance(IterT& iter, DistT d, std::input_iterator_tag) {
    while (d--) ++iter;  // O(n) for input iterators
}

template <typename IterT, typename DistT>
void advance(IterT& iter, DistT d) {
    // traits class provides compile-time type information
    doAdvance(iter, d,
        typename std::iterator_traits<IterT>::iterator_category());
}
```

[Full source code](https://github.com/henrytien/effective-cpp-3rd/blob/master/src/Item47/source.cpp)

## Things to Remember

- Traits classes make information about types available during compilation. They're implemented using templates and template specializations.
- In conjunction with overloading, traits classes make it possible to perform compile-time `if...else` tests on types.

## Related Items

- [Item 42](../chapter-07/item-42.md) — typename required for dependent type names (used with traits)
- [Item 48](../chapter-07/item-48.md) — Template metaprogramming (traits enable TMP)
- [Item 41](../chapter-07/item-41.md) — Compile-time polymorphism (traits are a key mechanism)
