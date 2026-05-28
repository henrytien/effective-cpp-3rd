---
sidebar_position: 5
---

# Item 22: Declare data members private

## Concept

Data members should be private. This gives you fine-grained access control (read-only, write-only, or read-write), allows you to enforce invariants, and provides encapsulation. Encapsulation means you can later change the internal representation without breaking client code. Public means unencapsulated, which means practically unlimited breakage if the implementation changes. Protected is no more encapsulated than public, because derived classes form a client base just as large as direct users.

## Code Example

```cpp
class AccessLevels {
public:
    // Fine-grained access control:
    int getReadOnly() const { return readOnly; }

    void setReadWrite(int value) { readWrite = value; }
    int getReadWrite() const { return readWrite; }

    void setWriteOnly(int value) { writeOnly = value; }

private:
    int noAccess;     // no access at all
    int readOnly;     // read-only access
    int readWrite;    // read-write access
    int writeOnly;    // write-only access
};

// Encapsulation enables implementation changes:
class SpeedDataCollection {
public:
    void addValue(int speed);
    double averageSoFar() const;
    // Can compute on-the-fly or cache — client code is unchanged!
private:
    // Implementation can change freely:
    // Option A: store all values, compute average when asked
    // Option B: maintain running sum and count
};
```

[Full source code](https://github.com/henrytien/effective-cpp-3rd/blob/master/src/Item22/source.cpp)

## Things to Remember

- Declare data members private. It gives clients syntactically uniform access to data, affords fine-grained access control, allows invariants to be enforced, and offers class authors implementation flexibility.
- Protected is no more encapsulated than public.

## Related Items

- [Item 23](../chapter-04/item-23.md) — Prefer non-member non-friend functions (encapsulation)
- [Item 28](../chapter-05/item-28.md) — Avoid returning handles to object internals
