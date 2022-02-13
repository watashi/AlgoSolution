class Solution {
public:
    static vector<pair<int, int>> diff(const unordered_map<int, int>& m) {
        vector<pair<int, int>> v(m.begin(), m.end());
        sort(v.begin(), v.end(), [](const auto& i, const auto& j){ return i.second > j.second; });
        v.resize(2);
        return v;
    }

    int minimumOperations(vector<int>& nums) {
        int n = (int)nums.size();
        unordered_map<int, int> odd, even;
        for (int i = 0; i < (int)nums.size(); i += 2) {
            ++even[nums[i]];
        }
        for (int i = 1; i < (int)nums.size(); i += 2) {
            ++odd[nums[i]];
        }
        auto x = diff(odd);
        auto y = diff(even);
        int z = 0;
        for (const auto& i: x) {
            for (const auto& j: y) {
                if (i.first != j.first) {
                    z = max(z, i.second + j.second);
                }
            }
        }
        return n - z;
    }
};
