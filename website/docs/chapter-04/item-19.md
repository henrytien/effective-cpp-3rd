---
sidebar_position: 2
---

# Item 19: Treat class design as type design

## Concept

Designing good classes is challenging because designing good types is challenging. You should approach class design with the same care that language designers lavish on built-in types. Before defining a new type, you should consider a set of design questions that guide virtually every aspect of your type: creation/destruction, initialization vs. assignment, pass-by-value semantics, legal values, inheritance, conversions, operators, access control, and generality (should it be a template?).

## Code Example

```cpp
// Questions to answer when designing a new type:

// 1. How should objects be created and destroyed?
//    -> constructors, destructors, memory allocation

// 2. How should initialization differ from assignment?
//    -> constructor vs. operator= behavior

// 3. What does pass-by-value mean for your type?
//    -> copy constructor defines this

// 4. What are the legal values?
//    -> invariants, error checking in member functions

// 5. Does your type fit into an inheritance graph?
//    -> virtual/non-virtual functions, virtual destructor?

// 6. What conversions are allowed?
//    -> implicit/explicit constructors, conversion operators

// 7. What operators and functions make sense?
//    -> member vs. non-member

// 8. What standard functions should be disallowed?
//    -> declare = delete

// 9. Who should have access to members?
//    -> public, private, protected, friend

// 10. What guarantees does your type offer?
//     -> exception safety, thread safety, performance

// 11. How general is your type?
//     -> perhaps a class template instead

// 12. Is a new type really needed?
//     -> maybe a non-member function or template will do

class Widget {
    // Each design decision above shapes this class
};
```

[Full source code](https://github.com/henrytien/effective-cpp-3rd/blob/master/src/Item19/source.cpp)

## Things to Remember

- Class design is type design. Before defining a new type, be sure to consider all the issues discussed in this Item.
- The quality of your types determines the quality of your code.

## Related Items

- [Item 18](../chapter-04/item-18.md) — Making interfaces easy to use correctly
- [Item 20](../chapter-04/item-20.md) — Pass-by-reference-to-const vs pass-by-value
- [Item 22](../chapter-04/item-22.md) — Declaring data members private
- [Item 24](../chapter-04/item-24.md) — Non-member functions for type conversions
