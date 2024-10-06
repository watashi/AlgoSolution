class Solution {
  using Graph = vector<vector<int>>;

  Graph fromEdgeList(int n, const vector<vector<int>>& edges) {
    Graph g(n);
    for (const auto& e : edges) {
      int a = e[0], b = e[1];
      g[a].emplace_back(b);
      g[b].emplace_back(a);
    }
    return g;
  }

public:
  int getnext(const Graph& g, int curr, vector<bool> used, int degree) {
    for (int i : g[curr]) {
      if (!used[i] && g[i].size() == degree) {
        return i;
      }
    }
    return -1;
  }

  vector<vector<int>> gao1(int n, const Graph& g, int start) {
    vector<bool> used(n, false);
    vector<int> ret;
    int curr = start;
    // cout << "gao1(" << start << endl;
    while (true) {
      used[curr] = true;
      ret.push_back(curr);
      int next = getnext(g, curr, used, 2);
      // cout << curr << " " << next << endl;
      if (next == -1) {
        curr = getnext(g, curr, used, 1);
        used[curr] = true;
        ret.push_back(curr);
        break;
      }
      curr = next;
    }
    return { ret };
  }

  vector<vector<int>> gao2(int n, const Graph& g, int start) {
    vector<bool> used(n, false);
    vector<vector<int>> ret;
    vector<int> row1;
    int curr = start;
    // cout << "gao2(" << start << endl;
    while (true) {
      used[curr] = true;
      row1.push_back(curr);
      int next = getnext(g, curr, used, 2);
      if (next == -1) {
        curr = getnext(g, curr, used, 3);
        continue;
      }
      used[next] = true;
      row1.push_back(next);
      break;
    }
    const int w = row1.size();
    ret.emplace_back(std::move(row1));
    while (true) {
      int base = 3;
      if (getnext(g, ret.back().front(), used, base) == -1) {
        base = 2;
      }
      vector<int> row = vector<int>();
      for (int i = 0; i < w; ++i) {
        curr = getnext(g, ret.back()[i], used, i == 0 || i == w - 1 ? base : base + 1);
        // cout << "[" << (i == 0 || i == w - 1 ? base : base + 1) << "] " << ret.back()[i] << " " << curr << endl;
        used[curr] = true;
        row.push_back(curr);
      }
      // cout << "===" << endl;
      ret.emplace_back(std::move(row));
      if (base == 2) {
        break;
      }
    }
    return ret;
  }
  
  vector<vector<int>> constructGridLayout(int n, vector<vector<int>>& edges) {
    Graph g = fromEdgeList(n, edges);
    for (int i = 0; i < n; ++i) {
      if (g[i].size() == 1) {
        return gao1(n, g, i);
      }
    }
    for (int i = 0; i < n; ++i) {
      if (g[i].size() == 2) {
        return gao2(n, g, i);
      }
    }
    return {};
  }
};
