#include <climits>
#include <iostream>
#include <algorithm>

using namespace std;

typedef long long llint;

int main() {
  llint n, sg, ans;

  cin >> n;
  cout << n * (n + 1) / 2 << " ";
  switch (n % 4) {
    case 0: sg = n; break;
    case 1: sg = 1; break;
    case 2: sg = n ^ 1; break;
    default: sg = 0; break;
  }

  if (sg == 0) {
    ans = 0;
  } else {
#if 0
    ans = 0;
    for (llint i = 1; i <= n; ++i) {
      if ((i ^ sg) < i) {
        ++ans;
      }
    }
#else
    sg = CHAR_BIT * sizeof(llint) - 1 - __builtin_clzll(sg);
    ans = 0;
    if (n >= (1 << (sg + 1))) {
      ans += (n >> (sg + 1) << sg);
    }
    if ((n & (1 << sg)) != 0) {
      ans += (n & ((1 << sg) - 1)) + 1;
    }
#endif
  }
  cout << ans << endl;

  return 0;
}

