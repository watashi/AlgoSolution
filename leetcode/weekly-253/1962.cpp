class Solution {
public:
  int minStoneSum(vector<int>& piles, int k) {
    multiset<int> s(piles.begin(), piles.end());
    for (int i = 0; i < k; ++i) {
      auto it = s.end();
      --it;
      int t = (*it + 1) / 2;
      s.erase(it);
      s.insert(t);
    }
    return accumulate(s.begin(), s.end(), 0);
  }
};
