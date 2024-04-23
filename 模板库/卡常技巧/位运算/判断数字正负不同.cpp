
int main() {
    int x = -1, y = 2;
    bool f = ((x ^ y) < 0); // true

    x = 3, y = 2;
    f = ((x ^ y) < 0); // false

}
