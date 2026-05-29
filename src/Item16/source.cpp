#include <iostream>
#include <string>
#include <memory>

int main() {
    std::cout << "Item 16: Use the same form in corresponding uses of new and delete.\n\n";

    // Rule: new with delete, new[] with delete[]

    // Single object
    std::string* sp = new std::string("hello");
    std::cout << "Single object: " << *sp << "\n";
    delete sp;

    // Array of objects
    std::string* arr = new std::string[3]{"one", "two", "three"};
    std::cout << "Array: " << arr[0] << ", " << arr[1] << ", " << arr[2] << "\n";
    delete[] arr;

    // Danger with typedefs that hide array nature
    typedef std::string AddressLines[4];
    std::string* pal = new AddressLines;  // new AddressLines = new string[4]
    // delete pal;   // WRONG! Undefined behavior - must use delete[]
    delete[] pal;    // Correct

    // Prefer modern alternatives that avoid the problem entirely
    auto safe_single = std::make_unique<std::string>("safe");
    auto safe_array = std::make_unique<int[]>(10);
    std::cout << "\nPrefer smart pointers: no manual delete needed\n";
    std::cout << "unique_ptr<string>: " << *safe_single << "\n";

    safe_array[0] = 42;
    std::cout << "unique_ptr<int[]>[0]: " << safe_array[0] << "\n";

    return 0;
}
