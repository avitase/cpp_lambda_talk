#include <iostream>

int main() {
    auto x = [] { return 1; };
    auto y = x;
    std::cout << x() << y();
}
