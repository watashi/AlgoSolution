#include <cstdio>
#include <vector>
#include <numeric>
#include <algorithm>

using namespace std;

const int MAXL = 10;

struct Rho {
  vector<int> x, y;
  int s, t;

  void init(int k, int a, int b, int m) {
    vector<int> w(m, -1);
    x.clear();
    for (int i = 0; ; ++i) {
      k %= m;
      if (w[k] == -1) {
        w[k] = i;
        x.push_back(k);
      } else {
        s = w[k];
        t = i;
        break;
      }
      k *= a;
      k += b;
    }
    y.clear();
    y.push_back(0);
    partial_sum(x.begin(), x.end(), back_inserter(y));
  }

  int at(int i) {
    return i < t ? x[i] : x[s + (i - s) % (t - s)];
  }

  int sum(int n) {
    if (n < t) {
      return y[n];
    } else {
      div_t d = div(n - s, t - s);
      return (y[t] - y[s]) * d.quot + y[s + d.rem];
    }
  }

  int sum(int l, int r) {
    return sum(r) - sum(l);
  }
} a, b;

int main() {
  int n, a0, A, B, M;
  double l, r, mid, sigma, cmp;

  while (scanf("%d", &n) != EOF) {
    ++n;
    scanf("%d%d%d%d", &a0, &A, &B, &M);
    a.init(a0, A * A, (A + 1) * B, M);
    a0 = (A * a0 + B) % M;
    b.init(a0, A * A, (A + 1) * B, M);
    sigma = a.sum(n);

    l = 0;
    r = 0.5;
    while (r - l > 1e-7) {
      mid = (l + r) / 2;
      cmp = mid * sigma;
      for (int i = 0; i <= MAXL && i <= n; ++i) {
        for (int j = i; j <= MAXL && j <= n; ++j) {
          if ((1 - mid) * a.sum(i, j) - mid * b.sum(i, j) >= cmp) {
            goto L;
          }
        }
        for (int j = max(i, n - MAXL); j <= n; ++j) {
          if ((1 - mid) * a.sum(i, j) - mid * b.sum(i, j) >= cmp) {
            goto L;
          }
        }
      }

      r = mid;
      continue;
L:
      l = mid;
      continue;
    }
    printf("%.6lf\n", l + r);
  }

  return 0;
}

//MAXL=500
//ID 	Date (UTC) 	Status 	CPU 	Memory 	Author 	Source 	Problem / Title
//715034  	2011-01-04 07:59:32 	Accepted	7.568	17040	26909	C++	4664 - Spam Detection

//MAXL=20
//ID 	Date (UTC) 	Status 	CPU 	Memory 	Author 	Source 	Problem / Title
//715035  	2011-01-04 08:00:42 	Accepted	3.670	17056	26909	C++	4664 - Spam Detection

/*
id => 1243131
pid => 4664
pname => Spam Detection
status => Accepted
lang => C++
time => 0.013
data => 2013-06-03 15:39:29
*/
