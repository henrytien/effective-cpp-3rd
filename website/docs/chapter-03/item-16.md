---
sidebar_position: 4
---

# Item 16: Use the same form in corresponding uses of new and delete

## Concept

When you use `new`, two things happen: memory is allocated and one or more constructors are called. When you use `delete`, two things happen: one or more destructors are called and memory is deallocated. The critical question is how many objects reside in the memory being deleted. If you used `new[]` (array form), you must use `delete[]`. If you used `new` (single object form), you must use `delete`. Using the wrong form results in undefined behavior because the memory layout for arrays includes the array size.

## Code Example

```cpp
#include <string>

void correct_usage() {
    // Single object: new matched with delete
    std::string* stringPtr1 = new std::string;
    delete stringPtr1;

    // Array: new[] matched with delete[]
    std::string* stringPtr2 = new std::string[100];
    delete[] stringPtr2;
}

void incorrect_usage() {
    // WRONG: undefined behavior!
    std::string* stringPtr = new std::string[100];
    // delete stringPtr;   // Should be delete[]!
}

// Be especially careful with typedefs
typedef std::string AddressLines[4];  // array typedef

void typedef_example() {
    std::string* pal = new AddressLines;  // same as new std::string[4]
    // delete pal;    // WRONG! Undefined behavior!
    delete[] pal;    // Correct — it's an array
}
```

[Full source code](https://github.com/henrytien/effective-cpp-3rd/blob/master/src/Item16/source.cpp)

## Things to Remember

- If you use `[]` in a `new` expression, you must use `[]` in the corresponding `delete` expression. If you don't use `[]` in a `new` expression, you mustn't use `[]` in the corresponding `delete` expression.
- Be wary of typedefs for array types; prefer `std::vector` or `std::array` instead.

## Related Items

- [Item 13](../chapter-03/item-13.md) — Using RAII to manage resources and avoid manual delete
- [Item 17](../chapter-03/item-17.md) — Storing newed objects in smart pointers
