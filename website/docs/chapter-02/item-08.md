---
sidebar_position: 4
---

# Item 8: Prevent exceptions from leaving destructors

## Concept

Destructors should never emit exceptions. If a destructor calls a function that might throw, the destructor should catch any exceptions and either swallow them or terminate the program. This is because if an exception is already active (stack unwinding) and a destructor emits a second exception, C++ calls `std::terminate`. If clients need to react to an exception thrown during an operation, the class should provide a regular (non-destructor) function that performs the operation.

## Code Example

```cpp
class DBConn {
public:
    // Provide a way for clients to handle errors
    void close() {
        db.close();
        closed = true;
    }

    ~DBConn() {
        if (!closed) {
            try {
                db.close();  // last-ditch attempt
            } catch (...) {
                // Log the failure
                // Option 1: std::abort() if we can't continue
                // Option 2: swallow the exception (document this!)
            }
        }
    }

private:
    DBConnection db;
    bool closed = false;
};

// Client code can handle errors explicitly:
DBConn dbc(DBConnection::create());
dbc.close();  // Client gets a chance to react to errors
// Destructor serves only as a backup
```

[Full source code](https://github.com/henrytien/effective-cpp-3rd/blob/master/src/Item08/source.cpp)

## Things to Remember

- Destructors should never emit exceptions. If functions called in a destructor may throw, the destructor should catch any exceptions, then swallow them or terminate the program.
- If class clients need to be able to react to exceptions thrown during an operation, the class should provide a regular (non-destructor) function that performs the operation.

## Related Items

- [Item 7](../chapter-02/item-07.md) — Virtual destructors in polymorphic base classes
- [Item 29](../chapter-05/item-29.md) — Exception-safe code and the nothrow guarantee
