#include <utility>

int main() {
    auto fib = [i=0, j=1]() mutable {
        struct Result {
            int &i, &j;

            auto next() {
                i = std::exchange(j, j + i);
                return *this;
            }
        };
        return Result{.i=i, .j=j}.next();
    };

    auto r = fib();
    r.i = 2; // mutate state
    r.j = 3; // mutate state
    return fib().j; // 5
}
