#include <iostream>
#include <list>

template <class T>  // the right way to use list for Set
class Set {
 public:
  inline bool member(const T& item) const;
  inline void insert(const T& item);
  inline void remove(const T& item);
  inline std::size_t size() const;
  inline void print() const {
    std::cout << "Elements of set: ";
    for (auto&& iter : rep_) {
      std::cout << iter << " ";
    }
    std::cout << "\n";
  }

 private:
  std::list<T> rep_;  // representation for Set data
};

template <typename T>
bool Set<T>::member(const T& item) const {
  return std::find(rep_.begin(), rep_.end(), item) != rep_.end();
}
template <typename T>
void Set<T>::insert(const T& item) {
  if (!member(item))
    rep_.push_back(item);
}
template <typename T>
void Set<T>::remove(const T& item) {
  typename std::list<T>::iterator it =
      std::find(rep_.begin(), rep_.end(), item);
  if (it != rep_.end())
    rep_.erase(it);
}

template <typename T>
std::size_t Set<T>::size() const {
  return rep_.size();
}

int main() {
  std::cout << "Item 38: Model ¡°has-a¡± or ¡°is-implemented-in-termsof¡± through "
               "composition.\n";

  Set<int> s;
  for (int i = 0; i < 10; i++) {
    s.insert(i);
  }
  s.insert(10);
  s.insert(10);
  s.insert(11);
  s.insert(12);

  
  s.print();

  std::string res = s.member(10) ? "is" : "not is";
  std::cout << "10 " << res << " member"
            << ".\n";

  s.remove(10);
  std::cout << "Remove 10 now, Set size is " << s.size() << ".\n";
  s.print();
  return 0;
}