class Solution {
public:
  vector<int> fullBloomFlowers(vector<vector<int>>& flowers, vector<int>& persons) {
    vector<pair<int, int>> fs;
    for (int i = 0; i < (int)flowers.size(); ++i) {
      fs.emplace_back(flowers[i][0], flowers[i][1]);
    }
    sort(fs.rbegin(), fs.rend());
    vector<pair<int, int>> qs;
    for (int i = 0; i < (int)persons.size(); ++i) {
      qs.emplace_back(persons[i], i);
    }
    sort(qs.begin(), qs.end());
    multiset<int> ms;
    vector<int> ret(persons.size());
    for (const auto& q : qs) {
      while (!fs.empty() && fs.back().first <= q.first) {
        ms.insert(fs.back().second);
        fs.pop_back();
      }
      while (!ms.empty() && *ms.begin() < q.first) {
        ms.erase(ms.begin());
      }
      ret[q.second] = (int)ms.size();
    }
    return ret;
  }
};
