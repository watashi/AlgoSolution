class Solution {
public:
  map<pair<int, int>, int> mp;
  vector<pair<int, int>> v;
  vector<vector<pair<int, int>>> e;

  int getId(const pair<int, int>& key) {
    auto it = mp.find(key);
    if (it != mp.end()) {
      return it->second;
    }
    else {
      int ret = v.size();
      mp[key] = ret;
      v.push_back(key);
      return ret;
    }
  }

  int minimumCost(vector<int>& start, vector<int>& target, vector<vector<int>>& specialRoads) {
    mp.clear();
    v.clear();
    int ss = getId({ start[0], start[1] });
    int tt = getId({ target[0], target[1] });
    for (const auto& i : specialRoads) {
      int a = getId({ i[0], i[1] });
      int b = getId({ i[2], i[3] });
    }

    int n = v.size();
    vector<vector<int>> e(n, vector<int>(n));
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < i; ++j) {
        e[i][j] = e[j][i] = abs(v[i].first - v[j].first) + abs(v[i].second - v[j].second);
      }
    }
    for (const auto& i : specialRoads) {
      int a = getId({ i[0], i[1] });
      int b = getId({ i[2], i[3] });
      e[a][b] = min(e[a][b], i[4]);
    }

    priority_queue<pair<int, int>> pq;
    vector<int> mind(n, 1 << 23);
    mind[ss] = 0;
    pq.push(make_pair(0, ss));
    while (!pq.empty()) {
      int a = pq.top().second;
      int d = -pq.top().first;
      pq.pop();
      if (mind[a] != d) {
        continue;
      }
      for (int b = 0; b < n; ++b) {
        int db = d + e[a][b];
        if (db < mind[b]) {
          mind[b] = db;
          pq.push(make_pair(-db, b));
        }
      }
    }
    return mind[tt];
  }
};
