#include <iostream>

int main() {
    auto x = [i=0]() mutable { return ++i; };
    std::cout << x() << x();
}
