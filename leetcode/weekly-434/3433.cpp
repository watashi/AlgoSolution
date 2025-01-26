class Solution {
public:
  vector<int> countMentions(int n, vector<vector<string>>& events) {
    vector<vector<int>> offlines(n);
    for (const auto& e : events) {
      if (e[0] == "OFFLINE") {
        int ts = stoi(e[1]);
        int x = stoi(e[2]);
        offlines[x].push_back(ts);
      }
    }
    for (auto& offline : offlines) {
      sort(offline.begin(), offline.end());
    }

    vector<int> mentions(n, 0);
    for (const auto& e : events) {
      if (e[0] == "MESSAGE") {
        int ts = stoi(e[1]);
        if (e[2] == "ALL") {
          for (int i = 0; i < n; ++i) {
            ++mentions[i];
          }
        }
        else if (e[2] == "HERE") {
          for (int i = 0; i < n; ++i) {
            auto it = upper_bound(offlines[i].begin(), offlines[i].end(), ts);
            if (it == offlines[i].begin() || ts >= it[-1] + 60) {
              ++mentions[i];
            }
          }
        }
        else {
          istringstream iss(e[2]);
          string m;
          while (iss >> m) {
            ++mentions[stoi(m.substr(2))];
          }
        }
      }
    }
    return mentions;
  }
};
