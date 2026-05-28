---
sidebar_position: 2
---

# Item 54: Familiarize yourself with the standard library, including TR1

## Concept

The original book discussed TR1 (Technical Report 1), which introduced components like smart pointers, function objects, hash containers, and regular expressions into the standard library. Since then, C++11/14/17/20/23 have incorporated and expanded upon these features. Modern C++ developers should be familiar with `std::shared_ptr`, `std::unique_ptr`, `std::function`, `std::unordered_map`, `std::optional`, `std::variant`, `std::string_view`, ranges, concepts, and coroutines. The standard library is vast and constantly growing — knowing what's available prevents reinventing the wheel.

## Code Example

```cpp
#include <memory>
#include <functional>
#include <unordered_map>
#include <optional>
#include <string_view>

// Smart pointers (TR1 -> C++11)
std::shared_ptr<int> sp = std::make_shared<int>(42);
std::unique_ptr<int> up = std::make_unique<int>(7);

// std::function (TR1 -> C++11)
std::function<int(int, int)> add = [](int a, int b) { return a + b; };

// Hash containers (TR1 -> C++11 as unordered_*)
std::unordered_map<std::string, int> wordCount;

// C++17 additions
std::optional<int> maybeValue = 42;
std::string_view sv = "zero-copy string reference";

// C++20: concepts, ranges, etc.
// template <std::integral T> auto square(T x) { return x * x; }
```

[Full source code](https://github.com/henrytien/effective-cpp-3rd/blob/master/src/Item54/source.cpp)

## Things to Remember

- The primary standard C++ library functionality consists of the STL, iostreams, locales, and components from C99/TR1 (now fully standardized).
- TR1 components are now part of the C++11 (and later) standard. Key additions include smart pointers, `std::function`, hash-based containers, regular expressions, and type traits.
- Know what's in the standard library to avoid re-implementing existing functionality.

## Related Items

- [Item 1](../chapter-01/item-01.md) — The STL as a sub-language of C++
- [Item 55](../chapter-09/item-55.md) — Boost libraries that are now standardized
- [Item 47](../chapter-07/item-47.md) — Traits classes (standardized as type_traits)
