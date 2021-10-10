class Solution {
public:
    vector<int> twoOutOfThree(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3) {
        map<int, int> c;
        auto go = [&c](const vector<int>& v) {
            set<int> s(v.begin(), v.end());
            for (int i: s) {
                ++c[i];
            }
        };
        go(nums1);
        go(nums2);
        go(nums3);
        vector<int> ret;
        for (const auto&i: c) {
            if (i.second >= 2) {
                ret.push_back(i.first);
            }
        }
        return ret;
    }
};
