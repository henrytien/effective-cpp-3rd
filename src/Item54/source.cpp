#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <functional>
#include <optional>
#include <variant>
#include <span>
#include <ranges>
#include <concepts>
#include <string>

// TR1 evolved into C++11/14/17/20 standard features:
// - TR1::shared_ptr -> std::shared_ptr (C++11)
// - TR1::function -> std::function (C++11)
// - TR1::bind -> std::bind / lambdas (C++11)
// - TR1::unordered_map -> std::unordered_map (C++11)
// - TR1::regex -> std::regex (C++11)
// - TR1::tuple -> std::tuple (C++11)

// C++20: Concepts replace SFINAE/enable_if for constraining templates
template<typename T>
concept Numeric = std::integral<T> || std::floating_point<T>;

template<Numeric T>
T safe_divide(T a, T b) {
    if (b == T{}) return T{};
    return a / b;
}

// C++20: Ranges simplify algorithm composition
void ranges_demo() {
    std::vector<int> data = {1, 5, 3, 8, 2, 9, 4, 7, 6};

    // Filter, transform, and take — all composable
    auto result = data
        | std::views::filter([](int n) { return n % 2 == 0; })
        | std::views::transform([](int n) { return n * n; });

    std::cout << "Even squares: ";
    for (int v : result) std::cout << v << " ";
    std::cout << "\n";
}

// C++17: std::optional for nullable values
std::optional<int> find_first_even(std::span<const int> data) {
    for (int n : data)
        if (n % 2 == 0) return n;
    return std::nullopt;
}

// C++17: std::variant as a type-safe union
using JsonValue = std::variant<int, double, std::string, bool>;

void print_json(const JsonValue& val) {
    std::visit([](const auto& v) {
        std::cout << "  value = " << v << "\n";
    }, val);
}

int main() {
    std::cout << "Item 54: Familiarize yourself with the standard library.\n";
    std::cout << "(Originally TR1, now fully integrated into C++11/14/17/20)\n\n";

    // Concepts (C++20)
    std::cout << "--- Concepts (C++20) ---\n";
    std::cout << "safe_divide(10, 3) = " << safe_divide(10, 3) << "\n";
    std::cout << "safe_divide(10.0, 3.0) = " << safe_divide(10.0, 3.0) << "\n";

    // Ranges (C++20)
    std::cout << "\n--- Ranges (C++20) ---\n";
    ranges_demo();

    // std::optional (C++17)
    std::cout << "\n--- std::optional (C++17) ---\n";
    std::vector<int> nums = {1, 3, 5, 7, 8, 9};
    if (auto val = find_first_even(nums))
        std::cout << "First even: " << *val << "\n";

    // std::variant (C++17)
    std::cout << "\n--- std::variant (C++17) ---\n";
    std::vector<JsonValue> values = {42, 3.14, std::string("hello"), true};
    for (const auto& v : values) print_json(v);

    // std::span (C++20) - non-owning view of contiguous data
    std::cout << "\n--- std::span (C++20) ---\n";
    int arr[] = {10, 20, 30, 40, 50};
    std::span<int> s(arr);
    std::cout << "span size: " << s.size() << ", first: " << s.front() << "\n";

    return 0;
}
