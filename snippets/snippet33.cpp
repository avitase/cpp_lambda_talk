#include <variant>

template<class... Ts> struct overloaded : Ts... { using Ts::operator()...; };
template<class... Ts> overloaded(Ts...) -> overloaded<Ts...>;

int main() {
    using T = std::variant<int, double>;
    overloaded visitor = overloaded{[](int x) -> T { return x + 1; },
                                    [](double x) -> T { return x + 2.; }};
    constexpr auto result = std::visit(visitor, T{41});
    static_assert(result.index() == 0 && std::get<0>(result) == 42);
}
