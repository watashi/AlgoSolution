class Solution {
public:
    vector<int> findLonely(vector<int>& nums) {
        unordered_map<int, int> c;
        for (int i: nums) {
            ++c[i];
        }
        vector<int> ret;
        for (int i: nums) {
            if (c[i] == 1 && c.count(i - 1) == 0 && c.count(i + 1) == 0) {
                ret.push_back(i);
            }
        }
        return ret;
    }
};
