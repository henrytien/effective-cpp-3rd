---
sidebar_position: 2
---

# Item 6: Explicitly disallow the use of compiler-generated functions you do not want

## Concept

Sometimes you want to prevent objects from being copied. Since the compiler generates copy operations automatically, you must explicitly disallow them. In C++11 and later, the preferred approach is to use `= delete`. In C++98, the technique was to declare the copy constructor and copy assignment operator private and not implement them. This prevents both member functions from being called and generates a linker error if they are inadvertently used internally.

## Code Example

```cpp
// C++11 approach (preferred): use = delete
class Uncopyable {
public:
    Uncopyable() = default;
    ~Uncopyable() = default;

    Uncopyable(const Uncopyable&) = delete;
    Uncopyable& operator=(const Uncopyable&) = delete;
};

// C++98 approach: declare private and don't implement
class HomeForSale {
public:
    HomeForSale() {}
private:
    HomeForSale(const HomeForSale&);             // not defined
    HomeForSale& operator=(const HomeForSale&);  // not defined
};

// Usage
HomeForSale h1;
// HomeForSale h2(h1);   // Error! Copy is disallowed
// h1 = h2;             // Error! Assignment is disallowed
```

[Full source code](https://github.com/henrytien/effective-cpp-3rd/blob/master/src/Item06/source.cpp)

## Things to Remember

- To disallow functionality automatically provided by compilers, declare the corresponding member functions private and give no implementations (C++98) or use `= delete` (C++11+).
- Using a base class like `Uncopyable` (boost::noncopyable) is one approach, but `= delete` is clearer and more direct.

## Related Items

- [Item 5](../chapter-02/item-05.md) — What functions the compiler generates automatically
- [Item 14](../chapter-03/item-14.md) — Copying behavior in resource-managing classes
