#include <algorithm>
#include <iostream>
#include <variant>
#include <vector>

int main() {
    int a = 0; double b = 0.;
    std::vector<std::variant<int, double>> v{1, 1.9, 2, 2.1};
    std::for_each(v.begin(), v.end(), [&a, &b](const auto& x) {
        std::visit([&a, &b](auto x) {
            if constexpr (std::is_same_v<int, decltype(x)>) a += x;
            else b += x;
        }, x);
    });
    std::cout << a << b;
}
