int main() {
    int i = 1;
    auto z = [i](int y) {
        return i + y;
    }(3);
    return z;
}
