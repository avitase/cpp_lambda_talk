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

    fib().next().next().next(); // mutate state
    return fib().i;
}
