class Solution {
public:
    vector<int> killProcess(vector<int>& pid, vector<int>& ppid, int kill) {
        map<int, set<int>> mp;
        int n = pid.size();
        for (int i = 0; i < n; ++i) {
            if (ppid[i] != 0) {
                mp[ppid[i]].emplace(pid[i]);
            }
        }
        vector<int> ret;
        ret.push_back(kill);
        for (int i = 0; i < (int)ret.size(); ++i) {
            for (int j: mp[ret[i]]) {
                ret.emplace_back(j);
            }
        }
        return ret;
    }
};
