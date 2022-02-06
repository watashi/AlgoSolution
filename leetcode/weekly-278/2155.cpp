class Solution {
public:
    vector<int> maxScoreIndices(vector<int>& nums) {
        int cur = count(nums.begin(), nums.end(), 1);
        int best = cur;
        vector<int> ret{0};
        for (int i = 0; i < (int)nums.size(); ++i) {
            if (nums[i] == 0) {
                cur += 1;
            } else {
                cur -= 1;
            }
            if (cur > best) {
                best = cur;
                ret = vector<int>{i + 1};
            } else if (cur == best) {
                ret.push_back(i + 1);
            }
        }
        return ret;
    }
};
