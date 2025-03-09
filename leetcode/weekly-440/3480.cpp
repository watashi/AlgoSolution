
class Solution {
public:
  long long maxSubarrays(int n, vector<vector<int>>& conflictingPairs) {
    const int m = conflictingPairs.size();
    vector<pair<int, int>> pairs;
    for (int i = 0; i < m; ++i) {
      int a = conflictingPairs[i][0] - 1, b = conflictingPairs[i][1] - 1;
      if (a > b) {
        swap(a, b);
      }
      pairs.emplace_back(a, b);
    }

    vector<vector<pair<int, int>>> forward(n), backward(n);
    for (int i = 0; i < m; ++i) {
      int a = pairs[i].first, b = pairs[i].second;
      forward[a].emplace_back(i, b);
      backward[b].emplace_back(i, a);
    }

    long long zero = 0;
    for (int i = 0, j = -1; i < n; ++i) {
      for (const auto& k : backward[i]) {
        j = max(j, k.second);
      }
      // cout << i << " " << j << endl;
      zero += i - j;
    }
    // cout << "zero = " << zero << endl;

    vector<long long> one(m, 0);
    set<int> conflicts;
    for (int i = 0, j = -1; i < n; ++i) {
      for (const auto& k : backward[i]) {
        if (k.second > j) {
          conflicts.insert(k.first);
        }
      }
      while (conflicts.size() > 1) {
        ++j;
        for (const auto& k : forward[j]) {
          conflicts.erase(k.first);
        }
      }
      if (conflicts.size() == 1) {
        const int k = *conflicts.begin();
        // cout << i << ": one[" << k << "] += " << pairs[k].first - j << endl;
        one[k] += pairs[k].first - j;
      }
    }

    return zero + *max_element(one.begin(), one.end());
  }
};
