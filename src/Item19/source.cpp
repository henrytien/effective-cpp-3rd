#include <iostream>
#include <string>
#include <stdexcept>
#include <memory>

// A well-designed type that demonstrates each design consideration from Item 19

class Month {
public:
    static Month Jan() { return Month(1); }
    static Month Feb() { return Month(2); }
    static Month Mar() { return Month(3); }

    int value() const { return val_; }
private:
    explicit Month(int m) : val_(m) {}
    int val_;
};

class Date {
public:
    // How should objects be created? Named constructor idiom for clarity
    static Date create(int year, Month month, int day) {
        if (day < 1 || day > 31) throw std::invalid_argument("invalid day");
        if (year < 1900 || year > 2100) throw std::invalid_argument("invalid year");
        return Date(year, month, day);
    }

    // How does initialization differ from assignment?
    Date(const Date&) = default;
    Date& operator=(const Date&) = default;

    // What does pass-by-value mean? (Prefer pass-by-reference-to-const)
    friend std::ostream& operator<<(std::ostream& os, const Date& d) {
        os << d.year_ << "-" << d.month_.value() << "-" << d.day_;
        return os;
    }

    // What are the restrictions on legal values?
    int year() const { return year_; }
    Month month() const { return month_; }
    int day() const { return day_; }

    // What operators make sense?
    bool operator==(const Date& rhs) const {
        return year_ == rhs.year_ && month_.value() == rhs.month_.value() && day_ == rhs.day_;
    }

    // What standard functions should be disallowed?
    Date() = delete;  // No default date makes sense

private:
    Date(int y, Month m, int d) : year_(y), month_(m), day_(d) {}
    int year_;
    Month month_;
    int day_;
};

int main() {
    std::cout << "Item 19: Treat class design as type design.\n\n";

    auto birthday = Date::create(2004, Month::Mar(), 14);
    std::cout << "Created date: " << birthday << "\n";

    auto copy = birthday;
    std::cout << "Copy: " << copy << "\n";
    std::cout << "Equal: " << (birthday == copy ? "yes" : "no") << "\n";

    try {
        auto bad = Date::create(2024, Month::Jan(), 99);
    } catch (const std::invalid_argument& e) {
        std::cout << "Caught invalid date: " << e.what() << "\n";
    }

    // Date d; // Won't compile - default construction is deleted

    return 0;
}
