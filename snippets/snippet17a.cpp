#include <algorithm>
#include <vector>

std::vector<int> get_ints();

int main() {
    auto ints = get_ints();
    auto in_range = [](int x) { return x > 0 && x < 10; };
    return *std::find_if(ints.begin(), ints.end(), in_range);
}
