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

int main() {
    int n;

    cin >> n;
    switch (n) {
        case 1: gao<1>(); break;
        case 2: gao<2>(); break;
        case 3: gao<3>(); break;
    }

    return 0;
}

