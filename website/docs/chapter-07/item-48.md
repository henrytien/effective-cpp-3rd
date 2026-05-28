---
sidebar_position: 8
---

# Item 48: Be aware of template metaprogramming

## Concept

Template metaprogramming (TMP) is writing programs that execute at compile time within the C++ compiler. TMP is Turing-complete — it can compute anything computable, using recursive template instantiations for loops and template specializations for conditionals. TMP shifts work from runtime to compile time, enabling earlier error detection, better performance (smaller executables, shorter runtimes), and solutions to problems that are difficult at runtime. Modern C++ offers `constexpr` and `consteval` as more readable alternatives for compile-time computation.

## Code Example

```cpp
// Classic TMP: compile-time factorial via recursive instantiation
template <unsigned N>
struct Factorial {
    static constexpr unsigned value = N * Factorial<N - 1>::value;
};

template <>
struct Factorial<0> {
    static constexpr unsigned value = 1;
};

// Modern C++ equivalent using constexpr
constexpr unsigned factorial(unsigned n) {
    return n == 0 ? 1 : n * factorial(n - 1);
}

// Usage: computed entirely at compile time
static_assert(Factorial<5>::value == 120);
static_assert(factorial(5) == 120);

// TMP for type manipulation
template <typename T>
struct RemoveConst { using type = T; };

template <typename T>
struct RemoveConst<const T> { using type = T; };
```

[Full source code](https://github.com/henrytien/effective-cpp-3rd/blob/master/src/Item48/source.cpp)

## Things to Remember

- Template metaprogramming can shift work from runtime to compile-time, thus enabling earlier error detection and higher runtime performance.
- TMP can be used to generate custom code based on combinations of policy choices, and it can also be used to avoid generating code inappropriate for particular types.

## Related Items

- [Item 47](../chapter-07/item-47.md) — Traits classes are a key TMP building block
- [Item 44](../chapter-07/item-44.md) — Factor parameter-independent code to control bloat from TMP
- [Item 41](../chapter-07/item-41.md) — Compile-time polymorphism (TMP is the extreme form)
