#include <functional>
#include <iostream>

struct Callable {
    auto operator()() {
        return 1; 
    }

    auto operator()() const {
        return 2;
    }
} c;

int main() {
    std::function<int(void)> f = c;
    const auto cf = f;
    std::cout << f() << cf(); // 11
}
