---
sidebar_position: 7
---

# Item 11: Handle assignment to self in operator=

## Concept

Self-assignment occurs when an object is assigned to itself (`w = w`). This can happen less obviously through aliasing (two pointers or references referring to the same object). A naive implementation of `operator=` might delete a resource before copying it, which is catastrophic during self-assignment. The traditional fix is an identity test, but a better approach is the copy-and-swap idiom, which is both self-assignment-safe and exception-safe.

## Code Example

```cpp
class Bitmap { /* ... */ };

class Widget {
    Bitmap* pb;
public:
    // Approach 1: Identity test (not exception-safe without more work)
    Widget& operator=(const Widget& rhs) {
        if (this == &rhs) return *this;  // identity test
        delete pb;
        pb = new Bitmap(*rhs.pb);
        return *this;
    }

    // Approach 2: Copy-and-swap (preferred — both self-assignment and exception safe)
    Widget& operator=(const Widget& rhs) {
        Widget temp(rhs);   // make a copy
        swap(temp);         // swap *this with the copy
        return *this;
    }

    void swap(Widget& other) {
        std::swap(pb, other.pb);
    }
};
```

[Full source code](https://github.com/henrytien/effective-cpp-3rd/blob/master/src/Item11/source.cpp)

## Things to Remember

- Make sure `operator=` is well-behaved when an object is assigned to itself. Techniques include comparing addresses of source and target objects, careful statement ordering, and copy-and-swap.
- Make sure that any function operating on more than one object behaves correctly if two or more of the objects are the same.

## Related Items

- [Item 10](../chapter-02/item-10.md) — Returning a reference to *this from assignment operators
- [Item 12](../chapter-02/item-12.md) — Copy all parts of an object
- [Item 25](../chapter-04/item-25.md) — Non-throwing swap
- [Item 29](../chapter-05/item-29.md) — Exception safety guarantees
