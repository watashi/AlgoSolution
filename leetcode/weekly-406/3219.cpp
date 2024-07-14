class Solution {
public:
  long long minimumCost(int m, int n, vector<int>& hc, vector<int>& vc) {
    sort(hc.rbegin(), hc.rend());
    sort(vc.rbegin(), vc.rend());
    int sh = 0;
    int sv = 0;
    long long ret = 0;
    while (!hc.empty() || !vc.empty()) {
      if (vc.empty() || (!hc.empty() && hc.back() < vc.back())) {
        ret += hc.back() * (1LL + (int)vc.size());
        hc.pop_back();
      }
      else {
        ret += vc.back() * (1LL + (int)hc.size());
        vc.pop_back();
      }
    }
    return ret;
  }
};

