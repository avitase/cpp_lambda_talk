class X {
private:
    int i;

public:
    X(int i): i(i) {}

    int operator()(int y) const {
        return i + y;
    }
};

// potentially lots of lines of code

int main() {
    int i = 1;
    auto z = X{i}(3);
    return z;
}
