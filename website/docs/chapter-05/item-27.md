---
sidebar_position: 2
---

# Item 27: Minimize casting

## Concept

Casts subvert the type system. Prefer C++-style casts (`static_cast`, `dynamic_cast`, `const_cast`, `reinterpret_cast`) over C-style casts. Avoid `dynamic_cast` in performance-sensitive code. Often, a redesign can eliminate the need for casting entirely.

## Code Example

```cpp
// Prefer static_cast for well-defined conversions
double d = static_cast<double>(numerator) / denominator;

// dynamic_cast is expensive — use virtual functions instead
if (auto* dp = dynamic_cast<Derived*>(basePtr)) {
    dp->special();
}
```

[Full source code](https://github.com/henrytien/effective-cpp-3rd/blob/master/src/Item27/source.cpp)

## Things to Remember

- Avoid casts whenever practical, especially `dynamic_cast` in performance-sensitive code.
- When casting is necessary, hide it inside a function.
- Prefer C++-style casts to old-style casts.

## Related Items

- [Item 3](../chapter-01/item-03.md) — Use const whenever possible
- [Item 34](../chapter-06/item-34.md) — Differentiate inheritance of interface and implementation
