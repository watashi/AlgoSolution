class Solution {
public:
  struct Node {
    int l;
    int r;
    vector<pair<int, int>> v;
    std::unique_ptr<Node> pl = nullptr;
    std::unique_ptr<Node> pr = nullptr;
  
    Node(int x, int y) : l(x), r(x + 1) {
      v.emplace_back(y, x + y);
    }

    Node(std::unique_ptr<Node> ppl, std::unique_ptr<Node> ppr) : l(ppl->l), r(ppr->r), pl(std::move(ppl)), pr(std::move(ppr)) {
      auto itl = pl->v.begin(), itr = pr->v.begin();
      while (itl != pl->v.end() || itr != pr->v.end()) {
        int x, y;
        if (itr == pr->v.end() || (itl != pl->v.end() && itl->first < itr->first)) {
          tie(x, y) = *itl++;
        }
        else if (itl == pl->v.end() || itr->first < itl->first) {
          tie(x, y) = *itr++;
        }
        else {
          tie(x, y) = *itl++;
          y = max(y, itr++->second);
        }
        while (!v.empty() && v.back().second <= y) {
          v.pop_back();
        }
        v.emplace_back(x, y);
      }
    }

    /*
    int query(int x, int y) {
      int z = queryImpl(x, y);
      printf("query(%d, %d) [%d, %d) = %d\n", x, y, l, r, z);
      for (const auto& i : v) {
        printf("(%d, %d), ", i.first, i.second);
      }
      puts("");
      return z;
    }
    */

    int query(int x, int y) {
      if (x >= r) {
        return -1;
      }
      else if (x <= l) {
        auto it = lower_bound(v.begin(), v.end(), make_pair(y, -1));
        return it == v.end() ? -1 : it->second;
      }
      else {
        return max(pl->query(x, y), pr->query(x, y));
      }
    }
  };

  std::unique_ptr<Node> build(int n, pair<int, int> a[]) {
    if (n == 1) {
      return std::make_unique<Node>(a[0].first, a[0].second);
    }
    else {
      int m = n / 2;
      return std::make_unique<Node>(build(m, a), build(n - m, a + m));
    }
  }

  vector<int> maximumSumQueries(vector<int>& nums1, vector<int>& nums2, vector<vector<int>>& queries) {
    map<int, int> mp;
    for (int i = 0; i < (int)nums1.size(); ++i) {
      int x = nums1[i], y = nums2[i];
      auto it = mp.find(x);
      if (it == mp.end()) {
        mp.emplace(x, y);
      }
      else {
        it->second = max(it->second, y);
      }
    }
    vector<pair<int, int>> v(mp.begin(), mp.end());
    auto tree = build(v.size(), v.data());

    vector<int> ans;
    for (const auto& q : queries) {
      int x = q[0], y = q[1];
      ans.push_back(tree->query(x, y));
    }
    return ans;
  }
};
