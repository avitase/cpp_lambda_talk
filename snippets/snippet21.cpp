#include <functional>
#include <tuple>
#include <type_traits>
#include <utility>

template <typename T> struct function_traits;
template <typename R, typename... Args> 
struct function_traits<std::function<R(Args...)>> {
    using result_type = R;
    static constexpr auto nargs = sizeof...(Args);

    template <std::size_t i>
    using arg_type = std::tuple_element_t<i, std::tuple<Args...>>;
};

template <typename F>
using lambda_traits = function_traits<decltype(std::function{std::declval<F>()})>;

int main() {
    int x = 5;
    auto g = [x](int a, bool invert_a) { return invert_a ? x - a : x + a; };

    using T = lambda_traits<decltype(g)>;
    static_assert(std::is_same_v<T::result_type, int>);
    static_assert(T::nargs == 2);
    static_assert(std::is_same_v<T::arg_type<0>, int>);
    static_assert(std::is_same_v<T::arg_type<1>, bool>);
}
