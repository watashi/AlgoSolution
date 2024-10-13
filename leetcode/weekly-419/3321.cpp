class Solution {
public:
  set<pair<int, int>> smaller, greater;
  size_t limit = 0;
  long long total = 0;

  void insert(const pair<int, int>& p) {
    if (greater.insert(p).second) {
      total += (long long)p.first * p.second;
    }
    if (greater.size() > limit) {
      auto v = *greater.begin();
      greater.erase(v);
      total -= (long long)v.first * v.second;
      smaller.insert(v);
    }
  }

  void erase(const pair<int, int>& p) {
    if (smaller.erase(p) > 0) {
      return;
    }
    if (greater.erase(p) > 0) {
      total -= (long long)p.first * p.second;
      if (greater.size() < limit && !smaller.empty()) {
        auto v = *smaller.rbegin();
        smaller.erase(v);
        total += (long long)v.first * v.second;
        greater.insert(v);
      }
    }
  }
  
  vector<long long> findXSum(vector<int>& nums, int k, int x) {
    map<int, int> c;
    for (int i = 0; i < k; ++i) {
      ++c[nums[i]];
    }

    smaller.clear();
    greater.clear();
    limit = x;
    total = 0;
    for (const auto& i : c) {
      insert(make_pair(i.second, i.first));
    }

    vector<long long> ret;
    ret.push_back(total);
    for (int i = k; i < (int)nums.size(); ++i) {
      const int head = nums[i - k];
      const int tail = nums[i];
      if (head != tail) {
        const int chead = c[head]--;
        const int ctail = c[tail]++;
        erase(make_pair(chead, head));
        if (chead > 1) {
          insert(make_pair(chead - 1, head));
        }
        if (ctail > 0) {
          erase(make_pair(ctail, tail));
        }
        insert(make_pair(ctail + 1, tail));
      }
      ret.push_back(total);
    }
    return ret;
  }
};
