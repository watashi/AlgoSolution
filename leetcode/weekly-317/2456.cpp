class Solution {
public:
  struct Stat {
    int64_t sum = 0;
    pair<int, string> best{1, ""};
  };

  vector<vector<string>> mostPopularCreator(vector<string>& creators, vector<string>& ids, vector<int>& views) {
    map<string, Stat> s;
    int64_t maxsum = -1;
    for (int i = 0; i < (int)creators.size(); ++i) {
      auto& t = s[creators[i]];
      t.sum += views[i];
      maxsum = max(maxsum, t.sum);
      t.best = min(t.best, make_pair(-views[i], ids[i]));
    }
    vector<vector<string>> ret;
    for (const auto& i : s) {
      if (i.second.sum == maxsum) {
        ret.push_back(vector<string>{i.first, i.second.best.second});
      }
    }
    return ret;
  }
};
