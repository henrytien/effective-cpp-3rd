# Scott Meyers - Effective C++ 3rd Edition
Effective C++: 55 Specific Ways to Improve Your Programs and Designs 3rd Edition. *If you enjoy these notes and examples, please [purchase the book](http://www.amazon.com/Effective-Specific-Improve-Programs-Designs/dp/0321334876)!*


<!-- TOC -->

- [Scott Meyers - Effective C++ 3rd Edition](#scott-meyers---effective-c-3rd-edition)
    - [Chapter 1: Accustoming Yourself to C++](#chapter-1-accustoming-yourself-to-c)
        - [Item 1: View C++ as a federation of languages.](#item-1-view-c-as-a-federation-of-languages)
        - [Item 2: Prefer consts, enums, and inlines to #defines.](#item-2-prefer-consts-enums-and-inlines-to-defines)
        - [Item 3: Use const whenever possible.](#item-3-use-const-whenever-possible)
        - [Item 4: Make sure that objects are initialized before they’re used.](#item-4-make-sure-that-objects-are-initialized-before-theyre-used)
    - [Chapter 2: Constructors, Destructors, and Assignment Operators](#chapter-2-constructors-destructors-and-assignment-operators)
        - [Item 5: Know what functions C++ silently writes and calls.](#item-5-know-what-functions-c-silently-writes-and-calls)
        - [Item 6: Explicitly disallow the use of compilergenerated functions you do not want.](#item-6-explicitly-disallow-the-use-of-compilergenerated-functions-you-do-not-want)
        - [Item 7: Declare destructors virtual in polymorphic base classes.](#item-7-declare-destructors-virtual-in-polymorphic-base-classes)
        - [Item 8: Prevent exceptions from leaving destructors.](#item-8-prevent-exceptions-from-leaving-destructors)
        - [Item 9: Never call virtual functions during construction or destruction.](#item-9-never-call-virtual-functions-during-construction-or-destruction)
        - [Item 10: Have assignment operators return a reference to *this.](#item-10-have-assignment-operators-return-a-reference-to-this)
        - [Item 11: Handle assignment to self in operator=.](#item-11-handle-assignment-to-self-in-operator)
        - [Item 12: Copy all parts of an object.](#item-12-copy-all-parts-of-an-object)
    - [Chapter 3: Resource Management](#chapter-3-resource-management)
        - [Item 13: Use objects to manage resources.](#item-13-use-objects-to-manage-resources)
        - [Item 14: Think carefully about copying behavior in resource-managing classes.](#item-14-think-carefully-about-copying-behavior-in-resource-managing-classes)
        - [Item 15: Provide access to raw resources in resourcemanaging classes.](#item-15-provide-access-to-raw-resources-in-resourcemanaging-classes)
        - [Item 16: Use the same form in corresponding uses of new and delete.](#item-16-use-the-same-form-in-corresponding-uses-of-new-and-delete)
        - [Item 17: Store newed objects in smart pointers in standalone statements.](#item-17-store-newed-objects-in-smart-pointers-in-standalone-statements)
    - [Chapter 4: Designs and Declarations](#chapter-4-designs-and-declarations)
        - [Item 18: Make interfaces easy to use correctly and hard to use incorrectly.](#item-18-make-interfaces-easy-to-use-correctly-and-hard-to-use-incorrectly)
        - [Item 19: Treat class design as type design.](#item-19-treat-class-design-as-type-design)
        - [Item 20: Prefer pass-by-reference-to-const to pass-by value.](#item-20-prefer-pass-by-reference-to-const-to-pass-by-value)
        - [Item 21: Don’t try to return a reference when you must return an object.](#item-21-dont-try-to-return-a-reference-when-you-must-return-an-object)
        - [Item 22: Declare data members private.](#item-22-declare-data-members-private)
        - [Item 23: Prefer non-member non-friend functions to member functions.](#item-23-prefer-non-member-non-friend-functions-to-member-functions)
        - [Item 24: Declare non-member functions when type conversions should apply to all parameters.](#item-24-declare-non-member-functions-when-type-conversions-should-apply-to-all-parameters)
        - [Item 25: Consider support for a non-throwing swap.](#item-25-consider-support-for-a-non-throwing-swap)
    - [Chapter 5: Implementations](#chapter-5-implementations)
        - [Item 26: Postpone variable definitions as long as possible.](#item-26-postpone-variable-definitions-as-long-as-possible)
        - [Item 27: Minimize casting.](#item-27-minimize-casting)
        - [Item 28: Avoid returning “handles” to object internals.](#item-28-avoid-returning-handles-to-object-internals)
        - [Item 29: Strive for exception-safe code.](#item-29-strive-for-exception-safe-code)
        - [Item 30: Understand the ins and outs of inlining.](#item-30-understand-the-ins-and-outs-of-inlining)
    - [Chapter 6: Inheritance and Object-Oriented Design](#chapter-6-inheritance-and-object-oriented-design)
        - [Item 32: Make sure public inheritance models “is-a.”](#item-32-make-sure-public-inheritance-models-is-a)
        - [Item 33: Avoid hiding inherited names.](#item-33-avoid-hiding-inherited-names)
        - [Item 34: Differentiate between inheritance of interface and inheritance of implementation.](#item-34-differentiate-between-inheritance-of-interface-and-inheritance-of-implementation)
        - [Item 35: Consider alternatives to virtual functions.](#item-35-consider-alternatives-to-virtual-functions)
        - [Item 36: Never redefine an inherited non-virtual function.](#item-36-never-redefine-an-inherited-non-virtual-function)
        - [Item 37: Never redefine a function’s inherited default parameter value.](#item-37-never-redefine-a-functions-inherited-default-parameter-value)
        - [Item 38: Model “has-a” or “is-implemented-in-termsof” through composition.](#item-38-model-has-a-or-is-implemented-in-termsof-through-composition)
        - [Item 39: Use private inheritance judiciously.](#item-39-use-private-inheritance-judiciously)
        - [Item 40: Use multiple inheritance judiciously.](#item-40-use-multiple-inheritance-judiciously)
    - [Chapter 7: Templates and Generic Programming](#chapter-7-templates-and-generic-programming)
        - [Item 41: Understand implicit interfaces and compiletime polymorphism.](#item-41-understand-implicit-interfaces-and-compiletime-polymorphism)
        - [Item 42: Understand the two meanings of typename.](#item-42-understand-the-two-meanings-of-typename)
        - [Item 43: Know how to access names in templatized base classes.](#item-43-know-how-to-access-names-in-templatized-base-classes)
        - [Item 44: Factor parameter-independent code out of templates.](#item-44-factor-parameter-independent-code-out-of-templates)
        - [Item 45: Use member function templates to accept “all compatible types.”](#item-45-use-member-function-templates-to-accept-all-compatible-types)
        - [Item 46: Define non-member functions inside templates when type conversions are desired.](#item-46-define-non-member-functions-inside-templates-when-type-conversions-are-desired)
        - [Item 47: Use traits classes for information about types.](#item-47-use-traits-classes-for-information-about-types)
        - [Item 48: Be aware of template metaprogramming.](#item-48-be-aware-of-template-metaprogramming)
    - [Chapter 8: Customizing new and delete](#chapter-8-customizing-new-and-delete)
        - [Item 49: Understand the behavior of the new-handler.](#item-49-understand-the-behavior-of-the-new-handler)
        - [Item 50: Understand when it makes sense to replace new and delete.](#item-50-understand-when-it-makes-sense-to-replace-new-and-delete)
        - [Item 51: Adhere to convention when writing new and delete.](#item-51-adhere-to-convention-when-writing-new-and-delete)
        - [Item 52: Write placement delete if you write placement new.](#item-52-write-placement-delete-if-you-write-placement-new)
    - [Chapter 9: Miscellany](#chapter-9-miscellany)
        - [Item 53: Pay attention to compiler warnings.](#item-53-pay-attention-to-compiler-warnings)
        - [Item 54: Familiarize yourself with the standard library, including TR1.](#item-54-familiarize-yourself-with-the-standard-library-including-tr1)
        - [Item 55: Familiarize yourself with Boost.](#item-55-familiarize-yourself-with-boost)
    - [Reference](#reference)

<!-- /TOC -->




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

✦ Exception-safe functions leak no resources and allow no data structures to become corrupted, even when exceptions are thrown. Such functions offer the basic, strong, or nothrow guarantees.

✦ The strong guarantee can often be implemented via copy-and-swap, but the strong guarantee is not practical for all functions.

✦ A function can usually offer a guarantee no stronger than the weakest guarantee of the functions it calls.

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

### Item 34: Differentiate between inheritance of interface and inheritance of implementation.

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

Things to Remember

✦ In derived class templates, refer to names in base class templates via a “this->” prefix, via using declarations, or via an explicit base class qualification.

### Item 44: Factor parameter-independent code out of templates.

Things to Remember

✦ Templates generate multiple classes and multiple functions, so any template code not dependent on a template parameter causes bloat.

✦ Bloat due to non-type template parameters can often be eliminated by replacing template parameters with function parameters or class data members.

✦ Bloat due to type parameters can be reduced by sharing implementations for instantiation types with identical binary representations.

### Item 45: Use member function templates to accept “all compatible types.”

Things to Remember

✦ Use member function templates to generate functions that accept all compatible types.

✦ If you declare member templates for generalized copy construction or generalized assignment, you’ll still need to declare the normal copy constructor and copy assignment operator, too.

### Item 46: Define non-member functions inside templates when type conversions are desired.

Things to Remember

✦ When writing a class template that offers functions related to the template that support implicit type conversions on all parameters, define those functions as friends inside the class template.

### Item 47: Use traits classes for information about types.

Things to Remember

✦ Traits classes make information about types available during compilation. They’re implemented using templates and template specializations.

✦ In conjunction with overloading, traits classes make it possible to perform compile-time if...else tests on types.

### Item 48: Be aware of template metaprogramming.

Things to Remember

✦ Template metaprogramming can shift work from runtime to compile time, thus enabling earlier error detection and higher runtime performance.

✦ TMP can be used to generate custom code based on combinations of policy choices, and it can also be used to avoid generating code inappropriate for particular types.



## Chapter 8: Customizing new and delete

### Item 49: Understand the behavior of the new-handler.

Things to Remember

✦ set_new_handler allows you to specify a function to be called when memory allocation requests cannot be satisfied.

✦ Nothrow new is of limited utility, because it applies only to memory allocation; associated constructor calls may still throw exceptions.

### Item 50: Understand when it makes sense to replace new and delete.

Things to Remember

✦ There are many valid reasons for writing custom versions of new and delete, including improving performance, debugging heap usage errors, and collecting heap usage information.

### Item 51: Adhere to convention when writing new and delete.

Things to Remember

✦ operator new should contain an infinite loop trying to allocate memory, should call the new-handler if it can’t satisfy a memory request, and should handle requests for zero bytes. Class-specific versions should handle requests for larger blocks than expected.

✦ operator delete should do nothing if passed a pointer that is null. Class-specific versions should handle blocks that are larger than expected.

### Item 52: Write placement delete if you write placement new.

Things to Remember

✦ When you write a placement version of operator new, be sure to write the corresponding placement version of operator delete. If you don’t, your program may experience subtle, intermittent memory leaks.

✦ When you declare placement versions of new and delete, be sure not to unintentionally hide the normal versions of those functions.



## Chapter 9: Miscellany

### Item 53: Pay attention to compiler warnings.

Things to Remember

✦ Take compiler warnings seriously, and strive to compile warningfree at the maximum warning level supported by your compilers.

✦ Don’t become dependent on compiler warnings, because different compilers warn about different things. Porting to a new compiler may eliminate warning messages you’ve come to rely on.

### Item 54: Familiarize yourself with the standard library, including TR1.

Things to Remember

✦ The primary standard C++ library functionality consists of the STL, iostreams, and locales. The C89 standard library is also included.

✦ TR1 adds support for smart pointers (e.g., tr1::shared_ptr), generalized function pointers (tr1::function), hash-based containers, regular expressions, and 10 other components.

✦ TR1 itself is only a specification. To take advantage of TR1, you need an implementation. One source for implementations of TR1 components is Boost.

### Item 55: Familiarize yourself with Boost.

Things to Remember

✦ Boost is a community and web site for the development of free, open source, peer-reviewed C++ libraries. Boost plays an influential role in C++ standardization.

✦ Boost offers implementations of many TR1 components, but it also offers many other libraries, too.



## Reference