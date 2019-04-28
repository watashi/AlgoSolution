#include <algorithm>
#include <cstdio>
#include <map>
#include <string>
#include <vector>

using namespace std;

struct Hungarian {
  int nx, ny;
  vector<int> mx, my;
  vector<vector<int> > e;

  void init(int nx, int ny) {
    this->nx = nx;
    this->ny = ny;
    mx.resize(nx);
    my.resize(ny);
    e.clear();
    e.resize(nx);
    mark.resize(nx);
  }

  void add(int a, int b) {
    e[a].push_back(b);
  }

  // vector<bool> is evil!!!
  basic_string<bool> mark;

  bool augment(int i) {
    if (!mark[i]) {
      mark[i] = true;
      for (vector<int>::const_iterator j = e[i].begin(); j != e[i].end(); ++j) {
        if (my[*j] == -1 || augment(my[*j])) {
          mx[i] = *j;
          my[*j] = i;
          return true;
        }
      }
    }
    return false;
  }

  int gao() {
    int ret = 0;
    fill(mx.begin(), mx.end(), -1);
    fill(my.begin(), my.end(), -1);
    for (int i = 0; i < nx; ++i) {
      fill(mark.begin(), mark.end(), false);
      if (augment(i)) {
        ++ret;
      }
    }
    return ret;
  }
} h;

int getId(map<string, int>& mp, const string& s) {
  auto it = mp.find(s);
  if (it != mp.cend()) {
    return it->second;
  } else {
    int ret = mp.size();
    mp.emplace(s, ret);
    return ret;
  }
}

int main() {
  int re;

  scanf("%d", &re);
  for (int ri = 1; ri <= re; ++ri) {
    int n, ans;
    char s[80], t[80];
    map<string, int> fst, snd;
    vector<pair<int, int>> e;

    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
      scanf("%s%s", s, t);
      e.emplace_back(getId(fst, s), getId(snd, t));
    }
    h.init(fst.size(), snd.size());
    for (const auto& i: e) {
      h.add(i.first, i.second);
    }
    ans = e.size() - (fst.size() + snd.size() - h.gao());
    printf("Case #%d: %d\n", ri, ans);
  }

  return 0;
}
