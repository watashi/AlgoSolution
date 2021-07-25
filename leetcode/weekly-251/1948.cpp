#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
  using mark_key_t = map<string, int>;
  using mark_t = map<mark_key_t, int>;
  struct Node {
    string dir;
    mutable int id;
    map<string, int> children;
  };

  void gao(const vector<Node>& dirs, int cur, mark_t& mark, unordered_set<int>& dup) {
    const Node& pwd = dirs[cur];
    mark_key_t k;
    for (auto child: pwd.children) {
      gao(dirs, child.second, mark, dup);
      k[child.first] = dirs[child.second].id;
    }
    if (mark.count(k) == 0) {
      pwd.id = (int)mark.size();
      mark[k] = pwd.id;
    } else {
      pwd.id = mark[k];
      dup.insert(pwd.id);
    }
  }

  void gen(const vector<Node>& dirs, int cur, unordered_set<int>& dup, vector<string> path, vector<vector<string>>& ret) {
    const Node& pwd = dirs[cur];
    if (pwd.children.empty() || dup.count(pwd.id) == 0) {
      path.push_back(pwd.dir);
      for (auto child: pwd.children) {
        gen(dirs, child.second, dup, path, ret);
      }
      ret.push_back(std::move(path));
    }
  }

  vector<vector<string>> deleteDuplicateFolder(vector<vector<string>>& paths) {
    vector<Node> dirs;
    dirs.push_back(Node{"ROOT", -1, map<string, int>()});
    for (const auto& path: paths) {
      int cur = 0;
      for (const auto& dir: path) {
        if (dirs[cur].children.count(dir) == 0) {
          dirs[cur].children[dir] = (int)dirs.size();
          dirs.push_back(Node{dir, -1, map<string, int>()});
        }
        cur = dirs[cur].children[dir];
      }
    }

    mark_t mark;
    unordered_set<int> dup;
    gao(dirs, 0, mark, dup);

    vector<vector<string>> ret;
    for (const auto& child: dirs[0].children) {
      gen(dirs, child.second, dup, vector<string>(), ret);
    }
    return ret;
  }
};

