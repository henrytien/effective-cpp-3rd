---
sidebar_position: 1
---

# Item 5: Know what functions C++ silently writes and calls

## Concept

When you declare an empty class, the compiler will implicitly generate a default constructor, a copy constructor, a copy assignment operator, and a destructor. These are all public and inline. The compiler-generated copy constructor and copy assignment operator simply copy each non-static data member from the source object to the target object. The compiler refuses to generate a copy assignment operator if the result would be code that is illegal or unreasonable (e.g., classes containing reference members or const members).

## Code Example

```cpp
// You write this:
class Empty {};

// The compiler effectively generates this:
class Empty {
public:
    Empty() { }                            // default constructor
    Empty(const Empty& rhs) { }            // copy constructor
    ~Empty() { }                           // destructor
    Empty& operator=(const Empty& rhs) { } // copy assignment operator
};

// These are generated only if they are needed:
Empty e1;       // default constructor, destructor
Empty e2(e1);   // copy constructor
e2 = e1;        // copy assignment operator
```

[Full source code](https://github.com/henrytien/effective-cpp-3rd/blob/master/src/Item05/source.cpp)

## Things to Remember

- Compilers may implicitly generate a class's default constructor, copy constructor, copy assignment operator, and destructor.
- The generated destructor is non-virtual unless the class inherits from a base class that itself declares a virtual destructor.
- The compiler refuses to generate operator= for classes with reference members, const members, or base classes with private copy assignment operators.

## Related Items

- [Item 6](../chapter-02/item-06.md) — Explicitly disallowing compiler-generated functions
- [Item 7](../chapter-02/item-07.md) — When the generated destructor should be virtual
- [Item 12](../chapter-02/item-12.md) — Copying all parts of an object
