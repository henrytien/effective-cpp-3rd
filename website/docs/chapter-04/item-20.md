---
sidebar_position: 3
---

# Item 20: Prefer pass-by-reference-to-const to pass-by-value

## Concept

By default, C++ passes objects to and from functions by value, meaning each parameter is a copy constructed from the actual argument. This can be very expensive for user-defined types. Pass-by-reference-to-const avoids all copy construction and destruction, and also avoids the slicing problem where a derived class object passed by value to a base class parameter loses its derived-class characteristics. However, for built-in types, STL iterators, and function objects, pass-by-value is usually more efficient.

## Code Example

```cpp
#include <string>

class Person {
public:
    Person() {}
    virtual ~Person() {}
    virtual std::string description() const { return "Person"; }
private:
    std::string name;
    std::string address;
};

class Student : public Person {
public:
    std::string description() const override { return "Student"; }
private:
    std::string schoolName;
    std::string schoolAddress;
};

// BAD: pass-by-value — expensive and causes slicing!
bool validateStudent_bad(Student s) { return true; }
// Copies Student: 1 Student ctor + 4 string ctors (at minimum)

// GOOD: pass-by-reference-to-const — no copies, no slicing
bool validateStudent(const Student& s) { return true; }

// Slicing problem demonstration:
void printDescription(Person p) {        // SLICES! Loses Student-ness
    std::cout << p.description();        // Always prints "Person"
}
void printDescription(const Person& p) { // No slicing
    std::cout << p.description();        // Prints "Student" for Students
}
```

[Full source code](https://github.com/henrytien/effective-cpp-3rd/blob/master/src/Item20/source.cpp)

## Things to Remember

- Prefer pass-by-reference-to-const over pass-by-value. It's typically more efficient and it avoids the slicing problem.
- The rule doesn't apply to built-in types, STL iterator types, and function object types. For them, pass-by-value is usually appropriate.

## Related Items

- [Item 1](../chapter-01/item-01.md) — C++ as a federation of languages (rules differ per sub-language)
- [Item 21](../chapter-04/item-21.md) — Don't return a reference when you must return an object
- [Item 3](../chapter-01/item-03.md) — Use const wherever possible
