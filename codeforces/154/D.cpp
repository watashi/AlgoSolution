#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

// a <= b
int gao(long long d, long long a, long long b) {
    if (d < 0) {
        return -gao(-d, -b, -a);
    } else if (b < 0) {
        throw "DRAW";
    } else if (a > 0) {
        long long c = d / (a + b) * (a + b);
        if (c + a <= d && d <= c + b) {
            return d - c;
        } else if (c == d) {
            throw "SECOND";
        } else {
            throw "DRAW";
        }
    } else if (a <= d && d <= b) {
        return d;
    } else {
        throw "DRAW";
    }
}

int main() {
    long long x1, x2, a, b;

    cin >> x1 >> x2 >> a >> b;
    try {
        x1 += gao(x2 - x1, a, b);
        cout << "FIRST" << endl << x1 << endl;
    } catch (const char* ex) {
        cout << ex << endl;
    }

    return 0;
}

