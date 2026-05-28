#include <iostream>
#include <cstdlib>
#include <cstring>
#include <new>

// Custom operator new/delete that detects usage errors and collects statistics
class MemoryTracker {
public:
    static MemoryTracker& instance() {
        static MemoryTracker tracker;
        return tracker;
    }

    void record_alloc(void* ptr, std::size_t size) {
        ++alloc_count_;
        total_bytes_ += size;
        std::cout << "  [alloc] " << size << " bytes at " << ptr << "\n";
    }

    void record_dealloc(void* ptr) {
        ++dealloc_count_;
        std::cout << "  [dealloc] at " << ptr << "\n";
    }

    void report() const {
        std::cout << "\n--- Memory Statistics ---\n";
        std::cout << "  Allocations:   " << alloc_count_ << "\n";
        std::cout << "  Deallocations: " << dealloc_count_ << "\n";
        std::cout << "  Total bytes:   " << total_bytes_ << "\n";
        if (alloc_count_ != dealloc_count_)
            std::cout << "  WARNING: possible leak!\n";
    }

private:
    MemoryTracker() = default;
    std::size_t alloc_count_ = 0;
    std::size_t dealloc_count_ = 0;
    std::size_t total_bytes_ = 0;
};

// Signature bytes to detect buffer overruns
static constexpr unsigned char GUARD_BYTE = 0xDE;
static constexpr std::size_t GUARD_SIZE = 4;

class Widget {
public:
    Widget(int val) : value_(val) {}
    int value() const { return value_; }

    static void* operator new(std::size_t size) {
        // Allocate extra space for guard bytes on both sides
        std::size_t total = GUARD_SIZE + size + GUARD_SIZE;
        void* raw = std::malloc(total);
        if (!raw) throw std::bad_alloc();

        // Write guard bytes
        auto* base = static_cast<unsigned char*>(raw);
        std::memset(base, GUARD_BYTE, GUARD_SIZE);
        std::memset(base + GUARD_SIZE + size, GUARD_BYTE, GUARD_SIZE);

        void* result = base + GUARD_SIZE;
        MemoryTracker::instance().record_alloc(result, size);
        return result;
    }

    static void operator delete(void* ptr) noexcept {
        if (!ptr) return;

        auto* base = static_cast<unsigned char*>(ptr) - GUARD_SIZE;

        // Check front guard
        for (std::size_t i = 0; i < GUARD_SIZE; ++i) {
            if (base[i] != GUARD_BYTE) {
                std::cerr << "  CORRUPTION: front guard overwritten!\n";
                break;
            }
        }

        MemoryTracker::instance().record_dealloc(ptr);
        std::free(base);
    }

private:
    int value_;
};

int main() {
    std::cout << "Item 50: Understand when it makes sense to replace new and delete.\n\n";

    std::cout << "Reasons to replace:\n";
    std::cout << "1. Detect usage errors (overruns, underruns, leaks)\n";
    std::cout << "2. Collect usage statistics\n";
    std::cout << "3. Increase allocation/deallocation speed\n";
    std::cout << "4. Reduce space overhead\n";
    std::cout << "5. Compensate for suboptimal alignment\n";
    std::cout << "6. Cluster related objects near one another\n\n";

    std::cout << "Demo: Custom allocator with guard bytes and tracking:\n";
    auto* w1 = new Widget(42);
    auto* w2 = new Widget(100);
    std::cout << "  w1->value() = " << w1->value() << "\n";
    std::cout << "  w2->value() = " << w2->value() << "\n";
    delete w1;
    delete w2;

    MemoryTracker::instance().report();
    return 0;
}
