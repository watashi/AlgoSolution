#include <cstdlib>
#include <iostream>

using namespace std;

bool gao(int a, int b) {
    if (a > b) {
        return gao(b, a);
    } else if (b != 4) {
        return b < 4;
    } else {
        return a < 3;
    }
}

int main() {
    int n, m, x1, x2, y1, y2;

    cin >> n >> m >> x1 >> y1 >> x2 >> y2;
    cout << (gao(abs(x1 - x2), abs(y1 - y2)) ? "First" : "Second") << endl;

    return 0;
}

