class Solution {
public:
  vector<bool> canMakePalindromeQueries(string s, vector<vector<int>>& queries) {
    int n = s.length();
    int m = n / 2;
    vector<pair<int, int>> bads;
    vector<int> diff(26, 0);
    vector<valarray<int>> c1(m + 1);
    vector<valarray<int>> c2(m + 1);
    c1[0] = c2[0] = valarray<int>(26);
    int nz = 0, start = -1;
    for (int i = 0; i < m; ++i) {
      c1[i + 1] = c1[i];
      ++c1[i + 1][s[i] - 'a'];
      c2[i + 1] = c2[i];
      ++c2[i + 1][s[n - 1 - i] - 'a'];
      if (i < m && s[i] == s[n - 1 - i]) {
        continue;
      }
      if (nz == 0) {
        start = i;
      }
      switch (++diff[s[i] - 'a']) {
      case 0:
        --nz;
        break;
      case 1:
        ++nz;
        break;
      }
      switch (--diff[s[n - 1 - i] - 'a']) {
      case 0:
        --nz;
        break;
      case -1:
        ++nz;
        break;
      }
      if (nz == 0) {
        // cout << "bad " << start << " " << i << endl;
        bads.emplace_back(start, i);
      }
    }

    // cout << "nz = " << nz << endl;
    if (nz != 0) {
      return vector<bool>(queries.size(), false);
    } else if (bads.empty()) {
      return vector<bool>(queries.size(), true);
    }

    vector<bool> ret;
    ret.reserve(queries.size());
    for (const auto& q : queries) {
      int a = q[0], b = q[1], c = n - 1 - q[3], d = n - 1 - q[2];
      if (a > c || (a == c && b <= d)) {
        swap(a, c);
        swap(b, d);
      }
      bool ok = a <= bads.front().first;
      if (b >= d) {
        ok = ok && b >= bads.back().second;
      }
      else {
        ok = ok && d >= bads.back().second;
        if (b < c) {
          auto it = lower_bound(bads.begin(), bads.end(), make_pair(c, -1));
          ok = ok && (it == bads.begin() || it[-1].second <= b);
        }
        else {
          a = q[0];
          b = q[1];
          c = n - 1 - q[3];
          d = n - 1 - q[2];
          // cout << a << " " << b << " " << c << " " << d << endl;
          if (a > c) {
            c = d + 1;
            d = b;
          }
          else {
            d = c - 1;
            c = a;
          }
          // cout << a << " " << b << " " << c << " " << d << endl;
          auto cc = c1[b + 1] - c1[a] - (c2[d + 1] - c2[c]);
          for (int i = 0; i < (int)cc.size(); ++i) {
            ok = ok && cc[i] >= 0;
          }
        }
      }
      ret.push_back(ok);
    }
    return ret;
  }
};
