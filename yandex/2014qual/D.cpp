#include <map>
#include <cstdio>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

int main() {
  int n, w, h;
  vector<pair<int, int>> v;

  scanf("%d", &n);
  v.resize(n);
  for (auto i = v.rbegin(); i != v.rend(); ++i) {
    scanf("%d%d", &i->first, &i->second);
  }

  map<int, int> mp;
  map<int, int>::iterator it;

  for (const auto& i: v) {
    tie(w, h) = i;
    it = mp.lower_bound(w);
    if (it != mp.end() && it->second >= h) {
      puts("Invisible paper detected");
      return 0;
    } else {
      while (true) {
        it = mp.upper_bound(w);
        if (it == mp.begin()) {
          break;
        } else {
          --it;
        }
        if (it->second > h) {
          break;
        } else {
          mp.erase(it);
        }
      }
      mp[w] = h;
    }
  }
  puts("Well done");
  return 0;
}

