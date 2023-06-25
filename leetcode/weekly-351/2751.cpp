class Solution {
public:
  struct Robot {
    int position;
    int health;
    int dir;
    int index;
  };

  int n;
  vector<Robot> v;
  priority_queue<pair<int, pair<int, int>>> pq;
  vector<int> left, right;

  void check(int i, int j) {
    if (v[i].dir > 0 && v[j].dir < 0) {
      int t = v[j].position - v[i].position;
      pq.emplace(-t, make_pair(i, j));
    }
  }

  void kill(int i) {
    v[i].health = 0;
    if (left[i] >= 0) {
      right[left[i]] = right[i];
    }
    if (right[i] < n) {
      left[right[i]] = left[i];
    }
  }

  vector<int> survivedRobotsHealths(vector<int>& positions, vector<int>& healths, string directions) {
    n = positions.size();
    v.resize(n);
    left.resize(n);
    right.resize(n);
    for (int i = 0; i < n; ++i) {
      v[i].position = positions[i];
      v[i].health = healths[i];
      v[i].dir = directions[i] == 'L' ? -1 : 1;
      v[i].index = i;
      left[i] = i - 1;
      right[i] = i + 1;
    }
    sort(v.begin(), v.end(), [](const auto& lhs, const auto& rhs) { return lhs.position < rhs.position; });

    priority_queue<pair<int, pair<int, int>>>().swap(pq);
    for (int i = 1; i < n; ++i) {
      check(i - 1, i);
    }
    while (!pq.empty()) {
      int t = pq.top().first;
      int i, j;
      tie(i, j) = pq.top().second;
      pq.pop();
      if (v[i].health < v[j].health) {
        kill(i);
        i = left[i];
        --v[j].health;
      }
      else if (v[i].health > v[j].health) {
        kill(j);
        j = right[j];
        --v[i].health;
      }
      else {
        kill(i);
        i = left[i];
        kill(j);
        j = right[j];
      }
      if (0 <= i && j < n) {
        check(i, j);
      }
    }

    sort(v.begin(), v.end(), [](const auto& lhs, const auto& rhs) { return lhs.index < rhs.index; });
    vector<int> ret;
    for (const auto& i : v) {
      if (i.health > 0) {
        ret.push_back(i.health);
      }
    }
    return ret;
  }
};
