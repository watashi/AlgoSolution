#include <cstdio>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;

void fill(int n, vector<int>& v) {
    v.resize(n);
    for (int i = 0; i < n; ++i) {
        v[i] = i;
    }
}

void swap(int a, int b, vector<int>& s, vector<int>& r) {
    swap(s[a], s[b]);
    r[s[a]] = a;
    r[s[b]] = b;
}

int main() {
    char op[80];
    int nx, ny, nz, x, y, z;
    vector<int> sx, sy, sz, rx, ry, rz;

    while (scanf("%s", op) != EOF) {
        if (strcmp(op, "FILL") == 0) {
            scanf("%d%d%d", &nx, &ny, &nz);
            fill(nx, sx);
            fill(nx, rx);
            fill(ny, sy);
            fill(ny, ry);
            fill(nz, sz);
            fill(nz, rz);
            puts("START");
        } else if (strcmp(op, "FIND") == 0) {
            scanf("%d", &x);
            --x;
            if (x < nx * ny * nz) {
                z = x % nz;
                x /= nz;
                y = x % ny;
                x /= ny;
                printf("%d %d %d\n", rx[x], ry[y], rz[z]);
            }
        } else if (strcmp(op, "QUERY") == 0) {
            scanf("%d%d%d", &x, &y, &z);
            x = sx[x];
            y = sy[y];
            z = sz[z];
            printf("%d\n", ((x * ny) + y) * nz + z + 1);
        } else {
            scanf("%d%d", &x, &y);
            if (op[4] == '1') {
                swap(x, y, sx, rx);
            } else if (op[4] == '2') {
                swap(x, y, sy, ry);
            } else if (op[4] == '3') {
                swap(x, y, sz, rz);
            } else {
                throw 1;
            }
        }
    }

    return 0;
}

// Run ID   Submit Time     Judge Status    Problem ID  Language    Run Time(ms)    Run Memory(KB)  User Name   Admin
// 369  2010-11-09 22:38:14     Accepted    C   C++     130     180     watashi@Zodiac  Source

// 2012-09-07 15:54:13 | Accepted | 3429 | C++ | 130 | 180 | watashi | Source
