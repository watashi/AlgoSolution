class Solution {
public:
  vector<long long> gao(const vector<int>& v) {
    stack<pair<long long, int>> stk;
    stk.emplace(0, -1);
    vector<long long> ret;
    long long sum = 0;
    for (int i = 0; i < (int)v.size(); ++i) {
      int last = i;
      while (stk.top().first >= v[i]) {
        sum -= (stk.top().first - v[i]) * (last - stk.top().second);
        last = stk.top().second;
        stk.pop();
      }
      sum += v[i];
      stk.emplace(v[i], last);
      ret.push_back(sum);
    }
    return ret;
  }

  long long maximumSumOfHeights(vector<int>& maxHeights) {
    auto pre = gao(maxHeights);
    auto suf = gao(vector<int>(maxHeights.rbegin(), maxHeights.rend()));
    reverse(suf.begin(), suf.end());
    /*
    errf("%lld, ", pre);
    errf("%lld, ", suf);
    errf("%d, ", maxHeights);
    */
    long long ret = 0;
    for (int i = 0; i < (int)maxHeights.size(); ++i) {
      ret = max(ret, pre[i] + suf[i] - maxHeights[i]);
    }
    return ret;
  }
};
