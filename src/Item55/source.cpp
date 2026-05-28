#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <functional>
#include <memory>
#include <type_traits>

// Item 55: Many Boost libraries became part of the C++ standard.
// This demonstrates the evolution from Boost -> Standard Library:
//
// Boost.SmartPtr      -> std::shared_ptr, std::unique_ptr (C++11)
// Boost.Function      -> std::function (C++11)
// Boost.Bind          -> std::bind / lambdas (C++11)
// Boost.Tuple         -> std::tuple (C++11)
// Boost.Optional      -> std::optional (C++17)
// Boost.Variant       -> std::variant (C++17)
// Boost.Any           -> std::any (C++17)
// Boost.Filesystem    -> std::filesystem (C++17)
// Boost.TypeTraits    -> <type_traits> (C++11)
// Boost.Regex         -> std::regex (C++11)

// Example: What used to require Boost.TypeTraits is now standard
template<typename T>
void print_type_info() {
    std::cout << "  is_integral: " << std::is_integral_v<T> << "\n";
    std::cout << "  is_class: " << std::is_class_v<T> << "\n";
    std::cout << "  is_polymorphic: " << std::is_polymorphic_v<T> << "\n";
}

// Example: What used to require Boost.Function + Boost.Bind
class Button {
public:
    using Callback = std::function<void()>;

    void set_click_handler(Callback cb) { on_click_ = std::move(cb); }
    void click() { if (on_click_) on_click_(); }

private:
    Callback on_click_;
};

class App {
public:
    void on_button_clicked() {
        std::cout << "  App::on_button_clicked() invoked\n";
    }
};

// Example: What used to require Boost.SmartPtr
class Resource {
public:
    Resource(std::string name) : name_(std::move(name)) {
        std::cout << "  Resource '" << name_ << "' acquired\n";
    }
    ~Resource() {
        std::cout << "  Resource '" << name_ << "' released\n";
    }
    const std::string& name() const { return name_; }
private:
    std::string name_;
};

int main() {
    std::cout << "Item 55: Familiarize yourself with Boost.\n";
    std::cout << "(Many Boost libs are now in the C++ standard)\n\n";

    // Smart pointers (was Boost.SmartPtr)
    std::cout << "--- Smart Pointers (ex-Boost.SmartPtr) ---\n";
    {
        auto r1 = std::make_shared<Resource>("shared");
        auto r2 = r1;
        std::cout << "  use_count: " << r1.use_count() << "\n";
    }

    // Function + bind (was Boost.Function + Boost.Bind)
    std::cout << "\n--- Callbacks (ex-Boost.Function/Bind) ---\n";
    Button btn;
    App app;
    btn.set_click_handler(std::bind(&App::on_button_clicked, &app));
    btn.click();
    btn.set_click_handler([&app]() { app.on_button_clicked(); });
    btn.click();

    // Type traits (was Boost.TypeTraits)
    std::cout << "\n--- Type Traits (ex-Boost.TypeTraits) ---\n";
    std::cout << "int:\n";
    print_type_info<int>();
    std::cout << "std::string:\n";
    print_type_info<std::string>();

    std::cout << "\nBoost remains valuable for libraries NOT yet standardized:\n";
    std::cout << "  Boost.Asio, Boost.Beast, Boost.Graph, Boost.Spirit, etc.\n";

    return 0;
}
