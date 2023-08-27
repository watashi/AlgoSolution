class Solution {
public:
  struct Chain {
    using Pos = pair<std::shared_ptr<Chain>, int>;
    int n;
    vector<int64_t> v;
    vector<int64_t> s;
    Pos next;

    Chain(const vector<int>& vv, const pair<std::shared_ptr<Chain>, int>& next): n(vv.size()), v(vv.begin(), vv.end()), next(next) {
      s.resize(n + 1);
      s[0] = 0;
      partial_sum(v.begin(), v.end(), s.begin() + 1);
    }

    int64_t total(int off, int64_t len) const {
      if (off + len <= n) {
        return s[off + len] - s[off];
      }
      int64_t ret = s[n] - s[off];
      len -= (n - off);
      if (next.first) {
        // cout << "next: " << next.first->v[next.second] << endl;
        ret += next.first->total(next.second, len);
      }
      else {
        ret += (len / n) * s.back();
        len %= n;
        ret += s[len] - s[0];
      }
      return ret;
    }
  };

  static void create(const vector<int>& v, const Chain::Pos& next, vector<Chain::Pos>& chain) {
    auto p = make_shared<Chain>(v, next);
    for (int i = 0; i < (int)v.size(); ++i) {
      chain[v[i]] = make_pair(p, i);
    }
  }

  long long getMaxFunctionValue(vector<int>& receiver, long long kk) {
    int n = (int)receiver.size();
    vector<int> d(n, 0);
    vector<int> mark(n, false);
    vector<Chain::Pos> chain(n);
    for (int i : receiver) {
      ++d[i];
    }

    for (int i = 0; i < n; ++i) {
      if (d[i] != 0) {
        continue;
      }
      vector<int> v;
      for (int j = i; ; j = receiver[j]) {
        if (!mark[j]) {
          // cout << "a " << j << endl;
          mark[j] = true;
          v.push_back(j);
          continue;
        }
        if (!chain[j].first) {
          vector<int> loop;
          do {
            loop.push_back(v.back());
            v.pop_back();
          } while (loop.back() != j);
          reverse(loop.begin(), loop.end());
          create(loop, {}, chain);
        }
        create(v, chain[j], chain);
        break;
      }
    }

    for (int i = 0; i < n; ++i) {
      if (chain[i].first) {
        continue;
      }
      vector<int> loop;
      for (int j = i; ; j = receiver[j]) {
        if (!mark[j]) {
          // cout << "b " << j << endl;
          mark[j] = true;
          loop.push_back(j);
          continue;
        }
        create(loop, {}, chain);
        break;
      }
    }

    // cout << "ready" << endl;
    int64_t ret = 0;
    for (const auto& i : chain) {
      ret = max(ret, i.first->total(i.second, kk + 1));
    }
    return ret;
  }
};
