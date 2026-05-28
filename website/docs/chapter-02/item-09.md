---
sidebar_position: 5
---

# Item 9: Never call virtual functions during construction or destruction

## Concept

During base class construction, virtual functions never go down into derived classes. While a base class constructor is executing, the object's type is effectively the base class type, not the derived class type. The same reasoning applies during destruction — once a derived class destructor has run, the object's derived parts have been destroyed, so C++ treats the object as a base class object. This means calling a virtual function from a constructor or destructor will not do what you expect.

## Code Example

```cpp
class Transaction {
public:
    Transaction() {
        // WRONG: calls Transaction::logTransaction, not derived version
        logTransaction();
    }
    virtual void logTransaction() const = 0;
};

class BuyTransaction : public Transaction {
public:
    virtual void logTransaction() const override {
        // This will NOT be called from Transaction's constructor
    }
};

// Better approach: pass info up to the base class constructor
class Transaction {
public:
    explicit Transaction(const std::string& logInfo) {
        logTransaction(logInfo);  // non-virtual call
    }
private:
    void logTransaction(const std::string& logInfo) const;
};

class BuyTransaction : public Transaction {
public:
    BuyTransaction() : Transaction(createLogString()) { }
private:
    static std::string createLogString();  // static to avoid using uninitialized members
};
```

[Full source code](https://github.com/henrytien/effective-cpp-3rd/blob/master/src/Item09/source.cpp)

## Things to Remember

- Don't call virtual functions during construction or destruction, because such calls will never go to a more derived class than that of the currently executing constructor or destructor.
- The workaround is to have derived classes pass necessary information up to base class constructors.

## Related Items

- [Item 7](../chapter-02/item-07.md) — Virtual destructors in polymorphic base classes
- [Item 34](../chapter-06/item-34.md) — Inheritance of interface vs. implementation
