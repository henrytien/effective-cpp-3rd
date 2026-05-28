---
sidebar_position: 5
---

# Item 30: Understand the ins and outs of inlining

## Concept

Inline functions replace each call with the function body, eliminating call overhead but potentially increasing code size (code bloat). `inline` is a request to the compiler, not a command — compilers may refuse to inline functions that are too complex (loops, recursion, virtual calls). Functions defined in a class body are implicitly inline. Excessive inlining increases executable size, which can lead to additional paging and reduced instruction cache hit rates. Inlining also complicates debugging and binary upgrades.

## Code Example

```cpp
// Implicitly inline: defined inside class body
class Person {
public:
    int age() const { return theAge; }  // implicitly inline
private:
    int theAge;
};

// Explicitly inline
inline int square(int x) { return x * x; }

// Compilers will likely REFUSE to inline:
inline void complexFunction() {
    for (int i = 0; i < 1000; ++i) {
        // ... complex loop body
    }
}

// Virtual functions are almost never inlined (resolved at runtime)
class Base {
public:
    virtual void doSomething() { }  // rarely inlined even if declared inline
};

// Template functions are NOT necessarily inline
// (templates in headers != inline)
template<typename T>
T maximum(T a, T b) {  // NOT automatically inline just because it's a template
    return a > b ? a : b;
}

// Use inline for small, frequently-called functions:
template<typename T>
inline const T& std::max(const T& a, const T& b) {
    return a < b ? b : a;
}
```

[Full source code](https://github.com/henrytien/effective-cpp-3rd/blob/master/src/Item30/source.cpp)

## Things to Remember

- Limit most inlining to small, frequently called functions. This facilitates debugging and binary upgradability, minimizes potential code bloat, and maximizes the chances of greater program speed.
- Don't declare function templates inline just because they appear in header files.
- `inline` is a request, not a command. Compilers may silently decline to inline.

## Related Items

- [Item 2](../chapter-01/item-02.md) — Prefer consts, enums, and inlines to #defines
- [Item 31](../chapter-05/item-31.md) — Minimize compilation dependencies (header file implications)
