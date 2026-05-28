---
sidebar_position: 8
---

# Item 12: Copy all parts of an object

## Concept

When you write your own copying functions (copy constructor and copy assignment operator), the compiler will not warn you if you forget to copy a data member. This is especially problematic when you add new members to a class or when you have a derived class that fails to copy its base class parts. Every copying function must copy all local data members and invoke the appropriate copying function in all base classes.

## Code Example

```cpp
class Customer {
public:
    Customer(const Customer& rhs)
        : name(rhs.name), lastTransaction(rhs.lastTransaction) {}  // copy ALL members

    Customer& operator=(const Customer& rhs) {
        name = rhs.name;
        lastTransaction = rhs.lastTransaction;  // don't forget new members!
        return *this;
    }
private:
    std::string name;
    Date lastTransaction;
};

class PriorityCustomer : public Customer {
public:
    PriorityCustomer(const PriorityCustomer& rhs)
        : Customer(rhs),         // invoke base class copy ctor!
          priority(rhs.priority) {}

    PriorityCustomer& operator=(const PriorityCustomer& rhs) {
        Customer::operator=(rhs);  // assign base class parts!
        priority = rhs.priority;
        return *this;
    }
private:
    int priority;
};
```

[Full source code](https://github.com/henrytien/effective-cpp-3rd/blob/master/src/Item12/source.cpp)

## Things to Remember

- Copying functions should be sure to copy all of an object's data members and all of its base class parts.
- Don't try to implement one of the copying functions in terms of the other. Instead, put common functionality in a third function that both call.

## Related Items

- [Item 5](../chapter-02/item-05.md) — Compiler-generated copy operations
- [Item 10](../chapter-02/item-10.md) — Returning *this from assignment operators
- [Item 11](../chapter-02/item-11.md) — Self-assignment safety
