#include <iostream>

template <typename F1, typename F2> struct X: F1, F2 {
    using F1::operator();
    using F2::operator();
};

int main() {
    auto f1 = [] { return 1; };
    auto f2 = [](int x) { return x; };
    X combined{f1, f2};
    std::cout << combined() << combined(2); // should print "12"
}
