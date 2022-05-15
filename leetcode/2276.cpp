class CountIntervals {
public:
  CountIntervals() {
    s = 0;
  }

  void add(int left, int right) {
    ++right;
    auto it = m.lower_bound(left);
    if (it != m.begin()) {
      --it;
      if (it->second >= right) {
        return;
      } else if (it->second >= left) {
        left = it->first;
        s -= it->second - it->first;
        it = m.erase(it);
      } else {
        ++it;
      }
    }
    while (it != m.end() && it->first <= right) {
      right = max(right, it->second);
      s -= it->second - it->first;
      it = m.erase(it);
    }
    s += right - left;
    m[left] = right;
  }

  int count() {
    return s;
  }

  map<int, int> m;
  int s;
};
