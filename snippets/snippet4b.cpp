int main() {
    struct {
        auto operator()(int y) const {
            return y;
        }
    } x;
    return x(42);
}
