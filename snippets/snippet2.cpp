#include <algorithm>
#include <vector>

int main() {
    std::vector<int> xs{1, 2, 3, 4, 5, 6, 7};
    auto is_even = [](int x) { return x % 2 == 0; };
    return std::count_if(xs.begin(), xs.end(), is_even);
}
