class Solution {
public:
  template<typename T = int>
  struct BIT {
    vector<T> a;

    void init(int n) {
      vector<T>(n + 1).swap(a);
    }

    void add(int i, T v) {
      for (int j = i + 1; j < (int)a.size(); j = (j | (j - 1)) + 1) {
        a[j] += v;
      }
    }

    // [0, i)
    T sum(int i) const {
      T ret = T();
      for (int j = i; j > 0; j = j & (j - 1)) {
        ret += a[j];
      }
      return ret;
    }

    T get(int i) const {
      return sum(i + 1) - sum(i);
    }

    void set(int i, T v) {
      add(i, v - get(i));
    }
  };

  vector<int> resultArray(vector<int>& x) {
    int n = x.size();
    map<int, int> mp;
    vector<int> a, b;
    for (int i : x) {
      mp[i];
    }
    int m = 0;
    for (auto& i : mp) {
      i.second = m++;
    }

    BIT<int> ca, cb;
    ca.init(m);
    cb.init(m);
    for (int i : x) {
      int j = mp[i];
      int ga = a.size() - ca.sum(j + 1);
      int gb = b.size() - cb.sum(j + 1);
      bool toA = true;
      if (a.empty()) {
        toA = true;
      }
      else if (b.empty()) {
        toA = false;
      }
      else if (ga != gb) {
        toA = ga > gb;
      }
      else {
        toA = a.size() <= b.size();
      }
      if (toA) {
        a.push_back(i);
        ca.add(j, 1);
      }
      else {
        b.push_back(i);
        cb.add(j, 1);
      }
    }
    // cout << a.size() << endl;
    a.insert(a.end(), b.begin(), b.end());
    return a;
  }
};
