#include <iostream>

int main() {
    int i = 1;
    auto x = [i]() mutable { return ++i; };
    std::cout << i << x() << i;
}
