---
sidebar_position: 3
---

# Item 55: Familiarize yourself with Boost

## Concept

Boost is a collection of free, peer-reviewed, portable C++ libraries that serves as a proving ground for additions to the C++ standard. Many Boost libraries have been adopted into C++11 and later standards (smart pointers, type traits, `std::function`, `std::bind`, `std::thread`, `std::filesystem`, `std::optional`, `std::variant`, `std::any`, regex). Boost remains valuable for libraries not yet standardized and for cutting-edge functionality. It covers areas including string manipulation, containers, algorithms, math, metaprogramming, and inter-process communication.

## Code Example

```cpp
// Many former Boost libraries are now standard C++:

// Boost.SmartPtr -> std::shared_ptr, std::unique_ptr (C++11)
#include <memory>
auto sp = std::make_shared<int>(42);

// Boost.Filesystem -> std::filesystem (C++17)
#include <filesystem>
namespace fs = std::filesystem;
bool exists = fs::exists("/some/path");

// Boost.Optional -> std::optional (C++17)
#include <optional>
std::optional<int> find(int id) {
    if (id > 0) return id * 10;
    return std::nullopt;
}

// Boost.Variant -> std::variant (C++17)
#include <variant>
std::variant<int, double, std::string> value = "hello";

// Still Boost-only (as of C++23):
// Boost.Asio, Boost.Spirit, Boost.Graph, Boost.Multiprecision
```

[Full source code](https://github.com/henrytien/effective-cpp-3rd/blob/master/src/Item55/source.cpp)

## Things to Remember

- Boost is a community and website for the development of free, open source, peer-reviewed C++ libraries. Boost plays an influential role in C++ standardization.
- Boost offers implementations of many TR1 components, but it also offers many other libraries too.

## Related Items

- [Item 54](../chapter-09/item-54.md) — The standard library (many features originated in Boost)
- [Item 35](../chapter-06/item-35.md) — std::function (originated as Boost.Function)
- [Item 47](../chapter-07/item-47.md) — Type traits (originated as Boost.TypeTraits)
