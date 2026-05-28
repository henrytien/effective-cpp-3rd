---
sidebar_position: 5
---

# Item 45: Use member function templates to accept "all compatible types"

## Concept

Smart pointers and other generic wrappers should support implicit conversions that their underlying raw pointers support (e.g., derived-to-base, non-const-to-const). Since the compiler won't generate these conversions automatically for unrelated template instantiations, you need generalized copy constructors and assignment operators — member function templates that accept any compatible type. Even when you declare generalized copy/conversion templates, you still need to declare the normal copy constructor and copy assignment operator, because the compiler will generate default ones otherwise.

## Code Example

```cpp
template <typename T>
class SmartPtr {
public:
    // Normal constructor
    explicit SmartPtr(T* p) : ptr_(p) {}

    // Generalized copy constructor: accepts compatible types
    template <typename U>
    SmartPtr(const SmartPtr<U>& other)
        : ptr_(other.get()) {}  // Compiles only if U* converts to T*

    // Generalized assignment
    template <typename U>
    SmartPtr& operator=(const SmartPtr<U>& other) {
        ptr_ = other.get();
        return *this;
    }

    // Still need the normal copy constructor!
    SmartPtr(const SmartPtr& other) : ptr_(other.ptr_) {}

    T* get() const { return ptr_; }
private:
    T* ptr_;
};

// Usage: derived-to-base conversion works naturally
// SmartPtr<Derived> spd(new Derived);
// SmartPtr<Base> spb(spd);  // Works via generalized ctor
```

[Full source code](https://github.com/henrytien/effective-cpp-3rd/blob/master/src/Item45/source.cpp)

## Things to Remember

- Use member function templates to generate functions that accept all compatible types.
- If you declare member templates for generalized copy construction or generalized assignment, you still need to declare the normal copy constructor and copy assignment operator as well.

## Related Items

- [Item 32](../chapter-06/item-32.md) — Public inheritance models is-a (conversions should mirror inheritance)
- [Item 46](../chapter-07/item-46.md) — Non-member functions in templates for type conversions
- [Item 41](../chapter-07/item-41.md) — Compile-time polymorphism via templates
