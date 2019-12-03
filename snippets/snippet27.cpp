#include <cmath>
#include <variant>

struct Circle { double radius; };
struct Box { double width, height; };
using Shape = std::variant<Circle, Box>;

auto area(const Shape& shape) {
    struct {
        auto operator()(const Circle& c) const {
            return M_PI * c.radius * c.radius;
        }
        auto operator()(const Box& b) const {
            return b.width * b.height;
        }
    } visitor;

    return std::visit(visitor, shape);
}
