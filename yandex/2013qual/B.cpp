#include <cstdio>
#include <vector>

using namespace std;

int main() {
  int n;
  vector<bool> p;

  scanf("%d", &n);
  vector<bool>(n + 2, true).swap(p);
  p[0] = p[1] = false;
  for (int i = 2; i < (int)p.size(); ++i) {
    if (p[i]) {
      if (p[i - 2]) {
        printf("%d\n", i - 1);
      }
      for (int j = i * i; j < (int)p.size(); j += i) {
        p[j] = false;
      }
    }
  }

  return 0;
}

