#include <functional>
#include <iostream>
#include <map>

int main() {
    std::unordered_map<int, std::function<int(int)>> f;
    
    for (int k = 0; k < 3; k++) {
        f.emplace(k, [k](int x) { return x + k; });
    }

    for (int i = 0; i < 3; i++) {
        std::cout << f[i](2);
    }
}
