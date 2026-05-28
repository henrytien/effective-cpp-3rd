---
sidebar_position: 6
---

# Item 23: Prefer non-member non-friend functions to member functions

## Concept

Encapsulation is inversely related to the number of functions that can access private data. A non-member non-friend function provides greater encapsulation than a member function because it doesn't increase the number of functions that can access the class's private parts. The natural way to organize such convenience functions is to put them in the same namespace as the class, possibly spread across multiple header files (like the STL does with `<vector>`, `<algorithm>`, etc.).

## Code Example

```cpp
class WebBrowser {
public:
    void clearCache();
    void clearHistory();
    void removeCookies();
    // ...
};

// BAD as a member: increases the number of functions with access to privates
// class WebBrowser {
//     void clearEverything();  // calls clearCache, clearHistory, removeCookies
// };

// GOOD: non-member non-friend in the same namespace
namespace WebBrowserStuff {

class WebBrowser { /* ... */ };

// Convenience function — same namespace, not a member or friend
void clearBrowser(WebBrowser& wb) {
    wb.clearCache();
    wb.clearHistory();
    wb.removeCookies();
}

}  // namespace WebBrowserStuff

// Can be split across headers for modularity:
// "webbrowser.h"       — class WebBrowser core
// "webbrowsercache.h"  — cache-related convenience functions
// "webbrowsercookies.h" — cookie-related convenience functions
```

[Full source code](https://github.com/henrytien/effective-cpp-3rd/blob/master/src/Item23/source.cpp)

## Things to Remember

- Prefer non-member non-friend functions to member functions. Doing so increases encapsulation, packaging flexibility, and functional extensibility.
- This reasoning applies only to non-friend functions. A friend function has the same access as a member function from an encapsulation standpoint.

## Related Items

- [Item 22](../chapter-04/item-22.md) — Declare data members private (encapsulation fundamentals)
- [Item 24](../chapter-04/item-24.md) — Non-member functions and type conversions
