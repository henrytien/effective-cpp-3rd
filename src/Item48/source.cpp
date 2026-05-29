#include <array>
#include <iostream>
#include <string>
#include <type_traits>

// Classic TMP: compile-time factorial
template <unsigned N>
struct Factorial {
  static constexpr unsigned value = N * Factorial<N - 1>::value;
};

template <>
struct Factorial<0> {
  static constexpr unsigned value = 1;
};

// C++20: consteval guarantees compile-time evaluation
consteval unsigned long long factorial(unsigned n) {
  unsigned long long result = 1;
  for (unsigned i = 2; i <= n; ++i)
    result *= i;
  return result;
}

// TMP: compile-time type manipulation
template <typename T>
struct TypeName {
  static constexpr const char* value = "unknown";
};

template <>
struct TypeName<int> {
  static constexpr const char* value = "int";
};

template <>
struct TypeName<double> {
  static constexpr const char* value = "double";
};

template <>
struct TypeName<std::string> {
  static constexpr const char* value = "std::string";
};

// if-constexpr: compile-time branching (C++17)
template <typename T>
std::string describe(const T& val) {
  if constexpr (std::is_integral_v<T>) {
    return "integral: " + std::to_string(val);
  } else if constexpr (std::is_floating_point_v<T>) {
    return "floating: " + std::to_string(val);
  } else {
    return std::string("other");
  }
}

// Compile-time Fibonacci using constexpr
constexpr std::array<int, 10> fibonacci() {
  std::array<int, 10> fib{};
  fib[0] = 0;
  fib[1] = 1;
  for (int i = 2; i < 10; ++i)
    fib[i] = fib[i - 1] + fib[i - 2];
  return fib;
}

// TMP for loop unrolling
template <int N>
struct DotProduct {
  static constexpr double compute(const double* a, const double* b) {
    return a[0] * b[0] + DotProduct<N - 1>::compute(a + 1, b + 1);
  }
};

template <>
struct DotProduct<1> {
  static constexpr double compute(const double* a, const double* b) { return a[0] * b[0]; }
};

int main() {
  std::cout << "Item 48: Be aware of template metaprogramming.\n\n";

  // 1. Classic TMP factorial
  std::cout << "Factorial<10> = " << Factorial<10>::value << "\n";

  // 2. consteval (C++20) - guaranteed compile-time
  constexpr auto f12 = factorial(12);
  std::cout << "factorial(12) = " << f12 << "\n";

  // 3. if-constexpr for type-dependent logic
  std::cout << "describe(42): " << describe(42) << "\n";
  std::cout << "describe(3.14): " << describe(3.14) << "\n";

  // 4. Compile-time array generation
  constexpr auto fib = fibonacci();
  std::cout << "Fibonacci: ";
  for (auto n : fib)
    std::cout << n << " ";
  std::cout << "\n";

  // 5. TMP loop unrolling (dot product)
  constexpr double a[] = {1.0, 2.0, 3.0, 4.0};
  constexpr double b[] = {5.0, 6.0, 7.0, 8.0};
  std::cout << "Dot product: " << DotProduct<4>::compute(a, b) << "\n";

  // 6. Type traits
  std::cout << "\nType traits:\n";
  std::cout << "  is_integral<int>: " << std::is_integral_v<int> << "\n";
  std::cout << "  is_floating_point<double>: " << std::is_floating_point_v<double> << "\n";
  std::cout << "  is_same<int, int>: " << std::is_same_v<int, int> << "\n";

  return 0;
}
