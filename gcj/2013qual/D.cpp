#include <set>
#include <map>
#include <cstdio>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

#include <boost/graph/adjacency_list.hpp>
#include <boost/graph/strong_components.hpp>

using namespace boost;

const int MAXN = 210;

struct Chest {
  bool self;
  int k;
  vector<int> v;
} chest[MAXN];

void open(map<int, int>& key, const Chest& chest) {
  if (--key[chest.k] == 0) {
    key.erase(chest.k);
  }
  for (int i: chest.v) {
    ++key[i];
  }
}

bool gao(map<int, int> key, set<int> todo) {
  for (bool loop = true; loop; ) {
    loop = false;

    map<int, int> need;
    for (int i: todo) {
      ++need[chest[i].k];
    }
    set<int> done;
    for (auto i: need) {
      if (key.count(i.first) > 0 && key[i.first] >= i.second) {
        done.insert(i.first);
      }
    }
    for (set<int>::iterator it = todo.begin(); it != todo.end(); ) {
      Chest &chest = ::chest[*it];
      if (done.count(chest.k) > 0 || (chest.self && key.count(chest.k) > 0)) {
        open(key, chest);
        loop = true;
        it = todo.erase(it);
      } else {
        ++it;
      }
    }

    static int id[MAXN];
    adjacency_list<vecS, vecS, directedS> g;
    for (int i: todo) {
      for (int j: chest[i].v) {
        add_edge(chest[i].k, j, g);
      }
    }
    strong_components(g, id);
    for (set<int>::iterator it = todo.begin(); it != todo.end(); ++it) {
      Chest &chest = ::chest[*it];
      if (key.count(chest.k) == 0) {
        continue;
      }
      for (int j: chest.v) {
        if (id[chest.k] == id[j]) {
          open(key, chest);
          loop = true;
          todo.erase(it);
          goto NEXT;
        }
      }
    }

NEXT:
    continue;
  }

  return todo.empty();
}

int main() {
  int re, m, n, x;
  set<int> todo;
  map<int, int> key;

  scanf("%d", &re);
  for (int ri = 1; ri <= re; ++ri) {
    scanf("%d%d", &m, &n);
    key.clear();
    for (int i = 0; i < m; ++i) {
      scanf("%d", &x);
      ++key[x];
    }
    todo.clear();
    for (int i = 0; i < n; ++i) {
      scanf("%d%d", &chest[i].k, &m);
      chest[i].self = false;
      chest[i].v.clear();
      for (int j = 0; j < m; ++j) {
        scanf("%d", &x);
        chest[i].self = chest[i].self || x == chest[i].k;
        chest[i].v.push_back(x);
      }
      todo.insert(i);
    }

    printf("Case #%d:", ri);
    if (gao(key, todo)) {
      while (!todo.empty()) {
        for (int i: todo) {
          if (key.count(chest[i].k) == 0) {
            continue;
          }
          map<int, int> key2 = key;
          set<int> todo2 = todo;
          open(key2, chest[i]);
          todo2.erase(i);
          if (gao(key2, todo2)) {
            open(key, chest[i]);
            todo.erase(i);
            printf(" %d", i + 1);
            break;
          }
        }
      }
      puts("");
    } else {
      puts(" IMPOSSIBLE");
    }
  }


  return 0;
}
