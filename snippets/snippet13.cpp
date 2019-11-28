#include <iostream>
#include <memory>

int main() {
    auto x = [i=std::make_unique<int>(1)] { return *i; };
    auto y = x;
    std::cout << x () << y();
}
