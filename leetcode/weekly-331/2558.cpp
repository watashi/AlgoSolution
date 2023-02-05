class Solution {
public:
  int isqrt(int x) {
    int y = (int)sqrt(x) - 1;
    while (y * y <= x) {
      ++y;
    }
    return y - 1;
  }

  long long pickGifts(vector<int>& gifts, int k) {
    priority_queue<int> pq(gifts.begin(), gifts.end());
    for (int i = 0; i < k; ++i) {
      int x = pq.top();
      pq.pop();
      pq.push(isqrt(x));
    }
    int64_t ret = 0;
    while (!pq.empty()) {
      ret += pq.top();
      pq.pop();
    }
    return ret;
  }
};
