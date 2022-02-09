# Scott Meyers - Effective C++ 3rd Edition
Effective C++: 55 Specific Ways to Improve Your Programs and Designs 3rd Edition. *If you enjoy these notes and examples, please [purchase the book](http://www.amazon.com/Effective-Specific-Improve-Programs-Designs/dp/0321334876)!*

## Chapter 1: Accustoming Yourself to C++

### Item 1: View C++ as a federation of languages.

Things to Remember

✦ Rules for effective C++ programming vary, depending on the part of C++ you are using.

### Item 2: Prefer consts, enums, and inlines to #defines.

Things to Remember

✦ For simple constants, prefer const objects or enums to #defines.

✦ For function-like macros, prefer inline functions to #defines.

### Item 3: Use const whenever possible.

Things to Remember

✦ Declaring something const helps compilers detect usage errors. const can be applied to objects at any scope, to function parameters and return types, and to member functions as a whole.

✦ Compilers enforce bitwise constness, but you should program using logical constness.

✦ When const and non-const member functions have essentially identical implementations, code 		duplication can be avoided by having the non-const version call the const version.

### Item 4: Make sure that objects are initialized before they’re used.

Things to Remember

✦ Manually initialize objects of built-in type, because C++ only sometimes initializes them itself.

✦ In a constructor, prefer use of the member initialization list to assignment inside the body of the constructor. List data members in the initialization list in the same order they’re declared in the class.

✦ Avoid initialization order problems across translation units by replacing non-local static objects with local static objects.

## Chapter 2: Constructors, Destructors, and Assignment Operators

### Item 5: Know what functions C++ silently writes and calls.

Things to Remember

✦ Compilers may implicitly generate a class’s default constructor, copy constructor, copy assignment operator, and destructor.

### Item 6: Explicitly disallow the use of compilergenerated functions you do not want.

Things to Remember

✦ To disallow functionality automatically provided by compilers, declare the corresponding member functions private and give no implementations. Using a base class like Uncopyable is one way to do this.

### Item 7: Declare destructors virtual in polymorphic base classes.

Things to Remember

✦ Polymorphic base classes should declare virtual destructors. If a class has any virtual functions, it should have a virtual destructor.

✦ Classes not designed to be base classes or not designed to be used polymorphically should not declare virtual destructors.

### Item 8: Prevent exceptions from leaving destructors.

Things to Remember

✦ Destructors should never emit exceptions. If functions called in a destructor may throw, the destructor should catch any exceptions, then swallow them or terminate the program.

✦ If class clients need to be able to react to exceptions thrown during an operation, the class should provide a regular (i.e., non-destructor) function that performs the operation.

### Item 9: Never call virtual functions during construction or destruction.

Things to Remember

✦ Don’t call virtual functions during construction or destruction, because such calls will never go to a more derived class than that of the currently executing constructor or destructor.

### Item 10: Have assignment operators return a reference to *this.

Things to Remember

✦ Have assignment operators return a reference to *this.

### Item 11: Handle assignment to self in operator=.

Things to Remember

✦ Make sure operator= is well-behaved when an object is assigned to itself. Techniques include comparing addresses of source and target objects, careful statement ordering, and copy-and-swap.

✦ Make sure that any function operating on more than one object behaves correctly if two or more of the objects are the same.

### Item 12: Copy all parts of an object.

Things to Remember

✦ Copying functions should be sure to copy all of an object’s data members and all of its base class parts.

✦ Don’t try to implement one of the copying functions in terms of the other. Instead, put common functionality in a third function that both call.

## Chapter 3: Resource Management

### Item 13: Use objects to manage resources.

Things to Remember

✦ To prevent resource leaks, use RAII objects that acquire resources in their constructors and release them in their destructors.

✦ Two commonly useful RAII classes are tr1::shared_ptr and auto_ptr. tr1::shared_ptr is usually the better choice, because its behavior when copied is intuitive. Copying an auto_ptr sets it to null.

### Item 14: Think carefully about copying behavior in resource-managing classes.

Things to Remember

✦ Copying an RAII object entails copying the resource it manages, so the copying behavior of the resource determines the copying behavior of the RAII object.

✦ Common RAII class copying behaviors are disallowing copying and performing reference counting, but other behaviors are possible.

### Item 15: Provide access to raw resources in resourcemanaging classes.

Things to Remember

✦ APIs often require access to raw resources, so each RAII class should offer a way to get at the resource it manages.

✦ Access may be via explicit conversion or implicit conversion. In general, explicit conversion is safer, but implicit conversion is more convenient for clients.

### Item 16: Use the same form in corresponding uses of new and delete.

Things to Remember

✦ If you use [] in a new expression, you must use [] in the corresponding delete expression. If you don’t use [] in a new expression, you mustn’t use [] in the corresponding delete expression.

### Item 17: Store newed objects in smart pointers in standalone statements.

Things to Remember

✦ Store newed objects in smart pointers in standalone statements. Failure to do this can lead to subtle resource leaks when exceptions are thrown.

## Chapter 4: Designs and Declarations

### Item 18: Make interfaces easy to use correctly and hard to use incorrectly.

Things to Remember

✦ Good interfaces are easy to use correctly and hard to use incorrectly. You should strive for these characteristics in all your interfaces.

✦ Ways to facilitate correct use include consistency in interfaces and behavioral compatibility with built-in types.

✦ Ways to prevent errors include creating new types, restricting operations on types, constraining object values, and eliminating client resource management responsibilities.

✦ tr1::shared_ptr supports custom deleters. This prevents the cross DLL problem, can be used to automatically unlock mutexes (see Item 14), etc.

### Item 19: Treat class design as type design.

Things to Remember

✦ Class design is type design. Before defining a new type, be sure to consider all the issues discussed in this Item.

### Item 20: Prefer pass-by-reference-to-const to pass-by value.

Things to Remember

✦ Prefer pass-by-reference-to-const over pass-by-value. It’s typically more efficient and it avoids the slicing problem.

✦ The rule doesn’t apply to built-in types and STL iterator and function object types. For them, pass-by-value is usually appropriate.

### Item 21: Don’t try to return a reference when you must return an object.

Things to Remember

✦ Never return a pointer or reference to a local stack object, a reference to a heap-allocated object, or a pointer or reference to a local static object if there is a chance that more than one such object will be needed. (Item 4 provides an example of a design where returning a reference to a local static is reasonable, at least in single-threaded environments.)

### Item 22: Declare data members private.

Things to Remember

✦ Declare data members private. It gives clients syntactically uniform access to data, affords fine-grained access control, allows invariants to be enforced, and offers class authors implementation flexibility.

✦ protected is no more encapsulated than public.

### Item 23: Prefer non-member non-friend functions to member functions.

Things to Remember

✦ Prefer non-member non-friend functions to member functions. Doing so increases encapsulation, packaging flexibility, and functional extensibility.

### Item 24: Declare non-member functions when type conversions should apply to all parameters.

Things to Remember

✦ If you need type conversions on all parameters to a function (including the one that would otherwise be pointed to by the this pointer), the function must be a non-member.

### Item 25: Consider support for a non-throwing swap.

Things to Remember

✦ Provide a swap member function when std::swap would be inefficient for your type. Make sure your swap doesn’t throw exceptions.

✦ If you offer a member swap, also offer a non-member swap that calls the member. For classes (not templates), specialize std::swap, too.

✦ When calling swap, employ a using declaration for std::swap, then call swap without namespace qualification.

✦ It’s fine to totally specialize std templates for user-defined types, but never try to add something completely new to std.

## Chapter 5: Implementations

### Item 26: Postpone variable definitions as long as possible.

Things to Remember

✦ Postpone variable definitions as long as possible. It increases program clarity and improves program efficiency.

### Item 27: Minimize casting.

Things to Remember

✦ Avoid casts whenever practical, especially dynamic_casts in performance sensitive code. If a design requires casting, try to develop a cast-free alternative.

✦ When casting is necessary, try to hide it inside a function. Clients can then call the function instead of putting casts in their own code.

✦ Prefer C++-style casts to old-style casts. They are easier to see, and they are more specific about what they do.

### Item 28: Avoid returning “handles” to object internals.

Things to Remember

✦ Avoid returning handles (references, pointers, or iterators) to object internals. Not returning handles increases encapsulation, helps const member functions act const, and minimizes the creation of dangling handles.

### Item 29: Strive for exception-safe code.

> Time goes on. We live. We learn.

Things to Remember

✦ Exception-safe functions leak no resources and allow no data structures

to become corrupted, even when exceptions are thrown. Such

functions offer the basic, strong, or nothrow guarantees.

✦ The strong guarantee can often be implemented via copy-and-swap,

but the strong guarantee is not practical for all functions.

✦ A function can usually offer a guarantee no stronger than the weakest

guarantee of the functions it calls.

### Item 30: Understand the ins and outs of inlining.

Things to Remember

✦ Limit most inlining to small, frequently called functions. This facilitates debugging and binary upgradability, minimizes potential code bloat, and maximizes the chances of greater program speed.

✦ Don’t declare function templates inline just because they appear in header files.

## Chapter 6: Inheritance and Object-Oriented Design

### Item 32: Make sure public inheritance models “is-a.”

Things to Remember

✦ Public inheritance means “is-a.” Everything that applies to base classes must also apply to derived classes, because every derived class object is a base class object.

### Item 33: Avoid hiding inherited names.

Things to Remember

✦ Names in derived classes hide names in base classes. Under public inheritance, this is never desirable.

✦ To make hidden names visible again, employ using declarations or forwarding functions.

### Item 34: Differentiate between inheritance of interface and  	inheritance of implementation.

Things to Remember

✦ Inheritance of interface is different from inheritance of implementation. Under public inheritance, derived classes always inherit base class interfaces.

✦ Pure virtual functions specify inheritance of interface only.

✦ Simple (impure) virtual functions specify inheritance of interface plus inheritance of a default implementation.

✦ Non-virtual functions specify inheritance of interface plus inheritance of a mandatory implementation.

### Item 35: Consider alternatives to virtual functions.

Things to Remember

✦ Alternatives to virtual functions include the NVI idiom and various forms of the Strategy design pattern. The NVI idiom is itself an example of the Template Method design pattern.

✦ A disadvantage of moving functionality from a member function to a function outside the class is that the non-member function lacks access to the class’s non-public members.

✦ tr1::function objects act like generalized function pointers. Such objects support all callable entities compatible with a given target signature.

### Item 36: Never redefine an inherited non-virtual function.

Things to Remember

✦ Never redefine an inherited non-virtual function.

### Item 37: Never redefine a function’s inherited default parameter value.

Things to Remember

✦ Never redefine an inherited default parameter value, because default parameter values are statically bound, while virtual functions — the only functions you should be redefining — are dynamically bound.

### Item 38: Model “has-a” or “is-implemented-in-termsof” through composition.

Things to Remember

✦ Composition has meanings completely different from that of public inheritance.

✦ In the application domain, composition means has-a. In the implementation domain, it means is-implemented-in-terms-of.

### Item 39: Use private inheritance judiciously.

Things to Remember

✦ Private inheritance means is-implemented-in-terms of. It’s usually inferior to composition, but it makes sense when a derived class needs access to protected base class members or needs to redefine

inherited virtual functions.

✦ Unlike composition, private inheritance can enable the empty base optimization. This can be important for library developers who strive to minimize object sizes.

### Item 40: Use multiple inheritance judiciously.

Things to Remember

✦ Multiple inheritance is more complex than single inheritance. It can lead to new ambiguity issues and to the need for virtual inheritance.

✦ Virtual inheritance imposes costs in size, speed, and complexity of initialization and assignment. It’s most practical when virtual base classes have no data.

✦ Multiple inheritance does have legitimate uses. One scenario involves combining public inheritance from an Interface class with private inheritance from a class that helps with implementation.

## Chapter 7: Templates and Generic Programming

### Item 41: Understand implicit interfaces and compiletime polymorphism.

Things to Remember

✦ Both classes and templates support interfaces and polymorphism.

✦ For classes, interfaces are explicit and centered on function signatures. Polymorphism occurs at runtime through virtual functions.

✦ For template parameters, interfaces are implicit and based on valid expressions. Polymorphism occurs during compilation through template instantiation and function overloading resolution.

### Item 42: Understand the two meanings of typename.

Things to Remember

✦ When declaring template parameters, class and typename are interchangeable.

✦ Use typename to identify nested dependent type names, except in base class lists or as a base class identifier in a member initialization list.

### Item 43: Know how to access names in templatized base classes.

