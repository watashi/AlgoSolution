class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        set<int> a(nums1.begin(), nums1.end()), b(nums2.begin(), nums2.end());
        vector<int> ab, ba;
        for (int i: a) {
            if (b.count(i) == 0) {
                ab.push_back(i);
            }
        }
        for (int i: b) {
            if (a.count(i) == 0) {
                ba.push_back(i);
            }
        }
        return vector<vector<int>>{std::move(ab), std::move(ba)};
    }
};
