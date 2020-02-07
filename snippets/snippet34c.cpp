#include <functional>
#include <iostream>
#include <map>

int main() {
    std::unordered_map<int, std::function<int(int)>> f;
    
    int k;
    for (k = 0; k < 3; k++) {
        f.emplace(k, [&k](int x) { return x + k; });
    }

    for (int k = 0; k < 3; k++) {
        std::cout << f[k](2);
    }
}
