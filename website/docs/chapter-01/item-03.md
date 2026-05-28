---
sidebar_position: 3
---

# Item 3: Use const whenever possible

## Concept

`const` communicates semantic constraints to compilers and other programmers. It can apply to:
- Pointers (`const char*` vs `char* const`)
- Iterators (`const_iterator`)
- Function return types and parameters
- Member functions (logical constness via `mutable`)

## Code Example

```cpp
// const with pointers
const char* p1 = "Hello";    // pointer to const data
char* const p2 = buf;        // const pointer to non-const data

// const member functions
class TextBlock {
public:
    const char& operator[](std::size_t pos) const {
        return text[pos];
    }
    char& operator[](std::size_t pos) {
        return const_cast<char&>(
            static_cast<const TextBlock&>(*this)[pos]
        );
    }
private:
    std::string text;
};
```

[Full source code](https://github.com/henrytien/effective-cpp-3rd/blob/master/src/Item03/Source.cpp)

## Things to Remember

- Declaring something `const` helps compilers detect usage errors.
- Compilers enforce bitwise constness, but you should program using logical constness.
- When `const` and non-`const` member functions have essentially identical implementations, the non-`const` version can call the `const` version to avoid duplication.

## Related Items

- [Item 2](./item-02.md) — Prefer consts to #defines
- [Item 21](../chapter-04/item-21.md) — Don't try to return a reference when you must return an object
