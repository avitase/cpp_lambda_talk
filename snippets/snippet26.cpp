#include <cassert>
#include <cmath>

struct Shape {
    enum class Type { Circle, Box } type;
    
    union {
        struct { double radius; } circle;
        struct { double width, height; } box;
    } geometry;
};

auto area(const Shape& shape) {
    switch(shape.type) {
        case Shape::Type::Circle: {
            const auto& g = shape.geometry.circle;
            return M_PI * g.radius * g.radius;
        }
        case Shape::Type::Box: {
            const auto& g = shape.geometry.box;
            return g.width * g.height;
        }
    }

    assert(false);
    __builtin_unreachable();
}
