---
sidebar_position: 4
---

# Item 4: Make sure that objects are initialized before they're used

## Concept

Reading uninitialized values yields undefined behavior. Rules:
- Always initialize objects before use
- Use member initialization lists in constructors (order must match declaration order)
- For non-local statics in different translation units, use the Singleton/local static idiom to avoid initialization order problems

## Code Example

```cpp
class PhoneNumber { /* ... */ };

class ABEntry {
public:
    // Good: use member initialization list
    ABEntry(const std::string& name, const std::string& address)
        : theName(name), theAddress(address), numTimesConsulted(0)
    {}
private:
    std::string theName;
    std::string theAddress;
    int numTimesConsulted;
};

// Replace non-local static with local static (Meyers' Singleton)
FileSystem& theFileSystem() {
    static FileSystem fs;
    return fs;
}
```

[Full source code](https://github.com/henrytien/effective-cpp-3rd/blob/master/src/Item04/Source.cpp)

## Things to Remember

- Manually initialize objects of built-in type, because C++ only sometimes initializes them itself.
- In a constructor, prefer use of the member initialization list to assignment inside the body. List data members in the initialization list in the same order they're declared in the class.
- Avoid initialization order problems across translation units by replacing non-local static objects with local static objects.

## Related Items

- [Item 5](../chapter-02/item-05.md) — Know what functions C++ silently writes and calls
- [Item 26](../chapter-05/item-26.md) — Postpone variable definitions as long as possible
