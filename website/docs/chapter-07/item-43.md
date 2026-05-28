---
sidebar_position: 3
---

# Item 43: Know how to access names in templatized base classes

## Concept

When a class template inherits from another class template, the compiler refuses to look into templatized base classes for inherited names. This is because the base class template might be specialized, and that specialization might not contain the expected names. You have three ways to tell the compiler to look in the base: prefix with `this->`, use a `using` declaration, or explicitly qualify the call with the base class name. Each approach promises the compiler that the name will exist at instantiation time.

## Code Example

```cpp
template <typename Company>
class MsgSender {
public:
    void sendClear(const std::string& msg) { /* ... */ }
    void sendEncrypted(const std::string& msg) { /* ... */ }
};

template <typename Company>
class LoggingMsgSender : public MsgSender<Company> {
public:
    // Approach 1: this-> prefix
    void sendClearMsg(const std::string& info) {
        this->sendClear(info);  // Works
    }

    // Approach 2: using declaration
    using MsgSender<Company>::sendClear;
    void sendClearMsg2(const std::string& info) {
        sendClear(info);  // Works after using declaration
    }

    // Approach 3: explicit qualification (disables virtual dispatch)
    void sendClearMsg3(const std::string& info) {
        MsgSender<Company>::sendClear(info);  // Works but no polymorphism
    }
};
```

[Full source code](https://github.com/henrytien/effective-cpp-3rd/blob/master/src/Item43/source.cpp)

## Things to Remember

- In derived class templates, refer to names in base class templates via a `this->` prefix, via `using` declarations, or via an explicit base class qualification.

## Related Items

- [Item 33](../chapter-06/item-33.md) — Avoid hiding inherited names (similar using-declaration technique)
- [Item 42](../chapter-07/item-42.md) — Typename for dependent names
- [Item 44](../chapter-07/item-44.md) — Factor parameter-independent code out of templates
