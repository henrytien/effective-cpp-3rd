---
sidebar_position: 1
---

# Item 1: View C++ as a federation of languages

## Concept

C++ is not a single unified language — it's a federation of four sub-languages, each with its own conventions:

1. **C** — blocks, statements, preprocessor, built-in types, arrays, pointers
2. **Object-Oriented C++** — classes, encapsulation, inheritance, polymorphism, virtual functions
3. **Template C++** — generic programming, template metaprogramming (TMP)
4. **The STL** — containers, iterators, algorithms, function objects

Rules for effective programming vary depending on which sub-language you're using. For example, pass-by-value is efficient for built-in C types, but pass-by-reference-to-const is generally preferred in Object-Oriented C++.

## Code Example

```cpp
// Sub-language 1: C
void c_sublanguage() {
    int arr[] = {3, 1, 4, 1, 5};
    int* p = arr;
}

// Sub-language 2: Object-Oriented C++
class Shape {
public:
    virtual ~Shape() = default;
    virtual double area() const = 0;
};

// Sub-language 3: Template C++
template <typename Container>
void print_all(const Container& c) { /* ... */ }

// Sub-language 4: The STL
void stl_sublanguage() {
    std::vector<int> v = {5, 2, 8, 1, 9, 3};
    std::sort(v.begin(), v.end());
}
```

[Full source code](https://github.com/henrytien/effective-cpp-3rd/blob/master/src/Item01/source.cpp)

## Things to Remember

- Rules for effective C++ programming vary, depending on the part of C++ you are using.

## Related Items

- [Item 20](../chapter-04/item-20.md) — Pass-by-reference-to-const vs pass-by-value (rules differ per sub-language)
- [Item 41](../chapter-07/item-41.md) — Implicit interfaces and compile-time polymorphism (Template C++)
- [Item 54](../chapter-09/item-54.md) — The standard library (STL sub-language)
