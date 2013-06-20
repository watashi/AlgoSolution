#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

struct Prob {
  int i, a, l, o;
};

struct Team {
  int t, z, v, c;
};

inline int ceil(int a, int b) {
  return (a + b - 1) / b;
}

int main() {
  int m, n, t, l;
  vector<Prob> prob;
  vector<Team> team;

#ifndef __WATASHI__
  freopen("unfair.in", "r", stdin);
  freopen("unfair.out", "w", stdout);
#endif

  scanf("%d%d%d%d", &m, &n, &t, &l);
  prob.resize(m);
  for (auto& i: prob) {
    scanf("%d%d%d%d", &i.i, &i.a, &i.l, &i.o);
  }
  team.resize(t);
  for (auto& j: team) {
    scanf("%d%d%d%d", &j.t, &j.z, &j.v, &j.c);
  }

  vector<bool> probset(m), ans;
  int bestrank = t;

  fill(probset.begin(), probset.begin() + n, true);
  do {
    vector<pair<int, int> > summary;
    for (const Team& j: team) {
      vector<pair<int, int> > todo;
      for (const Prob& i: prob) {
        if (!probset[&i - prob.data()] || j.t + j.c <= i.i - i.o) {
          continue;
        }
        int eij = ceil(i.i, i.o) + max(ceil(i.a, j.c), 5);
        int tij = max(i.i - j.t, 0) + ceil(i.a, j.z + j.c) + ceil(i.l, j.v);
        todo.emplace_back(eij, tij);
      }
      sort(todo.begin(), todo.end());

      int ac = 0, penalty = 0, time = 0;
      for (const auto& i: todo) {
        time += i.second;
        if (time > l) {
          break;
        } else {
          ++ac;
          penalty += time;
        }
      }
      summary.emplace_back(-ac, penalty);
    }

    pair<int, int> score = summary[0];
    sort(summary.begin(), summary.end());
    int rank = lower_bound(summary.begin(), summary.end(), score) - summary.begin();
    if (rank < bestrank) {
      bestrank = rank;
      ans = probset;
    }
  } while (prev_permutation(probset.begin(), probset.end()));

  bool first = true;
  for (int i = 0; i < (int)ans.size(); ++i) {
    if (ans[i]) {
      if (first) {
        first = false;
      } else {
        putchar(' ');
      }
      printf("%d", i + 1);
    }
  }
  puts("");

  return 0;
}



