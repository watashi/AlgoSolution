#include <cstdio>

int phi(int n) {
  int m = 1;
  for (int i = 2; n > 1; ++i) {
    if (n % i == 0) {
      m *= i - 1;
      n /= i;
      while (n % i == 0) {
        m *= i;
        n /= i;
      }
    }
  }
  return m;
}

int powMod(int a, int b, int m) {
  int c = 1 % m;
  while (b > 0) {
    if ((b & 1) != 0) {
      c = c * a % m;
    }
    a = a * a % m;
    b >>= 1;
  }
  return c;
}

int gao(int b) {
  if (b == 1) {
    return 0;
  } else {
    int d = phi(b);
    return powMod(2, d + gao(d), b);
  }
}

int gao(int n, int b) {
  if (n == 1) {
    return 2;
  } else if (n == 2) {
    return 4;
  } else if (n == 3) {
    return 16;
  } else if (n == 4) {
    return 65536;
  } else {
    int d = phi(b);
    return powMod(2, d + gao(n - 1, d), b);
  }
}

int main() {
  int t, n, m, x, y;

#ifndef __WATASHI__
  freopen("ackerman.in", "r", stdin);
  freopen("ackerman.out", "w", stdout);
#endif
  scanf("%d", &t);
  x = gao(t);
  for (int ri = 1; ; ++ri) {
    scanf("%d%d", &n, &m);
    if (n == 0) {
      break;
    } else if (n == 1) {
      y = 2 * m % t;
    } else if (n == 2) {
      y = powMod(2, m, t);
    } else if (n == 3) {
      if (m < 32) {
        y = gao(m, t) % t;
      } else {
        y = x;
      }
    } else {
      if (m == 1) {
        y = 2 % t;
      } else if (m == 2) {
        y = 4 % t;
      } else if (n == 4 && m == 3) {	// WA
        y = gao(4, t) % t;
      } else {
        y = x;
      }
    }
    printf("Case %d: %d\n", ri, y);
  }

  return 0;
}

