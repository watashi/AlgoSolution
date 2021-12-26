class Solution {
public:
    vector<long long> getDistances(vector<int>& arr) {
        unordered_map<int, vector<int>> m;
        vector<long long> ret(arr.size(), 0);
        for (int i = 0; i < arr.size(); ++i) {
            m[arr[i]].push_back(i);
        }
        for (const auto& i: m) {
            const auto& v = i.second;
            long long sum = 0;
            for (int j = 1; j < (int)v.size(); ++j) {
                sum += v[j] - v[0];
            }
            ret[v[0]] = sum;
            for (int j = 1; j < (int)v.size(); ++j) {
                long long gap = v[j] - v[j - 1];
                sum -= ((int)v.size() - j - j) * gap;
                ret[v[j]] = sum;
            }
        }
        return ret;
    }
};
