class Solution {
public:
  vector<string> removeAnagrams(vector<string>& words) {
    vector<string> ret;
    string pre;
    for (const auto& i : words) {
      auto j = i;
      sort(j.begin(), j.end());
      if (j != pre) {
        ret.push_back(i);
        pre = j;
      }
    }
    return ret;
  }
};
