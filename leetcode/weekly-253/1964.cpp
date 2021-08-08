class Solution {
public:
  vector<int> longestObstacleCourseAtEachPosition(vector<int>& obstacles) {
    map<int, int> mp;
    vector<int> ans;
    mp[-1] = 0;
    for (auto i: obstacles) {
      auto it = mp.upper_bound(i);
      --it;
      auto j = it->second + 1;
      ans.push_back(j);
      if (it->first < i) {
        ++it;
      }
      while (it != mp.end() && it->second <= j) {
        it = mp.erase(it);
      }
      mp[i] = j;
    }
    return ans;
  }
};
