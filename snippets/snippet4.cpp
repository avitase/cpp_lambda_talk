int main() {
    struct {
        auto operator()() const {
            return 5;
        }
    } x;
    return x();
}
