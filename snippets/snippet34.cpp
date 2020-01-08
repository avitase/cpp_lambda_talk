#include <tuple>
#include <utility>

template <typename idx_t, idx_t... i>
[[nodiscard]] constexpr auto f(std::integer_sequence<idx_t, i...>) noexcept {
    return std::make_tuple([](int x) { return x + i; }...);
}

int main() {
    return std::get<1>(f(std::make_index_sequence<3>{}))(2);
}
