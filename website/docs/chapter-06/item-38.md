---
sidebar_position: 7
---

# Item 38: Model "has-a" or "is-implemented-in-terms-of" through composition

## Concept

Composition (layering/containment) means having an object of one type as a data member of another. In the application domain, composition models "has-a" relationships (a Person has-a name, has-an address). In the implementation domain, composition models "is-implemented-in-terms-of" (a Set might be implemented using a std::list internally). Composition is fundamentally different from is-a (public inheritance) and should be used when the relationship between types doesn't satisfy the Liskov Substitution Principle.

## Code Example

```cpp
#include <string>
#include <list>

// "has-a" in the application domain
class Person {
private:
    std::string name_;     // Person has-a name
    std::string address_;  // Person has-a address
};

// "is-implemented-in-terms-of" in the implementation domain
template <typename T>
class Set {
public:
    void insert(const T& item) {
        if (!contains(item))
            data_.push_back(item);
    }
    bool contains(const T& item) const;
    void remove(const T& item);
private:
    std::list<T> data_;  // Set is-implemented-in-terms-of list
    // NOT "Set is-a list" — a list allows duplicates, a Set does not
};
```

[Full source code](https://github.com/henrytien/effective-cpp-3rd/blob/master/src/Item38/source.cpp)

## Things to Remember

- Composition has meanings completely different from that of public inheritance.
- In the application domain, composition means "has-a." In the implementation domain, it means "is-implemented-in-terms-of."

## Related Items

- [Item 32](../chapter-06/item-32.md) — Public inheritance models is-a (composition is the alternative)
- [Item 39](../chapter-06/item-39.md) — Private inheritance also models is-implemented-in-terms-of
- [Item 40](../chapter-06/item-40.md) — Multiple inheritance judiciously (combine with composition)
