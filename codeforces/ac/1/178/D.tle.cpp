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

long long s;
long long x[16];
vector<int> v[16];
long long y[4][4];
int how[4], con[5];

int test(int i, int j) {
    return (i >> j) & 1;
}

void put(int mask, long long& a, long long& b) {
    /*
    if (__builtin_popcount(mask) != 2) {
        printf("mask = %o\n", mask);
        throw "ERROR";
    }
    */
    int i;
    i = __builtin_ctz(mask);
    a = x[i];
    mask ^= 1 << i;
    i = __builtin_ctz(mask);
    b = x[i];
}

void check(int mask) {
    static long hhow[4];
    if (how[3] > how[0]) {
        return;
    }
    y[0][0] = x[con[4]];
    y[0][3] = x[con[3]];
    y[3][3] = x[con[2]];
    y[3][0] = x[con[1]];
    if (y[0][0] > y[0][3] || y[0][0] > y[3][3] || y[0][0] > y[3][0]) {
        return;
    }
    for (int i = 0; i < 4; ++i) {
        hhow[i] = how[i];
        hhow[i] ^= 1 << con[i];
        hhow[i] ^= 1 << con[i + 1];
    }
    put(hhow[3], y[0][1], y[0][2]);
    put(hhow[2], y[1][3], y[2][3]);
    put(hhow[1], y[3][1], y[3][2]);
    put(hhow[0], y[1][0], y[2][0]);

    vector<long long> todo;
    mask ^= (1 << 16) - 1;
    // printf("%o %o %o %o %o\n", how[0], how[1], how[2], how[3], mask);
    while (mask > 0) {
        int k = __builtin_ctz(mask);
        todo.push_back(x[k]);
        mask ^= 1 << k;
    }
    sort(todo.begin(), todo.end());
    /*
       printf("{");
       for (auto i: todo) {
       printf("%d, ", i);
       }
       printf("}\n");
       */
    //if (todo.size() != 4) {
    //    throw "NO!";
    //}
    // swap(y[0][1], y[0][2]);
    // swap(y[1][3], y[2][3]);
    /*
    bool flag = todo == vector<long long>({3, 8, 10, 13});
    flag &= y[0][0] == 7;
    flag &= y[0][3] == 14;
    if (flag) {
        cout << endl << s << endl;
        for (int i = 0; i < 4; ++i) {
            for (int j = 0; j < 4; ++j) {
                cout << y[i][j] << (j == 3 ? "\n" : " ");
            }
        }
    }
    */

    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < 2; ++j) {
            for (int k = 0; k < 2; ++k) {
                for (int l = 0; l < 2; ++l) {
                    long long ab = s - y[1][0] - y[1][3];
                    long long cd = s - y[2][0] - y[2][3];
                    long long ac = s - y[0][1] - y[3][1];
                    long long bd = s - y[0][2] - y[3][2];
                    long long ad = s - y[0][0] - y[3][3];
                    long long a = (ad + ac - cd) / 2;
                    long long b = ab - a;
                    long long d = (ad + bd - ab) / 2;
                    long long c = cd - d;
                    //if (flag) {
                    //    cout << a << ", " << b << ", " << c << ", " << d << endl;
                    //}
                    vector<long long> abcd = {a, b, c, d};
                    sort(abcd.begin(), abcd.end());
                    if (abcd == todo) {
                        y[1][1] = a;
                        y[1][2] = b;
                        y[2][1] = c;
                        y[2][2] = d;
                        if (y[1][0] + y[1][1] + y[1][2] + y[1][3] == s &&
                            y[2][0] + y[2][1] + y[2][2] + y[2][3] == s &&
                            y[0][1] + y[1][1] + y[2][1] + y[3][1] == s &&
                            y[0][2] + y[1][2] + y[2][2] + y[3][2] == s &&
                            y[0][0] + y[1][1] + y[2][2] + y[3][3] == s &&
                            y[0][3] + y[1][2] + y[2][1] + y[3][0] == s) {
                            cout << s << endl;
                            for (int i = 0; i < 4; ++i) {
                                for (int j = 0; j < 4; ++j) {
                                    cout << y[i][j] << (j == 3 ? "\n" : " ");
                                }
                            }
                            throw 1;
                        }
                    }
                    swap(y[3][1], y[3][2]);
                }
                swap(y[1][3], y[2][3]);
            }
            swap(y[0][1], y[0][2]);
        }
        swap(y[1][0], y[2][0]);
    }
}

void dfs(int n, int m, int mask) {
    --n;
    if (n == 0) {
        for (auto i: v[m]) {
            if (test(i, con[0]) == 0 || ((i ^ (1 << con[0])) & mask) != 0) {
                continue;
            }
            how[n] = i;
            check(mask | i);
        }
    } else {
        for (auto i: v[m]) {
            if (i & mask) {
                continue;
            }
            how[n] = i;
            for (int j = con[4] + 1; j < 16; ++j) {
                if (j != m && test(i, j) != 0) {
                    con[n] = j;
                    dfs(n, j, mask | (i ^ (1 << j)));
                }
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

    for (int i = 0; i < 16; ++i) {
        for (int j = 0; j < i; ++j) {
            for (int k = 0; k < j; ++k) {
                for (int l = 0; l < k; ++l) {
                    if (x[i] + x[j] + x[k] + x[l] == s) {
                        int m = (1 << i) | (1 << j) | (1 << k) | (1 << l);
                        v[i].push_back(m);
                        v[j].push_back(m);
                        v[k].push_back(m);
                        v[l].push_back(m);
                    }
                }
            }
        }
    }
    try {
        for (int i = 0; i < 16; ++i) {
            con[0] = con[4] = i;
            dfs(4, i, 0);
        }
    } catch (int) {
        return;
    }
    // throw -1;
}

int main() {
    int n;

    cin >> n;
    switch (n) {
    case 1: gao<1>(); break;
    case 2: gao<2>(); break;
    case 3: gao<3>(); break;
    case 4: gao<4>(); break;
    }

    return 0;
}

