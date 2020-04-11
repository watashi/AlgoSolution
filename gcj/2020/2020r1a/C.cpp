#include <cstdio>
#include <iostream>
#include <set>
#include <tuple>
#include <utility>
#include <vector>

using namespace std;

struct List {
  struct Node {
    int prev, next;
  };

  vector<Node> nodes;

  List(int n): nodes(n + 1) {
    for (int i = 0; i <= n; ++i) {
      nodes[i].prev = i - 1;
      nodes[i].next = i + 1;
    }
    nodes[n].next = 0;
  }

  void remove(int i) {
    nodes[nodes[i].prev].next = nodes[i].next;
    nodes[nodes[i].next].prev = nodes[i].prev;
  }

  const Node& operator[](int i) const {
    return nodes[i];
  }
};

void gao(const vector<vector<int>>& s, int x, int y, int& total, vector<pair<int, int>>& neightbors) {
  if (x != 0 && y != 0) {
    total += s[x][y];
    neightbors.emplace_back(x, y);
  }
}

int main() {
  int re;

  scanf("%d", &re);
  for (int ri = 1; ri <= re; ++ri) {
    int nr, nc;

    scanf("%d%d", &nr, &nc);

    vector<vector<int>> s(nr + 1, vector<int>(nc + 1));
    vector<List> r(nr + 1, List(nc)), c(nc + 1, List(nr));
    set<pair<int, int>> todo;
    int64_t ans = 0, sum = 0;

    for (int i = 1; i <= nr; ++i) {
      for (int j = 1; j <= nc; ++j) {
        scanf("%d", &s[i][j]);
        sum += s[i][j];
        todo.emplace(i, j);
      }
    }

    while (!todo.empty()) {
      set<pair<int, int>> curr = std::move(todo);
      set<pair<int, int>> dead;

      ans += sum;
      for (const auto& k: curr) {
        int i, j, total = 0;
        vector<pair<int, int>> neightbors;

        tie(i, j) = k;
        gao(s, i, r[i][j].prev, total, neightbors);
        gao(s, i, r[i][j].next, total, neightbors);
        gao(s, c[j][i].prev, j, total, neightbors);
        gao(s, c[j][i].next, j, total, neightbors);
        if ((int)neightbors.size() * s[i][j] < total) {
          sum -= s[i][j];
          dead.emplace(i, j);
          for (const auto& kk: neightbors) {
            todo.insert(kk);
          }
        }
      }

      for (const auto& k: dead) {
        r[k.first].remove(k.second);
        c[k.second].remove(k.first);
        todo.erase(k);  // !!
      }
    }

    cout << "Case #" << ri << ": " << ans << endl;
  }

  return 0;
}
