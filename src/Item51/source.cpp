#include <iostream>

class Base { // same as before, but now
public:      // operator delete is declared
  static void *operator new(std::size_t size) throw(std::bad_alloc);
  static void operator delete(void *rawMemory, std::size_t size) throw();
};

void *Base::operator new(std::size_t size) throw(std::bad_alloc) {
  // if size is ¡°wrong,¡± have standard operator
  if (size != sizeof(Base))
    return ::operator new(size);
  // new handle the request
  using namespace std; // take additional params
  if (size == 0) {     // handle 0-byte requests
    size = 1;          // by treating them as
  }                    // 1-byte requests
  while (true) {
    // attempt to allocate size bytes;
    auto p = ::operator new(size);
    if (p != nullptr)
      return p;
    // allocation was unsuccessful; find out what the
    // current new-handling function is (see below)
    new_handler globalHandler = set_new_handler(0);
    set_new_handler(globalHandler);
    if (globalHandler)
      (*globalHandler)();
    else
      throw std::bad_alloc();
  }

  // otherwise handle the request here
}
void Base::operator delete(void *rawMemory, std::size_t size) throw() {
  if (rawMemory == 0)
    return;                       // check for null pointer
  if (size != sizeof(Base)) {     // if size is ¡°wrong,¡±
    ::operator delete(rawMemory); // have standard operator
    return;                       // delete handle the request
  }
  //	deallocate the memory pointed to by rawMemory;
  ::operator delete(rawMemory);
  return;
}

class Widget : public Base {
public:
  Widget(int n) : n_(n) {}
  ~Widget() {}

private:
  int n_;
};

int main() {
  std::cout << "Item 51: Adhere to convention when writing new and delete.\n";

  auto p = new Widget(520);
  delete p;
  return 0;
}