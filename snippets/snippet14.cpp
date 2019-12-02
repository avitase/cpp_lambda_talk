#include <iostream>

int main() {
    auto x = [i=0]() mutable { return ++i; };
    auto y = x;
    x();
    x();
    y();
    y();
    std::cout << x();
}
