#include <iostream>
#include <vector>
namespace WidgetStuff {

// templatized WidgetImpl, etc.
template <typename T>
class WidgetImpl {
 public:
  WidgetImpl(T a, T b, T c, const std::vector<std::string>& v)
      : a_(a), b_(b), c_(c), v_(std::move(v)) {}
  ~WidgetImpl() {}
  T get_a() const { return a_; }
  T get_b() const { return b_; }
  T get_c() const { return c_; }
  std::vector<std::string> get_v() const { return v_; }

 private:
  T a_, b_, c_;
  std::vector<std::string> v_;
};

template <typename T>  // as before, including the swap
class Widget {
 public:
  Widget(const std::string& name, const T& n, WidgetImpl<T>* p);
  ~Widget() {}
  Widget(const Widget& rhs);
  Widget& operator=(const Widget& rhs);
  void swap(Widget& other);
  void print() {
    if (widget_ptr_ == NULL) {
      std::cout << name_ << " love score is " << score_ << ", message is "
                << "\"I love yawen so much!\"" << std::endl;
      return;
    }
    std::cout << name_ << " love score is " << score_ << ", message is \""
              << widget_ptr_->get_a() << " " << widget_ptr_->get_b() << " "
              << widget_ptr_->get_c() << "\"" << std::endl;
    std::cout << "I want to tell you: \"";
    std::string str;
    for (auto&& iter : widget_ptr_->get_v()) {
      str += iter + " ";
    }
    str.erase(str.end()-1);
    str += "\"";
    std::cout << str << std::endl;
  }

 private:
  std::string name_;
  T score_;
  WidgetImpl<T>* widget_ptr_;
};  // member function

template <typename T>
Widget<T>::Widget(const std::string& name, const T& n, WidgetImpl<T>* p)
    : name_(name), score_(n), widget_ptr_(p) {}

template <typename T>
Widget<T>::Widget(const Widget& rhs)
    : name_(std::move(rhs.name_)),
      score_(rhs.score_),
      widget_ptr_(rhs.widget_ptr_) {}

template <typename T>
Widget<T>& Widget<T>::operator=(const Widget& rhs) {
  /*this->name_ = std::move(rhs.name_);
  this->score_ = std::move(rhs.score_);*/
  Widget& temp = const_cast<Widget&>(rhs);
  swap(temp);
  return *this;
}

template <typename T>    // non-member swap function;
void swap(Widget<T>& a,  // not part of the std namespace
          Widget<T>& b) {
  a.swap(b);
}

template <typename T>
void Widget<T>::swap(Widget& other) {
  using std::swap;
  swap(widget_ptr_, other.widget_ptr_);
}
}  // namespace WidgetStuff

int main() {
  //std::cout << "Item 25: Consider support for a non-throwing swap."
  //          << std::endl;

  std::vector<std::string> chenyawen = {"I", "love", "yawen", "too"};
  WidgetStuff::WidgetImpl<std::string>* yawen_data =
      new WidgetStuff::WidgetImpl<std::string>("I", "love", "you", chenyawen);
  WidgetStuff::Widget<std::string> yawen("yawen", "100", yawen_data);

  std::vector<std::string> tianhangyu = {"I", "love", "hangyu", "too"};
  WidgetStuff::WidgetImpl<std::string>* hangyu_data =
      new WidgetStuff::WidgetImpl<std::string>("I", "love", "you", tianhangyu);
  WidgetStuff::Widget<std::string> hangyu("hangyu", "100", hangyu_data);
  WidgetStuff::Widget<std::string> hangyuya("hangyu", "100", nullptr);
  hangyuya.print();
  std::cout << "love after " << std::endl;
  WidgetStuff::swap(hangyu, yawen);
  yawen.print();
  return 0;
}