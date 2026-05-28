---
sidebar_position: 1
---

# Item 26: Postpone variable definitions as long as possible

## Concept

Define variables right before you need them, and ideally with initial values. This avoids paying for construction and destruction of objects you may never use (e.g., if an exception is thrown early). It also makes code clearer by keeping definitions close to their use.

## Code Example

```cpp
// Bad: defined too early, may never be used
std::string encrypt(const std::string& password) {
    std::string encrypted;  // unnecessary if exception thrown
    if (password.length() < 8)
        throw std::logic_error("too short");
    encrypted = password;   // default ctor + assignment
    return encrypted;
}

// Good: defined at point of use with initialization
std::string encrypt(const std::string& password) {
    if (password.length() < 8)
        throw std::logic_error("too short");
    std::string encrypted(password);  // single construction
    return encrypted;
}
```

[Full source code](https://github.com/henrytien/effective-cpp-3rd/blob/master/src/Item26/source.cpp)

## Things to Remember

- Postpone variable definitions as long as possible. It increases program clarity and improves program efficiency.

## Related Items

- [Item 4](../chapter-01/item-04.md) — Make sure objects are initialized before use
- [Item 13](../chapter-03/item-13.md) — Use objects to manage resources
