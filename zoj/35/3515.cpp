#include <cstdio>

long long gcd(long long a, long long b) {
    return b == 0 ? a : gcd(b, a % b);
}

long long gao(long long x, long long y, long long z) {
    long long ret = 0;
    long long c;
    c = z / x;
    ret += c * ((x + 1) * (y + 1) / 2 - y);
    ret += c * (c - 1) / 2 * (x * y);
    z %= x;
    ret += c * y * z;
//  printf("(%lld,%lld,%lld) 0+%lld\n", x, y, c * x + z, ret);
    if (z > 0) {
        if (x <= y) {
            c = y / x;
            ret += c * z * (z - 1) / 2;
            ret += gao(x, y % x, z);
        } else {
            c = y * (z - 1) / x + 1;
            ret += c * z;
            ret -= gao(y, x, c) - 1;
        }
    }
    return ret;
}

int main() {
    long long h, x, y, dx, dy, dz, ans;

    while (scanf("%lld%lld%lld", &h, &x, &y) != EOF) {
        dx = x;
        dy = y - h;
        if (h == 0) {
            ans = 0;
        } else {
            dz = gcd(dx, dy);
            dx /= dz;
            dy /= dz;
            dz = dx * h / (dx - dy) + 1;
            ans = gao(dx, dy, dz);
        //  printf("dx = %lld; dy = %lld; dz = %lld; ans = %lld\n", dx, dy, dz, ans);
            ans += h * dz;
            ans -= (dz + 1) * dz / 2;
        //  printf("+%lld -%lld\n", h * dz, (dz + 1) * dz / 2);
        }
        printf("%lld\n", ans);
    }

    return 0;
}

// 2012-09-07 16:04:13 | Accepted | 3515 | C++ | 0 | 180 | watashi | Source
