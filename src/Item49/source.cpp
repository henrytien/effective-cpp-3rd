#include <iostream>
#include <new>
// function to call if operator new can¡¯t allocate enough memory
void OutOfMem() {
  std::cerr << "Unable to satisfy request for memory\n";
  std::abort();
}
class NewHandlerHolder {
public:
  explicit NewHandlerHolder(std::new_handler nh) // acquire current
      : handler_(nh) {}                          // new-handler
  ~NewHandlerHolder()                            // release it
  {
    std::set_new_handler(handler_);
  }

private:
  std::new_handler handler_; // remember it
  NewHandlerHolder(const NewHandlerHolder &);
  // prevent copying  (see Item 14)
  NewHandlerHolder &operator=(const NewHandlerHolder &);
};

template <typename T>     // ¡°mixin-style¡± base class for
class NewHandlerSupport { // class-specific set_new_handler
public:                   // support
  static std::new_handler set_new_handler(std::new_handler p) throw();
  static void *operator new(std::size_t size) throw(std::bad_alloc);
  // other versions of op. new see Item 52
private:
  static std::new_handler current_handler_;
};

template <typename T>
std::new_handler
NewHandlerSupport<T>::set_new_handler(std::new_handler p) throw() {
  std::new_handler oldHandler = current_handler_;
  current_handler_ = p;
  return oldHandler;
}

template <typename T>
void *
NewHandlerSupport<T>::operator new(std::size_t size) throw(std::bad_alloc) {
  NewHandlerHolder h(std::set_new_handler(current_handler_));
  return ::operator new(size);
}
// this initializes each currentHandler to null
template <typename T>
std::new_handler NewHandlerSupport<T>::current_handler_ = 0;

class Widget : public NewHandlerSupport<Widget> {
public:
  static std::new_handler set_new_handler(std::new_handler p) throw();
  static void *operator new(std::size_t size) throw(std::bad_alloc);
  static void *operator new(std::size_t, const std::nothrow_t &) throw();

private:
  static std::new_handler current_handler_;
};

// Init to null in the class impl.
std::new_handler Widget::current_handler_ = 0;

std::new_handler Widget::set_new_handler(std::new_handler p) throw() {
  std::new_handler old_handler = current_handler_;
  current_handler_ = p;
  return old_handler;
}

void *Widget::operator new(std::size_t size) throw(std::bad_alloc) {
  // Install Widget¡¯s new-handler
  NewHandlerHolder h(std::set_new_handler(current_handler_));
  return ::operator new(size); // allocate memory or throw
} // restore global new-handler

void* Widget::operator new(std::size_t size, const std::nothrow_t& nt) throw()
{
	return ::operator new(size, nt);
}
int main() {

  std::cout << "Item 49: Understand the behavior of the new-handler.\n";
  {
    std::set_new_handler(OutOfMem);
    int *big_data_array = new int[100000000L];
  }
  {
    Widget::set_new_handler(OutOfMem); // set outOfMem as Widget¡¯s
    // new-handling function, if memory allocation fails, call outOfMem

    Widget *pw1 = new Widget;
    // If memory allocation fails, call the global new-handling
    // function (if there is one)
    std::string *ps = new std::string;

    // Set the Widget-specific new-handling function to nothing (i.e., null)
    Widget::set_new_handler(0);

    // if mem. alloc. fails, throw an exception immediately. (There is
    // no new- handling function for class Widget.)
    Widget *pw2 = new Widget;
  }
  {
    Widget *pw1 = new Widget; // throws bad_alloc if allocation fails
    if (pw1 == 0)             // this test must fail
    {
    }
    // returns 0 if allocation for the Widget fails

    Widget *pw2 = new (std::nothrow) Widget;
    // this test may succeed
    if (pw2 == 0) {
    }
  }

  return 0;
}