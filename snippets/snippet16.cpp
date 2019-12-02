#include <iostream>
#include <utility>

int main() {
    auto fib = [i=0, j=1]() mutable {
        i = std::exchange(j, j + i);
        return i;
    };

    for (int i = 0; i < 20; ++i) fib();
    std::cout << fib();
}
