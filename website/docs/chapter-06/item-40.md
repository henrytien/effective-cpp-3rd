---
sidebar_position: 9
---

# Item 40: Use multiple inheritance judiciously

## Concept

Multiple inheritance (MI) introduces complexity: ambiguity when two base classes have functions with the same name, and the "deadly diamond" problem where a class inherits from two classes that share a common base. Virtual inheritance solves the diamond problem but adds size, speed, and initialization complexity. MI is most defensible when combining a public interface class with a private implementation class. Use it sparingly and prefer simpler designs when possible.

## Code Example

```cpp
// The diamond problem
class File {
public:
    virtual ~File() = default;
    std::string name() const;
};

class InputFile : virtual public File { /* ... */ };
class OutputFile : virtual public File { /* ... */ };

// Without virtual inheritance, IOFile would have two File sub-objects
class IOFile : public InputFile, public OutputFile {
    // With virtual inheritance, only one File sub-object exists
};

// Legitimate MI: public interface + private implementation
class IPerson {
public:
    virtual ~IPerson() = default;
    virtual std::string name() const = 0;
    virtual std::string birthDate() const = 0;
};

class PersonInfo {  // Implementation helper
protected:
    std::string formatName() const;
};

class CPerson : public IPerson, private PersonInfo {
public:
    std::string name() const override { return formatName(); }
    std::string birthDate() const override;
};
```

[Full source code](https://github.com/henrytien/effective-cpp-3rd/blob/master/src/Item40/source.cpp)

## Things to Remember

- Multiple inheritance is more complex than single inheritance. It can lead to new ambiguity issues and to the need for virtual inheritance.
- Virtual inheritance imposes costs in size, speed, and complexity of initialization and assignment. It's most practical when virtual base classes have no data.
- Multiple inheritance does have legitimate uses. One scenario involves combining public inheritance from an Interface class with private inheritance from a class that helps with implementation.

## Related Items

- [Item 32](../chapter-06/item-32.md) — Public inheritance models is-a
- [Item 39](../chapter-06/item-39.md) — Private inheritance for implementation reuse
- [Item 38](../chapter-06/item-38.md) — Composition as a simpler alternative
