#include <cstdio>
#include <string>
#include <vector>

using namespace std;

vector<string> ans[13];
const string ans1[] = {"0", "1"};
const string ans2[] = {"00", "10", "01", "11"};

int main() {
#ifndef __WATASHI__
  freopen("code.in", "r", stdin);
  freopen("code.out", "w", stdout);
#endif

  int n;
  scanf("%d", &n);

  ans[1].insert(ans[1].begin(), ans1, ans1 + 2);
  ans[2].insert(ans[2].begin(), ans2, ans2 + 4);
  for (int k = 3; k <= n; ++k) {
    ans[k].resize(1 << k);
    int left = k / 2;
    int right = k - left;
    if (left % 2 != 0 && right % 2 != 0) {
      --left;
      ++right;
    }
    int maskl = (1 << left) - 1;
    int maskr = (1 << right) - 1;
    for (int i = 0; i < (int)ans[k].size(); ++i) {
      ans[k][i] = ans[left][i & maskl] + ans[right][(i + (i >> right)) & maskr];
    }
  }

  for (vector<string>::const_iterator i = ans[n].begin(); i != ans[n].end(); ++i) {
    puts(i->c_str());
  }

  return 0;
}

