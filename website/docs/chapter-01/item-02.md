---
sidebar_position: 2
---

# Item 2: Prefer consts, enums, and inlines to #defines

## Concept

Prefer the compiler to the preprocessor. `#define` doesn't enter the symbol table, making debugging harder. Use:

- `const` or `constexpr` for constants
- `enum` hack for class-scope integer constants
- `inline` functions (or templates) instead of `#define` macros

## Code Example

```cpp
// Bad: preprocessor macro
#define ASPECT_RATIO 1.653

// Good: typed constant
constexpr double AspectRatio = 1.653;

// Class-scope constant
class GamePlayer {
    static constexpr int NumTurns = 5;  // C++17 inline
    int scores[NumTurns];
};

// Bad: macro "function"
#define CALL_WITH_MAX(a, b) f((a) > (b) ? (a) : (b))

// Good: inline template
template<typename T>
inline const T& callWithMax(const T& a, const T& b) {
    return a > b ? a : b;
}
```

[Full source code](https://github.com/henrytien/effective-cpp-3rd/blob/master/src/Item02/Source.cpp)

## Things to Remember

- For simple constants, prefer `const` objects or `constexpr` to `#defines`.
- For function-like macros, prefer `inline` functions to `#defines`.

## Related Items

- [Item 3](./item-03.md) — Use const whenever possible
- [Item 30](../chapter-05/item-30.md) — Understand the ins and outs of inlining
- [Item 48](../chapter-07/item-48.md) — Template metaprogramming (compile-time computation)
