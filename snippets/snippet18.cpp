#include <cmath>
#include <iostream>

int main() {
    auto y = []<typename T>(T x) {
        T mean = 1.;
        T width = 3.;
        auto norm = 1. / std::sqrt(2. * M_PI);
        auto arg = (x - mean) / width;
        return norm * std::exp(-.5 * arg * arg);
    }(.5);

    std::cout << y;
}
