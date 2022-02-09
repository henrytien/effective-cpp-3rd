#include <iostream>
class StandardNewDeleteForms {
public:
  // normal new/delete
  static void *operator new(std::size_t size) throw(std::bad_alloc) {
    return ::operator new(size);
  }
  static void operator delete(void *pMemory) throw() {
    ::operator delete(pMemory);
  }
  // placement new/delete
  static void *operator new(std::size_t size, void *ptr) throw() {
    return ::operator new(size, ptr);
  }
  static void operator delete(void *pMemory, void *ptr) throw() {
    return ::operator delete(pMemory, ptr);
  }
  // nothrow new/delete
  static void *operator new(std::size_t size,
                            const std::nothrow_t &nt) throw() {
    return ::operator new(size, nt);
  }
  static void operator delete(void *pMemory, const std::nothrow_t &) throw() {
    ::operator delete(pMemory);
  }
};
class Widget : public StandardNewDeleteForms { // inherit std forms
public:
  using StandardNewDeleteForms::operator new;    // make those
  using StandardNewDeleteForms::operator delete; // forms visible

  // add a custom placement new
  static void *operator new(std::size_t size,
                            std::ostream &logStream) throw(std::bad_alloc);
  // add the corresponding placement delete
  static void operator delete(void *pMemory, std::ostream &logStream) throw();
};

void *Widget::operator new(std::size_t size,
                           std::ostream &logStream) throw(std::bad_alloc) {
  // if size is ¡°wrong,¡± have standard operator
  if (size != sizeof(Widget))
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
    else {
      logStream << "bad alloc";
      throw std::bad_alloc();
    }
  }
}

void Widget::operator delete(void *pMemory, std::ostream &logStream) throw() {
  // check for null pointer
  if (pMemory == 0)
    return;

  //	deallocate the memory pointed to by rawMemory;
  ::operator delete(pMemory);
  return;
}

class Base {
public:
  static void *operator new(std::size_t size,        // this new hides
                            std::ostream &logStream) // the normal
      throw(std::bad_alloc);                         // global forms
};

void *Base::operator new(std::size_t size,
                         std::ostream &logStream) throw(std::bad_alloc) {
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
    else {
      logStream << "bad alloc";
      throw std::bad_alloc();
    }
  }

  // otherwise handle the request here
}

int main() {
  std::cout << "Item 52: Write placement delete if you write placement new.\n";

  {
    // call operator new, passing cerr as
    // the ostream; this leaks memory
    // if the Widget constructor throws
    Widget *pw = new (std::cerr) Widget;
    delete pw; // invokes the normal  operator delete
  }
  {
    // Base* pb = new Base; // error! the normal form of operator new is hidden
    Base *pb = new (std::cerr) Base; // fine, calls Base¡¯s placement new
  }
  return 0;
}