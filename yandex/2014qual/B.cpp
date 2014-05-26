#include <map>
#include <string>
#include <cstdio>
#include <algorithm>

using namespace std;

const int MAXL = 80;

int main() {
  int n, m;
  char s[MAXL];
  map<string, int> c;

  scanf("%d", &n);
  m = __builtin_ctz(n);
  for (int i = 1; i < n; ++i) {
    scanf("%s%*s", s);
    ++c[s];
  }

  for (const auto& i: c) {
    if (i.second == m) {
      puts(i.first.c_str());
    }
  }

  return 0;
}

