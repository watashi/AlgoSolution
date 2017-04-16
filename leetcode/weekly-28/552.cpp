constexpr int SZ = 7;

struct Mat {
    int64_t a[SZ][SZ];

    int64_t* operator[](int i) {
        return a[i];
    }

    void show() const {
        for (int i = 0; i < SZ; ++i) {
            for (int j = 0; j < SZ; ++j) {
                printf("%lld ", a[i][j]);
            }
            puts("");
        }
    }
};

constexpr int64_t MOD = 1000000007;

Mat operator*(Mat a, Mat b) {
    Mat ret;
    for (int i = 0; i < SZ; ++i) {
        for (int j = 0; j < SZ; ++j) {
            ret[i][j] = 0;
            for (int k = 0; k < SZ; ++k) {
                ret[i][j] += a[i][k] * b[k][j];
                ret[i][j] %= MOD;
            }
        }
    }
    return ret;
}

Mat pow(Mat a, int64_t b) {
    Mat ret;
    for (int i = 0; i < SZ; ++i) {
        for (int j = 0; j < SZ; ++j) {
            ret[i][j] = i == j ? 1 : 0;
        }
    }
    while (b > 0) {
        if ((b & 1) != 0) {
            ret = ret * a;
        }
        a = a * a;
        b >>= 1;
    }
    return ret;
}

constexpr int P = 0, L = 1, LL = 2, AP = 3, AL = 4, ALL = 5, A = 6;

class Solution {
public:
    int checkRecord(int n) {
        Mat t;
        for (int i = 0; i < SZ; ++i) {
            for (int j = 0; j < SZ; ++j) {
                t[i][j] = 0;
            }
        }
        t[A][P] = t[A][L] = t[A][LL] = 1;   // ?A
        t[AP][A] = t[AL][A] = 1;    // A?
        t[P][P] = t[AP][AP] = 1;    // PP
        t[P][L] = t[P][LL] = t[AP][AL] = t[AP][ALL] = 1;    // LP
        t[L][P] = t[AL][AP] = 1;    // PL
        t[LL][L] = t[ALL][AL] = 1;  // LL
        t = pow(t, n - 1);
        int64_t ans = 0;
        for (int i = 0; i < SZ; ++i) {
            for (int j = 0; j < SZ; ++j) {
                if (j == P || j == L || j == A) {
                    ans += t[i][j];
                }
            }
        }
        return (int)(ans % MOD);
    }
};
