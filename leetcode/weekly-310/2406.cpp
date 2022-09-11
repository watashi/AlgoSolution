class Solution {
public:
  int minGroups(vector<vector<int>>& intervals) {
    vector<pair<int, int>> v;
    for (const auto& i : intervals) {
      v.emplace_back(i[0], i[1]);
    }
    sort(v.begin(), v.end());
    multiset<int> ms;
    for (const auto& i : v) {
      if (!ms.empty() && *ms.begin() < i.first) {
        ms.erase(ms.begin());
      }
      ms.insert(i.second);
    }
    return ms.size();
  }
};
