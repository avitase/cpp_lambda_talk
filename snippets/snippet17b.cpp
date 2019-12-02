#include <algorithm>
#include <vector>

std::vector<int> get_ints();

int main() {
    auto ints = get_ints();
    return *std::find_if(ints.begin(), ints.end(),
                         [](int x) { return x > 0 && x < 10; });
}
