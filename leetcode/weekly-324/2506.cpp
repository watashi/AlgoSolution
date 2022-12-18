class Solution {
public:
  int similarPairs(vector<string>& words) {
    map<set<char>, int> mp;
    for (const auto& i : words) {
      ++mp[set<char>(i.begin(), i.end())];
    }
    int ret = 0;
    for (const auto& i : mp) {
      ret += i.second * (i.second - 1) / 2;
    }
    return ret;
  }
};

