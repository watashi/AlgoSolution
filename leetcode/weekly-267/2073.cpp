class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        int ret = 0;
        for (int i = 0; i < (int)tickets.size(); ++i) {
            ret += min(tickets[i], tickets[k] + (i <= k ? 0 : -1));
        }
        return ret;
    }
};
