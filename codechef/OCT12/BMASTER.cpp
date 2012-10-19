#include <map>
#include <cstdio>
#include <vector>
#include <numeric>
#include <algorithm>

using namespace std;

struct State {
  int r, c;
  long long m;

  void init(int r, int c) {
    this->r = r;
    this->c = c;
  }

  void clear() {
    m = 0;
  }

  bool test(int i, int j) const {
    return m & (1LL << (i * c + j));
  }

  void flip(int i, int j) {
    m ^= 1LL << (i * c + j);
  }

  void flip(int i, int j, int x, int y) {
    while (0 <= i && i < r && 0 <= j && j < c) {
      flip(i, j);
      i += x;
      j += y;
    }
  }
};

const int dx[6][2] = {
  {-1, 1},
  {0, 0},
  {-1, 0},
  {0, 1},
  {1, 0},
  {0, -1},
};
const int dy[6][2] = {
  {0, 0},
  {-1, 1},
  {0, 1},
  {1, 0},
  {0, -1},
  {-1, 0},
};
int dz[6][2];
long long mask[50][50], diff[50][50][6];

int main() {
  int n, m, q, sx, sy;
  State s;
  long long t;
  vector<int> v, w;
  map<long long, int> mp;

  scanf("%d%d%d", &n, &m, &q);
  s.init(n, m);
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      s.clear();
      s.flip(i, j);
      for (int k = 0; k < n; ++k) {
        s.flip(k, j);
      }
      for (int k = 0; k < m; ++k) {
        s.flip(i, k);
      }
      mask[i][j] = s.m;
    }
  }

  scanf("%d%d", &sx, &sy);
  for (int i = 0; i < 6; ++i) {
    for (int j = 0; j < 2; ++j) {
      scanf("%d", &dz[i][j]);
    }
  }
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      for (int k = 0; k < 6; ++k) {
        s.clear();
        s.flip(i, j, dx[k][0] * dz[k][0], dy[k][0] * dz[k][0]);
        s.flip(i, j, dx[k][1] * dz[k][1], dy[k][1] * dz[k][1]);
        diff[i][j][k] = s.m;
      }
    }
  }

  s.clear();
  s.flip(sx - 1, sy - 1);
  for (int k = 0; ; ++k) {
    if (mp.count(s.m) > 0) {
      sx = mp[s.m];
      sy = k;
      break;
    } else {
      mp[s.m] = k;
      v.push_back(__builtin_popcountll(s.m));
      t = s.m;
      for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
          if (s.test(i, j)) {
            t ^= diff[i][j][__builtin_popcountll(s.m & mask[i][j]) % 6];
          }
        }
      }
      s.m = t;
    }
  }

  w.resize(v.size() + 1);
  partial_sum(v.begin(), v.end(), w.begin() + 1);
  for (int k = 0; k < q; ++k) {
    scanf("%lld", &t);
    ++t;
    if (t < sx) {
      t = w[t];
    } else {
      t -= sx;
      t = t / (sy - sx) * (w[sy] - w[sx]) + w[sx + t % (sy - sx)];
    }
    printf("%lld\n", t);
  }

  return 0;
}

//Correct Answer
//Execution Time: 27.54

