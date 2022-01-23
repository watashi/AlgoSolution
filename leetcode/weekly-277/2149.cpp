class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        vector<int> pos, neg;
        for (auto i: nums) {
            if (i > 0) {
                pos.push_back(i);
            } else {
                neg.push_back(i);
            }
        }
        vector<int> ret;
        for (int i = 0; i < (int)pos.size(); ++i) {
            ret.push_back(pos[i]);
            ret.push_back(neg[i]);
        }
        return ret;
    }
};
