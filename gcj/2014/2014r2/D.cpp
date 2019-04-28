#include <map>
#include <cstdio>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

const int MAXN = 128;
const int INF = 1'000'000'007;
const int64_t MOD = 1'000'000'007;

static int64_t f[MAXN], c[MAXN][MAXN];

void init() {
  for (int i = 0; i < MAXN; ++i) {
    c[i][0] = 1;
    f[i] = i == 0 ? 1 : f[i - 1] * i % MOD;
    for (int j = 1; j <= i; ++j) {
      c[i][j] = (c[i - 1][j - 1] + c[i - 1][j]) % MOD;
    }
  }
}

pair<int, int64_t> gao(int m, const string& prefix, const vector<string>& v);
pair<int, int64_t> cnt(int m, const string& prefix, const vector<string>& v);

map<pair<int, string>, pair<int, int64_t>> cache;

pair<int, int64_t> gao(int m, const string& prefix, const vector<string>& v) {
  if (cache.count({m, prefix}) > 0) {
    return cache[{m, prefix}];
  }

  pair<int, int64_t>& ret = cache[{m, prefix}];

  if (v.empty()) {
    ret = {0, 1};
  } else if (m == 0) {
    ret = {-INF, 0};
  } else if (v.size() == 1) {
    ret = {0, m};
  } else {
    ret = {0, 1};

    map<char, vector<string>> mp;

    for (const auto& i: v) {
      if (i.empty()) {
        ret.second = ret.second * m % MOD;
      } else {
        mp[i[0]].emplace_back(i.substr(1));
      }
    }

    for (const auto& i: mp) {
      pair<int, int64_t> tmp;
      if ((int)i.second.size() > m) {
        tmp = cnt(m, prefix + i.first, i.second);
        tmp.first += m - (int)i.second.size();
      } else {
        tmp = cnt((int)i.second.size(), prefix + i.first, i.second);
        tmp.second *= c[m][(int)i.second.size()];
        tmp.second %= MOD;
      }
      ret.first += tmp.first;
      ret.second *= tmp.second;
      ret.second %= MOD;
    }
  }

  // printf("[%d][%s] = %d %d\n", m, prefix.c_str(), ret.first, (int)ret.second);
  return ret;
}

pair<int, int64_t> cnt(int m, const string& prefix, const vector<string>& v) {
  auto a = gao(m, prefix, v);
  vector<int64_t> t(1, a.second);
  for (int i = 1; i <= m; ++i) {
    auto b = gao(m - i, prefix, v);
    if (b.first != a.first) {
      break;
    } else {
      t.emplace_back(b.second);
    }
  }
  for (int i = (int)t.size() - 2; i >= 0; --i) {
    for (int j = (int)t.size() - 1; j > i; --j) {
      t[i] -= c[m - i][m - j] * t[j];
      t[i] %= MOD;
    }
  }
  return {a.first, t[0]};
}


int main() {
  int re, n, m;
  char s[4096];
  vector<string> vs;

  init();
  scanf("%d", &re);
  for (int ri = 1; ri <= re; ++ri) {
    scanf("%d%d", &n, &m);
    vs.clear();
    for (int i = 0; i < n; ++i) {
      scanf("%s", s);
      vs.emplace_back(s);
    }
    sort(vs.begin(), vs.end());

    cache.clear();
    auto ans = cnt(m, "", vs);
    for (auto i: vs) {
      ans.first += i.size();
    }
    ans.second = (ans.second % MOD + MOD) % MOD;
    printf("Case #%d: %d %d\n", ri, ans.first + m, (int)ans.second);
  }

  return 0;
}

