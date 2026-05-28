---
sidebar_position: 2
---

# Item 42: Understand the two meanings of typename

## Concept

The `typename` keyword has two uses in C++. First, it's interchangeable with `class` in template parameter declarations. Second — and more importantly — it's required to disambiguate dependent type names inside templates. When a name in a template depends on a template parameter and refers to a type, the compiler assumes it's not a type unless you prefix it with `typename`. The exception is in base class lists and member initialization lists, where `typename` is neither needed nor allowed.

## Code Example

```cpp
template <typename T>  // typename == class here
class Container {
public:
    void inspect() {
        // T::const_iterator is a dependent name — could be a type or a value
        // Must use typename to tell the compiler it's a type
        typename T::const_iterator iter = data_.begin();

        // Without typename, compiler assumes T::const_iterator is a value
        // and the code won't compile
    }

    // Exception: no typename needed in base class list
    // or member initialization list

private:
    T data_;
};

template <typename IterT>
void printSecond(IterT iter) {
    typename std::iterator_traits<IterT>::value_type temp = *iter;
    // typename required: value_type is a dependent nested type
}
```

[Full source code](https://github.com/henrytien/effective-cpp-3rd/blob/master/src/Item42/source.cpp)

## Things to Remember

- When declaring template parameters, `class` and `typename` are interchangeable.
- Use `typename` to identify nested dependent type names, except in base class lists or as a base class identifier in a member initialization list.

## Related Items

- [Item 41](../chapter-07/item-41.md) — Implicit interfaces and compile-time polymorphism
- [Item 43](../chapter-07/item-43.md) — Accessing names in templatized base classes
- [Item 47](../chapter-07/item-47.md) — Traits classes use typename extensively
