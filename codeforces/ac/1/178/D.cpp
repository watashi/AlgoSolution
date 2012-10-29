#include <iostream>
#include <algorithm>

using namespace std;

template<int N>
void gao() {
    union {
        struct {
            long long a[N][N];
        };
        struct {
            long long p[N * N];
        };
    } u;
    long long s = 0;

    for (int i = 0; i < N * N; ++i) {
        cin >> u.p[i];
        s += u.p[i];
    }
    sort(u.p, u.p + N * N);
    s /= N;

    do {
        long long d1 = 0, d2 = 0;
        for (int i = 0; i < N; ++i) {
            d1 += u.a[i][i];
            d2 += u.a[i][N - 1 - i];
        }
        bool flag = d1 == s && d2 == s;
        for (int i = 0; flag && i < N; ++i) {
            long long r = 0, c = 0;
            for (int j = 0; j < N; ++j) {
                r += u.a[i][j];
                c += u.a[j][i];
            }
            flag &= r == s;
            flag &= c == s;
        }
        if (flag) {
            break;
        }
    } while (next_permutation(u.p, u.p + N * N));

    cout << s << endl;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            cout << u.a[i][j] << (j == N - 1 ? "\n" : " ");
        }
    }
}

const long long UNDEF = 0x123456789ABCDEFLL;

long long s;
long long x[16];
long long y[4][4];

int find(long long z) {
    return find(x, x + 16, z) - x;
}

void show() {
    cout << s << endl;
    for (int r = 0; r < 4; ++r) {
        for (int c = 0; c < 4; ++c) {
            cout << y[r][c] << (c == 3 ? "\n" : " ");
        }
    }
}

bool check() {
    return y[2][0] + y[2][1] + y[2][2] + y[2][3] == s
        && y[3][0] + y[3][1] + y[3][2] + y[3][3] == s;
}

void dfs(int i, int j) {
    if ((i == 0 || i == 1) && j == 3) {
        int p = find(s - y[i][0] - y[i][1] - y[i][2]);
        if (p < 16) {
            y[i][3] = x[p];
            x[p] = UNDEF;
            if (i == 0) {
                dfs(1, 0);
            } else {
                dfs(2, 1);
            }
            x[p] = y[i][3];
        }
    } else if (i == 2 && j == 0) {
        int p = find(s - y[0][3] - y[1][2] - y[2][1]);
        if (p < 16) {
            y[3][0] = x[p];
            x[p] = UNDEF;
            int q = find(s - y[0][0] - y[1][0] - y[3][0]);
            if (q < 16) {
                y[2][0] = x[q];
                x[q] = UNDEF;
                dfs(2, 2);
                x[q] = y[2][0];
            }
            x[p] = y[3][0];
        }
    } else if (i == 2 && j == 3) {
        int p = find(s - y[0][0] - y[1][1] - y[2][2]);
        if (p < 16) {
            y[3][3] = x[p];
            x[p] = UNDEF;
            int q = find(s - y[0][3] - y[1][3] - y[3][3]);
            if (q < 16) {
                y[2][3] = x[q];
                x[q] = UNDEF;
                dfs(3, 1);
                x[q] = y[2][3];
            }
            x[p] = y[3][3];
        }
        // show();
    } else if (i == 3 && j == 3) {
        if (check()) {
            show();
            throw 1;
        }
    } else if (i == 3) {
        int p = find(s - y[0][j] - y[1][j] - y[2][j]);
        if (p < 16) {
            y[3][j] = x[p];
            x[p] = UNDEF;
            dfs(i, j + 1);
            x[p] = y[3][j];
        }
    } else {
        long long last = UNDEF;
        for (int k = 0; k < 16; ++k) {
            if (x[k] != UNDEF && x[k] != last) {
                last = x[k];
                y[i][j] = x[k];
                x[k] = UNDEF;
                if (i < 2) {
                    dfs(i, j + 1);
                } else {
                    dfs(i, j ^ 1);
                }
                x[k] = y[i][j];
            }
        }
    }
}

template<>
void gao<4>() {
    s = 0;
    for (int i = 0; i < 16; ++i) {
        cin >> x[i];
        s += x[i];
    }
    sort(x, x + 16);
    s /= 4;

    try {
        dfs(0, 0);
    } catch (int) {
        return;
    }
    throw -1;
}

int main() {
    int n;

    cin >> n;
    fill(y[0], y[4], -1LL);
    switch (n) {
    case 1: gao<1>(); break;
    case 2: gao<2>(); break;
    case 3: gao<3>(); break;
    case 4: gao<4>(); break;
    }

    return 0;
}

