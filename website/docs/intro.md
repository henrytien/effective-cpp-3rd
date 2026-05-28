---
sidebar_position: 1
slug: /
---

# Effective C++ 3rd Edition - Code Examples

Welcome to the documentation and code companion for **Scott Meyers' Effective C++: 55 Specific Ways to Improve Your Programs and Designs (3rd Edition)**.

## What This Is

This project provides:

- **Working C++20 code examples** for each of the 55 Items in the book
- **Explanations and notes** for each concept
- **Cross-references** between related Items
- A **modern CMake build system** that works on Windows, Linux, and macOS

## Building the Examples

### Prerequisites

- CMake 3.20+
- A C++20 compatible compiler:
  - MSVC 2022 (Windows)
  - GCC 11+ (Linux)
  - Clang 14+ (macOS)

### Quick Start

```bash
# Clone the repository
git clone https://github.com/henrytien/effective-cpp-3rd.git
cd effective-cpp-3rd

# Configure and build all examples
cmake -B build
cmake --build build --config Release

# Build only a specific item
cmake -B build -DBUILD_ALL_ITEMS=OFF -DBUILD_ITEM_31=ON
cmake --build build --config Release
```

### Generate Visual Studio Solution

```bash
cmake -B build -G "Visual Studio 17 2022" -A x64
# Open build/EffectiveCpp3rd.sln in Visual Studio
```

## Book Structure

The 55 Items are organized into 9 chapters:

1. **Accustoming Yourself to C++** (Items 1-4)
2. **Constructors, Destructors, and Assignment Operators** (Items 5-12)
3. **Resource Management** (Items 13-17)
4. **Designs and Declarations** (Items 18-25)
5. **Implementations** (Items 26-31)
6. **Inheritance and Object-Oriented Design** (Items 32-40)
7. **Templates and Generic Programming** (Items 41-48)
8. **Customizing new and delete** (Items 49-52)
9. **Miscellany** (Items 53-55)

## Acknowledgments

All credit for the content and wisdom goes to **Scott Meyers**. If you find these examples helpful, please [purchase the book](http://www.amazon.com/Effective-Specific-Improve-Programs-Designs/dp/0321334876).
