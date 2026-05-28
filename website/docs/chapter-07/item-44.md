---
sidebar_position: 4
---

# Item 44: Factor parameter-independent code out of templates

## Concept

Templates generate code for each instantiation. If a template contains code that doesn't actually depend on a template parameter (especially non-type parameters like integer sizes), every instantiation duplicates that code, causing "code bloat." The solution is to factor parameter-independent code into a non-template base class or a template with fewer parameters. For non-type parameters, replace them with function parameters or data members. For type parameters, share implementations where the binary representation is identical (e.g., all pointer types can share one implementation).

## Code Example

```cpp
// Before: code bloat — separate code for each N
template <typename T, std::size_t N>
class SquareMatrix {
public:
    void invert();  // Duplicated for every N
private:
    T data_[N * N];
};

// After: factor out size-independent logic
template <typename T>
class SquareMatrixBase {
protected:
    void invert(std::size_t n, T* data);  // Shared implementation
};

template <typename T, std::size_t N>
class SquareMatrix : private SquareMatrixBase<T> {
public:
    void invert() {
        this->invert(N, data_);  // Thin inline call
    }
private:
    T data_[N * N];
};
```

[Full source code](https://github.com/henrytien/effective-cpp-3rd/blob/master/src/Item44/source.cpp)

## Things to Remember

- Templates generate multiple classes and multiple functions, so any template code not dependent on a template parameter causes bloat.
- Bloat due to non-type template parameters can often be eliminated by replacing template parameters with function parameters or class data members.
- Bloat due to type parameters can be reduced by sharing implementations for instantiation types that have identical binary representations.

## Related Items

- [Item 43](../chapter-07/item-43.md) — Accessing names in templatized base classes (uses this-> pattern)
- [Item 39](../chapter-06/item-39.md) — Private inheritance for implementation (used to share code)
- [Item 46](../chapter-07/item-46.md) — Non-member functions inside templates
