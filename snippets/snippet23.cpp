#include <iostream>

template <typename F1, typename F2> struct X: F1, F2 {
    X(F1 f1, F2 f2): F1(std::move(f1)), F2(std::move(f2)) {}
    using F1::operator();
    using F2::operator();
};

template <typename F1, typename F2> auto make_combined(F1&& f1, F2&& f2) {
    return X<std::decay_t<F1>, std::decay_t<F2>>{std::forward<F1>(f1),
                                                 std::forward<F2>(f2)};
}

int main() {
    auto f1 = [] { return 1; };
    auto f2 = [](int x) { return x; };
    auto combined = make_combined(f1, f2);
    std::cout << combined() << combined(2); // should print "12"
}
