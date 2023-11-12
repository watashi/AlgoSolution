class Solution {
public:
  static int toi(const char* s) {
    return (s[0] - '0') * 10 + (s[1] - '0');
  }
     
  vector<string> findHighAccessEmployees(vector<vector<string>>& access_times) {
    map<string, vector<int>> m;
    for (const auto& i : access_times) {
      const string& k = i[0];
      const string& t = i[1];
      m[k].push_back(toi(&t[0]) * 60 + toi(&t[2]));
    }
    vector<string> v;
    for (auto& it: m) {
      auto& ts = it.second;
      sort(ts.begin(), ts.end());
      for (int i = 2; i < (int)ts.size(); ++i) {
        if (ts[i] - ts[i - 2] < 60) {
          v.push_back(it.first);
          break;
        }
      }
    }
    return v;
  }
};
