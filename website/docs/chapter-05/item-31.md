---
sidebar_position: 6
---

# Item 31: Minimize compilation dependencies between files

## Concept

C++ doesn't do a great job of separating interfaces from implementations. A class definition typically includes not just the interface but all the implementation details (data members, private functions). This creates compilation dependencies: when an implementation detail changes, all clients must recompile. The key to minimizing this is to depend on declarations, not definitions. Two primary mechanisms: the pimpl idiom (Handle classes) and abstract base classes (Interface classes), both of which hide implementation behind a pointer or virtual dispatch.

## Code Example

```cpp
#include <memory>
#include <string>

// Forward declarations instead of #includes
class PersonImpl;  // forward declare implementation class
class Date;
class Address;

// Handle class (pimpl idiom): depends only on declarations
class Person {
public:
    Person(const std::string& name, const Date& birthday, const Address& addr);
    ~Person();

    std::string name() const;
    std::string birthDate() const;
    std::string address() const;

private:
    std::unique_ptr<PersonImpl> pImpl;  // pointer to implementation
};

// Interface class: pure abstract base class
class IPerson {
public:
    virtual ~IPerson() = default;
    virtual std::string name() const = 0;
    virtual std::string birthDate() const = 0;
    virtual std::string address() const = 0;

    // Factory function
    static std::unique_ptr<IPerson> create(const std::string& name,
                                            const Date& birthday,
                                            const Address& addr);
};

// Key rules:
// 1. Use forward declarations instead of #includes where possible
// 2. Declare (don't define) classes in header files
// 3. Use pointers/references to depend on declarations only
// 4. Provide separate "declaration-only" headers if needed
```

[Full source code](https://github.com/henrytien/effective-cpp-3rd/blob/master/src/Item31/source.cpp)

## Things to Remember

- The general idea behind minimizing compilation dependencies is to depend on declarations instead of definitions. Two approaches: Handle classes (pimpl) and Interface classes (abstract base).
- Library header files should exist in full and declaration-only forms. This applies regardless of whether templates are involved.
- Prefer forward declarations to #includes when a full class definition is not required.

## Related Items

- [Item 22](../chapter-04/item-22.md) — Encapsulation via private data members
- [Item 30](../chapter-05/item-30.md) — Inlining and header file implications
- [Item 25](../chapter-04/item-25.md) — Pimpl idiom as used with efficient swap
