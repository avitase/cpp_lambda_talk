#include <vector>

std::vector<int> get_ints();

int main() {
    auto ints = get_ints();
    const auto sum = [&ints] {
        int acc = 0;
        for (auto &x: ints) acc += x;
        return acc;
    }();

    return sum;
}
