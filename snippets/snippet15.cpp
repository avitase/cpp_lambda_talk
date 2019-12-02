#include <iostream>

int main() {
    auto x = [] { static int i = 0; return ++i; };
    auto y = x;
    x();
    x();
    y();
    y();
    std::cout << x();
}
