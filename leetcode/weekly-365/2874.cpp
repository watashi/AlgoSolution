class Solution {
public:
  long long maximumTripletValue(vector<int>& a) {
    long long diff = a[0] - a[1], maxa = a[0], ret = 0;
    for (int i = 2; i < (int)a.size(); ++i) {
      ret = max(ret, a[i] * diff);
      maxa = max<long long>(maxa, a[i - 1]);
      diff = max(diff, maxa - a[i]);
    }
    return ret;
  }
};
