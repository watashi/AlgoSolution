class Solution {
  struct SegTree {
    static inline int L(int i) { return i << 1; }
    static inline int R(int i) { return L(i) ^ 1; }

    int m = 1;
    vector<int> a, s;

    void init(int n) {
      m = 1;
      while (m < n) {
        m <<= 1;
      }
      a = vector<int>(m + m, 0);
      s = vector<int>(m + m, 0);
    }

    void add(int p, int pl, int pr, int l, int r, int x) {
      s[p] += x * (r - l);
      // printf("%d [%d, %d) [%d, %d) %d %d\n", p, pl, pr, l, r, a[p], s[p]);
      if (pl == l && pr == r) {
        a[p] += x;
        return;
      }
      int pm = (pl + pr) / 2;
      if (r <= pm) {
        add(L(p), pl, pm, l, r, x);
      }
      else if (pm <= l) {
        add(R(p), pm, pr, l, r, x);
      }
      else {
        add(L(p), pl, pm, l, pm, x);
        add(R(p), pm, pr, pm, r, x);
      }
    }

    void add(int x, int y) {
      printf("add(%d, %d)\n", x, y);
      add(1, 0, m, 1, x + 1, y);
    }

    int sum(int p, int pl, int pr, int l, int r) const {
      // printf("%d [%d, %d) [%d, %d) %d\n", p, pl, pr, l, r, a[p], s[p]);
      if (pl == l && pr == r) {
        return s[p];
      }
      int pm = (pl + pr) / 2;
      int ret = a[p] * (r - l);
      if (r <= pm) {
        ret += sum(L(p), pl, pm, l, r);
      }
      else if (pm <= l) {
        ret += sum(R(p), pm, pr, l, r);
      }
      else {
        ret += sum(L(p), pl, pm, l, pm) + sum(R(p), pm, pr, pm, r);
      }
      return ret;
    }

    // >= x
    int sum(int x) const {
      return sum(1, 0, m, x, m);
    }
  };

  int n = 0;
  vector<int> cs;
  map<int, int> mp;
  SegTree st;

  pair<int, int> getRange(int x) const {
    auto it = --mp.upper_bound(x);
    if (mp.size() > 1 && cs.front() != cs.back() && (it->first == 0 || it->second == n)) {
      return make_pair(mp.rbegin()->first, mp.begin()->second);
    }
    return *it;
  }

  int rangeSize(pair<int, int> r) const {
    int w = r.second - r.first;
    return w <= 0 ? w + n : w;
  }

  int query(int size) const {
    // printf("query(%d)\n", size);
    const auto r = getRange(0);
    if (n % 2 == 0 && rangeSize(r) == n) {
      return n;
    }
    else {
      return st.sum(size);
    }
  }

  void update(int index, int color) {
    // printf("update(%d, %d)\n", index, color);
    if (cs[index] == color) {
      return;
    }

    pair<int, int> r = *--mp.upper_bound(index);
    set<pair<int, int>> toDel, toAdd;
    toDel.emplace(r.first, r.second);
    if (r.first < index && index + 1 < r.second) {
      toAdd.emplace(r.first, index);
      toAdd.emplace(index, index + 1);
      toAdd.emplace(index + 1, r.second);
    }
    else {
      const bool left = index == r.first;
      if (left) {
        if (r.first != 0) {
          const auto prev = *--mp.lower_bound(r.first);
          toDel.insert(prev);
          r.first = prev.first;
        }
      }
      const bool right = index == r.second - 1;
      if (right) {
        if (r.second != n) {
          const auto next = *mp.lower_bound(r.second);
          toDel.insert(next);
          r.second = next.second;
        }
      }
      if (left && right) {
        toAdd.insert(r);
      }
      else if (left) {
        toAdd.emplace(r.first, index + 1);
        toAdd.emplace(index + 1, r.second);
      }
      else if (right) {
        toAdd.emplace(r.first, index);
        toAdd.emplace(index, r.second);
      }
      else {
        assert(false);
      }
    }

    set<pair<int, int>> deleted;
    for (const auto& i : toDel) {
      const auto ri = getRange(i.first);
      if (deleted.insert(ri).second) {
        st.add(rangeSize(ri), -1);
      }
    }
    for (const auto& i : {0, n}) {
      const auto ri = getRange(i);
      if (deleted.insert(ri).second) {
        st.add(rangeSize(ri), -1);
      }
    }
    for (const auto& i : toDel) {
      mp.erase(i.first);
    }

    set<pair<int, int>> added;
    cs[index] = color;
    for (const auto& i : toAdd) {
      mp[i.first] = i.second;
    }
    for (const auto& i : toAdd) {
      // printf("toAdd [%d, %d)\n", i.first, i.second);
      const auto ri = getRange(i.first);
      if (added.insert(ri).second) {
        st.add(rangeSize(ri), 1);
      }
    }
    for (const auto& i : {0, n}) {
      // printf("toAdd [%d, %d)\n", i.first, i.second);
      const auto ri = getRange(i);
      if (added.insert(ri).second) {
        st.add(rangeSize(ri), 1);
      }
    }
  }

public:
  vector<int> numberOfAlternatingGroups(vector<int>& colors, vector<vector<int>>& queries) {
    n = colors.size();
    cs = colors;
    mp.clear();
    st.init(n + 1);
    for (int i = 0; i < n; ) {
      int j = i, k = cs[i];
      do {
        ++j;
        k ^= 1;
      } while (j < n && cs[j] == k);
      mp[i] = j;
      i = j;
    }

    auto r0 = getRange(0);
    for (const auto& i : mp) {
      const auto r = getRange(i.first);
      if (i.first != 0 && i.second == n && r.first >= r.second) {
        continue;
      }
      st.add(rangeSize(r), 1);
    }

    vector<int> ret;
    for (const auto& q : queries) {
      if (q[0] == 1) {
        ret.push_back(query(q[1]));
      }
      else if (q[0] == 2) {
        update(q[1], q[2]);
      }
    }
    return ret;
  }
};
