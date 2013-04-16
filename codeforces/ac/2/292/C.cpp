#include <cstdio>
#include <vector>

using namespace std;

vector<int> digit, ip;
int d[20];

vector<vector<int> > ans;

void show(int n, int m) {
  if (n == 4) {
    if (d[m] == -1) {
      ans.push_back(ip);
    }
  } else if (d[m] == 0) {
    ip[n] = 0;
    show(n + 1, m + 1);
  } else {
    ip[n] = 0;
    for (int i = m; d[i] != -1; ++i) {
      ip[n] = ip[n] * 10 + d[i];
      if (ip[n] < 256) {
        show(n + 1, i + 1);
      }
    }
  }
}

void gen(int l, int r, int mask) {
  if (l <= r) {
    for (int i = 0; i < (int)digit.size(); ++i) {
      d[l] = d[r] = digit[i];
      gen(l + 1, r - 1, mask & ~(1 << i));
    }
  } else if (mask == 0) {
    show(0, 0);
  }
}

int main() {
  int n;

  scanf("%d", &n);
  digit.resize(n);
  for (int i = 0; i < n; ++i) {
    scanf("%d", &digit[i]);
  }
  ip.resize(4);
  for (int i = 4; i <= 12; ++i) {
    d[i] = -1;
    gen(0, i - 1, (1 << n) - 1);
  }
  printf("%d\n", (int)ans.size());
  for (const auto& i: ans) {
    printf("%d.%d.%d.%d\n", i[0], i[1], i[2], i[3]);
  }

  return 0;
}

