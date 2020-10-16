#include <iostream>
#include <optional>

int main() {
    using opt_t = std::optional<int>;
    auto o = []() -> opt_t {
        return 42;
    }();
    const auto co = o;
    std::cout << (*o)++;  // O.K.
    std::cout << (*co)++; // error!
}
